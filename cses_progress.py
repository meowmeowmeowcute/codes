#!/usr/bin/env python3
"""
CSES Progress Tracker
掃描本地 CSES 資料夾，對照完整題庫，顯示各類別解題進度。
使用方式: python cses_progress.py [CSES資料夾路徑]
         預設路徑為當前目錄下的 "CSES"
"""

import os
import sys
import re

# ─────────────────────────────────────────────
# CSES 完整題庫（從官網抓取，2026/04 版本）
# ─────────────────────────────────────────────
CSES_PROBLEMS = {
    "Introductory Problems": [
        "Weird Algorithm", "Missing Number", "Repetitions", "Increasing Array",
        "Permutations", "Number Spiral", "Two Knights", "Two Sets", "Bit Strings",
        "Trailing Zeros", "Coin Piles", "Palindrome Reorder", "Gray Code",
        "Tower of Hanoi", "Creating Strings", "Apple Division", "Chessboard and Queens",
        "Raab Game I", "Mex Grid Construction", "Knight Moves Grid", "Grid Coloring I",
        "Digit Queries", "String Reorder", "Grid Path Description",
    ],
    "Sorting and Searching": [
        "Distinct Numbers", "Apartments", "Ferris Wheel", "Concert Tickets",
        "Restaurant Customers", "Movie Festival", "Sum of Two Values",
        "Maximum Subarray Sum", "Stick Lengths", "Missing Coin Sum",
        "Collecting Numbers", "Collecting Numbers II", "Playlist", "Towers",
        "Traffic Lights", "Distinct Values Subarrays", "Distinct Values Subsequences",
        "Josephus Problem I", "Josephus Problem II", "Nested Ranges Check",
        "Nested Ranges Count", "Room Allocation", "Factory Machines",
        "Tasks and Deadlines", "Reading Books", "Sum of Three Values",
        "Sum of Four Values", "Nearest Smaller Values", "Subarray Sums I",
        "Subarray Sums II", "Subarray Divisibility", "Distinct Values Subarrays II",
        "Array Division", "Movie Festival II", "Maximum Subarray Sum II",
    ],
    "Dynamic Programming": [
        "Dice Combinations", "Minimizing Coins", "Coin Combinations I",
        "Coin Combinations II", "Removing Digits", "Grid Paths I", "Book Shop",
        "Array Description", "Counting Towers", "Edit Distance",
        "Longest Common Subsequence", "Rectangle Cutting", "Minimal Grid Path",
        "Money Sums", "Removal Game", "Two Sets II", "Mountain Range",
        "Increasing Subsequence", "Projects", "Elevator Rides", "Counting Tilings",
        "Counting Numbers", "Increasing Subsequence II",
    ],
    "Graph Algorithms": [
        "Counting Rooms", "Labyrinth", "Building Roads", "Message Route",
        "Building Teams", "Round Trip", "Monsters", "Shortest Routes I",
        "Shortest Routes II", "High Score", "Flight Discount", "Cycle Finding",
        "Flight Routes", "Round Trip II", "Course Schedule", "Longest Flight Route",
        "Game Routes", "Investigation", "Planets Queries I", "Planets Queries II",
        "Planets Cycles", "Road Reparation", "Road Construction", "Flight Routes Check",
        "Planets and Kingdoms", "Giant Pizza", "Coin Collector", "Mail Delivery",
        "De Bruijn Sequence", "Teleporters Path", "Hamiltonian Flights", "Knight's Tour",
        "Download Speed", "Police Chase", "School Dance", "Distinct Routes",
    ],
    "Range Queries": [
        "Static Range Sum Queries", "Static Range Minimum Queries",
        "Dynamic Range Sum Queries", "Dynamic Range Minimum Queries",
        "Range Xor Queries", "Range Update Queries", "Forest Queries",
        "Hotel Queries", "List Removals", "Salary Queries", "Prefix Sum Queries",
        "Pizzeria Queries", "Visible Buildings Queries", "Range Interval Queries",
        "Subarray Sum Queries", "Subarray Sum Queries II", "Distinct Values Queries",
        "Distinct Values Queries II", "Increasing Array Queries",
        "Movie Festival Queries", "Forest Queries II", "Range Updates and Sums",
        "Polynomial Queries", "Range Queries and Copies", "Missing Coin Sum Queries",
    ],
    "Tree Algorithms": [
        "Subordinates", "Tree Matching", "Tree Diameter", "Tree Distances I",
        "Tree Distances II", "Company Queries I", "Company Queries II",
        "Distance Queries", "Counting Paths", "Subtree Queries", "Path Queries",
        "Path Queries II", "Distinct Colors", "Finding a Centroid",
        "Fixed-Length Paths I", "Fixed-Length Paths II",
    ],
    "Mathematics": [
        "Josephus Queries", "Exponentiation", "Exponentiation II",
        "Counting Divisors", "Common Divisors", "Sum of Divisors",
        "Divisor Analysis", "Prime Multiples", "Counting Coprime Pairs",
        "Next Prime", "Binomial Coefficients", "Creating Strings II",
        "Distributing Apples", "Christmas Party", "Permutation Order",
        "Permutation Rounds", "Bracket Sequences I", "Bracket Sequences II",
        "Counting Necklaces", "Counting Grids", "Fibonacci Numbers",
        "Throwing Dice", "Graph Paths I", "Graph Paths II",
        "System of Linear Equations", "Sum of Four Squares", "Triangle Number Sums",
        "Dice Probability", "Moving Robots", "Candy Lottery", "Inversion Probability",
        "Stick Game", "Nim Game I", "Nim Game II", "Stair Game",
        "Grundy's Game", "Another Game",
    ],
    "String Algorithms": [
        "Word Combinations", "String Matching", "Finding Borders", "Finding Periods",
        "Minimal Rotation", "Longest Palindrome", "All Palindromes",
        "Required Substring", "Palindrome Queries", "Finding Patterns",
        "Counting Patterns", "Pattern Positions", "Distinct Substrings",
        "Distinct Subsequences", "Repeating Substring", "String Functions",
        "Inverse Suffix Array", "String Transform", "Substring Order I",
        "Substring Order II", "Substring Distribution",
    ],
    "Geometry": [
        "Point Location Test", "Line Segment Intersection", "Polygon Area",
        "Point in Polygon", "Polygon Lattice Points", "Minimum Euclidean Distance",
        "Convex Hull", "Maximum Manhattan Distances", "All Manhattan Distances",
        "Intersection Points", "Line Segments Trace I", "Line Segments Trace II",
        "Lines and Queries I", "Lines and Queries II", "Area of Rectangles",
        "Robot Path",
    ],
    "Advanced Techniques": [
        "Meet in the Middle", "Hamming Distance", "Corner Subgrid Check",
        "Corner Subgrid Count", "Reachable Nodes", "Reachability Queries",
        "Cut and Paste", "Substring Reversals", "Reversals and Sums",
        "Necessary Roads", "Necessary Cities", "Eulerian Subgraphs",
        "Monster Game I", "Monster Game II", "Subarray Squares",
        "Houses and Schools", "Knuth Division", "Apples and Bananas",
        "One Bit Positions", "Signal Processing", "New Roads Queries",
        "Dynamic Connectivity", "Parcel Delivery", "Task Assignment",
        "Distinct Routes II",
    ],
    "Sliding Window Problems": [
        "Sliding Window Sum", "Sliding Window Minimum", "Sliding Window Xor",
        "Sliding Window Or", "Sliding Window Distinct Values", "Sliding Window Mode",
        "Sliding Window Mex", "Sliding Window Median", "Sliding Window Cost",
        "Sliding Window Inversions", "Sliding Window Advertisement",
    ],
    "Interactive Problems": [
        "Hidden Integer", "Hidden Permutation", "K-th Highest Score",
        "Permuted Binary Strings", "Colored Chairs", "Inversion Sorting",
    ],
    "Bitwise Operations": [
        "Counting Bits", "Maximum Xor Subarray", "Maximum Xor Subset",
        "Number of Subset Xors", "K Subset Xors", "All Subarray Xors",
        "Xor Pyramid Peak", "Xor Pyramid Diagonal", "Xor Pyramid Row",
        "SOS Bit Problem", "And Subset Count",
    ],
    "Construction Problems": [
        "Inverse Inversions", "Monotone Subsequences", "Third Permutation",
        "Permutation Prime Sums", "Chess Tournament", "Distinct Sums Grid",
        "Filling Trominos", "Grid Path Construction",
    ],
    "Advanced Graph Problems": [
        "Nearest Shops", "Prüfer Code", "Tree Traversals", "Course Schedule II",
        "Acyclic Graph Edges", "Strongly Connected Edges", "Even Outdegree Edges",
        "Graph Girth", "Fixed Length Walk Queries", "Transfer Speeds Sum",
        "MST Edge Check", "MST Edge Set Check", "MST Edge Cost",
        "Network Breakdown", "Tree Coin Collecting I", "Tree Coin Collecting II",
        "Tree Isomorphism I", "Tree Isomorphism II", "Flight Route Requests",
        "Critical Cities", "Visiting Cities", "Graph Coloring", "Bus Companies",
        "Split into Two Paths", "Network Renovation", "Forbidden Cities",
        "Creating Offices", "New Flight Routes",
    ],
    "Counting Problems": [
        "Filled Subgrid Count I", "Filled Subgrid Count II",
        "All Letter Subgrid Count I", "All Letter Subgrid Count II",
        "Border Subgrid Count I", "Border Subgrid Count II", "Raab Game II",
        "Empty String", "Permutation Inversions", "Counting Bishops",
        "Counting Sequences", "Grid Paths II", "Counting Permutations",
        "Grid Completion", "Counting Reorders", "Tournament Graph Distribution",
        "Collecting Numbers Distribution", "Functional Graph Distribution",
    ],
    "Additional Problems I": [
        "Shortest Subsequence", "Distinct Values Sum", "Distinct Values Splits",
        "Swap Game", "Beautiful Permutation II", "Multiplication Table",
        "Bubble Sort Rounds I", "Bubble Sort Rounds II", "Nearest Campsites I",
        "Nearest Campsites II", "Advertisement", "Special Substrings",
        "Counting LCM Arrays", "Square Subsets", "Subarray Sum Constraints",
        "Water Containers Moves", "Water Containers Queries", "Stack Weights",
        "Maximum Average Subarrays", "Subsets with Fixed Average",
        "Two Array Average", "Pyramid Array", "Permutation Subsequence",
        "Bit Inversions", "Writing Numbers", "Letter Pair Move Game",
        "Maximum Building I", "Sorting Methods", "Cyclic Array", "List of Sums",
    ],
    "Additional Problems II": [
        "Bouncing Ball Steps", "Bouncing Ball Cycle", "Knight Moves Queries",
        "K Subset Sums I", "K Subset Sums II", "Increasing Array II",
        "Food Division", "Swap Round Sorting", "Binary Subsequences",
        "School Excursion", "Coin Grid", "Grid Coloring II",
        "Programmers and Artists", "Removing Digits II", "Coin Arrangement",
        "Replace with Difference", "Grid Puzzle I", "Grid Puzzle II",
        "Bit Substrings", "Reversal Sorting", "Book Shop II", "GCD Subsets",
        "Minimum Cost Pairs", "Same Sum Subsets", "Mex Grid Queries",
        "Maximum Building II", "Stick Divisions", "Stick Difference",
        "Coding Company", "Two Stacks Sorting",
    ],
}

