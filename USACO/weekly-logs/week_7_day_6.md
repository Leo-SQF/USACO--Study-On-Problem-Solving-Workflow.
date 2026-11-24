# Daily Experiment Log
Week 7 / Day 6
Date: ____ (YYYY‑MM‑DD)
Active modeling version: v1.0
Today's Experiment Objective: Month2 Week7 simulation‑queue problem. Simulate comfortable‑cow chain spawning reaction. Use offset shift for negative grid coordinates. Maintain work‑queue to re‑check cells that could become comfortable after any cow addition. Continue baseline timing & bug‑classification data collection.
Pre‑set hypothesis: When a cow gets exactly three occupied neighbours, force‑spawn cow in the one empty adjacent cell; spawning can trigger further spawns. After each manual placement output total cows minus input‑cow‑count i. Shift coordinates +2000 for negative values. Enqueue neighbours of newly‑spawned cow for re‑evaluation.
Selected problems for today:
‑ USACO 2021 February Silver P1 — Comfortable Cows

| Problem Link | Modeling Time | Coding Time | Debug Time | Result | Bug Type |
| ---- | ---- | ---- | ---- | ---- | ---- |
| Comfortable Cows 2021 Feb Silver P1 | ____ min | ____ min | ____ min | ____ | ____ |

---
## Step 1 Problem Abstraction
We manually place N cows one‑by‑one onto infinite grid.
Definition: A cow is comfortable when exactly three of its four orthogonal neighbours are occupied.
Rule: Whenever any cow becomes comfortable, we must immediately add a new cow into its only empty adjacent cell. This can create chain‑reaction, more cows may become comfortable.
If manual input tries to place cow onto already‑filled cell: nothing changes.
After processing i‑th manual cow, output how many automatically‑spawned extra cows exist (total cows − i).

## Step 2 Algorithm Selection
Candidate1: Naive rescan entire grid after every placement — rejected, too slow.
Candidate2: Queue‑driven simulation: only re‑check cells which could possibly turn comfortable after a cow is added.
Selected algorithm: queue‑based event simulation
Reason: Only cells adjacent to newly‑added cow can change neighbour‑count; we enqueue them for re‑check, avoid full‑grid scan.
Complexity: bounded by grid MAX=4005.

## Step3 Logic & Data Structure Framework
Data structure:
‑ `has[MAX][MAX]`: boolean grid whether cell contains cow
‑ SHIFT = 2000 offset for negative coordinates
‑ queue<pair<int,int>> work queue for cells to check
‑ `total`: total cows (manual + auto spawned)
‑ helper `count_nei(x,y)`: count occupied four‑direction neighbours
‑ helper `find_empty(x,y)`: return the one empty neighbour coordinate for comfortable cow

Pseudocode:
SHIFT = 2000
MAX = 4005
Initialize has all false
Read N
queue empty
total = 0
for i from 1 to N:
    read x, y
    x += SHIFT
    y += SHIFT
    if has[x][y]:
        print(total - i)
        continue
    has[x][y] = true
    total += 1
    q.push({x,y})

    while q not empty:
        cx, cy = q.front(); q.pop()
        c = count_nei(cx, cy)
        if c != 3:
            continue
        // comfortable, must spawn new cow
        nx, ny = find_empty(cx, cy)
        if has[nx][ny]:
            continue
        has[nx][ny] = true
        total +=1
        q.push({nx, ny})
        // enqueue four neighbours of newly spawned cow for re‑check
        for four directions d:
            nnx = nx+dx[d], nny = ny+dy[d]
            if has[nnx][nny]:
                q.push({nnx, nny})
    print(total - i)

## Step4 Boundary & Fault Tolerance Modeling
Pre‑predicted edge cases:
1. Manual input cow lands on already‑occupied cell: skip adding cow and spawn logic.
2. Negative input coordinates: apply SHIFT offset before array indexing.
3. Chain‑reaction multi‑level spawn triggered by auto‑added cows.
4. After spawning new cow: enqueue its four occupied neighbours, they may now have neighbour‑count changed and become comfortable.
5. Before spawn: check target cell is empty to avoid duplicate cow creation.
6. Output formula `total‑i`: total cows minus i manually‑placed cows.

## Step5 Verification & Reflection Modeling
Test official sample; test duplicate input position; test multi‑step chain spawn.
Classify bug type: ____ (A/B/C/D) — fill after real testing.
Evaluate 5‑step workflow(v1.0): Step1 understanding chain‑reaction spawn rule is key; Step4 points out coordinate‑shift and enqueue‑neighbour traps.
Did the process catch errors early? ____

---
## Review after solving all problems
Compare predicted edge cases and real bugs: ____
Did the 5‑step modeling process help catch errors in advance? ____
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today): ____

## Quick Reflection
Which step was hardest today: ____

## Tomorrow's Simple Plan
Week7 continue Silver‑level practice; keep v1.0 workflow and timing‑bug logging.

✅ Checklist
- [x] New problem markdown added to /problems
- [x] Source code added to /solutions
- [x] This daily log saved
- [x] Git commit completed
