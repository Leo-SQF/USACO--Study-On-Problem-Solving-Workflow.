# Problem Template

<!-- One copy of this file per problem. Save as:
problems/<topic>/<problem-name>.md
Fill every section BEFORE coding (model first!), and reflect AFTER. -->## Problem Info

- **Name:** `Cow Watering`
- **Source:** `Self-made USACO Bronze practice`
- **Difficulty (self-rated):** `4`
- **Date attempted:** `2026-10-07`
- **Status:** `Not started`
- **Time spent:** `XX min`

---

## Step 1 — Read & Restate

> 
> Farmer John has N water taps in a line. Each tap has a flow value. We will receive Q queries. Each query asks for the sum of tap flows from position L to position R inclusive. Compute and print the sum for each query.
> | Item | Value |
> |------|-------|
> | Input | First line: two integers N and Q.Second line: N integers, the flow of each tap.Next Q lines: each line two integers L, R. |
> | Output | For every query, output the sum of values from index L to R. |
> | Constraint on N | \(1 \le N \le 1000,\ 1\le Q \le 1000\) |
> | Edge cases | L=R (sum is just the single element); L=1, R=N (sum all elements); N=1, multiple queries. |

---

## Step 2 — Model

- Model type: `Prefix Sum`
- Explanation:
We precompute a prefix sum array once. Then each range sum query can be answered in O(1) using the formula \(s[R]-s[L-1]\). This is perfect for multiple range sum queries.

---

## Step 3 — Algorithm

- Algorithm chosen: `Prefix Sum`
- Time complexity: \(O(N+Q)\)
- Space complexity: \(O(N)\)
- Why it fits the constraints:
N and Q are up to 1000. Preprocessing takes 1000 steps, each query is constant time. Far under time limits for Bronze.

---

## Step 4 — Implementation Notes

- Data structures used: `int array a, long long prefix sum array s`
- Pitfalls / bugs I hit: `Off-by-one index error; forget s[0]=0; use int for sum and hit integer overflow`

---

## Step 5 — Verification

- Passes provided samples
- Passes my edge cases
- Within time limit
- Brute-force cross-check (if applicable)

---

## Reflection (fill AFTER solving)

- What was the hardest part? `...`
- Did I follow the workflow, or skip a step? `...`
- If stuck: where did I get stuck and what unblocked me? `...`
- One thing to improve next time: `...`
- 
