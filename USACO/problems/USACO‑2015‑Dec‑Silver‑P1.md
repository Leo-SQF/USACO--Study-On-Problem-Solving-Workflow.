# Problem Info
- Name: Switch on the Lights
- Source: USACO 2015 December Silver P1
- Difficulty (self‑rated): ____ (1–10)
- Date attempted: ____ (YYYY‑MM‑DD)
- Status: ____ (Not started / In progress / Solved / Stuck / Solved with help)
- Time spent: ____ min

## Step 1 — Read & Restate
We have an N×N grid of rooms (1‑based indices).
Some rooms have light switches that can turn on lights in **other remote rooms**.
We start at room `(1,1)`, its light is on initially.
We can move to an adjacent (4‑direction) room **only if that room’s light is already on**.
When we are inside a room, we may flip all its switches to turn on lights in other rooms.
A room whose light just got turned on becomes reachable (added to BFS queue) if it shares a side with any already‑visited room.

Count total number of rooms that can have their lights turned on.

| Item | Value |
|------|-------|
| Input | N M; M lines `x y a b`: switch in room (x,y) can turn on light in (a,b) |
| Output | total count of rooms we can turn lights ON |
| Constraints | N ≤ 100; grid 1‑based indexing |
| Edge cases | newly‑lit room adjacent to visited area → enqueue; newly‑lit room not adjacent → wait until later neighbor gets visited; multiple switches target same room |

## Step 2 — Model
- Model type: Modified BFS / two‑state grid traversal (separate: `light[][]` light‑on status, `vis[][]` physically‑visited/reachable status)
- Explanation:
Two independent boolean 2D arrays:
1. `light[x][y]`: whether room’s light is turned ON.
2. `vis[x][y]`: whether we have physically reached / visited this room (inside BFS queue).

BFS queue stores physically reachable rooms (`vis=true`).
When dequeuing a room `(x,y)`:
1. Fire all switches in this room: turn on light for target rooms.
   If a target room’s light was off: mark `light=true`, increment answer.
   If this newly‑lit room is adjacent to **any already visited room**, mark `vis=true` and push into queue.
2. Explore four‑way adjacent cells: if neighbor has light on and not visited, mark visited and enqueue.

> Important distinction: A room can have light ON (`light=true`) but **not yet physically reachable** (`vis=false`). It will be enqueued only when one of its four neighbours becomes visited.

## Step 3 — Algorithm
- Algorithm chosen: Custom modified BFS
- Time complexity: O(N²), N ≤ 100, small grid
- Space complexity: O(N²) for grid arrays and switch storage
- Why it fits: Standard BFS is insufficient because lighting a room and physically visiting a room are two separate events. We must handle newly‑lit rooms that become reachable later.

## Step 4 — Implementation Notes
- Data structures used:
`switches[x][y]`: vector of Point; stores all remote rooms that switches in (x,y) can activate
`light[N+1][N+1]`: is light turned on
`vis[N+1][N+1]`: physically visited / reachable
`queue<Point>` BFS queue; dx,dy four direction offset
- Pitfalls / bugs I hit: ____
  1. Grid is **1‑based**, indices run from 1 … N, not zero.
  2. Separate two states: `light` ≠ `vis`. Light‑on does NOT equal physically reachable.
  3. When turning on a new light: check if any four neighbour is already `vis=true`. If yes → enqueue it.
  4. Do not re‑process switch targets that already have light on.
  5. Starting cell `(1,1)`: set both `light[1][1]=true` and `vis[1][1]=true`. ans starts at 1.

## Step 5 — Verification
- [ ] Pass official sample input
- [ ] Test newly‑lit room not adjacent to visited area (held back, not enqueued immediately)
- [ ] Test multiple switches pointing to same target room
- [ ] Boundary check for 1‑based grid

## Reflection (fill AFTER solving)
- What was the hardest part? ____
- Did I follow the workflow, or skip a step? ____
- If stuck: where did I get stuck and what unblocked me? ____
- One thing to improve next time: ____
