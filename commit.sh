#!/bin/bash

echo "$1"

echo '$1'

git config --global user.name "kobunteki"

git config --global user.email "gwdolorin@hotmail.com"

git add .

//提交

git commit -m “”

//提交到远程
git push -u origin master