# ─────────────────────────────────────────────
# 工具函式
# ─────────────────────────────────────────────

def normalize(name: str) -> str:
    """統一化名稱以便比對：去空白、小寫、移除非字母數字字元。"""
    return re.sub(r'[^a-z0-9]', '', name.lower())

def get_solved_names(category_path: str) -> list[str]:
    """
    回傳此類別資料夾內，所有已解題目的「資料夾名稱 / .cpp 檔名（去副檔名）」清單。
    """
    solved = []
    try:
        entries = os.listdir(category_path)
    except FileNotFoundError:
        return solved

    for entry in entries:
        full = os.path.join(category_path, entry)
        if os.path.isdir(full):
            solved.append(entry)
        elif entry.endswith('.cpp'):
            solved.append(entry[:-4])  # 去掉 .cpp
    return solved

def match_to_official(local_names: list[str], official_list: list[str]) -> list[str]:
    """
    加強版的匹配邏輯。先嘗試移除題號前綴，再進行模糊比對。
    """
    official_norm = {normalize(p): p for p in official_list}
    matched = set()

    for local in local_names:
        # 移除常見的編號前綴，例如 "01-", "1. ", "001_"
        local_clean = re.sub(r'^\d+[\s\-_.]*', '', local)
        local_norm = normalize(local_clean)

        # 1. 完全比對
        if local_norm in official_norm:
            matched.add(official_norm[local_norm])
            continue

        # 2. 模糊包含比對（官方題名 包含 本地名，或反之）
        found = False
        for off_norm, off_name in official_norm.items():
            if local_norm and (local_norm in off_norm or off_norm in local_norm):
                matched.add(off_name)
                found = True
                break

        # 3. 若還是沒找到，保留原始名稱（標記為未對應）
        if not found:
            matched.add(f"[unmapped] {local}")

    return list(matched)

