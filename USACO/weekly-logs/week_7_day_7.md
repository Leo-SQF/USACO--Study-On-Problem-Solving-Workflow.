# Daily Experiment Log
Week 7 / Day 7
Date: ____ (YYYY‑MM‑DD)
Active modeling version: v1.0
Today's Experiment Objective: Month2 Week7 final day; functional‑graph cycle‑detection problem. Every node points to exactly one other node; components = trees feeding into cycles. Three‑state visited marker (0‑unvisited,1‑visiting‑in‑path,2‑processed). For each cycle subtract its minimal value from total sum. Continue baseline timing & bug‑classification data collection.
Pre‑set hypothesis: Functional graph structure. Each cycle must lose its minimum‑value node; all tree nodes are preserved. Use path list + three‑color visited to detect cycles, compute min value for each found cycle, accumulate subtract. Answer = sum_total − subtract. All sum variables long long. Nodes are 1‑based.
Selected problems for today:
‑ USACO 2022 USOpen Silver P1

| Problem Link | Modeling Time | Coding Time | Debug Time | Result | Bug Type |
| ---- | ---- | ---- | ---- | ---- | ---- |
| 2022 USOpen Silver P1 Functional Graph Cycle | ____ min | ____ min | ____ min | ____ | ____ |

---
## Step 1 Problem Abstraction
We have N nodes (1‑based). Each node i points to exactly one other node `a[i]`. Each node has value `v[i]`.
Graph is functional graph: each component consists of trees whose edges point toward exactly one cycle.
Rule: For every cycle in the graph we must remove exactly one node from that cycle; to maximize total sum we remove node with minimal `v` value on that cycle. All tree‑nodes (not on cycle) are kept.
Compute total sum of all node values, subtract sum of each cycle’s minimal value. Output result.

## Step 2 Algorithm Selection
Candidate1: DFS recursion for cycle detection — risk stack overflow for large N.
Candidate2: Iterative functional‑graph walk, maintain explicit path + three‑state visited marker.
Selected algorithm: iterative functional‑graph traversal with three‑color visited and path storage
Reason: Iterative avoids stack overflow; O(N) time, clean cycle extraction from path vector.
Complexity: O(N).

## Step3 Logic & Data Structure Framework
Data structure:
‑ `a[]`: each node’s outgoing target
‑ `v[]`: node value
‑ `vis[]`: three‑state: 0=unvisited, 1=visiting(in current path), 2=fully‑processed
‑ `path`: vector storing nodes in current traversal chain
‑ `sum_total`: sum of all v[i]
‑ `subtract`: sum of min(v) for every cycle found

Pseudocode:
Read N
for i from 1 to N:
    read a[i], v[i]
sum_total += v[i]

fill vis array with 0
subtract = 0

for i from 1 to N:
    if vis[i] == 0:
        path.clear()
        cur = i
        while true:
            if vis[cur] == 1:
                // found cycle: cur is inside current path
                pos = 0
                while path[pos] != cur:
                    pos += 1
                minv = INF
                for j = pos; j < path.size(); j++:
                    minv = min(minv, v[path[j]])
                subtract += minv
                break
            if vis[cur] == 2:
                break
            vis[cur] = 1
            path.push_back(cur)
            cur = a[cur]
        // mark all nodes in path as fully processed
        for x in path:
            vis[x] = 2

print(sum_total - subtract)

## Step4 Boundary & Fault Tolerance Modeling
Pre‑predicted edge cases:
1. Self‑loop cycle: one‑node cycle, subtract that node’s v value.
2. Multiple disconnected components each with own cycle.
3. Long tree chain leading into cycle.
4. 1‑based indexing for nodes.
5. Three‑state distinction critical: vis=1 (in‑current‑path) vs vis=2 (finished old component).
6. All sum / min variables must use long long.

## Step5 Verification & Reflection Modeling
Test official sample; test self‑loop single‑node cycle, multi‑component graph.
Classify bug type: ____ (A/B/C/D) — fill after real testing.
Evaluate 5‑step workflow(v1.0): Step1 understand functional‑graph structure is key; Step4 highlights three‑state visited trap.
Did the process catch errors early? ____

---
## Review after solving all problems
Compare predicted edge cases and real bugs: ____
Did the 5‑step modeling process help catch errors in advance? ____
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today): ____

## Quick Reflection
Which step was hardest today: ____

## Tomorrow's Simple Plan
Week7 weekend review. Aggregate Week7 timing and bug‑type statistics, complete Week7 weekly‑log final report.

✅ Checklist
- [x] New problem markdown added to /problems
- [x] Source code added to /solutions
- [x] This daily log saved
- [x] Git commit completed
