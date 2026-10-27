# Daily Experiment Log
Week 4 / Day 5
Date: ____ (YYYY‑MM‑DD)
Active modeling version: v0.0
Today's Experiment Objective: Week4 mixed Bronze review; brute‑force geometry enumeration. Practice reading geometric problem constraints, recognizing when triple‑loop brute force is acceptable. Continue collecting baseline experiment data for month‑1 summary.
Pre‑set hypothesis: Since N is small, triple loop O(N³) brute‑force enumeration over all candidate corner points will work. We do not need complex computational geometry. The fourth rectangle corner does not have to be present in input posts.
Selected problems for today:
- USACO 2020 February Bronze P1 — Social Distancing (Posts)

| Problem Link | Modeling Time | Coding Time | Debug Time | Result | Bug Type |
| ---- | ---- | ---- | ---- | ---- | ---- |
| Social Distancing 2020 Feb Bronze P1 | ____ min | ____ min | ____ min | ____ | ____ |

---
## Step 1 Problem Abstraction
We are given N fence posts as (x,y) coordinates on a 2D plane.
We choose one post i as one corner of axis‑aligned rectangle.
We find another post j sharing same y‑coordinate to get horizontal width dx.
We find another post k sharing same x‑coordinate to get vertical height dy.
Area = dx * dy.
Goal: find maximum possible area from all such candidate rectangles.
Important: The fourth corner point is virtual; it does not need to be one of input posts.

## Step 2 Algorithm Selection
Candidate1: Try pre‑group points by x‑key and y‑key, then compute combinations.
→ Rejected: For small N, pre‑group adds extra thinking overhead; brute‑force triple loop is simpler.

Candidate2: Triple loop brute‑force: iterate base point i, find j with same y, find k with same x, compute area and track maximum.
Selected algorithm: triple nested brute‑force loops.
Reason: N is small; logic is direct, reduces modeling misinterpretation risk.
Complexity: O(N³).

## Step3 Logic & Data Structure Framework
Data structure:
`vector<vector<int>> post` stores each post coordinate pair (x,y).

Pseudocode:
Initialize max_ans = 0
Loop i over all posts:
    xi = post[i][0], yi = post[i][1]
    Loop j over all posts:
        if post[j][1] == yi:
            dx = abs(post[j][0] - xi)
            Loop k over all posts:
                if post[k][0] == xi:
                    dy = abs(post[k][1] - yi)
                    area2 = dx * dy
                    if area2 > max_ans:
                        max_ans = area2
Output max_ans

## Step4 Boundary & Fault Tolerance Modeling
Pre‑predicted edge cases:
1. dx = 0 or dy = 0 → area zero; will not overwrite valid larger max_ans.
2. j or k can be identical to base point i. Code still safe.
3. Misconception trap: mistakenly require fourth corner point to exist inside input list.
4. Multiple points share same x or same y coordinate.
5. All points are on one horizontal or vertical line → max area = 0.

## Step5 Verification & Reflection Modeling
Test official sample and minimal edge cases.
Classify bug type: ____ (A/B/C/D) — fill after real testing.
Evaluate 5‑step workflow: Step1 abstraction is critical, especially understanding the fourth corner does not need to exist. Step2 correctly choose brute‑force instead of over‑engineering.
Did the process catch errors early? ____

---
## Review after solving all problems
Compare predicted edge cases and real bugs: ____
Did the 5‑step modeling process help catch errors in advance? ____
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today): ____

## Quick Reflection
Which step was hardest today: ____

## Tomorrow's Simple Plan
Finish remaining Week‑4 mixed Bronze practice. Collect all Week1‑Week4 experimental data for month‑one baseline summary. Prepare to summarize bug statistics and plan v1.0 methodology revisions.

✅ Checklist
- [x] New problem markdown added to /problems
- [x] Source code added to /solutions
- [x] This daily log saved
- [x] Git commit completed
