# Problem Info
- Name: Blocks
- Source: USACO 2016 December Bronze P2
- Difficulty (self‑rated): ____ (1–10)
- Date attempted: ____ (YYYY‑MM‑DD)
- Status: ____ (Not started / In progress / Solved / Stuck / Solved with help)
- Time spent: ____ min

## Step 1 — Read & Restate
We have N sets of two words. For each set, you can use wooden letter‑blocks to build **either the first word OR the second word**. For each letter a‑z, find the **total minimal number of blocks needed** across all N pairs.
For each pair, for one letter, take `max(count in w1, count in w2)`, sum this value over all N pairs for each character. Output sum for each of 26 letters on separate lines.
> Note: Program uses file I/O: read `blocks.in`, write `blocks.out`.

| Item | Value |
|------|-------|
| Input | N; N lines each contain two strings w1 w2 |
| Output | 26 integers, one per lowercase letter, total required blocks for that letter |
| Constraints | Words only lowercase a‑z; small N |
| Edge cases | One word has zero occurrences of a letter; w1 and w2 have different letter counts; empty‑count letters output zero |

## Step 2 — Model
- Model type: Character frequency counting
- Explanation:
1. Write helper function `count_letters`: compute frequency array size 26 for input string.
2. For each pair(w1,w2): get frequency c1 for w1, c2 for w2.
3. For each character 0‑25: add `max(c1[c], c2[c])` to final answer array ans[c].
Because for each pair we choose one word to build, we need at least the larger count of that letter between the two words.

## Step 3 — Algorithm
- Algorithm chosen: Character frequency counting with helper function
- Time complexity: O(total characters across all input words)
- Space complexity: O(26), fixed‑size frequency arrays
- Why it fits: Simple counting problem; no complex data‑structures needed. File‑based input/output.

## Step 4 — Implementation Notes
- Data structures used: int frequency arrays size 26; helper function `count_letters`; `ifstream / ofstream` for file IO
- Pitfalls / bugs I hit: ____
  1. File I/O: must read `blocks.in` and write `blocks.out`, not standard cin/cout for judge.
  2. Helper function must **zero‑initialize counts array** before counting each string.
  3. Use `max(c1[c], c2[c])`, **not sum**. We build only one word per pair.
  4. Output each of 26 numbers on separate lines.

## Step 5 — Verification
- [ ] Pass official sample input
- [ ] Test letter appears only in w1 or only in w2
- [ ] Test zero‑occurrence letters output zero
- [ ] Check file read‑write correctness

## Reflection (fill AFTER solving)
- What was the hardest part? ____
- Did I follow the workflow, or skip a step? ____
- If stuck: where did I get stuck and what unblocked me? ____
- One thing to improve next time: ____
