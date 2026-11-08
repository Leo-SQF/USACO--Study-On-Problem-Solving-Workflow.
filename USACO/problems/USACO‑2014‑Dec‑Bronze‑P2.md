# Problem Info
- Name: Clue
- Source: USACO 2014 December Bronze P2
- Difficulty (self‑rated): ____ (1–10)
- Date attempted: ____ (YYYY‑MM‑DD)
- Status: ____ (Not started / In progress / Solved / Stuck / Solved with help)
- Time spent: ____ min

## Step 1 — Read & Restate
Given an N‑by‑M grid. Cell is either `'.'` empty or `'#'` blocked wall.
A cell (i,j) is a clue cell if it satisfies **horizontal condition OR vertical condition**:
1. Horizontal condition：Cell itself is empty; left side is blocked(wall or grid boundary); next two cells to the right are also empty.
2. Vertical condition：Cell itself is empty; upper side is blocked(wall or grid boundary); next two cells downward are also empty.

Collect all clue cell positions. Output total count, then output each coordinate using **1‑based index**.

| Item | Value |
|------|-------|
| Input | N M; N lines of grid string |
| Output | number of clue cells; each cell (row,col), 1‑based |
| Constraints | small N,M; brute‑force scan every cell feasible |
| Edge cases | cell at grid boundary; right/down near border cannot satisfy two‑empty requirement; both horizontal & vertical condition satisfied for same cell; wall on left/up |

## Step 2 — Model
- Model type: Grid brute‑force cell‑by‑cell checking with boundary guard
- Explanation:
Iterate every grid cell(i,j, 0‑based in code).
Skip if cell is wall `#`.
Check horizontal clue condition:
`leftBlock`(j==0 or grid[i][j‑1]=='#') AND j+1,j+2 inside grid and both are '.'.
Check vertical clue condition:
`upBlock`(i==0 or grid[i‑1][j]=='#') AND i+1,i+2 inside grid and both are '.'.
If either condition true → it is clue cell, push (i+1,j+1) to answer list for 1‑based output.

## Step 3 — Algorithm
- Algorithm chosen: Full grid brute‑force scan, conditional check for each cell
- Time complexity: O(N*M)
- Space complexity: O(N*M) store grid; answer vector for result points
- Why it fits: Grid size small; straightforward per‑cell condition checking; no BFS/DFS needed.

## Step 4 — Implementation Notes
- Data structures used: `vector<string> grid`, `vector<pair<int,int>> ans`
- Pitfalls / bugs I hit: ____
  1. Code uses 0‑based indices internally; output must convert to **1‑based** (i+1, j+1).
  2. Must do boundary check before accessing j+1, j+2 / i+1, i+2; avoid array out‑of‑bounds.
  3. Current cell itself must be '.'; skip '#' cells immediately.
  4. Logical OR: satisfy horizontal OR vertical condition counts as clue cell.
  5. leftBlock includes j==0 (grid left border counts as block); upBlock includes i==0 (grid top border counts as block).

## Step 5 — Verification
- [ ] Pass official sample input
- [ ] Test cell at grid right border: cannot have two cells to right → horizontal condition false
- [ ] Test cell near bottom border: cannot have two cells down → vertical condition false
- [ ] Test cell satisfies both horizontal and vertical, still record once
- [ ] Test cell on top‑left corner

## Reflection (fill AFTER solving)
- What was the hardest part? ____
- Did I follow the workflow, or skip a step? ____
- If stuck: where did I get stuck and what unblocked me? ____
- One thing to improve next time: ____
