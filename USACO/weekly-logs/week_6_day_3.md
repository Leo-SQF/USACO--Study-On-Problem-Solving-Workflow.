# Daily Experiment Log
Week 6 / Day 3
Date: ____ (YYYY‑MM‑DD)
Active modeling version: v1.0
Today's Experiment Objective: Month2 Week6 Silver entry‑level problem. Enumerate x‑axis boundaries, maintain sorted y‑list, binary‑search count y‑positions. Practice O(N² logN) thinking, avoid O(N⁴) brute four‑corner enumeration. Continue collect timing & bug‑classification baseline data.
Pre‑set hypothesis: Sort cows on x. For every left‑right x pair, keep ys sorted. Use lower_bound to count points below yL and above yH; product gives valid y‑bound combinations. Add single‑point rectangles, final +1 for empty rectangle. Must use long long for answer.
Selected problems for today:
‑ USACO 2020 December Silver P2 — Rectangular Pasture

| Problem Link | Modeling Time | Coding Time | Debug Time | Result | Bug Type |
| ---- | ---- | ---- | ---- | ---- | ---- |
| Rectangular Pasture 2020 Dec Silver P2 | ____ min | ____ min | ____ min | ____ | ____ |

---
## Step 1 Problem Abstraction
Given N distinct cow points on 2‑D plane.
Count all axis‑aligned rectangles satisfying:
1. At least two corners are given cow points (also count single‑point “rectangle”, plus empty rectangle).
2. No cows lie strictly inside rectangle interior (cows are allowed to lie exactly on rectangle edges).

N ≤ 250. Output total number of such rectangles.

## Step 2 Algorithm Selection
Candidate1: Enumerate all four corners brute‑force O(N⁴) — rejected, far too slow.
Candidate2: Fix left‑right x boundaries by enumerating sorted‑x cow pairs, dynamically maintain sorted y‑coordinates, binary‑search count available y‑range candidates.
Selected algorithm: sort x; left‑right double loop; maintain sorted ys vector + lower_bound binary search
Reason: Reduce complexity down O(N² logN), fits N=250 constraints.
Complexity: O(N² logN).

## Step3 Logic & Data Structure Framework
Data structure:
‑ `struct Cow {x,y}` with operator< sort by x
‑ `vector<Cow> cow` store points
‑ `vector<int> ys`: keep y‑values inside current left‑right x‑range sorted ascending
‑ `long long ans` accumulator

Pseudocode:
Read N
read N cows(x,y)
sort cows by x
ans = 0
for left from 0 to N‑1:
    clear ys
    for right from left to N‑1:
        // insert cow[right].y into sorted ys
        it = lower_bound(ys.begin(), ys.end(), cow[right].y);
        ys.insert(it, cow[right].y);
        if left == right:
            ans += 1
        else:
            yL = min(cow[left].y, cow[right].y);
            yH = max(cow[left].y, cow[right].y);
            below = lower_bound(ys.begin(), ys.end(), yL+1) - ys.begin();
            above = ys.end() - lower_bound(ys.begin(), ys.end(), yH);
            ans += below * above;
// empty rectangle
ans += 1
print ans

## Step4 Boundary & Fault Tolerance Modeling
Pre‑predicted edge cases:
1. N=1 single cow: count point rectangle plus empty rectangle.
2. `below` strictly less than yL; `above` strictly greater than yH. Use yL+1 in lower_bound to enforce strictly‑less.
3. Overflow risk: ans must be long long.
4. left==right single‑point case must add one.
5. Final ans +=1 for empty rectangle is easy‑to‑miss correction.
6. Insert into ys must maintain sorted order via lower_bound.

## Step5 Verification & Reflection Modeling
Test official sample and N=1 minimal case.
Classify bug type: ____ (A/B/C/D) — fill after real testing.
Evaluate 5‑step workflow(v1.0): Step2 algorithm selection critical, reject O(N⁴); Step4 points out long‑long and empty‑rectangle correction trap.
Did the process catch errors early? ____

---
## Review after solving all problems
Compare predicted edge cases and real bugs: ____
Did the 5‑step modeling process help catch errors in advance? ____
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today): ____

## Quick Reflection
Which step was hardest today: ____

## Tomorrow's Simple Plan
Week6 continue; keep v1.0 workflow, prepare for more Silver‑level enumeration / prefix‑sum problems, keep timing‑bug logging.

✅ Checklist
- [x] New problem markdown added to /problems
- [x] Source code added to /solutions
- [x] This daily log saved
- [x] Git commit completed
