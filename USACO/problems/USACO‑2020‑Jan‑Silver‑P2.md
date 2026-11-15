# Problem Info
- Name: Berry Picking
- Source: USACO 2020 January Silver P2
- Difficulty (self‑rated): ____ (1–10)
- Date attempted: ____ (YYYY‑MM‑DD)
- Status: ____ (Not started / In progress / Solved / Stuck / Solved with help)
- Time spent: ____ min

## Step 1 — Read & Restate
We have n bushes, bush `i` has `B[i]` berries.
We choose an integer `x`. For every bush with `b` berries:
- Split into full baskets of size x: `full = b / x` baskets each holding x berries.
- Remainder `r = b % x` (0 < r < x) is leftover partial basket.

Collect all full‑size baskets, then fill up to total `k` baskets using leftover partial baskets (add one leftover per basket). If we still have fewer than k baskets, pad with baskets of 0 berries.

Sort all k baskets in descending order. Take the **second‑half baskets** starting from index `k/2` to end, sum their berries.
Iterate every possible x (1 ≤ x ≤ max(B)), maximize this sum, output the maximum sum.

| Item | Value |
|------|-------|
| Input | n k; array B of berry counts per bush |
| Output | maximum achievable sum |
| Constraints | n ≤ 100, max(B) ≤ 1000, k ≤ 1000 |
| Edge cases | remainder list empty; full baskets already ≥ k; need zero‑padding to reach exactly k baskets; k is odd or even for half index |

## Step 2 — Model
- Model type: Brute‑force iterate candidate basket‑size x; simulate basket generation for each x; greedy sort‑and‑sum
- Explanation:
1. Try every possible basket size x from 1 to maxb(max berry count in any bush).
2. For each bush b:
   - generate `b/x` full baskets of size x
   - if remainder `b%x > 0`, add remainder to `rems` list
3. Take full baskets first, then append leftover remainders until we have k baskets. If still short, fill with zero‑berry baskets.
4. Sort all k baskets descending. Sum elements from index `half = k/2` to end.
5. Keep track of global maximum sum over all x.

## Step 3 — Algorithm
- Algorithm chosen: Brute‑force enumerate x; simulate basket construction; sort & sum
- Time complexity: O(maxb * (total_baskets log k)). maxb ≤1000, fits constraints.
- Space complexity: O(k), store bask and rems vectors
- Why it fits: max(B) is only up to 1000, brute‑force all x is feasible; no smarter mathematical shortcut required for given limits.

## Step 4 — Implementation Notes
- Data structures used: `vector<int> B`; `vector<int> bask` completed baskets; `vector<int> rems` partial remainders
- Pitfalls / bugs I hit: ____
  1. `half = k / 2` is integer division, use this starting index for summing second half after sorting descending.
  2. Remainder r > 0 only; do not push r=0 into rems.
  3. When total baskets < k: must pad with 0 until exactly k baskets.
  4. Sort baskets **descending** before summing second half.
  5. x loops starts from 1, not 0 (division‑by‑zero risk).

## Step 5 — Verification
- [ ] Pass official sample input
- [ ] Test when full baskets already exceed k (ignore remainders)
- [ ] Test case needing zero padding
- [ ] Check odd‑k and even‑k half index calculation

## Reflection (fill AFTER solving)
- What was the hardest part? ____
- Did I follow the workflow, or skip a step? ____
- If stuck: where did I get stuck and what unblocked me? ____
- One thing to improve next time: ____
