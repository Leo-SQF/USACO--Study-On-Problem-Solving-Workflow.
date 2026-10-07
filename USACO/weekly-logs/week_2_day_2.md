# Daily Experiment Log
Week: 1 | Day: 2
Date: 2026-10-07
Active modeling version: v0.0
## 1. Today's Experiment Objective
What is the goal of today’s experiment?
Example: Test 2 Bronze greedy problems using the 5-step modeling process.
Pre-set hypothesis:
Using the 5-step problem template before writing C++ code can reduce compile errors and logical bugs, especially for struct and array index mistakes.
________________________________________
Selected problems for today:
1. Cow Watering (prefix sum, struct practice)
2. (reserved for second bronze problem)
## 2. Experiment Records
| Problem Link | Modeling Time | Coding Time | Debug Time | Result (AC/WA/TLE) | Bug Type (A/B/C/D) |
| ---- | ---- | ---- | ---- | ---- | ---- |
| problems/prefix-sum/cow-watering.md | 12 min | 10 min | 18 min | AC | A |
> Bug Type legend:
> A: Compile error (syntax / type name vs variable name)
> B: Logical error / off-by-one index
> C: Uninitialized variable
> D: Time limit exceeded

## 3. Review after solving all problems
Compare predicted edge cases and real bugs:
Predicted edge cases: L=R, N=1, full array query. These did not trigger bugs.
Real bug: Confused struct type name and array variable name; forgot reset total=0 for each query.
________________________________________
Did the 5-step modeling process help catch errors in advance?
Partially. I did not fully think about struct variable declaration before coding, which became the main compile error. The edge case planning helped avoid runtime logical bugs.
________________________________________
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today):
Add a dedicated field in the problem template: "Data Structure Declaration" to write struct and array definitions before coding.
________________________________________
## 4. Quick Reflection
Which step of the 5-step process worked poorly today?
Step4 Implementation Notes: I skipped drafting data structure definitions before writing input code.
________________________________________
## 5. Git & File Update Check
- [x] New problem markdown added to /problems
- [x] Source code added to /solutions
- [x] This daily log saved
- [ ] Git commit completed
## 6. Tomorrow's Simple Plan
Finish a second USACO bronze problem (greedy + struct + sort), fully complete the 5-step template before writing any code, record modeling/coding/debug time.

如果你想，我可以把Bug Type的定义固定写在日志模板顶部，或者直接帮你把明天那道青铜题的md problem模板提前填好。
