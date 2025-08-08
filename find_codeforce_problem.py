#!/usr/bin/env python3

import webbrowser
import re

def open_codeforces_problem(problem_code):
  """
  Constructs a Codeforces problem URL from a problem code and opens it in a web browser.

  Args:
    problem_code: The problem code, e.g., "2115A" or "2115a".
  """
  # Use regular expression to find the numerical and alphabetical parts
  match = re.match(r"(\d+)([a-zA-Z])", problem_code)

  if match:
    contest_id = match.group(1)
    problem_index = match.group(2).upper() # Ensure the problem index is uppercase
    url = f"https://codeforces.com/problemset/problem/{contest_id}/{problem_index}"
    print(f"Opening URL: {url}")
    webbrowser.open_new_tab(url)
  else:
    print("Invalid problem code format. Please use a format like '2115A'.")

if __name__ == "__main__":
  problem_input = input("Enter the Codeforces problem code (e.g., 2115A): ")
  if problem_input:
    open_codeforces_problem(problem_input)