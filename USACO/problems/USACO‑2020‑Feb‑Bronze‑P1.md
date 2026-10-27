# Problem Info
- Name: Social Distancing (Posts)
- Source: USACO 2020 February Bronze P1
- Difficulty (self‑rated): 5 (1–10)
- Date attempted: 2026-10-27 (YYYY‑MM‑DD)
- Status: Solved (Not started / In progress / Solved / Stuck / Solved with help)
- Time spent: 37 min

## Step 1 — Read & Restate
Given N fence post points on 2‑D plane. We need to find the largest possible axis‑aligned rectangle such that one corner of the rectangle is exactly one of the given posts.
One side of rectangle shares the same y‑coordinate with another post, another side shares same x‑coordinate with a third post. Compute maximum area among all such rectangles.

| Item | Value |
|------|-------|
| Input | N, followed by N pairs (a,b) representing post coordinates |
| Output | Maximum rectangle area found |
| Constraints | Small N (Bronze, triple loop feasible) |
| Edge cases | Only few points; dx or dy equal zero (area zero); multiple posts share same x or same y coordinate |

## Step 2 — Model
- Model type: Brute‑force enumeration of candidate rectangle corners
- Explanation:
Pick base point `i (xi, yi)` as rectangle corner.
1. Find point `j` that shares same y = yi, compute horizontal distance `dx = abs(xj − xi)`.
2. Find point `k` that shares same x = xi, compute vertical distance `dy = abs(yk − yi)`.
3. The candidate rectangle area = dx * dy.
We scan all i,j,k triples and keep track of maximum area.
> Note: The fourth corner point does not need to exist in input posts.

## Step 3 — Algorithm
- Algorithm chosen: Triple nested brute‑force loops
- Time complexity: O(N³)
- Space complexity: O(N), store points in vector of vector<int>
- Why it fits: N is small for Bronze; triple loop runs quickly; no complex geometry algorithm needed.

## Step 4 — Implementation Notes
- Data structures used: `vector<vector<int>> post` to store each (x,y) coordinate pair
- Pitfalls / bugs I hit: ____
  1. dx or dy can be zero → area becomes zero, will not affect max_ans.
  2. j and k can be same index as base point i; code still safe because dx/dy becomes zero.
  3. We do NOT require the fourth corner to exist in input points. This is easy to misinterpret.
  4. Initialize `max_ans = 0`.

## Step 5 — Verification
- [ ] Pass official sample input
- [ ] Test case: points with same x or same y
- [ ] Test minimal N=3 case
- [ ] Test case where dx=0 or dy=0 (area zero)

## Reflection (fill AFTER solving)
- What was the hardest part? ____
- Did I follow the workflow, or skip a step? ____
- If stuck: where did I get stuck and what unblocked me? ____
- One thing to improve next time: ____
