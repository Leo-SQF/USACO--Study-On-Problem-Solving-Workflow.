# Daily Experiment Log
Week 6 / Day 4
Date: ____ (YYYY‑MM‑DD)
Active modeling version: v1.0
Today's Experiment Objective: Month2 Week6 Silver‑level brute‑force simulation problem. Iterate candidate basket‑size x, simulate basket splitting, handle full baskets, partial remainders and zero‑padding. Continue baseline timing & bug‑classification data collection.
Pre‑set hypothesis: Since maximum berry count per bush ≤ 1000, brute‑force trying every possible x is feasible. For each x build basket list: full baskets first, then partial remainders, pad zeros to reach exactly k baskets. Sort descending and sum second‑half, track global maximum. Avoid x=0 to prevent division‑by‑zero.
Selected problems for today:
‑ USACO 2020 January Silver P2 — Berry Picking

| Problem Link | Modeling Time | Coding Time | Debug Time | Result | Bug Type |
| ---- | ---- | ---- | ---- | ---- | ---- |
| Berry Picking 2020 Jan Silver P2 | ____ min | ____ min | ____ min | ____ | ____ |

---
## Step 1 Problem Abstraction
Given n bushes each with B[i] berries, total k baskets. We pick a basket size x.
Each bush b: split into full baskets of x berries, leftover remainder r = b % x (only kept if r>0).
Collect full baskets first, then add leftover remainders until we have k baskets; add baskets of zero berries if still short.
Sort all k baskets from largest to smallest. Sum baskets starting at index `k/2` to end.
We test every possible x value 1…maxb, find the maximum possible sum.

## Step 2 Algorithm Selection
Candidate1: Try to derive direct math formula for optimal x — rejected; complex interaction between full baskets and remainders.
Candidate2: Brute‑force enumerate all feasible x, simulate basket construction for each x.
Selected algorithm: brute‑force x iteration + simulation + sort‑sum evaluation
Reason: max(B) ≤1000; total iterations small, simulation straightforward.
Complexity: O(maxb * (work per x)).

## Step3 Logic & Data Structure Framework
Data structure:
‑ `vector<int> B`: berries per bush
‑ `vector<int> bask`: finished baskets
‑ `vector<int> rems`: partial remainders

Pseudocode:
Read n, k
Read array B
maxb = max element in B
half = k / 2
ans = 0
for x from 1 to maxb:
    bask.clear()
    rems.clear()
    for each b in B:
        full = b / x
        for i in 0..full‑1:
            bask.push_back(x)
        r = b % x
        if r > 0:
            rems.push_back(r)
    // fill remainders until k baskets
    p = 0
    while bask.size() < k && p < rems.size():
        bask.push_back(rems[p])
        p +=1
    // pad zero if still not reach k
    while bask.size() < k:
        bask.push_back(0)
    // sort descending
    sort(bask.rbegin(), bask.rend())
    sum = 0
    for i from half to k‑1:
        sum += bask[i]
    ans = max(ans, sum)
print ans

## Step4 Boundary & Fault Tolerance Modeling
Pre‑predicted edge cases:
1. x starts at 1, x=0 would cause division‑by‑zero.
2. full baskets count already >=k: remainders are never used.
3. After using all remainders we still need more baskets: pad zero‑berry baskets.
4. Remainder r=0 must NOT be added to rems list.
5. `half = k/2` integer division works for both odd and even k.
6. Sort in descending order, ascending gives wrong sum.

## Step5 Verification & Reflection Modeling
Test official sample, test full‑basket overflow case, zero‑padding case.
Classify bug type: ____ (A/B/C/D) — fill after real testing.
Evaluate 5‑step workflow(v1.0): Step1 careful reading of basket assembly order(full first then remainders) is critical; Step4 catches division‑by‑zero and sorting‑order traps.
Did the process catch errors early? ____

---
## Review after solving all problems
Compare predicted edge cases and real bugs: ____
Did the 5‑step modeling process help catch errors in advance? ____
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today): ____

## Quick Reflection
Which step was hardest today: ____

## Tomorrow's Simple Plan
Week6 continue Silver‑level practice; keep v1.0 workflow, continue recording timing and bug classification.

✅ Checklist
- [x] New problem markdown added to /problems
- [x] Source code added to /solutions
- [x] This daily log saved
- [x] Git commit completed
