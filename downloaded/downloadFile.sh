#! /bin/bash

fileName=("$@")

curl http://ec2-13-209-5-1.ap-northeast-2.compute.amazonaws.com/file/image/download/${fileName}/ --output test.tar
