# Daily Experiment Log
Week 5 / Day 3
Date: ____ (YYYY‑MM‑DD)
Active modeling version: v1.0
Today's Experiment Objective: Month2 Week5 practice; custom alphabet order mapping problem. Use v1.0 modeling workflow; practice mapping characters to rank index, carefully judge boolean trigger condition. Continue collecting experiment timing and bug‑classification data.
Pre‑set hypothesis: By building pos[] mapping for custom alphabet rank, we only need one linear pass over hear string. Each time current character rank ≤ previous rank we need an additional copy of cow string; initial answer starts at one copy.
Selected problems for today:
- USACO 2021 January Bronze P1 — Uddered but not Herd

| Problem Link | Modeling Time | Coding Time | Debug Time | Result | Bug Type |
| ---- | ---- | ---- | ---- | ---- | ---- |
| Uddered but not Herd 2021 Jan Bronze P1 | ____ min | ____ min | ____ min | ____ | ____ |

---
## Step 1 Problem Abstraction
Input a 26‑character permutation of lowercase letters `cow`, defines a special reading order.
Given string `hear`. We read characters from hear. Whenever next character does not appear later than previous character inside cow order, we have to start another full copy of cow string.
Count total number of cow copies needed.

## Step 2 Algorithm Selection
Candidate1: Search cow string for each character every time when comparing — rejected, repeated string search wastes time.
Candidate2: Pre‑compute pos array mapping each letter to its index inside cow, then one‑pass scan hear.
Selected algorithm: character‑rank mapping + linear scan
Reason: Pre‑compute position mapping O(26), then process hear in linear time, simple and efficient.
Complexity: O(len(hear)).

## Step3 Logic & Data Structure Framework
Data structure:
- `string cow, hear`
- `int pos[26]`: store index position for each character in cow custom order

Pseudocode:
Read cow string
for i from 0 to 25:
    pos[cow[i] - 'a'] = i
Read hear string
ans = 1
len = hear.size()
for i from 1 to len‑1:
    prev_rank = pos[ hear[i‑1] - 'a' ]
    curr_rank = pos[ hear[i]   - 'a' ]
    if curr_rank <= prev_rank:
        ans = ans + 1
print ans

## Step4 Boundary & Fault Tolerance Modeling
Pre‑predicted edge cases:
1. hear length = 1, output ans=1.
2. Two identical consecutive characters: curr_rank == prev_rank → trigger new copy.
3. All characters in hear strictly follow cow custom order: ans keeps 1.
4. Every adjacent pair triggers reset: ans equals hear length.
5. Logical trap: write condition `curr_rank < prev_rank` forgetting `=` equal case.

## Step5 Verification & Reflection Modeling
Test official sample input and above edge‑case groups.
Classify bug type: ____ (A/B/C/D) — fill after real testing.
Evaluate 5‑step workflow(v1.0): Step1 abstraction critical to correctly understand when to add new copy; Step4 points out the `<=` easy‑to‑miss condition trap.
Did the process catch errors early? ____

---
## Review after solving all problems
Compare predicted edge cases and real bugs: ____
Did the 5‑step modeling process help catch errors in advance? ____
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today): ____

## Quick Reflection
Which step was hardest today: ____

## Tomorrow's Simple Plan
Week5 continue, move toward simple DFS / recursion problems, keep methodology v1.0, record timing and bug metrics.

✅ Checklist
- [x] New problem markdown added to /problems
- [x] Source code added to /solutions
- [x] This daily log saved
- [x] Git commit completed
