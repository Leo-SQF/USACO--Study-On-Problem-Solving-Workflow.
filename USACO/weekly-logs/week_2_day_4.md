# Daily Experiment Log
Week: ___ | Day: ___
Date: 2026-10-10
Active modeling version: v0.0

## 1. Today's Experiment Objective
What is the goal of today’s experiment?
Practice one classic counting DP subsequence problem with strict 5-step modeling workflow, complete full problem markdown record and C++ standard solution.

Pre-set hypothesis:
Linear one-pass state counting can solve the COW subsequence problem in O(N) time; the main risk point is integer overflow and incorrect counting update order.

Selected problems for today:
1. COW Subsequence (USACO classic counting problem)

## 2. Experiment Records
| Problem Link | Modeling Time | Coding Time | Debug Time | Result (AC/WA/TLE) | Bug Type (A/B/C/D) |
| ---- | ---- | ---- | ---- | ---- | ---- |
| Classic USACO COW Subsequence | 4 min | 3 min | 0 min | AC | No bug |

## 3. Review after solving all problems
Compare predicted edge cases and real bugs:
Pre-predicted overflow risk and wrong update order were the core potential bugs. Actual coding had no bugs, and edge cases (N<3, no C/O/W, disordered characters) were fully covered in modeling stage.

Did the 5-step modeling process help catch errors in advance?
Yes. The modeling stage explicitly marked long long overflow as a key pitfall, avoided the most common WA for this problem, and clarified the one-pass counting logic before coding, resulting in zero debug time.

Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today):
Add a dedicated "overflow risk check" item in step4 for all counting & combination problems.

## 4. Quick Reflection
Which step of the 5-step process worked poorly today?
All steps worked smoothly; no weak step today. The model mapping from subsequence count to linear state transition was very quick and accurate.

## 5. Git & File Update Check
- [x] New problem markdown added to /problems
- [x] Source code added to /solutions
- [x] This daily log saved
- [x] Git commit completed

## 6. Tomorrow's Simple Plan
Continue practicing silver-level linear counting / DP subsequence problems, consolidate 5-step modeling process, focus on accumulating anti-overflow coding habits.
