# Daily Experiment Log
Week 6 / Day 2
Date: ____ (YYYY‑MM‑DD)
Active modeling version: v1.0
Today's Experiment Objective: Month2 Week6 practice; character‑frequency counting with helper function, file‑IO USACO format. Continue baseline data collection under v1.0 workflow.
Pre‑set hypothesis: For each word‑pair we build exactly one word, so per‑letter requirement for that pair equals max(count in w1, count in w2). Sum max values over all pairs. Pay attention to file‑based input‑output and zero‑initialization inside counting helper.
Selected problems for today:
‑ USACO 2016 December Bronze P2 — Blocks

| Problem Link | Modeling Time | Coding Time | Debug Time | Result | Bug Type |
| ---- | ---- | ---- | ---- | ---- | ---- |
| Blocks 2016 Dec Bronze P2 | ____ min | ____ min | ____ min | ____ | ____ |

---
## Step 1 Problem Abstraction
Given N pairs of words. For each pair we select either word‑1 or word‑2 to construct using letter blocks. For each lowercase letter a‑z compute minimal total blocks we need.
For each pair: for a given character, required blocks for this pair = max(number in w1, number in w2). Sum across all pairs for final answer.
Input from file `blocks.in`; output to file `blocks.out`.

## Step 2 Algorithm Selection
Candidate1: Simulate trying both choices for every pair by brute‑force — rejected, unnecessary. Math formula `max` directly gives minimal required count.
Candidate2: Helper function compute frequency for each word, accumulate max(c1[c],c2[c]) into answer array.
Selected algorithm: frequency counting helper function
Reason: Direct mathematical formulation; linear on total input characters.
Complexity: O(total characters).

## Step3 Logic & Data Structure Framework
Data structure:
‑ `count_letters()` helper: fill int[26] frequency array for input string
‑ `ans[26]`: accumulate total block requirement for each letter

Pseudocode:
open fin("blocks.in"), fout("blocks.out")
read N
initialize ans array all zero
for i from 0 to N‑1:
    read w1, w2
    count_letters(w1, c1)
    count_letters(w2, c2)
    for c in 0..25:
        ans[c] = ans[c] + max(c1[c], c2[c])
for each letter 0..25:
    fout << ans[c] << endl
close fin, fout

## Step4 Boundary & Fault Tolerance Modeling
Pre‑predicted edge cases:
1. Letter does not appear in either word → max(0,0), add zero.
2. Letter appears only in w1 or only in w2: take the non‑zero count.
3. Helper function must reset counts array to zero for every new string, otherwise old data pollutes result.
4. Trap: use `c1[c]+c2[c]` instead of max(c1[c],c2[c]) (serious model error).
5. USACO file‑IO trap: accidentally use cin/cout instead of fin/fout, judge will give wrong answer.

## Step5 Verification & Reflection Modeling
Test official sample and edge‑case groups: letters missing from one/both words.
Classify bug type: ____ (A/B/C/D) — fill after real testing.
Evaluate 5‑step workflow(v1.0): Step1 abstraction critical for understanding take max instead of sum; Step4 highlights file‑IO and helper‑array initialization traps.
Did the process catch errors early? ____

---
## Review after solving all problems
Compare predicted edge cases and real bugs: ____
Did the 5‑step modeling process help catch errors in advance? ____
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today): ____

## Quick Reflection
Which step was hardest today: ____

## Tomorrow's Simple Plan
Week6 continue, move to DFS / backtracking exercises; focus on visited‑array reset and recursion state management; keep v1.0 workflow and bug‑timing recording.

✅ Checklist
- [x] New problem markdown added to /problems
- [x] Source code added to /solutions
- [x] This daily log saved
- [x] Git commit completed
