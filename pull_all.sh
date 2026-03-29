#!/bin/bash

# 1. 獲取遠端最新資訊
git fetch --all

# 2. 獲取目前所在的分支名稱
CURRENT_BRANCH=$(git rev-parse --abbrev-ref HEAD)

echo "正在將本地分支 [$CURRENT_BRANCH] 強制重置為遠端 [origin/$CURRENT_BRANCH]..."

# 3. 無條件覆蓋本地代碼
# --hard 會刪除所有未提交的改動
git reset --hard "origin/$CURRENT_BRANCH"

# 4. (選配) 清理未受版本控制的檔案與資料夾
# 如果想連新建立但沒 add 的檔案都刪掉，請取消下面這行的註解
# git clean -fd

echo "同步完成！本地代碼已與遠端一致。"