def progress_bar(done: int, total: int, width: int = 28) -> str:
    pct = done / total if total else 0
    filled = round(pct * width)
    bar = '█' * filled + '░' * (width - filled)
    return f"[{bar}] {done}/{total}  {pct*100:.0f}%"

# ─────────────────────────────────────────────
# 主程式
# ─────────────────────────────────────────────

def main():
    # 決定 CSES 根目錄
    if len(sys.argv) >= 2 and not sys.argv[1].startswith("-"):
        root = sys.argv[1]
    else:
        # 自動偵測：先找當前目錄，再找腳本同層
        candidates = [
            os.path.join(os.getcwd(), "CSES"),
            os.path.join(os.path.dirname(os.path.abspath(__file__)), "CSES"),
            os.getcwd(),  # 當前目錄本身就是 CSES 根
        ]
        root = None
        for c in candidates:
            if os.path.isdir(c):
                root = c
                break
        if root is None:
            print("找不到 CSES 資料夾，請指定路徑：python cses_progress.py <路徑>")
            sys.exit(1)

    root = os.path.abspath(root)
    print(f"\n📂 掃描路徑：{root}\n")

    results = {}
    total_solved = 0
    total_official = 0

    for category, official_list in CSES_PROBLEMS.items():
        local_dir = None
        cat_norm = normalize(category)
        
        # 嘗試對應本地資料夾（允許部分關鍵字匹配）
        try:
            for entry in os.listdir(root):
                entry_path = os.path.join(root, entry)
                if not os.path.isdir(entry_path): 
                    continue
                
                entry_norm = normalize(entry)
                # 如果資料夾名稱包含類別關鍵字，或類別包含資料夾名
                if entry_norm and (entry_norm in cat_norm or cat_norm in entry_norm):
                    local_dir = entry_path
                    break
        except FileNotFoundError:
            pass

        if local_dir:
            local_names = get_solved_names(local_dir)
            matched = match_to_official(local_names, official_list)
            unmatched = [m for m in matched if m.startswith("[unmapped]")]
            solved = [m for m in matched if not m.startswith("[unmapped]")]
        else:
            solved = []
            unmatched = []

        results[category] = {
            "solved": solved,
            "unmatched": unmatched,
            "official_count": len(official_list),
            "official_list": official_list,
        }
        total_solved += len(solved)
        total_official += len(official_list)

    # 決定輸出模式
    detail_mode = any(a in ("--detail", "-d") for a in sys.argv[1:])

    if detail_mode:
        print_detail(results, total_solved, total_official)
    else:
        print_summary(results, total_solved, total_official)

