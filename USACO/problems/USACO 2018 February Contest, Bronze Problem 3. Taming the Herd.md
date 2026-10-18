# Problem Template filled for Taming the Herd

## Problem Info

- **Name:** `Taming the Herd`
- **Source:** `USACO January 2018 Bronze P3`
- **Difficulty (self-rated):** `4`
- **Date attempted:** `2026-10-18`
- **Status:** `Solved with help`
- **Time spent:** `70 min`

---

## Step 1 — Read & Restate

> 
> Farmer John logs a counter each morning. The counter shows how many days have passed since the last cow breakout.
> Rule: If a breakout happens on a morning, that day’s counter = 0. If no breakout, counter increases by 1 from the previous day.
> The log starts on a breakout day, so day 1 (index 0) must be 0.
> Some log entries are missing and marked `-1`.
> We need to check if there exists any valid breakout sequence matching the remaining log entries. If impossible, output `-1`.
> If valid, output two integers: the **minimum possible total breakouts** and the **maximum possible total breakouts** over all valid sequences.

| Item | Value |
| --- | --- |
| Input | First line: integer N, number of days. Second line: N integers, each either `-1` (missing log) or non-negative integer (counter value for that day). |
| Output | If no valid sequence exists: `-1`. Otherwise: two space-separated integers m M, m = minimum breakouts, M = maximum breakouts. |
| Constraint on N | $1 \le N \le 100$ |
| Edge cases | N=1; all entries are -1; day 0 input is non-zero and not -1 (invalid); a positive log value requires a breakout before day 0 (invalid); fixed log values conflict with required sequence. |

---

## Step 2 — Model

- Model type: `greedy + constraint propagation`
- Explanation:
We propagate hard constraints from known non -1 log values first. Any day with value $(v>0)$ forces a breakout $v$ days before it, and fixes all intermediate days to $(0,1,2,...,v)$. After fixing all forced values:

1. Positions locked to `0` are mandatory breakouts.
2. Remaining `-1` positions are free variables:
   - For min count: do NOT place breakouts on free positions.
   - For max count: place a breakout on every free position.
   No DP / search needed; constraints can be directly filled in one pass.

---

## Step 3 — Algorithm

- Algorithm chosen: `constraint propagation + greedy counting`
- Time complexity: $O(N^2)$
- Space complexity: $(O(N))$
- Why it fits the constraints:
$N \le 100$, $N^2 = 10^4$ operations, trivial for C++. We loop each day, and for any positive log value, fill a range of fixed values backward.

---

## Step 4 — Implementation Notes

- Data structures used: `vector<int>` to store the log array.
- Pitfalls / bugs I hit:

1. Confused assignment `=` and equality comparison `==` in if conditions.
2. Forgot to enforce day 0 (the first day) must be 0.
3. Array out-of-bounds: when a log value $v$ is larger than its index, $i-v <0$, which is impossible.
4. Misunderstood what min/max breakout count represents: initially tried counting fixed entries and unknown entries directly instead of propagating constraints first.
5. Did not overwrite the `-1` entries forced by known positive log values before counting breakouts.

---

## Step 5 — Verification

- Passes provided samples
- Passes my edge cases
- Within time limit
- Brute-force cross-check (if applicable)

---

## Reflection (fill AFTER solving)

- What was the hardest part? `Understanding how a positive log entry forces all prior values in its range, and realizing the free `-1` positions are the source of min/max difference.`
- Did I follow the workflow, or skip a step? `I skipped modeling first and jumped straight to writing code, which caused many logical bugs.`
- If stuck: where did I get stuck and what unblocked me? `I incorrectly tried to count breakouts without propagating constraints first. Drawing the required number sequence for a positive log entry helped me see the constraint propagation idea.`
- One thing to improve next time: `Write the problem restate and model section before writing any code, catch misconceptions early.`
