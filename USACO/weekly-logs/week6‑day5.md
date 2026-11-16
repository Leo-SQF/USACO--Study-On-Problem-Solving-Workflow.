# Daily Experiment Log
Week 6 / Day 5
Date: ____ (YYYY‑MM‑DD)
Active modeling version: v1.0
Today's Experiment Objective: Month2 Week6 Silver classic greedy two‑pointer problem. Understand optimal card‑matching greedy logic. Continue baseline timing & bug‑classification data collection.
Pre‑set hypothesis: After sorting both players’ cards ascending. Use smallest possible Bessie card that can beat Elsie’s current smallest card to get a point; otherwise discard that useless Bessie card. This greedy strategy produces maximum score.
Selected problems for today:
‑ USACO 2015 December Silver P2 — High Card

| Problem Link | Modeling Time | Coding Time | Debug Time | Result | Bug Type |
| ---- | ---- | ---- | ---- | ---- | ---- |
| High Card 2015 Dec Silver P2 | ____ min | ____ min | ____ min | ____ | ____ |

---
## Step 1 Problem Abstraction
Pool of integers `1 … 2n`. Elsie takes n unique cards; Bessie receives the leftover n cards.
In each round each plays one card. Bessie gets one point if her card value > Elsie’s card.
Compute maximum score Bessie can obtain with optimal card‑selection strategy.

## Step 2 Algorithm Selection
Candidate1: Permutation / brute‑force try all matchings — rejected, n up to 5e4 impossible.
Candidate2: Greedy two‑pointer after sorting both sequences.
Selected algorithm: sort + two‑pointer greedy matching
Reason: This classic greedy strategy provably yields maximum wins, O(n log n) suitable for n up to 50 000.
Complexity: O(n log n).

## Step3 Logic & Data Structure Framework
Data structure:
‑ `vector<bool> has(2*n+1)` mark Elsie’s numbers
‑ `elsie`: Elsie’s card list
‑ `bessie`: Bessie’s card list
‑ pointers `e_ptr, b_ptr`, score counter

Pseudocode:
Read n
fill has array false
read n elsie numbers, fill elsie vector, mark has[x]=true
// build Bessie’s list
for i from 1 to 2*n:
    if not has[i]:
        bessie.push_back(i)
sort(elsie.begin(), elsie.end())
sort(bessie.begin(), bessie.end())

e_ptr = 0, b_ptr = 0
score = 0
while e_ptr < n && b_ptr < n:
    if bessie[b_ptr] > elsie[e_ptr]:
        score += 1
        e_ptr += 1
        b_ptr += 1
    else:
        b_ptr +=1
print(score)

## Step4 Boundary & Fault Tolerance Modeling
Pre‑predicted edge cases:
1. All Bessie cards smaller: score = 0.
2. All Bessie cards larger: score = n.
3. Array size for `has`: need 2n+1, avoid out‑of‑bounds access.
4. Must sort **both** sequences ascending before two‑pointer loop.
5. Condition strictly greater `>`, not `>=`.

## Step5 Verification & Reflection Modeling
Test official sample; zero‑score and full‑score edge‑case groups.
Classify bug type: ____ (A/B/C/D) — fill after real testing.
Evaluate 5‑step workflow(v1.0): Step2 is key — understand why this greedy strategy is optimal. Step4 highlights sorting and array‑size trap.
Did the process catch errors early? ____

---
## Review after solving all problems
Compare predicted edge cases and real bugs: ____
Did the 5‑step modeling process help catch errors in advance? ____
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today): ____

## Quick Reflection
Which step was hardest today: ____

## Tomorrow's Simple Plan
Week6 Silver practice continues, keep v1.0 workflow, record timing and bug metrics.

✅ Checklist
- [x] New problem markdown added to /problems
- [x] Source code added to /solutions
- [x] This daily log saved
- [x] Git commit completed
