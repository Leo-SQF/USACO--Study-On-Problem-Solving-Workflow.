# Problem Info
- Name: Uddered but not Herd
- Source: USACO 2021 January Bronze P1
- Difficulty (self‑rated): ____ (1–10)
- Date attempted: ____ (YYYY‑MM‑DD)
- Status: ____ (Not started / In progress / Solved / Stuck / Solved with help)
- Time spent: ____ min

## Step 1 — Read & Restate
We are given one string `cow` of length 26 containing every lowercase‑letter exactly once; this defines a custom alphabet order.
Given second string `hear`. We read `hear` following this custom order. Every time a character in `hear` is **not later** in custom‑order than previous character, we must start a new copy of the cow string.
Count how many total copies of the cow string we need.

| Item | Value |
|------|-------|
| Input | cow (26 unique lowercase letters); hear (target string) |
| Output | number of required copies of cow string |
| Constraints | cow contains all 26 letters exactly one time; 1 ≤ hear.length ≤ 1000 |
| Edge cases | hear single character (ans=1); every next character resets count; whole hear follows custom order without reset |

## Step 2 — Model
- Model type: Custom‑order mapping + one‑pass linear scan
- Explanation:
1. Build `pos[]` array: `pos[ch‑'a']` stores index position of character `ch` inside cow string, represents its custom order rank.
2. Start ans = 1 (at least one copy).
3. Iterate hear from i=1 to end:
    Compare position of current character and previous character in custom order.
    If `pos[current] <= pos[previous]`: we need new copy, ans += 1.

## Step 3 — Algorithm
- Algorithm chosen: Pre‑compute position mapping + single pass linear scan
- Time complexity: O(26 + len(hear)) → O(N)
- Space complexity: O(26) for pos array
- Why it fits: Only need to compare relative custom‑order rank between adjacent characters in hear; no nested loops required.

## Step 4 — Implementation Notes
- Data structures used: string cow, hear; int pos[26] to store each letter’s index in custom order
- Pitfalls / bugs I hit: ____
  1. ans initial value must be 1, not 0, even for single‑character input.
  2. Condition trigger new copy: `now <= prev` (less‑than OR equal), not only `<`. Equal position means same character, must open new copy.
  3. pos array index: `char - 'a'` convert char to 0‑25 offset.
  4. cow string guaranteed length exactly 26 with all distinct letters.

## Step 5 — Verification
- [ ] Pass official sample input
- [ ] Test hear with length = 1 → output = 1
- [ ] Test consecutive same character, should increment ans
- [ ] Test full sequence strictly following custom order, ans remains 1

## Reflection (fill AFTER solving)
- What was the hardest part? ____
- Did I follow the workflow, or skip a step? ____
- If stuck: where did I get stuck and what unblocked me? ____
- One thing to improve next time: ____
