# Daily Experiment Log
Week 7 / Day 3
Date: ____ (YYYY‑MM‑DD)
Active modeling version: v1.0
Today's Experiment Objective: Month2 Week7 practice; classic line‑sweep interval problem. Compute total covered time and per‑guard uniquely‑covered time; find best single‑guard to delete. Continue baseline timing & bug‑classification data collection.
Pre‑set hypothesis: Sweep‑line over interval start/end events. Between two event timestamps, if exactly one guard active add duration to that guard’s lost time. Answer = total_covered_time − min(lost[i]). Use special encoding for end events. All time variables long long.
Selected problems for today:
‑ USACO 2018 January Silver P1 — Monitoring

| Problem Link | Modeling Time | Coding Time | Debug Time | Result | Bug Type |
| ---- | ---- | ---- | ---- | ---- | ---- |
| Monitoring 2018 Jan Silver P1 | ____ min | ____ min | ____ min | ____ | ____ |

---
## Step 1 Problem Abstraction
N guards each have working interval `[s, e]`.
Total covered time: total length of time covered by at least one guard.
`lost[i]`: amount of time where guard i is the **only active guard**.
If we remove guard i, we lose exactly `lost[i]` from total covered time.
We must delete exactly one guard; maximize remaining coverage = `total − min(lost[i])`.

## Step 2 Algorithm Selection
Candidate1: Brute‑force remove each guard then recompute coverage — O(N² log N), works but redundant recomputation.
Candidate2: Single‑pass line‑sweep: compute total and all lost[i] in one sweep.
Selected algorithm: line‑sweep event scan
Reason: One pass computes everything we need. N ≤250, O(N²) from vector erase is acceptable.
Complexity: O(N²).

## Step3 Logic & Data Structure Framework
Data structure:
‑ `guard`: store each guard interval (s,e)
‑ `events`: pair(time, encoded_id). start: (s,i); end: (e, -i‑1)
‑ `active`: vector of ids of currently working guards
‑ `lost[]`: unique‑only time for each guard
‑ `total`: overall covered time

Pseudocode:
Read N
for i in 0..N‑1:
    read s, e
    guard[i] = {s,e}
    events.emplace_back(s, i)
    events.emplace_back(e, -i‑1)

sort events by time
total = 0
fill lost array with 0
prev_t = -1
cnt = 0
active empty

for each ev in events:
    t = ev.first
    id = ev.second
    if prev_t != -1 and t > prev_t and cnt > 0:
        delta = t - prev_t
        total += delta
        if cnt == 1:
            only_id = active[0]
            lost[only_id] += delta
    // process this event
    if id >= 0:
        active.push_back(id)
        cnt += 1
    else:
        rid = -id - 1
        // find & erase rid from active
        for it = active.begin(); it != active.end(); ++it:
            if *it == rid:
                active.erase(it)
                break
        cnt -= 1
    prev_t = t

min_lost = min element in lost
print(total - min_lost)

## Step4 Boundary & Fault Tolerance Modeling
Pre‑predicted edge cases:
1. Guard i has lost[i]=0 (never the sole active guard; removing it does nothing to total coverage).
2. Multiple events share same timestamp; delta = 0 so no contribution to total/lost.
3. Initial prev_t = -1: skip time calculation for very first event segment.
4. End‑event encoding: `-i‑1` decoding must be correct.
5. All time variables need long long to avoid overflow.
6. Time‑delta calculation happens **before** applying the current event.

## Step5 Verification & Reflection Modeling
Test official sample; test guard with zero lost time; test equal‑timestamp events.
Classify bug type: ____ (A/B/C/D) — fill after real testing.
Evaluate 5‑step workflow(v1.0): Step1 abstraction key: understand `lost[i]` definition; Step4 highlights event‑order and encoding traps.
Did the process catch errors early? ____

---
## Review after solving all problems
Compare predicted edge cases and real bugs: ____
Did the 5‑step modeling process help catch errors in advance? ____
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today): ____

## Quick Reflection
Which step was hardest today: ____

## Tomorrow's Simple Plan
Week7 continue practice; keep v1.0 workflow, keep timing‑bug logging.

✅ Checklist
- [x] New problem markdown added to /problems
- [x] Source code added to /solutions
- [x] This daily log saved
- [x] Git commit completed
