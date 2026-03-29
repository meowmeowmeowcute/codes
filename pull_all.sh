#!/bin/bash

# 1. Fetching from remote
echo "Action: Fetching all updates from remote..."
git fetch --all
if [ $? -eq 0 ]; then
    echo "Status: Fetch successful."
else
    echo "Status: Fetch failed. Please check your network or permissions."
    exit 1
fi

# 2. Get current branch name
CURRENT_BRANCH=$(git rev-parse --abbrev-ref HEAD)

# 3. Performing Hard Reset
echo "Action: Resetting local branch [$CURRENT_BRANCH] to [origin/$CURRENT_BRANCH]..."
git reset --hard "origin/$CURRENT_BRANCH"

if [ $? -eq 0 ]; then
    echo "Status: Reset successful. Local changes overwritten."
else
    echo "Status: Reset failed. Ensure the remote branch exists."
    exit 1
fi

# 4. (Optional) Clean untracked files
# echo "Action: Cleaning untracked files..."
# git clean -fd
# echo "Status: Clean complete."

echo "----------------------------------------"
echo "Final Status: Local repository is now synced with remote."