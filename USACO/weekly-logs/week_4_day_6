# Daily Experiment Log
Week 4 / Day 6
Date: 2026-10-28 (YYYY‑MM‑DD)
Active modeling version: v0.0
Today's Experiment Objective: Week4 mixed Bronze review; greedy text‑wrapping simulation problem. Practice carefully separating problem‑given counting rules (spaces do not count towards width limit). Continue collecting baseline bug and timing data for month‑1 final summary.
Pre‑set hypothesis: Greedy sequential placement works directly for this problem. Only word lengths contribute to K limit; space separators are output formatting only and should be ignored during line‑width calculation. Must remember to flush the last line after iteration completes.
Selected problems for today:
- USACO 2020 January Bronze P1 — Word Processor

| Problem Link | Modeling Time | Coding Time | Debug Time | Result | Bug Type |
| ---- | ---- | ---- | ---- | ---- | ---- |
| Word Processor 2020 Jan Bronze P1 | ____ min | ____ min | ____ min | ____ | ____ |

---
## Step 1 Problem Abstraction
Given N words in fixed order and maximum line width K.
We arrange words into lines: sum of lengths of words on one line cannot exceed K.
Important rule: single spaces between output words do **not count against K limit**.
If next word cannot fit into current line, output current line, start new line with that word.
After iterating all words, output words left in current line buffer.

## Step 2 Algorithm Selection
Candidate1: DP line‑break for minimal badness — rejected, unnecessary. Problem enforces greedy rule, we cannot re‑order words.
Candidate2: One‑pass greedy simulation, maintain current‑line buffer and sum of word lengths.
Selected algorithm: greedy sequential simulation
Reason: Problem defines exact placement rule, words cannot be reordered. Straightforward simulation matches problem statement.
Complexity: linear with total character count of input words.

## Step3 Logic & Data Structure Framework
Data structure:
- `vector<string> words`: store all input words
- `vector<string> line`: buffer holding words for current unfinished line
- `sum_len`: integer sum of lengths of words inside current line (spaces excluded)

Pseudocode:
Read N, K and all words.
Initialize line empty, sum_len = 0
For each word w in words:
    wlen = length of w
    if sum_len + wlen ≤ K:
        add w to line
        sum_len += wlen
    else:
        print line elements separated by space
        clear line
        add w to line
        sum_len = wlen
# print the remaining words in last line
print line elements separated by space

## Step4 Boundary & Fault Tolerance Modeling
Pre‑predicted edge cases:
1. All words fit within a single line: final buffer print is the only output.
2. Every word fills one full line; each iteration triggers line output.
3. Trap: mistakenly add space length to sum_len (violates problem rule).
4. Forgetting to output the final remaining line after main for‑loop finishes.
5. Output formatting: avoid leading space and trailing space on printed lines.

## Step5 Verification & Reflection Modeling
Test official sample input and edge‑case test groups.
Classify bug type: ____ (A/B/C/D) — fill after real testing.
Evaluate 5‑step workflow: Step1 abstraction is critical to catch “spaces do not count” detail. Step4 helps remind about final‑line output trap.
Did the process catch errors early? ____

---
## Review after solving all problems
Compare predicted edge cases and real bugs: ____
Did the 5‑step modeling process help catch errors in advance? ____
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today): ____

## Quick Reflection
Which step was hardest today: ____

## Tomorrow's Simple Plan
Finish Week4 remaining practice problems. Gather all Week1‑Week4 experiment data. Prepare week‑4 weekly summary and baseline statistics for v1.0 methodology revision planning.

✅ Checklist
- [x] New problem markdown added to /problems
- [x] Source code added to /solutions
- [x] This daily log saved
- [x] Git commit completed
