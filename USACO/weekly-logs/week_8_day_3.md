# Daily Experiment Log
Week 8 / Day 3
Date: ____ (YYYY‑MM‑DD)
Active modeling version: v1.0
Today's Experiment Objective: Month2 Week8 Day3; modified BFS grid problem. Strictly separate `light`(light‑on) and `vis`(physically‑visited). Newly lit room only joins queue when adjacent to already‑visited cell. Continue baseline timing & bug‑classification data collection.
Pre‑set hypothesis: Two independent boolean 2D arrays. BFS queue holds physically‑reachable cells. When executing switches, newly lit room is enqueued only if it has visited neighbour. Grid is 1‑based. Answer counts total rooms whose lights are turned‑on.
Selected problems for today:
‑ USACO 2015 December Silver P1 — Switch on the Lights

| Problem Link | Modeling Time | Coding Time | Debug Time | Result | Bug Type |
| ---- | ---- | ---- | ---- | ---- | ---- |
| Switch on the Lights 2015 Dec Silver P1 | ____ min | ____ min | ____ min | ____ | ____ |

---
## Step 1 Problem Abstraction
N×N 1‑based grid of rooms.
M switches: switch inside room `(x,y)` can turn‑on light in remote room `(a,b)`.
Start at `(1,1)`: light is on and we are physically inside this room.
Movement rule: you can only walk to adjacent room if its light is already ON.
While staying inside a room you can trigger all its switches.
A newly‑lit room can only be physically entered when one of its four neighbours has already been visited.
Output total number of rooms we can turn lights ON.

## Step 2 Algorithm Selection
Candidate1: Ordinary standard BFS with only visited array — rejected, cannot model “light‑on but unreachable” state.
Candidate2: Modified BFS maintaining two separate boolean grids `light` and `vis`.
Selected algorithm: modified BFS
Reason: Separates lighting logic and movement logic correctly.
Complexity: O(N²).

## Step3 Logic & Data Structure Framework
Data structure:
‑ `sw[x][y]`: list of remote coordinates activated by switches in `(x,y)`
‑ `light[N+1][N+1]`: whether room light is on
‑ `vis[N+1][N+1]`: whether physically visited
‑ four‑direction dx, dy offset
‑ queue for BFS; ans counter

Pseudocode:
Read N, M
Initialize sw structure
for M times:
    read x y a b
    sw[x][y].emplace_back(a,b)

Initialize light all false, vis all false
light[1][1] = true
vis[1][1] = true
q.emplace(1,1)
ans = 1

while q not empty:
    auto [x,y] = q.front(); q.pop()

    // activate all switches in current room
    for each (a,b) in sw[x][y]:
        if not light[a][b]:
            light[a][b] = true
            ans += 1
            // check whether new‑lit room is adjacent to visited cell
            reachable = false
            for four directions d:
                nx = a+dx[d], ny = b+dy[d]
                if in‑bounds and vis[nx][ny]:
                    reachable = true
                    break
            if reachable and not vis[a][b]:
                vis[a][b] = true
                q.emplace(a,b)

    // four‑direction normal movement
    for four directions d:
        nx = x+dx[d], ny = y+dy[d]
        if in‑bounds and light[nx][ny] and not vis[nx][ny]:
            vis[nx][ny] = true
            q.emplace(nx, ny)

print(ans)

## Step4 Boundary & Fault Tolerance Modeling
Pre‑predicted edge cases:
1. 1‑based grid, index range from 1 to N.
2. New‑lit room without visited neighbour: light on but not enqueued, wait for later.
3. Multiple switches pointing to same target room: only process first‑time light‑on event.
4. Starting cell `(1,1)`: must set both light and vis to true, ans initial = 1.
5. Major conceptual trap: confusing `light` and `vis`.

## Step5 Verification & Reflection Modeling
Test official sample; test newly‑lit non‑adjacent room scenario.
Classify bug type: ____ (A/B/C/D) — fill after real testing.
Evaluate 5‑step workflow(v1.0): Step1 abstraction is critical to separate two states. Step4 highlights conceptual trap.
Did the process catch errors early? ____

---
## Review after solving all problems
Compare predicted edge cases and real bugs: ____
Did the 5‑step modeling process help catch errors in advance? ____
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today): ____

## Quick Reflection
Which step was hardest today: ____

## Tomorrow's Simple Plan
Week8 continue DP / simulation / graph Silver‑level exercises; keep v1.0 workflow and timing‑bug logging.

✅ Checklist
- [x] New problem markdown added to /problems
- [x] Source code added to /solutions
- [x] This daily log saved
- [x] Git commit completed
