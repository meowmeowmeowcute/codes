#!/bin/bash

# 將所有變更（包含新增檔案）加入暫存區
git add -A

# 如果沒有輸入參數，使用今天日期作為 commit 訊息
if [ -z "$1" ]; then
  commit_msg=$(date +"%Y%m%d")
else
  commit_msg="$1"
fi

echo "Commit message: $commit_msg"

# 嘗試 commit，若無變更則跳過
if git commit -m "$commit_msg" > /dev/null 2>&1; then
  echo "Commit successful"
else
  echo "Nothing to commit or commit failed"
fi

# 嘗試 push
if git push > /dev/null 2>&1; then
  echo "Push successful"
else
  echo "Push failed. Please check network or remote settings"
fi
