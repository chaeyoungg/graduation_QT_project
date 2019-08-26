#! /bin/bash

##서버에 올릴 파일 title을 실행시 받는다
fileTitle=("$@")

##curl 명령어로 /send에 get 요청을 보내고 받은 헤더를 cookie.txt로 저장한다. 또한 Set-Cookie를 추가적으로 추출한다
header=`curl -i -c cookie.txt http://ec2-13-209-5-1.ap-northeast-2.compute.amazonaws.com/file/weight/send/ | grep Set-Cookie`

##csrftoken 부분 뒤를 슬라이싱
csrfToken=${header##*csrftoken}

##csrftoken 뒤에 ;를 기준으로 이어지는 필요없는 부분을 제거하여 토큰값만 뽑아낸다
csrfToken=`echo $csrfToken | cut -d"=" -f2 | cut -d";" -f1`

##아까 저장한 cookie.txt 파일과 X-CSRFToken을 헤더로 설정하고 같은 폴더 내에 존재하는 test.zip 파일을 서버로 POST 한다.

curl -b cookie.txt --header "X-CSRFToken:${csrfToken}" http://ec2-13-209-5-1.ap-northeast-2.compute.amazonaws.com/file/weight/send/ -F 'title='${fileTitle} -F 'weight_file=@./test.zip'

rm cookie.txt