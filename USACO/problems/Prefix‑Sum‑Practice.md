# Problem Info
- Name: Prefix Sum Practice
- Source: Self‑practice (Week5 Month2 baseline warm‑up)
- Difficulty (self‑rated): ____ (1–10)
- Date attempted: ____ (YYYY‑MM‑DD)
- Status: ____ (Not started / In progress / Solved / Stuck / Solved with help)
- Time spent: ____ min

## Step 1 — Read & Restate
Given an array of n integers. Build a prefix‑sum array. Answer q queries; each query gives L, R, compute sum of elements from index L to R inclusive (1‑based indexing).

| Item | Value |
|------|-------|
| Input | n; n array elements; q; q pairs L R |
| Output | Sum for each query L~R |
| Constraints | Use long long to avoid integer overflow; array uses 1‑based index |
| Edge cases | L=1 (pre[L‑1]=pre[0]=0); L=R single‑element query; large sum causing int overflow |

## Step 2 — Model
- Model type: Prefix‑sum static range‑sum model
- Explanation:
`pre[i] = a[1] + a[2] + … + a[i]`
Range sum [L, R] formula: `sum(L,R) = pre[R] − pre[L‑1]`
pre[0] = 0 as base case.
Pre‑compute once, each query answered in O(1).

## Step 3 — Algorithm
- Algorithm chosen: Prefix sum pre‑computation
- Time complexity: O(n + q)
- Space complexity: O(n) for original array and prefix array
- Why it fits: Static array, no updates. Prefix‑sum converts range‑sum queries to constant time after one‑time preprocessing.

## Step 4 — Implementation Notes
- Data structures used: `vector<long long> a(n+1)`, `vector<long long> pre(n+1,0)`, 1‑based indexing
- Pitfalls / bugs I hit: ____
  1. Use `long long` to prevent integer overflow on large sums.
  2. 1‑based index: pre[0] must initialize to zero.
  3. Formula: `pre[R] - pre[L‑1]`, not pre[R]‑pre[L].
  4. Do not recompute sum inside each query loop (would become O(nq)).

## Step 5 — Verification
- [ ] Test sample input with normal range query
- [ ] Test L=1 boundary case
- [ ] Test L=R single element query
- [ ] Verify large values do not overflow (long long)

## Reflection (fill AFTER solving)
- What was the hardest part? ____
- Did I follow the workflow, or skip a step? ____
- If stuck: where did I get stuck and what unblocked me? ____
- One thing to improve next time: ____
