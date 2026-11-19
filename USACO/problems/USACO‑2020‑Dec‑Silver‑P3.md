# Problem Info
- Name: Stuck in a Rut
- Source: USACO 2020 December Silver P3
- Difficulty (self‑rated): ____ (1–10)
- Date attempted: ____ (YYYY‑MM‑DD)
- Status: ____ (Not started / In progress / Solved / Stuck / Solved with help)
- Time spent: ____ min

## Step 1 — Read & Restate
N cows on infinite 2‑D plane. Each cow points either East `E` (increase x) or North `N` (increase y). All cows move at same speed.
Two cows can only interfere if one goes East and the other goes North.
Compute potential intersection point `(ix, iy)`.
- `E‑cow` reaches intersection at time `te = ix − E.x`
- `N‑cow` reaches intersection at time `tn = iy − N.y`

Rules:
1. If `te < tn`: North cow would get blocked at time `tn` by the East cow (East cow arrives earlier).
2. If `tn < te`: East cow would get blocked at time `te` by the North cow (North cow arrives earlier).
3. Equal arrival time: they pass through point simultaneously, no blocking.

Collect all possible blocking events, sort events by time `t`.
Process events in chronological order. If either blocker or victim is already stopped, skip this event. Otherwise mark victim as stopped and record blocker‑→victim directed edge.

After building directed graph: for each cow i, count total number of cows that i is responsible for stopping (reachable nodes from i in graph). Output count for each cow.

| Item | Value |
|------|-------|
| Input | N; each line direction char, x, y coordinate |
| Output | For each cow: how many other cows it causes to stop |
| Constraints | N ≤ 50; coordinates fit long long |
| Edge cases | Both cows already stopped before event; equal arrival time (no block); intersection lies behind one cow’s starting position; chain‑reaction blocking |

## Step 2 — Model
- Model type: Event‑generation + chronological event simulation + BFS reachability counting
- Explanation:
1. Enumerate every unordered pair of cows. Only consider pairs with one E, one N.
2. Calculate theoretical intersection point. Skip if intersection is behind either cow.
3. Compute arrival times te, tn. Generate an Event `(block_time, blocker_id, victim_id)` if one can block another.
4. Sort all events by event time ascending.
5. Process events time‑order: if both blocker and victim are still moving, victim becomes stopped; add directed edge blocker → victim.
6. Build directed graph `g`. For each cow run BFS to count reachable victims (total cows this cow stopped).

## Step 3 — Algorithm
- Algorithm chosen: Pair‑wise event generation; sort events; time‑ordered simulation; BFS reachability count
- Time complexity: O(N² + N·(N+E)). N ≤50 so completely feasible.
- Space complexity: O(N²) for events and adjacency graph
- Why it fits: N small (max 50). Brute‑force all pairs is acceptable. BFS per cow for reachable count.

## Step 4 — Implementation Notes
- Data structures used: `struct Cow {dir, x, y, id}`; `struct Event {t, blocker, victim}` with operator< for sorting; `stopped[]` boolean array; adjacency list `g[]`; BFS queue + visited array.
- Pitfalls / bugs I hit: ____
  1. Only E‑N mixed pairs can block; same‑direction pairs skip immediately.
  2. Intersection check: `ix > E.x && iy > N.y` — intersection must lie strictly in front of both cows.
  3. Ignore case `te == tn`: they arrive together, no blocking event.
  4. Before applying an event: **if blocker OR victim already stopped, discard event**.
  5. Use `long long` for coordinates and time to avoid integer overflow.
  6. Directed graph edge: `blocker → victim`. BFS counts all nodes reachable starting from source cow.

## Step 5 — Verification
- [ ] Pass official sample input
- [ ] Test equal arrival‑time case (no block)
- [ ] Test intersection behind starting position (skip event)
- [ ] Test multi‑step chain blocking (A blocks B, B blocks C; A counts both B and C)

## Reflection (fill AFTER solving)
- What was the hardest part? ____
- Did I follow the workflow, or skip a step? ____
- If stuck: where did I get stuck and what unblocked me? ____
- One thing to improve next time: ____
