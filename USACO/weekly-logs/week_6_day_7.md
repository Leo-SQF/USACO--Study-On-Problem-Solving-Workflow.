# Daily Experiment Log
Week 6 / Day 7
Date: ____ (YYYY‑MM‑DD)
Active modeling version: v1.0
Today's Experiment Objective: Month2 Week7 final day; event‑driven simulation with min‑heap scheduling. Simulate cow eating, select waiting cow with smallest original id, compute maximum wait time. Continue baseline timing & bug‑classification data collection.
Pre‑set hypothesis: Sort cows on arrival time. Use min‑id priority queue for cows that have arrived and are waiting. When queue empty jump simulation clock to next cow arrival time. Time variables must use long long. Outer loop runs while there are unprocessed cows OR waiting cows in heap.
Selected problems for today:
‑ USACO 2018 December Silver P2 — Convention

| Problem Link | Modeling Time | Coding Time | Debug Time | Result | Bug Type |
| ---- | ---- | ---- | ---- | ---- | ---- |
| Convention 2018 Dec Silver P2 | ____ min | ____ min | ____ min | ____ | ____ |

---
## Step 1 Problem Abstraction
N cows, each with arrival time `a`, eating duration `t`, original input id.
When multiple cows have arrived and are waiting to eat, always pick cow with smallest original id first.
Wait time = moment cow starts eating minus its arrival time.
Simulate whole process and output maximum wait time over all cows.
N ≤ 1e5, must use O(N log N) simulation.

## Step 2 Algorithm Selection
Candidate1: Naive scan all waiting cows every time — O(N²), too slow for N=1e5.
Candidate2: Sort cows by arrival time; use min‑id priority‑queue for waiting cows; simulate clock `now`.
Selected algorithm: sort + min‑heap event simulation
Reason: Heap gives O(logN) get‑min‑id. Overall O(N logN), fits constraints.
Complexity: O(N log N).

## Step3 Logic & Data Structure Framework
Data structure:
‑ `struct Cow {a, t, id}` for sorting by arrival time
‑ `info[]`: index by original id to retrieve a and t
‑ min‑heap `pq`: stores original cow id (smallest id on top)
‑ `now`: simulation clock; `max_wait`: answer

Pseudocode:
Read N
for i from 0 to N‑1:
    read a, t
    cows[i] = {a, t, id = i}
    info[i] = {a, t}
sort cows by arrival a, tie‑break id

ptr = 0
now = 0
max_wait = 0
while ptr < N OR !pq.empty():
    // add all cows that have arrived by current time now
    while ptr < N && cows[ptr].a <= now:
        pq.push(cows[ptr].id)
        ptr += 1
    if not pq.empty():
        cid = pq.top(); pq.pop()
        a = info[cid].first
        t = info[cid].second
        wait = now - a
        max_wait = max(max_wait, wait)
        now += t
    else:
        // no waiting cows, jump time to next arrival
        now = cows[ptr].a

print(max_wait)

## Step4 Boundary & Fault Tolerance Modeling
Pre‑predicted edge cases:
1. Heap empty: must jump `now` forward to next cow arrival time, do not add small delta.
2. All cows come sequentially, no waiting → max_wait = 0.
3. Many cows arrive at exactly same time.
4. All time variables need long long to avoid overflow.
5. Heap stores original input id, not sorted‑array index; info array is needed for lookup.
6. Outer‑loop condition `ptr < N || !pq.empty()`: both conditions important.

## Step5 Verification & Reflection Modeling
Test official sample; test zero‑wait case; test time‑jump empty‑heap scenario.
Classify bug type: ____ (A/B/C/D) — fill after real testing.
Evaluate 5‑step workflow(v1.0): Step2 algorithm selection critical for performance; Step4 highlights id‑mapping and long‑long traps.
Did the process catch errors early? ____

---
## Review after solving all problems
Compare predicted edge cases and real bugs: ____
Did the 5‑step modeling process help catch errors in advance? ____
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today): ____

## Quick Reflection
Which step was hardest today: ____

## Tomorrow's Simple Plan
Week6 weekend review. Aggregate Week6 timing and bug‑type statistics, complete Week6 weekly‑log final report.

✅ Checklist
- [x] New problem markdown added to /problems
- [x] Source code added to /solutions
- [x] This daily log saved
- [x] Git commit completed
