# Daily Experiment Log
Week 8 / Day 1
Date: ____ (YYYY‑MM‑DD)
Active modeling version: v1.0
Today's Experiment Objective: Month2 Week8 Day1; functional‑graph cycle‑length summation problem. Re‑use three‑color iterative cycle‑detection pattern seen in week7‑day7. Sum length of every cycle in functional graph. Continue baseline timing & bug‑classification data collection.
Pre‑set hypothesis: Functional‑graph, each node one outgoing edge. Use 0‑unvisited /1‑visiting‑in‑path /2‑processed visited states. When hitting a node marked vis=1 compute cycle length `path.size()‑pos` and add to answer. Nodes 1‑based. Watch for syntax typo in if‑condition.
Selected problems for today:
‑ USACO 2017 December Silver P3

| Problem Link | Modeling Time | Coding Time | Debug Time | Result | Bug Type |
| ---- | ---- | ---- | ---- | ---- | ---- |
| 2017 Dec Silver P3 Functional‑Graph Sum Cycle Length | ____ min | ____ min | ____ min | ____ | ____ |

---
## Step 1 Problem Abstraction
N‑node functional graph. Every node i points to exactly one other node `a[i]`.
Each component consists of in‑trees directed toward one cycle.
Compute sum of lengths of **all cycles** present in the graph.

## Step 2 Algorithm Selection
Candidate1: Recursive DFS cycle detection — risk stack‑overflow for large N.
Candidate2: Iterative walk with three‑state visited + explicit path storage.
Selected algorithm: iterative functional‑graph traversal
Reason: O(N), no recursion depth risk; cleanly extract cycle segment from path vector.
Complexity: O(N).

## Step3 Logic & Data Structure Framework
Data structure:
‑ `a[]`: each node’s outgoing target (1‑based)
‑ `vis[]`: three‑state: 0‑unvisited,1‑visiting‑in‑path,2‑processed
‑ `path`: vector storing nodes along current traversal chain
‑ `ans`: total sum of all cycle lengths

Pseudocode:
Read N
for i from 1 to N:
    read a[i]
fill vis array with 0
ans = 0

for i from 1 to N:
    if vis[i] == 0:
        path.clear()
        cur = i
        while true:
            if vis[cur] == 1:
                // found cycle in current path
                pos = 0
                while path[pos] != cur:
                    pos +=1
                cycle_len = path.size() - pos
                ans += cycle_len
                break
            if vis[cur] == 2:
                break
            vis[cur] = 1
            path.push_back(cur)
            cur = a[cur]
        // mark all nodes in path as fully processed
        for x in path:
            vis[x] = 2

print(ans)

## Step4 Boundary & Fault Tolerance Modeling
Pre‑predicted edge cases:
1. Self‑loop single‑node cycle: cycle length = 1.
2. Multiple disconnected components each containing their own cycle.
3. Long tree prefix before entering cycle.
4. 1‑based node indexing.
5. Common syntax bug: `if(vis[i==0])` wrong; correct `if (vis[i]==0)`.
6. Must set every element in path to vis=2 after component processing.

## Step5 Verification & Reflection Modeling
Test official sample; test self‑loop case; multi‑component graph.
Classify bug type: ____ (A/B/C/D) — fill after real testing.
Evaluate 5‑step workflow(v1.0): Recognize functional‑graph pattern from week7‑day7; main traps are syntax typo and three‑state visited misuse.
Did the process catch errors early? ____

---
## Review after solving all problems
Compare predicted edge cases and real bugs: ____
Did the 5‑step modeling process help catch errors in advance? ____
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today): ____

## Quick Reflection
Which step was hardest today: ____

## Tomorrow's Simple Plan
Week8 continue DFS / backtracking & prefix‑difference Silver‑level exercises; keep v1.0 workflow and timing‑bug logging.

✅ Checklist
- [x] New problem markdown added to /problems
- [x] Source code added to /solutions
- [x] This daily log saved
- [x] Git commit completed
