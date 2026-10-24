# Problem Info
- Name: Race
- Source: USACO 2020 January Bronze P3
- Difficulty (self-rated): 6 (1–10)
- Date attempted: 2026-10-24 (YYYY-MM-DD)
- Status: solved (Not started / In progress / Solved / Stuck / Solved with help)
- Time spent: 60 min

## Step 1 — Read & Restate
> A cow runs distance K starting from speed 0. Each second it may increase speed by at most 1 and can never exceed the per-query cap X. It must finish the last second at speed 1. For each X, find the minimum time to cover at least K.

| Item | Value |
|------|-------|
| Input | K, N; then N values of X |
| Output | one minimum time per X |
| Constraint on N | X <= 2e5, K large (use long long) |
| Edge cases | X=1; minimal distance; last-second speed=1 rule |

## Step 2 — Model
- Model type: `Binary search (monotonic) + math (accelerate/decelerate distance)`
- Explanation: reachable distance increases with time → binary search time; within a fixed time, binary search peak speed to maximize distance.

## Step 3 — Algorithm
- Algorithm chosen: binary search on time (solve) + binary search on peak speed (calc)
- Time complexity: O(N * log^2(2e5))
- Space complexity: O(1)
- Why it fits: monotonicity makes binary search valid; math formula computes max distance in O(log 2e5).

## Step 4 — Implementation Notes
- Data structures used: none special, long long arithmetic
- Pitfalls / bugs I hit: ____

## Step 5 — Verification
- [ ] Passes provided samples
- [ ] Passes my edge cases (X=1, small K, max X)
- [ ] Within time limit
- [ ] Brute-force cross-check (if applicable)

## Reflection (fill AFTER solving)
- What was the hardest part? ____
- Did I follow the workflow, or skip a step? ____
- If stuck: where did I get stuck and what unblocked me? ____
- One thing to improve next time: ____
