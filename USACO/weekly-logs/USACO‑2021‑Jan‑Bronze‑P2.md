# Problem Info
- Name: Even More Odd Photos
- Source: USACO 2021 January Bronze P2
- Difficulty (self‑rated): ____ (1–10)
- Date attempted: ____ (YYYY‑MM‑DD)
- Status: ____ (Not started / In progress / Solved / Stuck / Solved with help)
- Time spent: ____ min

## Step 1 — Read & Restate
We have n integers representing cow group sizes. We separate them into a sequence of groups.
Group sequence rule: the parity of group size must alternate starting with even number.
Pattern: even‑size group, then odd‑size group, then even‑size group, then odd‑size group …
We can merge two odd‑count cows together to make one even‑size group.
Count maximum number of groups we can form following this alternating parity rule.

| Item | Value |
|------|-------|
| Input | n, followed by n integers (each is 1 for odd cow, 2 for even cow) |
| Output | maximum number of alternating parity groups starting with even |
| Constraints | n ≤ 100; count total odd and even cows only, original order does not matter |
| Edge cases | zero even cows; leftover cows cannot form next valid group; two odds combine into even; final leftover elements trigger subtract‑one correction |

## Step 2 — Model
- Model type: Greedy simulation based on parity count
- Explanation:
Count total number of odd cows(`odd`) and even cows(`even`).
We build groups in fixed order: even → odd → even → odd …
1. Need even group: either consume one existing even cow, or merge two odd cows to make an even group.
2. Need odd group: consume one odd cow.
Loop until cannot make next required group.
After loop ends, if there are still unused cows left that cannot form next group, subtract one from answer.

## Step 3 — Algorithm
- Algorithm chosen: Greedy parity‑count simulation loop
- Time complexity: O(n)
- Space complexity: O(1), only two counters odd / even
- Why it fits: The original ordering of cows does not matter; only total count of odd and even matters. Simulate building groups following parity alternation rule.

## Step 4 — Implementation Notes
- Data structures used: two integer counters `odd`, `even`
- Pitfalls / bugs I hit: ____
  1. Start sequence must begin with even group.
  2. To make an even group without even cows: must spend **two odd cows**.
  3. When loop exits, check leftover cows; if any cows remain unused, ans needs `ans‑=1`.
  4. Careful about condition `odd >=2` when trying to make even from two odds.

## Step 5 — Verification
- [ ] Pass official sample input
- [ ] Test case zero even cows
- [ ] Test leftover remaining cows after loop (trigger ans‑1)
- [ ] Test all‑odd input

## Reflection (fill AFTER solving)
- What was the hardest part? ____
- Did I follow the workflow, or skip a step? ____
- If stuck: where did I get stuck and what unblocked me? ____
- One thing to improve next time: ____
