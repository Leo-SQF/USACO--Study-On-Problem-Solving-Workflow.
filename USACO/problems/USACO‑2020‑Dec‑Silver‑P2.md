# Problem Info
- Name: Rectangular Pasture
- Source: USACO 2020 December Silver P2
- Difficulty (self‑rated): ____ (1–10)
- Date attempted: ____ (YYYY‑MM‑DD)
- Status: ____ (Not started / In progress / Solved / Stuck / Solved with help)
- Time spent: ____ min

## Step 1 — Read & Restate
Given N distinct 2‑D points(cows). Count number of axis‑aligned rectangles whose corners are among given cow points, and all interior points (strictly inside rectangle) contain **zero cows**.
We sort cows by x‑coordinate. Iterate left‑right x‑boundaries(left, right). Maintain sorted list of y‑coordinates inside current x‑range.
Let `yL = min(y_left, y_right)`, `yH = max(y_left, y_right)`.
`below`: number of y values strictly less than yL in current ys list.
`above`: number of y values strictly greater than yH in current ys list.
Add `below * above` to answer. Single‑point case add 1. Finally add +1 for empty rectangle.

| Item | Value |
|------|-------|
| Input | N; N pairs (x,y), all points distinct |
| Output | total count of valid zero‑internal‑point rectangles |
| Constraints | N ≤ 250; O(N² log N) acceptable |
| Edge cases | single cow point; empty rectangle(+1 final correction); left==right single‑point case |

## Step 2 — Model
- Model type: Enumerate x‑bounds + maintain sorted y list, binary‑search count y‑range
- Explanation:
1. Sort all cows by x coordinate. Enumerate every pair `(left, right)` as left‑right vertical boundaries of rectangle.
2. Expand right pointer, insert cow[right].y into maintained sorted `ys` vector.
3. When `left == right`: this is a single‑point rectangle, ans += 1.
4. Otherwise take yL,yH from cow[left] and cow[right].
    - below = count of y < yL
    - above = count of y > yH
    The product `below * above` counts valid choices for top‑bottom y boundaries, giving rectangles with no cows strictly inside.
5. At very end add 1 to count empty rectangle.

## Step 3 — Algorithm
- Algorithm chosen: Sort by x; double loop over left,right; maintain dynamic sorted y‑list with insert + lower_bound binary search
- Time complexity: O(N² log N). Outer left O(N), inner right O(N), insert into vector O(N), binary‑search O(logN). N=250 fits limit.
- Space complexity: O(N), store cow struct and ys dynamic list
- Why it fits: N small 250, O(N² logN) passes. Cannot brute‑force all four‑corner combinations(O(N⁴)).

## Step 4 — Implementation Notes
- Data structures used: `struct Cow {x,y}` with custom `<` operator sorting by x; `vector<int> ys` keep y sorted; long long ans for large count
- Pitfalls / bugs I hit: ____
  1. Answer can be large, must use `long long ans`.
  2. Insert y into correct sorted position using `lower_bound` before insert.
  3. `below` counts strictly less than yL; `above` counts strictly greater than yH.
  4. `left == right` single‑point case add 1.
  5. Final `ans +=1` counts empty rectangle, easy to forget.
  6. Sort cows by x first.

## Step 5 — Verification
- [ ] Pass official sample input
- [ ] Test N=1 single‑point case
- [ ] Check empty‑rectangle +1 correction
- [ ] Verify binary‑search boundary for strictly‑less / strictly‑greater

## Reflection (fill AFTER solving)
- What was the hardest part? ____
- Did I follow the workflow, or skip a step? ____
- If stuck: where did I get stuck and what unblocked me? ____
- One thing to improve next time: ____
