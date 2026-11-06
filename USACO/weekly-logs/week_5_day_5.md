# Daily Experiment Log
Week 5 / Day 6
Date: 2026-11-6(YYYY‑MM‑DD)
Active modeling version: v1.0
Today's Experiment Objective: Month2 Week5 practice; bus‑route condition‑check brute‑force problem. Use v1.0 modeling workflow. Emphasize logical condition "A occurs before B", distinguish from “A and B both exist”. Continue collecting timing and bug‑classification experimental data.
Pre‑set hypothesis: Only single bus routes can be used (no transfers). A route is valid only when scanning left‑to‑right we first encounter A, then later encounter B. Keep track minimal cost; if no valid route exists output -1.
Selected problems for today:
- USACO 2015 January Bronze P4 — Cow Route

| Problem Link | Modeling Time | Coding Time | Debug Time | Result | Bug Type |
| ---- | ---- | ---- | ---- | ---- | ---- |
| Cow Route 2015 Jan Bronze P4 | ____ min | ____ min | ____ min | ____ | ____ |

---
## Step 1 Problem Abstraction
Given start city A, destination city B, total N bus routes.
Each bus route has a cost and ordered list of visited cities.
Route is valid: in its city sequence, city A appears at some position, and city B appears **after** A. Transfers between different bus routes are NOT allowed; we can take exactly one bus.
Find minimal cost among all valid routes. If there is no valid bus route output -1.

## Step 2 Algorithm Selection
Candidate1: Build graph and run Dijkstra shortest‑path — rejected. Problem forbids transfers; we only evaluate each original route directly, full graph algorithm is overkill.
Candidate2: Iterate every bus route, scan city list sequentially, judge whether A occurs before B. Keep minimal valid cost.
Selected algorithm: brute‑force per‑route sequential scan
Reason: Constraints are small; problem rule prohibits bus transfer, so we do not need general shortest‑path.
Complexity: O(N*m).

## Step3 Logic & Data Structure Framework
Data structure:
- `vector<int> cities`: store city list for current bus route
- boolean `foundA`, `valid`
- `ans = INT_MAX`: sentinel for minimal cost

Pseudocode:
Read A, B, N
ans = INT_MAX
for i from 0 to N‑1:
    read cost, m
    read m cities into vector cities
    foundA = false
    valid = false
    for each city in cities:
        if city == A:
            foundA = true
        if foundA && city == B:
            valid = true
            break
    if valid:
        if cost < ans:
            ans = cost
if ans == INT_MAX:
    print(-1)
else:
    print(ans)

## Step4 Boundary & Fault Tolerance Modeling
Pre‑predicted edge cases:
1. B appears earlier than A in city list → route invalid, even‑though both cities exist.
2. A present, B missing in route → invalid.
3. B present, A missing in route → invalid.
4. A and B are consecutive in correct order A then B → valid.
5. No valid routes at all: ans remains INT_MAX → output -1.
6. Trap: mis‑read problem and allow bus transfers (this is a model‑error risk).

## Step5 Verification & Reflection Modeling
Test official sample and edge‑case groups: B before‑A case, no‑valid‑route case, consecutive A‑B case.
Classify bug type: ____ (A/B/C/D) — fill after real testing.
Evaluate 5‑step workflow(v1.0): Step1 abstraction critical to capture “no transfer” and “A‑before‑B” logic; Step4 lists the common misinterpretation traps.
Did the process catch errors early? ____

---
## Review after solving all problems
Compare predicted edge cases and real bugs: ____
Did the 5‑step modeling process help catch errors in advance? ____
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today): ____

## Quick Reflection
Which step was hardest today: ____

## Tomorrow's Simple Plan
Week5 continue; practice simple DFS / recursion problems, keep methodology v1.0, record timing and bug metrics.

✅ Checklist
- [x] New problem markdown added to /problems
- [x] Source code added to /solutions
- [x] This daily log saved
- [x] Git commit completed
