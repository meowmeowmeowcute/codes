#!/bin/bash

# 將路徑轉換成 Unix 格式（處理 Windows 傳來的路徑）
src=$(cygpath "$1")

# 切換到原始檔所在資料夾
cd "$(dirname "$src")" || exit 1

# 擷取檔名
src_file="$(basename "$src")"

# 設定暫存輸出檔名（用純檔名）
out="run_temp_$$.exe"

# 清理函數
cleanup() {
    rm -f "$out"
    rm -f tempCodeRunnerFile.cpp
}
# 設定在 EXIT、INT（Ctrl+C）時自動呼叫 cleanup
trap cleanup EXIT INT

# 編譯
g++ "$src_file" -o "$out" || exit 1

# 執行
./"$out"
