# Daily Experiment Log
Week 6 / Day 8
Date: ____ (YYYY‑MM‑DD)
Active modeling version: v1.0
Today's Experiment Objective: Month2 Week6 Silver problem; generate geometric blocking‑events for moving cows, simulate events in chronological order, build directed graph and use BFS to count reachable victims. Continue baseline timing & bug‑classification data collection.
Pre‑set hypothesis: Only E‑N mixed pairs can block each other. Generate candidate blocking events for valid forward intersection. Sort events by time. Skip event if either participant is already stopped. Build directed blocker‑to‑victim edges. BFS from each cow to count total cows it stops. Use long long for position and time.
Selected problems for today:
‑ USACO 2020 December Silver P3 — Stuck in a Rut

| Problem Link | Modeling Time | Coding Time | Debug Time | Result | Bug Type |
| ---- | ---- | ---- | ---- | ---- | ---- |
| Stuck in a Rut 2020 Dec Silver P3 | ____ min | ____ min | ____ min | ____ | ____ |

---
## Step 1 Problem Abstraction
N cows move either East(increasing x) or North(increasing y) at equal speed on infinite plane.
Only an East‑moving and a North‑moving cow can potentially block each other.
Compute intersection point. If intersection is behind a cow’s starting point: no interaction.
Compare arrival times to intersection:
- If E arrives earlier: North cow will get blocked at its arrival time.
- If N arrives earlier: East cow will get blocked at its arrival time.
- Equal arrival time: pass through point together; no blocking.

Collect all candidate blocking events, sort by time. Process events from earliest to latest. If blocker or victim already stopped, discard event. When block occurs add directed edge blocker → victim.
For each cow, count total number of cows reachable via this directed graph (all cows it directly or indirectly caused to stop). Output each count.

## Step 2 Algorithm Selection
Candidate1: Continuous time‑step simulation — rejected, coordinates can be huge, cannot step through time.
Candidate2: Generate all pairwise candidate blocking‑events, sort by time, discrete event‑driven simulation, then BFS reachability.
Selected algorithm: pairwise event generation + sorted discrete‑event simulation + BFS
Reason: N ≤ 50, O(N²) event generation is trivial. Discrete event simulation avoids iterating over huge coordinate values.
Complexity: O(N² + N*(N+E)).

## Step3 Logic & Data Structure Framework
Data structure:
‑ `Cow struct`: direction, x, y, id
‑ `Event struct`: t (event time), blocker id, victim id; sort comparator by t
‑ `stopped[]`: boolean whether cow has been stopped
‑ adjacency list `g[]`: directed graph blocker → victim
‑ queue for BFS, vis array for reachability counting

Pseudocode:
Read N
Read N cows, assign id 0…N‑1
Initialize empty events vector
for i from 0 to N‑1:
    for j from i+1 to N‑1:
        a = cow[i], b = cow[j]
        if a.dir == b.dir: continue
        // separate E‑cow and N‑cow
        if a.dir == 'E':
            E = a; ei = i
            N = b; ni = j
        else:
            E = b; ei = j
            N = a; ni = i
        ix = N.x
        iy = E.y
        // intersection must lie forward for both cows
        if ix <= E.x || iy <= N.y:
            continue
        te = ix - E.x
        tn = iy - N.y
        if te < tn:
            // East arrives first, North cow(ni) gets blocked
            events.emplace_back(tn, ei, ni)
        elif tn < te:
            // North arrives first, East cow(ei) gets blocked
            events.emplace_back(te, ni, ei)
        // te == tn: no event, do nothing

sort events by t ascending
fill stopped array with false
initialize adjacency list g empty
for each event in sorted events:
    b = event.blocker
    v = event.victim
    if stopped[b] || stopped[v]:
        continue
    stopped[v] = true
    g[b].push_back(v)

// BFS for each cow count reachable victims
for i from 0 to N‑1:
    vis array reset false
    queue q
    q.push(i)
    vis[i]=true
    cnt = 0
    while q not empty:
        u = q.front(); q.pop()
        for nxt in g[u]:
            if not vis[nxt]:
                vis[nxt]=true
                cnt +=1
                q.push(nxt)
    print(cnt)

## Step4 Boundary & Fault Tolerance Modeling
Pre‑predicted edge cases:
1. Same‑direction cows: skip pair immediately.
2. Intersection point lies behind starting position of E or N cow: discard candidate event.
3. te == tn arrival time equal: no blocking event generated.
4. Either blocker or victim is already stopped when event comes up: skip event.
5. Chain blocking: A blocks B, B blocks C. BFS must count both B and C for source A.
6. All position and time variables must use long long to avoid overflow.

## Step5 Verification & Reflection Modeling
Test official sample input; test equal arrival‑time; intersection behind start; multi‑step blocking‑chain.
Classify bug type: ____ (A/B/C/D) — fill after real testing.
Evaluate 5‑step workflow(v1.0): Step1 geometric rules are critical; Step4 catches multiple geometric and simulation traps.
Did the process catch errors early? ____

---
## Review after solving all problems
Compare predicted edge cases and real bugs: ____
Did the 5‑step modeling process help catch errors in advance? ____
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today): ____

## Quick Reflection
Which step was hardest today: ____

## Tomorrow's Simple Plan
Week6 complete. Finalize Week6 weekly‑log report, aggregate all timing and bug statistics.

✅ Checklist
- [x] New problem markdown added to /problems
- [x] Source code added to /solutions
- [x] This daily log saved
- [x] Git commit completed