def print_summary(results: dict, total_solved: int, total_official: int):
    W = 70
    BAR = 20

    print("=" * W)
    print(f"{'🔥  CSES 刷題進度報告  🔥':^68}")
    print("=" * W)

    active = {cat: info for cat, info in results.items() if len(info["solved"]) > 0}
    
    if not active:
        print(f"\n{'⚠️ 找不到任何已解題目。請確認資料夾結構與命名。':^66}\n")
    else:
        cat_col = max((len(c) for c in active), default=10) + 2
        for category, info in sorted(active.items()):
            s = len(info["solved"])
            t = info["official_count"]
            pct = s / t * 100 if t else 0
            filled = round(pct / 100 * BAR)
            bar = '█' * filled + '░' * (BAR - filled)
            print(f"  {category:<{cat_col}}| {s:3d}/{t:<3d}  ~~  {pct:5.1f}% [{bar}]")

    print("-" * W)
    pct_total = total_solved / total_official * 100 if total_official else 0
    filled = round(pct_total / 100 * 25)
    bar = '█' * filled + '░' * (25 - filled)
    
    # 修正："🏆" 和 "總進度" 共有 4 個全形/雙寬字元，排版補白時需扣除 4 以求完美對齊
    total_title = "🏆 總進度 (Overall)"
    pad_len = cat_col - 4 if active else 21
    print(f"  {total_title:<{pad_len}}| {total_solved:3d}/{total_official:<3d}  ~~  {pct_total:5.1f}% [{bar}]")
    
    print("=" * W)
    print(f"\n  使用 --detail 或 -d 查看完整題目列表\n")

def print_detail(results: dict, total_solved: int, total_official: int):
    SEP = "─" * 62

    print("╔══════════════════════════════════════════════════════════════╗")
    print("║              🏆  CSES 解題進度總覽（完整版）                ║")
    print("╚══════════════════════════════════════════════════════════════╝")
    print(f"\n  總進度  {progress_bar(total_solved, total_official, 30)}")
    print(f"\n{SEP}")

    for category, info in results.items():
        s = len(info["solved"])
        t = info["official_count"]
        bar = progress_bar(s, t, 20)

        print(f"\n  📌 {category}")
        print(f"     {bar}")

        unsolved = [p for p in info["official_list"] if p not in info["solved"]]
        if s == 0 and not info["unmatched"]:
            print("     （尚未開始）")
        else:
            if s > 0:
                print(f"     ✅ 已解 ({s}題)：", end="")
                print(", ".join(info["solved"]))
            if unsolved:
                print(f"     ⬜ 未解 ({len(unsolved)}題)：", end="")
                print(", ".join(unsolved))

        if info["unmatched"]:
            print(f"     ⚠️  無法對應至官方題庫：", end="")
            print(", ".join(m.replace("[unmapped] ", "") for m in info["unmatched"]))

    print(f"\n{SEP}")
    print(f"\n  🎯 最終統計：{total_solved} / {total_official} 題  ({total_solved/total_official*100:.1f}%)\n")

if __name__ == "__main__":
    main()