# Problem Info
- Name: Word Processor
- Source: USACO 2020 January Bronze P1
- Difficulty (self‑rated): 8 (1–10)
- Date attempted: 2026-10-28 (YYYY‑MM‑DD)
- Status: Solved (Not started / In progress / Solved / Stuck / Solved with help)
- Time spent: 45 min

## Step 1 — Read & Restate
We have N words and a maximum line width K. Put words onto lines. Words keep original order.
When adding next word to current line: if total character length of words on line plus new word’s length ≤ K, place it on current line.
Otherwise, print out current line, start new line with this word.
Words on same line are separated by single space character. Spaces **do NOT count toward the K character limit**. Print all lines at end.

| Item | Value |
|------|-------|
| Input | N K, then N word strings |
| Output | Formatted lines of words |
| Constraints | Each single word length ≤ K; spaces do not count against line width K |
| Edge cases | One single word per line; all words fit in one line; last remaining line after loop must be printed |

## Step 2 — Model
- Model type: Greedy line‑breaking simulation
- Explanation:
Maintain current line buffer and sum of word lengths (excluding spaces).
Try adding next word:
- If sum_len + word.length() ≤ K → append word to current line, add word length to sum_len.
- Else: output current line, clear buffer, place this word as first word of new line, reset sum_len to word length.
After loop finishes, output the words remaining in buffer (the final line).

## Step 3 — Algorithm
- Algorithm chosen: Greedy sequential simulation
- Time complexity: O(total characters across all words)
- Space complexity: O(N), store word list and current‑line buffer vector
- Why it fits: Process words in input order; greedy placement directly follows problem statement; no complex dynamic programming needed for Bronze requirements.

## Step 4 — Implementation Notes
- Data structures used: `vector<string> words` store all input words; `vector<string> line` for current‑line buffer; integer `sum_len` tracks sum of word lengths in current line.
- Pitfalls / bugs I hit: ____
  1. Space characters do **not** count against K limit. Only sum word lengths.
  2. Must print leftover words in `line` after for‑loop ends (last line).
  3. When printing line elements: print space only between words, not at start or end of line.
  4. Each input word is guaranteed length ≤ K, we never have a word that cannot fit on a line by itself.

## Step 5 — Verification
- [ ] Pass official sample input
- [ ] Test: all words fit inside one single line
- [ ] Test: every word occupies its own separate line
- [ ] Verify no trailing space on output lines

## Reflection (fill AFTER solving)
- What was the hardest part? ____
- Did I follow the workflow, or skip a step? ____
- If stuck: where did I get stuck and what unblocked me? ____
- One thing to improve next time: ____
