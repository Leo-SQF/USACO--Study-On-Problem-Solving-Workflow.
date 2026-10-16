# Daily Experiment Log
Week: _3__ | Day: _2__
Date: 2026-10-16
Active modeling version: v0.0
## 1. Today's Experiment Objective
What is the goal of today’s experiment?
Example: Test 2 Bronze greedy problems using the 5-step modeling process.
Pre-set hypothesis:
> Using greedy backward traversal for cowtip and brute-force enumeration for hoof-paper-scissors will correctly solve both USACO Bronze problems; all edge cases (N=1, all 0s, all 1s) can be handled without TLE since N ≤ 100.
________________________________________
Selected problems for today:
1. Hoof, Paper, Scissors (hps)
2. Cow Tip (cowtip)
## 2. Experiment Records
| Problem Link | Modeling Time | Coding Time | Debug Time | Result (AC/WA/TLE) | Bug Type (A/B/C/D) |
| ---- | ---- | ---- | ---- | ---- | ---- |
| Hoof Paper Scissors | 8 min | 7 min | 2 min | AC | None |
| Cow Tip | 10 min | 6 min | 3 min | AC | None |
## 3. Review after solving all problems
Compare predicted edge cases and real bugs:
> Predicted edge cases: N=1 grid for cowtip, all games are ties for hps. No unexpected bugs appeared. The only minor slip was mixing up the win condition pairs for HPS at first, caught quickly.
________________________________________
Did the 5-step modeling process help catch errors in advance?
> Yes. Writing out the full state rules and enumerating all permutations before coding prevented logic mistakes for HPS. For Cowtip, reasoning about the greedy invariant (processed bottom-right cells can no longer be changed) avoided wrong traversal order.
________________________________________
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today):
> Add a mandatory "edge case checklist" step before starting to write code, explicitly list 2–3 edge cases for each problem.
________________________________________
## 4. Quick Reflection
Which step of the 5-step process worked poorly today?
> The step of manually enumerating permutations for HPS was slightly error-prone; could pre-write permutation list on paper before coding.
________________________________________
## 5. Git & File Update Check
- [ ] New problem markdown added to /problems
- [ ] Source code added to /solutions
- [ ] This daily log saved
- [ ] Git commit completed
## 6. Tomorrow's Simple Plan
> Solve another 2 USACO Bronze problems, continue practicing greedy simulation problems, test more boundary edge cases during modeling phase.
