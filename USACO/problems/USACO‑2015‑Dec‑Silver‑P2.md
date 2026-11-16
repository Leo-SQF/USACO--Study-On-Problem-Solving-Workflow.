# Problem Info
- Name: High Card
- Source: USACO 2015 December Silver P2
- Difficulty (self‑rated): ____ (1–10)
- Date attempted: ____ (YYYY‑MM‑DD)
- Status: ____ (Not started / In progress / Solved / Stuck / Solved with help)
- Time spent: ____ min

## Step 1 — Read & Restate
Numbers from `1 ~ 2n`. Elsie holds n distinct numbers. Bessie gets the remaining n numbers.
Two players play card‑game: in each round each plays one card. If Bessie’s card > Elsie’s card, Bessie gains 1 point.
Find the **maximum possible score** Bessie can achieve with optimal play.

| Item | Value |
|------|-------|
| Input | n; n integers: Elsie’s cards |
| Output | maximum score Bessie can get |
| Constraints | All numbers 1…2n, no duplicates; n ≤ 50 000 |
| Edge cases | All Bessie cards smaller than Elsie’s; all Bessie cards larger; mixed sizes |

## Step 2 — Model
- Model type: Greedy two‑pointer (optimal card‑matching / classic two‑pointer game)
- Explanation:
1. Collect Elsie’s cards, collect Bessie’s remaining cards.
2. Sort both lists in ascending order.
3. Two‑pointer greedy strategy:
    - If Bessie’s current smallest available card > Elsie’s current smallest card: use this card to win one round, increment score, move both pointers forward.
    - Else: this Bessie card cannot beat any remaining Elsie card; discard it, only advance Bessie pointer.
This greedy yields maximum possible wins.

## Step 3 — Algorithm
- Algorithm chosen: Collect sets → sort → two‑pointer greedy matching
- Time complexity: O(n log n), dominated by sorting
- Space complexity: O(n)
- Why it fits: Classic optimal greedy for this card‑game; no need for DP. Two‑pointer linear scan after sort.

## Step 4 — Implementation Notes
- Data structures used: `vector<bool> has` mark which numbers belong to Elsie; `elsie`, `bessie` vector for cards; two pointers `e_ptr, b_ptr`
- Pitfalls / bugs I hit: ____
  1. Value range `1 ~ 2*n`, size of `has` array needs `2*n+1`.
  2. Both lists must be sorted ascending before two‑pointer loop.
  3. Condition: only count point when `bessie[b_ptr] > elsie[e_ptr]`.
  4. Pointer movement rules: win → both ++；lose candidate → only b_ptr++.

## Step 5 — Verification
- [ ] Pass official sample input
- [ ] Test zero‑score case (all Bessie cards smaller)
- [ ] Test maximum n‑score case (all Bessie cards bigger)
- [ ] Mixed case partial wins

## Reflection (fill AFTER solving)
- What was the hardest part? ____
- Did I follow the workflow, or skip a step? ____
- If stuck: where did I get stuck and what unblocked me? ____
- One thing to improve next time: ____
