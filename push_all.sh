#!/bin/bash

# 把所有改動（包含新增檔案）加入暫存區
git add -A

# 提交，帶上你輸入的訊息參數
if [ -z "$1" ]
then
  echo "請輸入 commit 訊息"
  exit 1
fi

git commit -m "$1"

# 推送到遠端預設分支
git push
