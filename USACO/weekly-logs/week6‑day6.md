# Daily Experiment Log
Week 6 / Day 6
Date: ____ (YYYY‑MM‑DD)
Active modeling version: v1.0
Today's Experiment Objective: Month2 Week6 Silver simulation problem; maintain dynamic maximum with ordered frequency map. Simulate milk‑production events, track leader‑state change count. Continue baseline timing & bug‑classification data collection.
Pre‑set hypothesis: Sort events by day. Use unordered_map to store each cow’s milk value, ordered map `freq` to count how many cows have each milk value. Compare leader state (leader_value, count_of_max) before and after each event; increment answer only when state pair changes. Remember erase freq key when frequency drops to zero. Cow default milk = G.
Selected problems for today:
‑ USACO 2017 December Silver P2 — Milk Measurement

| Problem Link | Modeling Time | Coding Time | Debug Time | Result | Bug Type |
| ---- | ---- | ---- | ---- | ---- | ---- |
| Milk Measurement 2017 Dec Silver P2 | ____ min | ____ min | ____ min | ____ | ____ |

---
## Step 1 Problem Abstraction
N events: each event happens on a certain day, modifies one cow’s milk production by delta.
Cows start with baseline milk value G.
Global leader state:
- If highest milk value among cows > G: leader = (highest_value, number_of_cows_with_this_highest_value)
- Else: leader = (G, INF) (no cow beats baseline)

Process events sorted in day order. After applying each change, if leader‑state pair changes, add one to answer. Output total number of state‑changes.
N ≤ 1e5, need O(N log N) algorithm; cannot scan all cows per‑event.

## Step 2 Algorithm Selection
Candidate1: Every event scan all cows to recompute max — rejected O(N²), too slow for N=1e5.
Candidate2: Maintain two maps: one for cow‑to‑milk‑value; ordered frequency map count how many cows have each milk‑value. Read max via map reverse‑iterator.
Selected algorithm: event‑sort + dual‑map simulation
Reason: Each modification O(logN). Ordered map `map` allows quick access to current maximum milk‑value via rbegin().
Complexity: O(N log N).

## Step3 Logic & Data Structure Framework
Data structure:
‑ `records`: tuple(day, cow_id, delta) store all events
‑ `cow_milk`: unordered_map cow_id → current milk value
‑ `freq`: ordered map<ll,int> milk_value → count of cows
‑ lambda `get_state()` return pair(leader_value, count_at_leader)

Pseudocode:
Read N, G
Read N records into vector
sort records by day
Initialize cow_milk empty; freq empty; ans=0

get_state lambda:
    if freq empty: return {G, INF}
    max_val = freq.rbegin()->first
    if max_val > G:
        return {max_val, freq[max_val]}
    else:
        return {G, INF}

for each record in sorted records:
    day, cid, delta = unpack record
    old_state = get_state()
    // get old value for this cow
    oldv = G
    if cow_milk contains cid:
        oldv = cow_milk[cid]
    // remove oldv from freq
    freq[oldv] -= 1
    if freq[oldv] == 0:
        freq.erase(oldv)
    // apply delta
    newv = oldv + delta
    cow_milk[cid] = newv
    freq[newv] += 1
    new_state = get_state()
    if old_state != new_state:
        ans += 1

print ans

## Step4 Boundary & Fault Tolerance Modeling
Pre‑predicted edge cases:
1. Cow modified for first‑time: oldv = G, not present in cow_milk map.
2. After decrement freq count reaches zero: must erase key from freq; otherwise rbegin() reads dead entry.
3. State comparison must compare **both value and count of max cows**. Same max value but different number of top cows counts as state‑change.
4. When all cows’ milk ≤ G: leader state falls back to baseline G.
5. Large cow_id and milk value, must use long long.
6. Events must be sorted by day before processing.

## Step5 Verification & Reflection Modeling
Test official sample; test first‑modification cow; test multiple‑cow‑share‑max; test max drop back ≤G.
Classify bug type: ____ (A/B/C/D) — fill after real testing.
Evaluate 5‑step workflow(v1.0): Step2 algorithm choice is critical; Step4 highlights freq‑erase trap and state‑pair comparison trap.
Did the process catch errors early? ____

---
## Review after solving all problems
Compare predicted edge cases and real bugs: ____
Did the 5‑step modeling process help catch errors in advance? ____
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today): ____

## Quick Reflection
Which step was hardest today: ____

## Tomorrow's Simple Plan
Week6 Silver practice continues; keep v1.0 workflow, keep timing‑bug logging.

✅ Checklist
- [x] New problem markdown added to /problems
- [x] Source code added to /solutions
- [x] This daily log saved
- [x] Git commit completed
