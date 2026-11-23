# Daily Experiment Log
Week 7 / Day 5
Date: ____ (YYYY‑MM‑DD)
Active modeling version: v1.0
Today's Experiment Objective: Month2 Week7 practice; classic reverse‑simulation DSU problem. Convert node‑deletion sequence into reverse node‑addition sequence, use Union‑Find to track connected‑component count. Collect reversed answers then reverse for final output. Continue baseline timing & bug‑classification data collection.
Pre‑set hypothesis: DSU does not support deletion. Simulate backwards: start with all nodes inactive, add nodes in reverse deletion order. Maintain active‑flag and component‑count `comp`. After each addition, if comp ==1 record YES else NO; reverse answer array to match original deletion timeline.
Selected problems for today:
‑ USACO 2016 USOpen Silver P3 — Closing the Farm

| Problem Link | Modeling Time | Coding Time | Debug Time | Result | Bug Type |
| ---- | ---- | ---- | ---- | ---- | ---- |
| Closing the Farm 2016 USOpen Silver P3 | ____ min | ____ min | ____ min | ____ | ____ |

---
## Step 1 Problem Abstraction
Given undirected graph N nodes, M edges.
Nodes get removed one‑by‑one following given deletion‑order.
After each deletion operation: check whether all **still‑existing(active)** nodes form exactly one connected component. Output YES or NO after each step.

Since DSU cannot delete nodes efficiently, run simulation backwards:
- Start with zero active nodes.
- Add nodes in reverse‑deletion order.
- Track number of connected components `comp`.
- Record YES/NO for each backward step, then reverse answer list to get answers for original deletion process.

## Step 2 Algorithm Selection
Candidate1: After each deletion run DFS/BFS to count components — O(N(N+M)), works for small N but not elegant.
Candidate2: Reverse simulation + DSU(Union‑Find with path compression).
Selected algorithm: reverse‑simulation + DSU
Reason: Transform deletions into insertions, DSU is optimized for union operations. Near‑linear complexity.
Complexity: O((N+M) α(N)).

## Step3 Logic & Data Structure Framework
Data structure:
‑ adjacency list `adj`: store undirected graph edges
‑ DSU `parent[]`: 1‑based nodes
‑ `order[]`: given deletion order
‑ `active[]`: mark whether node has been added in reversed simulation
‑ `comp`: connected‑component count of active nodes
‑ `rev_ans`: collect answers from reversed‑simulation steps

Pseudocode:
Read N, M
build adjacency list for graph
read deletion‑order array order[0…N‑1]
// DSU init
for i from 1 to N:
    parent[i] = i
fill active[] = false
comp = 0
rev_ans empty

for i from N‑1 down to 0:
    u = order[i]
    active[u] = true
    comp += 1
    for each neighbor v in adj[u]:
        if active[v]:
            if find(u) != find(v):
                unite(u, v)
                comp -= 1
    if comp == 1:
        rev_ans.push_back("YES")
    else:
        rev_ans.push_back("NO")

reverse rev_ans
for each s in rev_ans:
    print(s)

## Step4 Boundary & Fault Tolerance Modeling
Pre‑predicted edge cases:
1. Last step of original process: only one node left → comp=1 → YES.
2. Adding one node connects multiple separate components; comp decreases multiple times.
3. Only perform union when neighbor v is active.
4. comp increments on node activation; only decrement on successful union(different roots).
5. Must reverse rev_ans before printing output, otherwise answers are backwards.
6. Nodes are 1‑based for DSU and adjacency list.

## Step5 Verification & Reflection Modeling
Test official sample; test single‑node remaining case.
Classify bug type: ____ (A/B/C/D) — fill after real testing.
Evaluate 5‑step workflow(v1.0): Step1 / Step2 key insight is reversing deletion into addition for DSU. Step4 highlights answer‑reversal trap.
Did the process catch errors early? ____

---
## Review after solving all problems
Compare predicted edge cases and real bugs: ____
Did the 5‑step modeling process help catch errors in advance? ____
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today): ____

## Quick Reflection
Which step was hardest today: ____

## Tomorrow's Simple Plan
Week7 Silver practice continues; keep v1.0 workflow and timing‑bug logging.

✅ Checklist
- [x] New problem markdown added to /problems
- [x] Source code added to /solutions
- [x] This daily log saved
- [x] Git commit completed
