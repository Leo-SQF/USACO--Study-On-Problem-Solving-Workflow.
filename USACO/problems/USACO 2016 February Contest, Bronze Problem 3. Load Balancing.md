# Problem Template

## Problem Info

- **Name:** `Balancing`
- **Source:** `USACO 2016 February Bronze Problem 2`
- **Difficulty (self-rated):** `3/10`
- **Date attempted:** `2026-10-13`
- **Status:** `Solved`
- **Time spent:** `25 min`

---

## Step 1 — Read & Restate

> 
> We have N cows on a 2D plane. Every cow's (x,y) coordinates are positive odd integers. We place one vertical fence `x=a` (a even) and one horizontal fence `y=b` (b even). These two fences split the farm into four quadrants. Cows never lie exactly on the fences. We define M as the maximum number of cows among the four regions. We need to choose a and b to minimize this M.

表格

| Item | Value |
| --- | --- |
| Input | First line: N (number of cows), B (max coordinate bound, unused in our algorithm). Next N lines each have x,y of a cow. |
| Output | The minimal possible value of M (the largest cow count in any of four quadrants after optimal fence placement). |
| Constraint on N | \(1 \le N \le 100\) |
| Edge cases | N=1 (answer is 1); all cows clustered on one side; all cows separated evenly. |

---

## Step 2 — Model

- Model type: `Brute force / Enumeration`
- Explanation:
We don’t need to check every possible even a and b up to B (B up to 1e6). The only meaningful split positions are just to the right of a cow’s x coordinate or above a cow’s y coordinate. Any split between two cows will produce exactly the same quadrant counts as splitting right after one cow. So we only need to enumerate candidate split points generated from cow coordinates. Since N ≤ 100, total candidates are small, brute force is feasible.

---

## Step 3 — Algorithm

- Algorithm chosen: `Enumerate all candidate split lines a and b`
  1. Collect candidate a values: for each cow x, add `x+1` (even vertical split line to the right of cow). Deduplicate.
  2. Collect candidate b values: for each cow y, add `y+1` (even horizontal split line above cow). Deduplicate.
  3. Iterate every pair (a,b):
     - Count cows in four quadrants.
     - Compute M = max of four counts. Track the global minimum M.
- Time complexity: \(O(N^3)\)
Number of a candidates ≤ N, number of b candidates ≤ N. For each pair, loop over N cows: \(O(N \cdot N \cdot N)=O(N^3)\). For N=100, \(10^6\) operations, trivial.
- Space complexity: \(O(N)\) to store cow coordinates and candidate values.
- Why it fits the constraints: N ≤ 100, \(10^6\) operations run instantly in C++/Python. No need for more advanced algorithms.

---

## Step 4 — Implementation Notes

- Data structures used: `vector` to store cows; `set` to store candidate split values (auto deduplication).
- Pitfalls / bugs I hit:
  1. Originally used C++11 range-based for loops, but compiler set to C++98 which does not support it → compile error. Fixed by switching to iterator-based loops and array index loops.
  2. `max({v1,v2,v3,v4})` initializer list max is C++11 only; replaced with nested `max(max(a,b),max(c,d))`.
  3. Misunderstanding quadrant definitions (mix up less than / greater than). Must remember a is vertical fence `x=a`: cows with `x<a` are on left, `x>a` on right.
  4. B is given as input but not used, easy to mistakenly try to loop up to B (1e6), which is way too slow.

---

## Step 5 — Verification

- Passes provided samples
- Passes my edge cases
- Within time limit
- Brute-force cross-check (if applicable)

---

## Reflection (fill AFTER solving)

- What was the hardest part? Realizing we do NOT need to iterate all possible a and b up to B, only candidate split points from cows. This is the key insight to avoid TLE.
- Did I follow the workflow, or skip a step? I first read and restated the problem, then designed model before coding. When compiler errors appeared I debugged implementation issues.
- If stuck: where did I get stuck and what unblocked me? Got stuck on C++ standard compatibility errors; switched to old-style iterators and nested max to match C++98.
- One thing to improve next time: When writing C++ code for older compilers, avoid C++11 features at the start if the judge environment may use C++98.
