#!/bin/bash

# 腳本的第一個參數 ($1) 是由 settings.json 中的 "$fullFileName" 傳入的完整檔案路徑。

# --- 智慧路徑處理 (已升級) ---

# 【關鍵修正】
# 首先，主動清理掉從 Windows bash 傳來時，可能被附加在結尾的反斜線。
# 語法: ${VAR%\\} - 如果變數 VAR 以 \ 結尾，則移除它。
clean_path="${1%\\}"

# 接著，執行跨平台路徑轉換
if [[ "$OSTYPE" == "cygwin" || "$OSTYPE" == "msys" ]]; then
    # 在 Windows 環境下，使用 cygpath 將 Windows 路徑 (d:\...) 轉換為 Unix 風格路徑 (/d/...)
    src_path=$(cygpath "$clean_path")
else
    # 在 Linux 或 macOS 環境下，直接使用清理過的的路徑
    src_path="$clean_path"
fi

# 確保路徑有效
if [ -z "$src_path" ]; then
    echo "錯誤：未提供原始碼檔案路徑。"
    exit 1
fi

# --- 核心執行邏輯 (使用 Bash 內建功能，保持不變) ---
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