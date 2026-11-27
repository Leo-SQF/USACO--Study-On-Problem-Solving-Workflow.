# Daily Experiment Log
Week 8 / Day 2
Date: ____ (YYYY‑MM‑DD)
Active modeling version: v1.0
Today's Experiment Objective: Month2 Week8 Day2; 2‑dimensional DP problem. State dp[i][j] = minimal distance arriving at point i having skipped j points. Enumerate previous landing point t, compute skipped intermediate points `i‑t‑1`. Answer is min over dp[N][0…K]. Continue baseline timing & bug‑classification data collection.
Pre‑set hypothesis: DP state `dp[i][j]`. Base dp[1][0]=0. Transition over previous landing point t, skip = i‑t‑1. Can use up‑to‑K skips so take min across j=0..K for final answer. Points are 1‑based. Initialize dp with INF.
Selected problems for today:
‑ USACO 2014 December Silver P2 — Marathon

| Problem Link | Modeling Time | Coding Time | Debug Time | Result | Bug Type |
| ---- | ---- | ---- | ---- | ---- | ---- |
| Marathon 2014 Dec Silver P2 | ____ min | ____ min | ____ min | ____ | ____ |

---
## Step 1 Problem Abstraction
N checkpoints in fixed order. Start at point 1, must finish at point N.
We may skip **at most K intermediate check‑points**.
Travel cost between two points is Manhattan distance.
Goal: find minimal total travel distance.

DP state:
`dp[i][j]` = minimal total distance to reach checkpoint i after skipping exactly j points.
From previous landing point t (t < i):
- Points t+1 … i‑1 get skipped: skip = i‑t‑1
- If j >= skip: `dp[i][j] = min(dp[i][j], dp[t][j‑skip] + dist(t,i))`
Answer = `min(dp[N][0 ... K])`

## Step 2 Algorithm Selection
Candidate1: Brute‑force enumerate subsets of skipped points — exponential, impossible.
Candidate2: Two‑dimensional dynamic programming dp[i][j].
Selected algorithm: 2‑D DP triple‑loop
Reason: N ≤ 500, dp table fits memory; straightforward state transition.
Complexity: O(N²·K).

## Step3 Logic & Data Structure Framework
Data structure:
‑ `p[]`: array of Point {x,y}, 1‑based
‑ `dp[i][j]`: minimal distance arriving i with j skips
‑ helper `dist(a,b)` compute Manhattan distance
‑ INF constant for unreachable states

Pseudocode:
Read N, K
for i from 1 to N:
    read p[i].x, p[i].y

fill dp table with INF
dp[1][0] = 0

for i from 2 to N:
    for j from 0 to K:
        for t from 1 to i‑1:
            skip = i - t - 1
            if j >= skip:
                dp[i][j] = min(dp[i][j], dp[t][j‑skip] + dist(t,i))

ans = INF
for j from 0 to K:
    ans = min(ans, dp[N][j])
print(ans)

## Step4 Boundary & Fault Tolerance Modeling
Pre‑predicted edge cases:
1. K=0: cannot skip any point, follow full original path.
2. Jump directly from point 1 to point N, skip all intermediate.
3. Use fewer than K allowed skips; answer must sample j=0…K not only j=K.
4. Initialize dp to INF; only dp[1][0]=0.
5. 1‑based point indexing.
6. Manhattan distance formula using absolute values.

## Step5 Verification & Reflection Modeling
Test official sample; test K=0 baseline; test big skip 1→N.
Classify bug type: ____ (A/B/C/D) — fill after real testing.
Evaluate 5‑step workflow(v1.0): Step1 state‑definition is critical; easy to misunderstand “skip j points” meaning. Step4 highlights answer‑range trap (0‑K not only K).
Did the process catch errors early? ____

---
## Review after solving all problems
Compare predicted edge cases and real bugs: ____
Did the 5‑step modeling process help catch errors in advance? ____
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today): ____

## Quick Reflection
Which step was hardest today: ____

## Tomorrow's Simple Plan
Week8 continue DP / DFS‑backtracking Silver‑level exercises; keep v1.0 workflow and timing‑bug logging.

✅ Checklist
- [x] New problem markdown added to /problems
- [x] Source code added to /solutions
- [x] This daily log saved
- [x] Git commit completed
