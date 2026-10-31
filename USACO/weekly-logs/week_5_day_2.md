# Daily Experiment Log
Week 5 / Day 2
Date: 2026-10-31 (YYYY‑MM‑DD)
Active modeling version: v1.0
Today's Experiment Objective: Month2 Week5 practice; same‑direction two‑pointer sliding‑window algorithm. Test v1.0 modeling workflow; learn condition difference between while / if for window shrinking; record boundary and overflow risks. Continue experiment baseline data collection.
Pre‑set hypothesis: Because all array elements are positive, sum is monotonic; left pointer only moves forward, O(n) two‑pointer algorithm is valid. Must use while to shrink window, single if is insufficient.
Selected problems for today:
- Same‑Direction Two‑Pointers Practice (Sliding Window)

| Problem Link | Modeling Time | Coding Time | Debug Time | Result | Bug Type |
| ---- | ---- | ---- | ---- | ---- | ---- |
| Same‑Direction Two‑Pointers Practice | ____ min | ____ min | ____ min | ____ | ____ |

---
## Step 1 Problem Abstraction
Given n positive integers stored in 1‑based array.
We need to find maximum length of contiguous subarray such that sum of elements ≤10.
Elements are guaranteed positive, sum variable need 64‑bit integer to avoid overflow.

## Step 2 Algorithm Selection
Candidate1: Brute‑force enumerate all subarrays, compute sum — rejected O(n²), inefficient for larger n.
Candidate2: Two‑pointer sliding‑window(same direction).
Selected algorithm: same‑direction two‑pointers sliding window
Reason: Positive elements give monotonic sum; left pointer never goes backward, overall linear complexity O(n).
Complexity: O(n).

## Step3 Logic & Data Structure Framework
Data structure:
- `vector<int> num_input(n+1,0)` 1‑based storage
- left pointer start at 1
- `long long sum = 0` accumulate window sum
- `maxlen` store answer

Pseudocode:
Read n
for i from 1 to n:
    read num_input[i]
left = 1
sum = 0
maxlen = 0
for right from 1 to n:
    sum += num_input[right]
    while sum > 10:
        sum -= num_input[left]
        left += 1
    maxlen = max(maxlen, right-left+1)
print maxlen

## Step4 Boundary & Fault Tolerance Modeling
Pre‑predicted edge cases:
1. Single element >10: window will shrink, valid length becomes zero.
2. Entire array sum ≤ 10: maxlen = n.
3. Element exactly equals limit 10, valid window length 1.
4. Trap: use `if` instead of `while` to shrink window → window still invalid after one step.
5. Overflow risk: sum must be long long.
6. 1‑based index, pointers initialized to 1.

## Step5 Verification & Reflection Modeling
Test normal case, full‑array valid case, element exceeding limit case.
Classify bug type: ____ (A/B/C/D) — fill after real testing.
Evaluate 5‑step workflow(v1.0): Step2 algorithm reasoning relies on positive‑element property; Step4 highlights while‑vs‑if logical trap.
Did the process catch errors early? ____

---
## Review after solving all problems
Compare predicted edge cases and real bugs: ____
Did the 5‑step modeling process help catch errors in advance? ____
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today): ____

## Quick Reflection
Which step was hardest today: ____

## Tomorrow's Simple Plan
Week5 continue; move to simple DFS / recursion exercise; keep using methodology v1.0, record timing and bug metrics.

✅ Checklist
- [x] New problem markdown added to /problems
- [x] Source code added to /solutions
- [x] This daily log saved
- [x] Git commit completed
