#!/bin/bash

# --- 1. 將所有變更加入暫存區 ---
echo "Adding all changes to staging..."
git add -A

# --- 2. 準備 Commit 訊息 ---
# 如果沒有提供參數，則使用今天的日期
if [ -z "$1" ]; then
  commit_msg=$(date +"%Y%m%d")
else
  commit_msg="$1"
fi

echo "Attempting to commit with message: \"$commit_msg\""

# --- 3. 執行 Commit 並捕捉詳細輸出 ---
# 將 `git commit` 的所有輸出 (標準和錯誤) 都儲存到變數中
# `2>&1` 的意思是將「錯誤輸出」重導向到「標準輸出」，以便 `$(...)` 能一併捕捉
commit_output=$(git commit -m "$commit_msg" 2>&1)
commit_status=$? # 立刻儲存 commit 指令的結束狀態碼

# 檢查 commit 的狀態碼
if [ $commit_status -eq 0 ]; then
  # 狀態碼為 0，代表成功
  echo " Commit successful"
else
  # 狀態碼非 0，代表有問題
  # 我們需要特別處理 "nothing to commit" 這種不算錯誤的狀況
  if echo "$commit_output" | grep -q "nothing to commit"; then
    echo " Nothing to commit, working tree clean."
  else
    # 其他都是真正的錯誤，這時我們印出捕捉到的完整錯誤訊息
    echo "❌ Commit FAILED. Reason:"
    echo "--------------------------------------"
    echo "$commit_output" # 印出原始的 git 錯誤訊息
    echo "--------------------------------------"
    exit 1 # 因為 commit 失敗，直接退出腳本，不再進行 push
  fi
fi

# --- 4. 執行 Push 並捕捉詳細輸出 ---
echo "" # 印出空行以分隔
echo "Attempting to push to remote..."

# 同樣地，捕捉 `git push` 的所有輸出
push_output=$(git push 2>&1)
push_status=$? # 立刻儲存 push 指令的結束狀態碼

# 檢查 push 的狀態碼
if [ $push_status -eq 0 ]; then
  echo " Push successful"
else
  # 任何非 0 狀態碼都代表 push 失敗，印出完整錯誤訊息
  echo "❌ Push FAILED. Reason:"
  echo "--------------------------------------"
  echo "$push_output" # 印出原始的 git 錯誤訊息
  echo "--------------------------------------"
  exit 1 # 以錯誤碼退出腳本
fi