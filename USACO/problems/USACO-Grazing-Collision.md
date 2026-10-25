# Problem Info
- Name: Grazing Collision (Crossing Paths)
- Source: USACO Bronze
- Difficulty (self-rated): ____ (1–10)
- Date attempted: ____ (YYYY-MM-DD)
- Status: ____ (Not started / In progress / Solved / Stuck / Solved with help)
- Time spent: ____ min

## Step 1 — Read & Restate
We have N cows on an infinite grid. Each cow starts at a unique cell, either facing East (E, x+1, y) or North (N, x, y+1).
Rules every hour:
1. If the cow’s current cell grass is already eaten → stop moving.
2. Otherwise: eat grass on current cell, then move forward one step.
Special rule: If two cows step onto the same grassy cell in the same move, they share it and keep moving.
Goal: For each cow, output how many cells it eats. If it never stops, output Infinity.

| Item | Value |
|------|-------|
| Input | N, then N lines: direction, x, y |
| Output | N lines: count or Infinity for each input cow |
| Constraints | 1 ≤ N ≤ 50; x,y up to 1e9; all starting x distinct, all starting y distinct |
| Edge cases | Cow A blocks cow B; they arrive at intersection at exactly same time (no block); one cow is blocked infinitely far away |

## Step 2 — Model
- Model type: `Event-driven simulation / collision timing`
- Explanation:
Only E cow and N cow can possibly block each other.
For an east cow (E, xe, ye) and north cow (N, xn, yn):
Intersection point = `(xn, ye)`
- E cow needs `t_e = xn - xe` steps to reach intersection
- N cow needs `t_n = ye - yn` steps to reach intersection
If t_e < 0 or t_n <0: paths never cross.
- If t_e < t_n: E arrives earlier → E eats that cell first, N will be blocked at time t_n
- If t_n < t_e: N arrives earlier → N eats that cell first, E will be blocked at time t_e
- If t_e == t_n: They arrive together, no blocking.

## Step 3 — Algorithm
- Algorithm chosen: Collect all possible collision events, sort events by collision time, process earliest event first. Mark which cow gets blocked at which time. Once a cow is blocked, ignore its future collision events.
- Time complexity: O(N² log N)
- Space complexity: O(N)
- Why it fits: N is small (≤50). We cannot simulate step by step because coordinates are up to 1e9. Must work with collision timestamps instead of grid simulation.

## Step 4 — Implementation Notes
- Data structures: Store each cow’s start position, direction, block_time = infinity initially.
- Pitfalls / bugs I hit: ____
  1. Must only process an event if **both cows are still unblocked** at that event’s time
  2. Distinguish: equal arrival time → no block
  3. Block time = arrival time at intersection; the cow eats exactly `block_time` cells
  4. If a cow’s block_time remains infinity → output Infinity

## Step 5 — Verification
- [ ] Passes provided sample input
- [ ] Pass edge test: E and N reach crossing point same time
- [ ] Pass edge test: one cow is blocked before it can reach the crossing
- [ ] Handle very large coordinates (no grid array, only math)

## Reflection (fill AFTER solving)
- What was the hardest part? ____
- Did I follow the workflow, or skip a step? ____
- If stuck: where did I get stuck and what unblocked me? ____
- One thing to improve next time: ____
