<!-- Save as: problems/greedy/cowtip.md -->
## Problem Info
- **Name:** `Cow Tip (cowtip)`
- **Source:** `USACO Bronze`
- **Difficulty (self-rated):** `2/10`
- **Date attempted:** `2026-10-16`
- **Status:** `Solved`
- **Time spent:** `19 min`
---
## Step 1 — Read & Restate
> We have an N×N grid of cows, 0 = upright, 1 = tipped over.
> One operation: pick an upper-left rectangle (the rectangle’s bottom-right corner is some cell (i,j)), flip every cow inside this rectangle (0 ↔ 1).
> Find the **minimum number of operations** to turn the entire grid into all 0s.

| Item | Value |
|------|-------|
| Input | First line N; next N lines each is a string of N characters (0 or 1) |
| Output | Minimum number of rectangle flip operations |
| Constraint on N | 1 ≤ N ≤ 10 |
| Edge cases | N=1; grid already all 0; grid all 1 |
---
## Step 2 — Model
- Model type: `greedy + simulation`
- Explanation:
Process grid starting from the **bottom-right cell moving up and left**. The bottom-right cell can only be toggled by the rectangle ending exactly at this cell. If the cell is 1, we must flip this rectangle, increment count, and flip all cells in that upper-left rectangle. Once we move on, we will never touch this cell again. This greedy approach guarantees minimal steps.
---
## Step 3 — Algorithm
- Algorithm chosen: Backward greedy scan + brute rectangle flip
- Time complexity: $O(N^3)$
- Space complexity: $O(N^2)$
- Why it fits the constraints:
N ≤ 10, so total operations are at most $10^3=1000$, extremely small. No performance issues.
---
## Step 4 — Implementation Notes
- Data structures used: 2D integer vector to store grid
- Pitfalls / bugs I hit:
1. Accidentally scanning top-to-bottom instead of bottom-to-top (breaks greedy invariant)
2. Off-by-one error in rectangle flip boundaries
---
## Step 5 — Verification
- [x] Passes provided samples
- [x] Passes my edge cases
- [x] Within time limit
- [x] Brute-force cross-check (if applicable)
---
## Reflection (fill AFTER solving)
- What was the hardest part? Realizing why the greedy order (bottom-right first) works. It’s easy to think of trying rectangles randomly, but only processing from the end guarantees correctness.
- Did I follow the workflow, or skip a step? Followed workflow, first modeled the greedy invariant before coding.
- If stuck: where did I get stuck and what unblocked me? Not stuck.
- One thing to improve next time: Draw small grid examples by hand to verify the greedy logic before coding.
