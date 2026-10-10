# Problem Template

<!-- One copy of this file per problem. Save as:
problems/<topic>/<problem-name>.md
Fill every section BEFORE coding (model first!), and reflect AFTER. -->## Problem Info

- **Name:** `COW Subsequence`
- **Source:** `USACO 2015, Ben Cousins and Brian Dean`
- **Difficulty (self-rated):** `2`
- **Date attempted:** `2026-10-10`
- **Status:** `Solved`
- **Time spent:** `8 min`

---

## Step 1 — Read & Restate

> 
> We have a string made up of only C, O, W characters. Count the total number of **COW subsequences**. A subsequence does not require characters to be adjacent, only order preserved. Characters can be reused across different subsequences.

表格

| Item | Value |
| --- | --- |
| Input | First line: integer N, length of string. Second line: length-N string composed only of C/O/W |
| Output | Total count of COW subsequences (use 64-bit integer, result can be large) |
| Constraint on N | \(N \le 10^5\) |
| Edge cases | No C / no O / no W → output 0; all C; all O; all W; N<3; C followed by W with no O; O appears before C; W appears before C/O |

---

## Step 2 — Model

- Model type: `DP / one-pass counting`
- Explanation:
We keep track of three cumulative counts as we scan left to right:

1. `cntC`: number of C’s seen so far
2. `cntCO`: number of "CO" pairs (each existing C pairs with a new O)
3. `cntCOW`: total COW subsequences (each existing CO pairs with a new W)
We only update counts when we hit the matching character. This is a lightweight dynamic programming approach, no full DP table needed.

---

## Step 3 — Algorithm

- Algorithm chosen: `Linear scan with running counters`
- Time complexity: \(O(N)\)
- Space complexity: \(O(N)\) for storing string; can be \(O(1)\) if read character-by-character
- Why it fits the constraints:
\(N \le 10^5\), linear pass is fast enough. No nested loops (brute force triple loop would be \(O(N^3)\) and impossible for \(10^5\)).

---

## Step 4 — Implementation Notes

- Data structures used: simple integer variables (must use 64-bit integer type to avoid overflow)
- Pitfalls / bugs I hit:
  - Overflow: in some languages int is 32-bit and will overflow quickly, need long/long long.
  - Update order: update counters only on the correct character. When seeing W, add cntCO to answer, not cntC.
  - Don’t reset counters, keep accumulating as we go left to right.

---

## Step 5 — Verification

- Passes provided samples (Sample input: 6, CCOOWW → output 6)
- Passes my edge cases: e.g. "COW" →1; "CWO" →0; "CCC" →0
- Within time limit
- Brute-force cross-check (only feasible for tiny N)

---

## Reflection (fill AFTER solving)

- What was the hardest part? Realizing we don’t need to store all positions and combine them combinatorially; incremental counting is enough.
- Did I follow the workflow, or skip a step? Followed workflow, first restated problem then modeled before coding.
- If stuck: where did I get stuck and what unblocked me? Not stuck.
- One thing to improve next time: immediately think about overflow for counting problems where answer can get huge.
