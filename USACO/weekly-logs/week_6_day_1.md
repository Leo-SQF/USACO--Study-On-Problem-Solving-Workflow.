# Daily Experiment Log
Week 6 / Day 1
Date: ____ (YYYY‑MM‑DD)
Active modeling version: v1.0
Today's Experiment Objective: Month2 Week6 start; time‑interval frequency‑counting problem. Use v1.0 workflow. Practice half‑open interval semantics, compute effect of deleting exactly one interval by counting uniquely‑covered timestamps. Continue baseline experiment data collection.
Pre‑set hypothesis: Since time is bounded ≤1000, brute‑force count array is acceptable. When deleting interval i, only time points that **only this interval covers(count[t]==1)** get lost. Answer is `total_covered - lost_time`, take maximum over all i. Intervals are half‑open `[start, end)`.
Selected problems for today:
- USACO 2018 January Bronze P2

| Problem Link | Modeling Time | Coding Time | Debug Time | Result | Bug Type |
| ---- | ---- | ---- | ---- | ---- | ---- |
| 2018 Jan Bronze P2 Interval Remove | ____ min | ____ min | ____ min | ____ | ____ |

---
## Step 1 Problem Abstraction
Given n time intervals in half‑open format `[start, end_time)`.
`count[t]` stores how many intervals cover time t.
`total_covered` is total distinct time points covered by at least one interval.
We must delete exactly one interval. If a time point t is covered **only by this deleted interval**, t will no longer be covered.
For each interval i compute `lost_time`: number of such unique‑coverage timestamps inside interval i.
Compute `total_covered - lost_time` for every i, output maximum value.

## Step 2 Algorithm Selection
Candidate1: Difference array + scan — possible optimization, but for T=1000 not required.
Candidate2: Brute‑force fill count array by iterating every time point inside each interval.
Selected algorithm: brute‑force time‑point counting
Reason: Time upper limit small (1000). Implementation simple and direct to problem statement.
Complexity: O(n*T).

## Step3 Logic & Data Structure Framework
Data structure:
- `start[]`, `end_time[]`: store each interval’s start and end
- `count[1001]`: frequency count for each time stamp 0~1000

Pseudocode:
Read n
Read n pairs into start, end_time
Initialize count array all zero
for i from 0 to n‑1:
    t = start[i]
    while t < end_time[i]:
        count[t] += 1
        t += 1

total_covered = 0
for t from 0 to 1000:
    if count[t] > 0:
        total_covered += 1

max_covered = 0
for i from 0 to n‑1:
    lost_time = 0
    for t = start[i]; t < end_time[i]; t++:
        if count[t] == 1:
            lost_time +=1
    max_covered = max(max_covered, total_covered - lost_time)

print(max_covered)

## Step4 Boundary & Fault Tolerance Modeling
Pre‑predicted edge cases:
1. Half‑open interval trap: condition `t < end_time`, not `t <= end_time`.
2. One interval completely nested inside another: nested interval lost_time=0, removing it changes nothing.
3. Fully disjoint intervals: removing one interval loses all its time points.
4. Must remove exactly one interval, cannot skip removal.
5. All time points are covered by multiple intervals: every lost_time = 0, answer = total_covered.

## Step5 Verification & Reflection Modeling
Test official sample and edge‑case groups: nested intervals, disjoint intervals.
Classify bug type: ____ (A/B/C/D) — fill after real testing.
Evaluate 5‑step workflow(v1.0): Step1 abstraction important to understand half‑open interval and definition of lost_time. Step4 highlights off‑by‑one risk on interval boundaries.
Did the process catch errors early? ____

---
## Review after solving all problems
Compare predicted edge cases and real bugs: ____
Did the 5‑step modeling process help catch errors in advance? ____
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today): ____

## Quick Reflection
Which step was hardest today: ____

## Tomorrow's Simple Plan
Week6 continue, move to DFS / backtracking problems, keep methodology v1.0; pay attention to visited‑array reset and recursion state management.

✅ Checklist
- [x] New problem markdown added to /problems
- [x] Source code added to /solutions
- [x] This daily log saved
- [x] Git commit completed
