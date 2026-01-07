import json
import os

# 設定路徑
SOURCE_TEMPLATE = '.template/template.cpp'
OUTPUT_SNIPPET = '.vscode/cpp.code-snippets'

def generate():
    if not os.path.exists(SOURCE_TEMPLATE):
        print("找不到原始模板檔！")
        return

    with open(SOURCE_TEMPLATE, 'r', encoding='utf-8') as f:
        lines = f.read().splitlines()

    snippet_content = {
        "Competitive Programming Template": {
            "prefix": "cp",
            "body": lines,
            "description": "Auto-generated from base_template.cpp"
        }
    }

    # 確保 .vscode 資料夾存在
    os.makedirs('.vscode', exist_ok=True)

    with open(OUTPUT_SNIPPET, 'w', encoding='utf-8') as f:
        json.dump(snippet_content, f, indent=4)
    
    print(f"成功將 {SOURCE_TEMPLATE} 轉換為 {OUTPUT_SNIPPET}")

if __name__ == "__main__":
    generate()