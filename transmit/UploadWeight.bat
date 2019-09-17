@echo off

rem 서버에 올릴 파일 title을 실행시 받는다
set fileTitle=%1
echo %fileTitle%

rem curl 명령어로 /send에 get 요청을 보내고 받은 헤더를 cookie.txt로 저장한다. 또한 Set-Cookie를 추가적으로 추출한다
curl -i -c cookie.txt http://ec2-13-209-5-1.ap-northeast-2.compute.amazonaws.com/file/weight/send/

for /f "tokens=7 delims=	" %%i in (
'find "csrftoken" cookie.txt'
) do (
    set csrftoken=%%i
)

rem 아까 저장한 cookie.txt 파일과 X-CSRFToken을 헤더로 설정하고 같은 폴더 내에 존재하는 test.zip 파일을 서버로 POST 한다.
curl -vL -b cookie.txt --header "X-CSRFToken:%csrftoken%" http://ec2-13-209-5-1.ap-northeast-2.compute.amazonaws.com/file/weight/send/ -F "title="%fileTitle% -F "weight_file="@test.tar

del cookie.txt

cmd.exe