# Daily Experiment Log
Week 4 / Day 7
Date: ____ (YYYY‑MM‑DD)
Active modeling version: v0.0
Today's Experiment Objective: Week4 final mixed Bronze practice; greedy graph coloring with adjacency‑list graph representation. Continue baseline data collection for Month‑1 summary. Finish Week4 problem set, ready to aggregate Week1‑Week4 full experimental data.
Pre‑set hypothesis: Process nodes sequentially; pick the smallest available color from {1,2,3,4} that is not used by already‑colored adjacent vertices. Problem guarantees valid coloring exists, so greedy will find an answer without backtracking.
Selected problems for today:
- USACO 2019 February Bronze P2 — Graph 4‑color assignment

| Problem Link | Modeling Time | Coding Time | Debug Time | Result | Bug Type |
| ---- | ---- | ---- | ---- | ---- | ---- |
| Graph Coloring 2019 Feb Bronze P2 | ____ min | ____ min | ____ min | ____ | ____ |

---
## Step 1 Problem Abstraction
Given an undirected graph with N vertices and M edges. Assign each vertex a color from 1‑4. Adjacent vertices connected by an edge cannot share same color. Any valid assignment is acceptable; output color sequence for vertex 1 to N.
Constraints N ≤100, input graph always can be colored within four colors.

## Step 2 Algorithm Selection
Candidate1: Backtracking search for all color combinations — rejected, unnecessary overhead for small problem, greedy is sufficient.
Candidate2: Greedy sequential coloring: iterate nodes 1…N, try color 1‑4, pick first color unused by already‑colored neighbors.
Selected algorithm: greedy graph coloring using adjacency list
Reason: Problem only requires one valid coloring, not minimal colors. Input guarantee ensures we always find color among {1,2,3,4}.
Complexity: O(N * degree).

## Step3 Logic & Data Structure Framework
Data structure:
- `vector<int> g[105]`: adjacency list for undirected graph
- `col[105]`: store color number for each node

Pseudocode:
Read N, M
Initialize adjacency list g empty
For each of M edges:
    read a,b
    add b to g[a], add a to g[b]
Initialize col array to zero
For i from 1 to N:
    for c from 1 to 4:
        ok = true
        for each neighbor v in g[i]:
            if col[v] == c:
                ok = false
                break
        if ok:
            col[i] = c
            break
Print col[1], col[2] ... col[N]

## Step4 Boundary & Fault Tolerance Modeling
Pre‑predicted edge cases:
1. Isolated node with zero adjacent edges: any color 1‑4 works.
2. Node with many already‑colored neighbors, must skip colors taken by neighbors.
3. Nodes start index at 1 (common off‑by‑one bug if using 0‑based).
4. Undirected graph: must add both directions for each input edge.

## Step5 Verification & Reflection Modeling
Test official sample and edge‑case test groups.
Classify bug type: ____ (A/B/C/D) — fill after real testing.
Evaluate 5‑step workflow: Step1 correctly model undirected graph; Step4 helps catch 1‑based index trap.
Did the process catch errors early? ____

---
## Review after solving all problems
Compare predicted edge cases and real bugs: ____
Did the 5‑step modeling process help catch errors in advance? ____
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today): ____

## Quick Reflection
Which step was hardest today: ____

## Tomorrow's Simple Plan
Week4 weekend review: aggregate all Week1‑Week4 experiment data, bug‑type statistics, solve‑rate and timing metrics. Complete Week4 weekly‑log report, prepare revision points for Methodology v1.0.

✅ Checklist
- [x] New problem markdown added to /problems
- [x] Source code added to /solutions
- [x] This daily log saved
- [x] Git commit completed
