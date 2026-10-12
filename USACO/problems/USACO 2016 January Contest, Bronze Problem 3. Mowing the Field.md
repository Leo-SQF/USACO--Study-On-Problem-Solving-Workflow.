# Problem Template

## Problem Info

- **Name:** `Mowing`
- **Source:** `USACO January 2016 Bronze P3`
- **Difficulty (self-rated):** `3/10`
- **Date attempted:** `2026-10-12`
- **Status:** `Solved with help`
- **Time spent:** `40 min`

---

## Step 1 — Read & Restate

> 
> Farmer John moves on an infinite 2D grid to cut grass. He starts at a cell at time t=0, cutting the grass there. He follows N movement commands. Each command gives a direction and a number of steps. Each step takes 1 time unit.
> Grass cut at time `t_cut` regrows at time `t_cut + x`. Every time FJ steps onto a cell, the grass there must already have regrown. This means the time difference between two visits to the same cell must be at least `x`.
> We need to find the maximum possible value of `x`. If FJ never visits any cell twice, output `-1`.

表格

| Item | Value |
| --- | --- |
| Input | First line: integer N. The next N lines each contain a direction character and an integer step count. |
| Output | The maximum valid integer x. Output `-1` if no cell is revisited. |
| Constraint on N | \(1 \le N \le 100\), each command has \(1 \le S \le 10\), total steps ≤ 1000 |
| Edge cases | 1. No repeated cells → output -1. 2. Multiple revisits to same cell (only the most recent prior visit counts). 3. Minimum time difference from many revisits controls the final answer. |

---

## Step 2 — Model

- Model type: `Simulation + Hash Map / Map`
- Explanation:
We simulate FJ’s movement step-by-step. We keep track of the timestamp when each grid cell was last visited. Whenever we revisit a cell, calculate the time gap between the two visits. The answer is the **minimum of all these gaps**, because `x` has to be less than or equal to every gap.

---

## Step 3 — Algorithm

- Algorithm chosen: `Grid simulation with map to record last visit time`
- Time complexity: \(O(T)\), where T = total steps (max 1000)
- Space complexity: \(O(T)\), we store a map entry for every unique cell visited.
- Why it fits the constraints:
Total steps are at most 1000, which is tiny. Even a simple simulation with a `map` runs instantly. No heavy computation needed.

---

## Step 4 — Implementation Notes

- Data structures used: `map<pair<int,int>, int>` to map coordinate pairs to last visited time; `vector<int>` to store all time differences from revisits.
- Pitfalls / bugs I hit:

1. Used C++11 range-based for loop `for(int d : deltas)` which fails in C++98 compiler mode. Fixed by replacing with traditional indexed for-loop.
2. Must **update the stored time of the cell every time we step on it**, not only on first visit.
3. `INT_MAX` requires header `<climits>`.
4. `pair` needs `<utility>` or `<map>`.

---

## Step 5 — Verification

- Passes provided samples
- Passes my edge cases
- Within time limit
- Brute-force cross-check (if applicable)

---

## Reflection (fill AFTER solving)

- What was the hardest part? Remembering to overwrite the cell’s last visit time after every visit, not only on repeated visits. Also compiler compatibility issues with C++11 syntax.
- Did I follow the workflow, or skip a step? I read the problem and modeled it first, then coded.
- If stuck: where did I get stuck and what unblocked me? Got stuck on the range-based for loop compile error. Switched to old-style for loop compatible with C++98.
- One thing to improve next time: Write C++98 compatible loops when practicing in older compilers, and check required headers before coding.
