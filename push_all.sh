#!/bin/bash

# 把所有改動（包含新增檔案）加入暫存區
git add -A

# 如果沒有輸入參數，使用今天日期當 commit 訊息
if [ -z "$1" ]; then
  commit_msg=$(date +"%Y%m%d")
else
  commit_msg="$1"
fi

echo "Commit 訊息: $commit_msg"

git commit -m "$commit_msg"

# 推送到遠端預設分支
git push
