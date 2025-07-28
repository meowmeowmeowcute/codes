#!/bin/bash

# 腳本的第一個參數 ($1) 是由 settings.json 中的 "$fullFileName" 傳入的完整檔案路徑。

# --- 智慧路徑處理 ---
# 檢查作業系統類型，只在 Windows 的 bash 環境 (如 Git Bash) 中執行 cygpath
if [[ "$OSTYPE" == "cygwin" || "$OSTYPE" == "msys" ]]; then
    # 在 Windows 環境下，轉換路徑 (e.g., C:/... -> /c/...)
    src_path=$(cygpath "$1")
else
    # 在 Linux 或 macOS 環境下，直接使用傳入的路徑
    src_path="$1"
fi

# 確保傳入的路徑有效
if [ -z "$src_path" ]; then
    echo "錯誤：未提供原始碼檔案路徑。"
    exit 1
fi

# --- 核心執行邏輯 ---

# 切換到原始檔所在的資料夾，並用引號保護以處理空格
cd "$(dirname "$src_path")" || exit 1

# 從完整路徑中僅擷取檔名
src_file="$(basename "$src_path")"

# 設定一個唯一的暫存輸出檔名，避免同時執行多個檔案時互相覆蓋
out_file="runner_temp_$(date +%s)_$$.out"

# 設定清理函數：當腳本無論是正常結束還是被中斷(Ctrl+C)時，都自動刪除暫存檔
cleanup() {
    rm -f "$out_file"
}
trap cleanup EXIT INT

# 編譯 C++ 檔案，用引號保護檔名以處理空格
echo "編譯中: g++ -std=c++17 \"$src_file\" -o \"$out_file\""
g++ -std=c++17 "$src_file" -o "$out_file"

# 檢查上一個指令 (編譯) 是否成功。如果失敗 (回傳值不為 0)，則退出腳本
if [ $? -ne 0 ]; then
    echo "編譯失敗。"
    exit 1
fi

# 執行編譯後的程式
echo "執行中: ./\"$out_file\""
echo "--------------------------------------"
./"$out_file"