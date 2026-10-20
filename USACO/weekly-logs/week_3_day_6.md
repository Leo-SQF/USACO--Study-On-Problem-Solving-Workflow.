# Daily Experiment Log
Week: ___ | Day: ___
Date: YYYY-MM-DD
Active modeling version: v0.0
## 1. Today's Experiment Objective
What is the goal of today’s experiment?
Example: Test 2 Bronze greedy problems using the 5-step modeling process.
Pre-set hypothesis:
Using the 5-step modeling process before coding can reduce debug time and avoid careless logical bugs on USACO Bronze simulation problems.
________________________________________
Selected problems for today:
1. Mix Milk (USACO Bronze)
2. (leave blank / fill your second problem later)
## 2. Experiment Records
| Problem Link | Modeling Time | Coding Time | Debug Time | Result (AC/WA/TLE) | Bug Type (A/B/C/D) |
| ---- | ---- | ---- | ---- | ---- | ---- |
| Mix Milk | 5 min | 8 min | 1 min | AC | None |
|  |  |  |  |  |  |
## 3. Review after solving all problems
Compare predicted edge cases and real bugs:
Predicted edge case: large value up to 1e9 (need long long). No actual bugs appeared; we handled the data type correctly ahead of coding.
________________________________________
Did the 5-step modeling process help catch errors in advance?
Yes. It reminded me to check the data range first and confirm the pouring sequence (1→2,2→3,3→1, loop 100 times), so I avoided mixing up the order of buckets.
________________________________________
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today):
Add a fixed checklist item: confirm whether variables need 64-bit integer (long long) when input constraints go above int limit.
________________________________________
## 4. Quick Reflection
Which step of the 5-step process worked poorly today?
All steps worked fine; no weak link for this simulation problem.
________________________________________
## 5. Git & File Update Check
- [ ] New problem markdown added to /problems
- [ ] Source code added to /solutions
- [ ] This daily log saved
- [ ] Git commit completed
## 6. Tomorrow's Simple Plan
Practice another USACO Bronze simulation problem, keep using the 5-step modeling workflow, and record edge cases during modeling.
