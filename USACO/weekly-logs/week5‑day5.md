# Daily Experiment Log
Week 5 / Day 5
Date: ____ (YYYY‑MM‑DD)
Active modeling version: v1.0
Today's Experiment Objective: Month2 Week5 practice; nearest‑neighbor directed‑graph construction with special two‑node‑cycle correction. Use v1.0 workflow. Practice building adjacency/jump table, compute in‑degree, handle special cycle edge‑case correction logic. Continue collecting timing and bug‑classification experimental data.
Pre‑set hypothesis: After sorting positions each stone jumps to nearest neighbor, tie break jump left. Build directed jump array `to[]`. Count indeg=0 nodes as base answer. Two‑node mutual cycle will have no source nodes so need extra manual correction to add one count.
Selected problems for today:
- USACO 2018 February Bronze P2

| Problem Link | Modeling Time | Coding Time | Debug Time | Result | Bug Type |
| ---- | ---- | ---- | ---- | ---- | ---- |
| 2018 Feb Bronze P2 Snow Boots‑Bronze | ____ min | ____ min | ____ min | ____ | ____ |

---
## Step 1 Problem Abstraction
Given n stones on 1‑D line with arbitrary input positions.
Sort positions. Each stone jumps to its geometric nearest neighbor.
- First stone can only jump rightwards.
- Last stone can only jump leftwards.
- Middle stone: compare distance to left and right neighbor; if equal pick left.

Each jump creates directed edge i → to[i].
We count source nodes (nodes with in‑degree zero).
Special rule: when two adjacent nodes point mutually to each other forming 2‑node cycle and both indeg equal 1, add additional 1 to total answer.
Output final answer.

## Step 2 Algorithm Selection
Candidate1: Simulate jumping for every node to trace components — rejected, over‑complicated for problem requirement.
Candidate2: Sort positions; construct jump‑target array to[]; compute in‑degree array; count sources; add manual correction for two‑node cycles.
Selected algorithm: sort + build directed jump graph + in‑degree counting + special correction
Reason: n small, explicit graph construction is straightforward. Two‑node cycle is a special case which is not captured by counting indeg=0.
Complexity: O(n log n), sorting dominates runtime.

## Step3 Logic & Data Structure Framework
Data structure:
- `vector<int> x` stone positions
- `vector<int> to`: to[i] is jump‑target index for node i
- `vector<int> indeg`: in‑degree counter for each node

Pseudocode:
Read n
Read x array
sort(x.begin(), x.end())
if n == 1:
    print(1)
    exit
Initialize vector to(n)
to[0] = 1
to[n‑1] = n‑2
for i from 1 to n‑2:
    d_left = x[i] - x[i‑1]
    d_right = x[i+1] - x[i]
    if d_left >= d_right:
        to[i] = i‑1
    else:
        to[i] = i+1

Initialize indeg array all zero
for i from 0 to n‑1:
    indeg[ to[i] ] += 1

ans = 0
for i from 0 to n‑1:
    if indeg[i] == 0:
        ans +=1

# two‑node mutual cycle correction
for i from 0 to n‑2:
    if to[i]==i+1 && to[i+1]==i:
        if indeg[i]==1 && indeg[i+1]==1:
            ans += 1

print ans

## Step4 Boundary & Fault Tolerance Modeling
Pre‑predicted edge cases:
1. n = 1, direct output 1, early exit.
2. Two‑stone input forming mutual jump cycle, both indeg=1, no indeg‑zero nodes, correction adds one.
3. Middle node left‑right distance equal: must jump to left neighbor (easy misread rule).
4. First node can only jump right, last node can only jump left.
5. Trap: forgetting the two‑node‑cycle correction term will give wrong answer for cycle case.

## Step5 Verification & Reflection Modeling
Test official sample and edge‑case groups: n=1, two‑stone cycle, equal‑distance middle node.
Classify bug type: ____ (A/B/C/D) — fill after real testing.
Evaluate 5‑step workflow(v1.0): Step1 abstraction critical to capture tie‑break rule and special two‑node‑cycle correction requirement; Step4 points out easy‑to‑miss correction logic trap.
Did the process catch errors early? ____

---
## Review after solving all problems
Compare predicted edge cases and real bugs: ____
Did the 5‑step modeling process help catch errors in advance? ____
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today): ____

## Quick Reflection
Which step was hardest today: ____

## Tomorrow's Simple Plan
Week5 continue; start simple DFS / recursion practice; keep methodology v1.0; record timing and bug metrics.

✅ Checklist
- [x] New problem markdown added to /problems
- [x] Source code added to /solutions
- [x] This daily log saved
- [x] Git commit completed
