# Problem Info
- Name: Daisy Chains
- Source: USACO 2020 December Bronze P2
- Difficulty (self‑rated): ____ (1–10)
- Date attempted: ____ (YYYY‑MM‑DD)
- Status: ____ (Not started / In progress / Solved / Stuck / Solved with help)
- Time spent: ____ min

## Step 1 — Read & Restate
Given an array of N integers. Count the number of contiguous subarrays where the average value of the subarray appears as one of the elements inside that subarray.

| Item | Value |
|------|-------|
| Input | N, followed by N integers array p |
| Output | Total count of valid contiguous subarrays |
| Constraints | 1 ≤ N ≤ 100 |
| Edge cases | Subarray length = 1 (always valid, element equals its own average); all elements equal; average is integer only; multiple overlapping subarrays |

## Step 2 — Model
- Model type: Brute‑force complete subarray enumeration
- Explanation:
We need to examine every contiguous subarray `p[i … j]`.
1. Compute sum of subarray i~j, length `len = j‑i+1`.
2. If `sum % len != 0`, average is not integer → subarray invalid, skip.
3. Else compute integer average `avg = sum / len`.
4. Check whether avg exists inside elements from i to j. If yes, count +=1.

Since N ≤ 100, total subarrays ~ 5000, triple loop is acceptable. No need for advanced optimization.

## Step 3 — Algorithm
- Algorithm chosen: Triple nested brute‑force enumeration
- Time complexity: O(N³)
- Space complexity: O(N) for storing input array
- Why it fits: N is only up to 100; N³ = 1 000 000 operations, well within time limit. More complex math optimization is unnecessary for Bronze constraints.

## Step 4 — Implementation Notes
- Data structures used: vector<int> to store input numbers
- Pitfalls / bugs I hit: ____
  1. Length‑1 subarrays are always valid (average equals itself), must be counted.
  2. Average must be integer: must check `sum % len == 0` before division.
  3. Only search for avg inside current subarray i…j, not whole array.
  4. ans starts at zero, increment only when all conditions satisfied.

## Step 5 — Verification
- [ ] Pass official sample input
- [ ] Test N=1 single‑element case
- [ ] Test all‑equal elements array
- [ ] Test case where sum is not divisible by length (should skip)

## Reflection (fill AFTER solving)
- What was the hardest part? ____
- Did I follow the workflow, or skip a step? ____
- If stuck: where did I get stuck and what unblocked me? ____
- One thing to improve next time: ____
