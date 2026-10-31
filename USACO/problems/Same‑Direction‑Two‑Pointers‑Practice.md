# Problem Info
- Name: Same‑Direction Two‑Pointers Practice (Sliding Window)
- Source: Self‑practice Week5 Month2 warm‑up
- Difficulty (self‑rated): 3 (1–10)
- Date attempted: 2026-10-31 (YYYY‑MM‑DD)
- Status: Solved (Not started / In progress / Solved / Stuck / Solved with help)
- Time spent: 10 min

## Step 1 — Read & Restate
Given an array of n positive integers (1‑based index). Find the maximum length of a contiguous subarray whose total sum ≤ 10.

| Item | Value |
|------|-------|
| Input | n; followed by n integers |
| Output | maximum length of valid subarray |
| Constraints | All elements positive; use long long for sum to avoid overflow; 1‑based indexing |
| Edge cases | Single element >10 (window length 0); whole array sum ≤10; one element exactly equal to 10 |

## Step 2 — Model
- Model type: Sliding window / same‑direction two‑pointers
- Explanation:
Since all numbers are positive, when right pointer moves right, the window sum strictly increases.
Maintain left, right two pointers. Expand window by moving right.
If current window sum exceeds limit 10, keep moving left forward until sum ≤10.
At each right, record window length `right‑left+1`, keep track of maximum length.

## Step 3 — Algorithm
- Algorithm chosen: Same‑direction two‑pointers(sliding window)
- Time complexity: O(n), each element is added once and subtracted once
- Space complexity: O(n), store input array
- Why it fits: All elements positive → monotonic sum guarantees left only moves forward, never roll‑back. Avoid O(n²) brute‑force enumeration.

## Step 4 — Implementation Notes
- Data structures used: `vector<int> num_input(n+1,0)` 1‑based array; `left,right` pointers; `long long sum`; `maxlen`
- Pitfalls / bugs I hit: ____
  1. `sum` must use long long to prevent integer overflow.
  2. Array is 1‑based, pointers start at 1, not 0.
  3. Condition `while(sum>10)` not `if(sum>10)`; may need to shrink multiple steps.
  4. Update maxlen after window is valid.

## Step 5 — Verification
- [ ] Normal test case: multiple valid windows
- [ ] Whole array sum ≤ 10 → answer equals n
- [ ] One element > 10 case
- [ ] Element exactly equal to limit 10

## Reflection (fill AFTER solving)
- What was the hardest part? ____
- Did I follow the workflow, or skip a step? ____
- If stuck: where did I get stuck and what unblocked me? ____
- One thing to improve next time: ____
