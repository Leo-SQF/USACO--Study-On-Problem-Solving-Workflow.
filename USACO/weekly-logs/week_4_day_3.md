# Daily Experiment Log
Week 4 / Day 3
Date: 2026-10-25 (YYYY-MM-DD)
Active modeling version: v0.0
Today's Experiment Objective: Event-based collision simulation; learn to avoid naive grid simulation for huge coordinates; identify pairwise collision events and process chronologically. Continue baseline bug collection.
Pre-set hypothesis: We cannot simulate each step because coordinates up to 1e9. We need to calculate collision times mathematically and process events in order of time.
Selected problems for today:
- USACO Bronze Grazing Collision (Crossing Paths)

| Problem Link | Modeling Time | Coding Time | Debug Time | Result | Bug Type |
| ---- | ---- | ---- | ---- | ---- | ---- |
| Grazing Collision | ____ min | ____ min | ____ min | ____ | ____ |

---
## Step 1 Problem Abstraction
N cows on infinite grid, each moving E or N.
Each hour: check if current cell grass is eaten; if yes stop, else eat and move forward.
Exception: two cows arriving at same cell at the same time do NOT block each other.
We need the grass count for each cow, or Infinity if never blocked.
Constraints N ≤ 50, coordinates up to 1e9, so brute force grid simulation is impossible.

## Step 2 Algorithm Selection
Candidate1: Simulate every time step on grid — rejected, coordinates up to 1e9, impossible to store grid.
Candidate2: Enumerate all E-N cow pairs, compute intersection and arrival time for each pair, generate collision events. Sort events from earliest to latest. Process events only when both cows are still active (not blocked earlier).
Selected algorithm: Event-driven simulation with pairwise collision math
Reason: Only E-N pairs can cross. N is small (50 → at most 50*50=2500 pairs). Sort events is cheap.
Complexity: O(N² log(N²)) = O(N² log N)

## Step3 Logic & Data Structure Framework
Data structure:
1. Cow array: dir, x, y, block_time (initialize to INF)
2. Event list: (collision_time, blocker_cow_idx, victim_cow_idx)
Pseudocode:
1. Iterate all pairs of E cow and N cow
   a. Compute intersection (xn, ye)
   b. Compute t_e = xn - xe; t_n = ye - yn
   c. If t_e>0 and t_n>0:
      - if t_e < t_n: event at t_n: N cow is blocked by E cow
      - if t_n < t_e: event at t_e: E cow is blocked by N cow
      - equal: skip, no block
2. Sort all events ascending by collision time
3. Iterate sorted events:
   a. If victim already blocked → skip
   b. If blocker is blocked before this event time → skip
   c. Set victim.block_time = this event time
4. Output: if cow.block_time is INF → Infinity else block_time

## Step4 Boundary & Fault Tolerance Modeling
Pre-predicted edge cases:
1. Two cows arrive at intersection exactly same time: no blocking
2. A cow is blocked by another event before it can reach this intersection → ignore this later event
3. Multiple possible collisions for one cow: only the earliest valid collision matters
4. Only E & N pairs can intersect; E-E or N-N cows never cross
5. Very large coordinates: all calculations use 64-bit integer to avoid overflow
6. Starting positions guarantee unique x and unique y, but we still validate t_e, t_n positive

## Step5 Verification & Reflection Modeling
Test sample input:
6
E 3 5
N 5 3
E 4 6
E 10 4
N 11 2
N 8 1
Expected sample output:
5
3
Infinity
Infinity
2
5
Classify bug type: ____ (A/B/C/D) — fill after real testing.
Evaluate 5-step workflow: Step 2 was the key leap — realizing we can’t simulate grid and must switch to event math.
Did the process catch errors early? ____

---
## Review after solving all problems
Compare predicted edge cases and real bugs: ____
Did the 5-step modeling process help catch errors in advance? ____
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today): ____

## Quick Reflection
Which step was hardest today: ____

## Tomorrow's Simple Plan
Continue Week4 Bronze problems, stick to v0.0, track bug types, focus on event ordering and validity checks.

✅ Checklist
- [x] New problem markdown added to /problems
- [x] Source code added to /solutions
- [x] This daily log saved
- [x] Git commit completed
