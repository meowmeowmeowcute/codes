#!/bin/bash

# 腳本的第一個參數 ($1) 是由 settings.json 中的 "$fullFileName" 傳入的完整檔案路徑。

# --- 智慧路徑處理 (保持不變) ---
if [[ "$OSTYPE" == "cygwin" || "$OSTYPE" == "msys" ]]; then
    src_path=$(cygpath "$1")
else
    src_path="$1"
fi

if [ -z "$src_path" ]; then
    echo "錯誤：未提供原始碼檔案路徑。"
    exit 1
fi

# --- 核心執行邏輯 (已修改) ---

# 【修改點】使用 Bash 內建功能來安全地獲取目錄和檔名
# 語法解釋：
#   ${variable##*/}  : 從變數開頭刪除最長符合 */ 的部分，剩下檔名
#   ${variable%/*}   : 從變數結尾刪除最短符合 /* 的部分，剩下目錄名
src_dir="${src_path%/*}"
src_file="${src_path##*/}"

# 切換到原始檔所在的資料夾
cd "$src_dir" || exit 1

# 設定唯一的暫存輸出檔名
out_file="runner.out"

# 設定清理函數
cleanup() {
    rm -f "$out_file"
}
trap cleanup EXIT INT

# 編譯 C++ 檔案
echo "編譯中: g++ -std=c++17 \"$src_file\" -o \"$out_file\""
g++ -std=c++17 "$src_file" -o "$out_file"

# 檢查編譯是否成功
if [ $? -ne 0 ]; then
    echo "編譯失敗。"
    exit 1
fi

# 執行編譯後的程式
echo "執行中: ./\"$out_file\""
echo "--------------------------------------"
./"$out_file"