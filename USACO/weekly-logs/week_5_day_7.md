# Daily Experiment Log
Week 5 / Day 7
Date: ____ (YYYY‑MM‑DD)
Active modeling version: v1.0
Today's Experiment Objective: Month2 Week5 final day; grid condition‑check problem. Use v1.0 modeling workflow. Practice grid boundary guard logic, distinguish 0‑based internal index and 1‑based output index. Continue collect timing and bug‑classification data for Week5 summary.
Pre‑set hypothesis: Scan every grid cell. A clue cell needs either horizontal pattern(left blocked + two empty to right) OR vertical pattern(top blocked + two empty downward). Be careful about out‑of‑bounds access; output coordinates must add one for 1‑based requirement.
Selected problems for today:
- USACO 2014 December Bronze P2 — Clue

| Problem Link | Modeling Time | Coding Time | Debug Time | Result | Bug Type |
| ---- | ---- | ---- | ---- | ---- | ---- |
| Clue 2014 Dec Bronze P2 | ____ min | ____ min | ____ min | ____ | ____ |

---
## Step 1 Problem Abstraction
Given N rows M columns grid, cell `#` is wall, `.` is empty.
A clue cell (i,j) must be empty.
Horizontal rule: left side is wall OR grid left boundary; next two cells to right are both empty and inside grid.
Vertical rule: upper side is wall OR grid top boundary; next two cells downward are both empty and inside grid.
If horizontal OR vertical rule holds, cell is clue cell.
Collect all clue positions, output count and positions in **1‑based coordinate**.

## Step 2 Algorithm Selection
Candidate1: BFS / flood fill — rejected, no connected‑component requirement, only static per‑cell pattern check.
Candidate2: Brute‑force iterate all cells in grid, evaluate horizontal and vertical condition for each candidate cell.
Selected algorithm: full grid scan with conditional checking
Reason: Grid dimension small, O(N*M) is efficient, logic directly follows problem statement.
Complexity: O(N*M).

## Step3 Logic & Data Structure Framework
Data structure:
- `vector<string> grid`: store input grid (0‑based internally)
- `vector<pair<int,int>> ans`: store 1‑based answer coordinates

Pseudocode:
Read N, M
Read N lines into grid
ans empty
for i from 0 to N‑1:
    for j from 0 to M‑1:
        if grid[i][j] == '#': continue
        isClue = false
        // horizontal condition
        leftBlock = (j == 0) || (grid[i][j‑1] == '#')
        twoRightClear = (j+1 < M && grid[i][j+1]=='.') && (j+2 < M && grid[i][j+2]=='.')
        if leftBlock && twoRightClear:
            isClue = true
        // vertical condition
        upBlock = (i == 0) || (grid[i‑1][j] == '#')
        twoDownClear = (i+1 < N && grid[i+1][j]=='.') && (i+2 < N && grid[i+2][j]=='.')
        if upBlock && twoDownClear:
            isClue = true
        if isClue:
            ans.emplace_back(i+1, j+1)
print ans.size()
for each pair in ans:
    print first, second

## Step4 Boundary & Fault Tolerance Modeling
Pre‑predicted edge cases:
1. Cell near right edge: j+1 or j+2 out‑of‑range → twoRightClear false.
2. Cell near bottom edge: i+1 or i+2 out‑of‑range → twoDownClear false.
3. j=0: leftBlock is true by boundary; i=0: upBlock is true by boundary.
4. Same cell satisfies both horizontal and vertical: add answer only once.
5. Index trap: internal 0‑based, output must plus 1 for row and column.
6. Trap: access grid[j+2] without range check → runtime crash.

## Step5 Verification & Reflection Modeling
Test official sample and edge‑case groups: border cells, cell satisfying both rules.
Classify bug type: ____ (A/B/C/D) — fill after real testing.
Evaluate 5‑step workflow(v1.0): Step4 is critical for grid boundary and index conversion traps.
Did the process catch errors early? ____

---
## Review after solving all problems
Compare predicted edge cases and real bugs: ____
Did the 5‑step modeling process help catch errors in advance? ____
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today): ____

## Quick Reflection
Which step was hardest today: ____

## Tomorrow's Simple Plan
Week5 weekend weekly review. Aggregate Week5 timing, bug‑type statistics, complete Week5 weekly‑log report.

✅ Checklist
- [x] New problem markdown added to /problems
- [x] Source code added to /solutions
- [x] This daily log saved
- [x] Git commit completed
