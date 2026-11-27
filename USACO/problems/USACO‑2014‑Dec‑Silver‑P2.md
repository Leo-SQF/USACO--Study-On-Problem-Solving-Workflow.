# Problem Info
- Name: Marathon
- Source: USACO 2014 December Silver P2
- Difficulty (self‑rated): ____ (1–10)
- Date attempted: ____ (YYYY‑MM‑DD)
- Status: ____ (Not started / In progress / Solved / Stuck / Solved with help)
- Time spent: ____ min

## Step 1 — Read & Restate
We have N check‑points in fixed visiting order (1 → 2 → … → N).
We are allowed to **skip up to K intermediate points**. We must still start at point 1 and end at point N.
Movement cost is Manhattan distance `|x1‑x2|+|y1‑y2|`.
`dp[i][j]`: minimal total distance to reach point `i`, having skipped exactly `j` points so far.
Transition: previous landing point is `t` (`t < i`).
Number of skipped points between t and i: `skip = i‑t‑1`.
If `j >= skip`: `dp[i][j] = min(dp[i][j], dp[t][j‑skip] + dist(t,i))`.
Initialize `dp[1][0]=0`, rest INF.
Answer = minimum value among `dp[N][0 … K]`.

| Item | Value |
|------|-------|
| Input | N K; N coordinate points in order 1…N |
| Output | minimal total Manhattan distance starting at 1, ending at N, skip at most K points |
| Constraints | N ≤ 500, K < N; DP table size 505×505 |
| Edge cases | K=0 (skip nothing, original full path); skip all intermediate points (jump directly 1→N); skip exactly K points; skip fewer than K |

## Step 2 — Model
- Model type: 2‑dimensional dynamic‑programming
- Explanation:
State definition `dp[i][j]`: minimum travel distance arriving at point `i` with total `j` points skipped.
1. Base case: start at point 1, zero skips: `dp[1][0] = 0`. All others set to INF.
2. For each current point i, for each possible skip‑count j, enumerate previous landing point t (t < i).
   The points `t+1 … i‑1` are skipped: `skip = i‑t‑1`.
   If we have enough allowed skips `j >= skip`, relax dp[i][j].
3. Result: take min over `dp[N][0...K]` because we may skip **at most K** (not required to use all K skips).

## Step 3 — Algorithm
- Algorithm chosen: 2‑D DP with triple nested loops
- Time complexity: O(N²·K). N=500, theoretical upper large, but within problem’s given constraints.
- Space complexity: O(N·K) for dp table
- Why it fits: N ≤ 500, DP table 505×505 fits memory.

## Step 4 — Implementation Notes
- Data structures used: `Point p[]` store coordinates; `dp[505][505]` 2D‑DP table; `dist()` computes Manhattan distance; INF large constant.
- Pitfalls / bugs I hit: ____
  1. Initialize entire dp table to INF, only `dp[1][0]=0`.
  2. `skip = i‑t‑1`: count of intermediate points skipped between t and i.
  3. Condition `j >= skip`: cannot use more skips than j already accumulated.
  4. Answer is min of `dp[N][0 ... K]`: we can use **0 up to K skips**, do not only take dp[N][K].
  5. Points are 1‑based indexing.
  6. Manhattan distance: `abs(xa‑xb)+abs(ya‑yb)`.

## Step 5 — Verification
- [ ] Pass official sample input
- [ ] Test K=0 (no‑skip baseline)
- [ ] Test jump directly 1 → N (skip all middle points)
- [ ] Test case using fewer than K allowed skips

## Reflection (fill AFTER solving)
- What was the hardest part? ____
- Did I follow the workflow, or skip a step? ____
- If stuck: where did I get stuck and what unblocked me? ____
- One thing to improve next time: ____
