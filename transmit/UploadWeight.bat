@echo off

rem 서버에 올릴 파일 title을 실행시 받는다
set fileTitle=%1

rem curl 명령어로 /send에 get 요청을 보내고 받은 헤더를 cookie.txt로 저장한다. 또한 Set-Cookie를 추가적으로 추출한다
echo %fileTitle%
cmd.exe