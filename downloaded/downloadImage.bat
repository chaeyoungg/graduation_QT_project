@echo off

curl http://ec2-13-209-5-1.ap-northeast-2.compute.amazonaws.com/file/image/download/%1/ --output test.tar
cmd.exe