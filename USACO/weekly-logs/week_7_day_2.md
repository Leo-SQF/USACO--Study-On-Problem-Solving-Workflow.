# Daily Experiment Log
Week 7 / Day 2
Date: ____ (YYYY‑MM‑DD)
Active modeling version: v1.0
Today's Experiment Objective: Month2 Week7 practice; greedy suffix‑max problem. Understand why only suffix‑maximum stops are worth visiting. Pre‑compute suffix‑maximum then linear scan, accumulate answer. Continue baseline timing & bug‑classification data collection.
Pre‑set hypothesis: Since forward speed > backward speed, optimal plan only visits stops that are maximum enjoyment among all stops remaining ahead. Build suffix‑max array from right‑to‑left. Traverse stops left‑to‑right; whenever stop value equals suffix‑max, compute segment contribution and add to answer. All arithmetic uses long long.
Selected problems for today:
‑ USACO 2018 February Silver P1

| Problem Link | Modeling Time | Coding Time | Debug Time | Result | Bug Type |
| ---- | ---- | ---- | ---- | ---- | ---- |
| 2018 Feb Silver P1 Snow Boots Travel | ____ min | ____ min | ____ min | ____ | ____ |

---
## Step 1 Problem Abstraction
Total road length L. N scenic stops at position x with enjoyment c.
Forward speed rF is strictly larger than backward speed rB.
We start at position 0, drive toward L. We can make side‑trips backward to visit stops.
Goal: maximize total sum of (extra travel time) × (enjoyment value of visited stop).
Optimal strategy: only visit stops which have maximum enjoyment among all stops from current position onward.
Compute suffix‑max array `suf[i] = max c from i … N‑1`.
For each selected worthwhile stop i:
- dx = distance from previous worthwhile stop to current stop x.
- extra_time = dx * (rF − rB)
- add `extra_time * c` to answer.

## Step 2 Algorithm Selection
Candidate1: Dynamic programming for each stop — rejected, unnecessary; greedy suffix‑max gives optimal answer in linear time.
Candidate2: Compute suffix‑maximum array backward, then one‑pass left‑to‑right greedy accumulation.
Selected algorithm: suffix‑max pre‑compute + linear greedy scan
Reason: Problem greedy property holds; O(N) fits N up to 1e5.
Complexity: O(N).

## Step3 Logic & Data Structure Framework
Data structure:
‑ `stops`: pair<ll,ll> store (position x, enjoyment c)
‑ `suf[N+1]`: suffix‑maximum array, suf[N]=0
‑ `ans`: total answer, `last_x`: position of last worthwhile stop

Pseudocode:
Read L, N, rF, rB
Read N pairs into stops
// build suffix max from right to left
suf[N] = 0
for i from N‑1 down to 0:
    suf[i] = max(stops[i].second, suf[i+1])

ans = 0
last_x = 0
for i from 0 to N‑1:
    x = stops[i].first
    c = stops[i].second
    if c == suf[i]:
        dx = x - last_x
        extra_time = dx * (rF - rB)
        ans += extra_time * c
        last_x = x

print(ans)

## Step4 Boundary & Fault Tolerance Modeling
Pre‑predicted edge cases:
1. First stop is worthwhile: dx = x‑0.
2. Many consecutive non‑worthwhile stops get skipped.
3. Multiple stops share same suffix‑max value.
4. All variables must be long long to avoid overflow.
5. Suffix array must iterate backwards starting at N‑1.

## Step5 Verification & Reflection Modeling
Test official sample; test skipped‑stop cases.
Classify bug type: ____ (A/B/C/D) — fill after real testing.
Evaluate 5‑step workflow(v1.0): Step2 greedy justification is the key mental hurdle; Step4 highlights overflow risk for large coordinates.
Did the process catch errors early? ____

---
## Review after solving all problems
Compare predicted edge cases and real bugs: ____
Did the 5‑step modeling process help catch errors in advance? ____
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today): ____

## Quick Reflection
Which step was hardest today: ____

## Tomorrow's Simple Plan
Week7 continue DFS / backtracking‑oriented practice; keep v1.0 workflow and timing‑bug logging.

✅ Checklist
- [x] New problem markdown added to /problems
- [x] Source code added to /solutions
- [x] This daily log saved
- [x] Git commit completed
