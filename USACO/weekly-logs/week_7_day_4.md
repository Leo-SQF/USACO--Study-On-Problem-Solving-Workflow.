# Daily Experiment Log
Week 7 / Day 4
Date: ____ (YYYY‑MM‑DD)
Active modeling version: v1.0
Today's Experiment Objective: Month2 Week7 modified‑BFS problem. Distinguish “light is on” vs “physically visited”. Handle rooms whose lights get turned‑on but are not immediately reachable. Continue baseline timing & bug‑classification data collection.
Pre‑set hypothesis: Two separate boolean grids: `light` for light status and `vis` for physical reachability. BFS queue holds physically‑visited rooms. When firing switches, newly‑lit room joins queue only if adjacent to already‑visited cell. Grid uses 1‑based indexing. Count total rooms with light turned‑on as answer.
Selected problems for today:
‑ USACO 2015 December Silver P1 — Switch on the Lights

| Problem Link | Modeling Time | Coding Time | Debug Time | Result | Bug Type |
| ---- | ---- | ---- | ---- | ---- | ---- |
| Switch on the Lights 2015 Dec Silver P1 | ____ min | ____ min | ____ min | ____ | ____ |

---
## Step 1 Problem Abstraction
N×N grid of rooms, 1‑based.
M switches: switch inside room (x,y) can turn on light in remote room (a,b).
Start at room (1,1), its light is on and we are physically inside it.
Movement rule: you can walk into adjacent room **only if that room’s light is already on**.
While you are present inside a room you may trigger all its switches to turn‑on lights of other rooms.
A room whose light is just turned‑on may or may not be reachable right away; it becomes traversable only when one of its four neighbours is physically visited.
Output total number of rooms for which we can turn the light ON.

## Step 2 Algorithm Selection
Candidate1: Standard simple BFS (only visited tracking) — rejected. Cannot model “light‑on but not reachable” state.
Candidate2: Modified BFS maintaining two separate status grids: light‑on and physically‑visited.
Selected algorithm: modified BFS
Reason: Separates lighting logic and movement logic. When new light turns on, check adjacency to visited cells to decide enqueue.
Complexity: O(N²).

## Step3 Logic & Data Structure Framework
Data structure:
‑ `struct Point {x,y}`
‑ `switches[x][y]`: list of remote points activated by switches in room (x,y)
‑ `light[N+1][N+1]`: light is turned on
‑ `vis[N+1][N+1]`: physically visited / reachable
‑ 4‑direction dx dy offset array
‑ queue for BFS, ans counter

Pseudocode:
Read N, M
Initialize switches structure
for M times:
    read x y a b
    switches[x][y].push_back({a,b})

Initialize light all false, vis all false
light[1][1] = true
vis[1][1] = true
q.push({1,1})
ans = 1

while q not empty:
    cur = q.front(); q.pop()
    x = cur.x, y = cur.y

    // fire all switches in current room
    for each p in switches[x][y]:
        a = p.x; b = p.y
        if not light[a][b]:
            light[a][b] = true
            ans += 1
            // check if newly lit room is next to any visited room
            ok = false
            for four directions d:
                nx = a+dx[d], ny = b+dy[d]
                if 1<=nx<=N and 1<=ny<=N and vis[nx][ny]:
                    ok = true
                    break
            if ok and not vis[a][b]:
                vis[a][b] = true
                q.push({a,b})

    // four‑way movement to adjacent rooms
    for four directions d:
        nx = x+dx[d], ny = y+dy[d]
        if in‑bounds and light[nx][ny] and not vis[nx][ny]:
            vis[nx][ny] = true
            q.push({nx, ny})

print(ans)

## Step4 Boundary & Fault Tolerance Modeling
Pre‑predicted edge cases:
1. 1‑based grid boundaries; do not access index zero.
2. New‑lit room has no visited neighbour: light is on but NOT enqueued; waits for later.
3. Multiple switches target same room: only process first time light turns from off → on.
4. Starting cell (1,1): must set both light and vis to true, ans = 1 initially.
5. Important conceptual trap: confusing `light` and `vis`; light‑on is not equivalent to being able to walk in.

## Step5 Verification & Reflection Modeling
Test official sample; test newly‑lit non‑adjacent room scenario.
Classify bug type: ____ (A/B/C/D) — fill after real testing.
Evaluate 5‑step workflow(v1.0): Step1 abstraction critical to separate light‑state vs visited‑state. Step4 points out major conceptual trap.
Did the process catch errors early? ____

---
## Review after solving all problems
Compare predicted edge cases and real bugs: ____
Did the 5‑step modeling process help catch errors in advance? ____
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today): ____

## Quick Reflection
Which step was hardest today: ____

## Tomorrow's Simple Plan
Week7 keep practicing Silver‑level problems; keep v1.0 workflow and timing‑bug logging.

✅ Checklist
- [x] New problem markdown added to /problems
- [x] Source code added to /solutions
- [x] This daily log saved
- [x] Git commit completed
