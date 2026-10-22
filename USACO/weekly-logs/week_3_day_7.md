# Daily Experiment Log
Week: _3__ | Day: _7__
Date: 2026-10-22
Active modeling version: v0.0
## 1. Today's Experiment Objective
What is the goal of today’s experiment?
Test 2 USACO Bronze problems by analyzing problem nature, transforming the problem and finding the core mathematical rule (instead of jumping into simulation).
Pre-set hypothesis:
For many Bronze problems, the optimal solution comes from reinterpreting the operation rules and finding invariant sub-sequences / the hardest-to-distinguish pair, rather than simulating the whole process.
________________________________________
Selected problems for today:
1. Sleepy Cow Sorting
2. Guess the Animal
## 2. Experiment Records
| Problem Link | Modeling Time | Coding Time | Debug Time | Result (AC/WA/TLE) | Bug Type (A/B/C/D) |
| ---- | ---- | ---- | ---- | ---- | ---- |
| Sleepy Cow Sorting | 8 min | 4 min | 1 min | AC | A |
| Guess the Animal | 7 min | 5 min | 0 min | AC | - |
> Bug type reference: A=misunderstanding problem rule; B=off-by-one; C=logic error; D=input/output format
## 3. Review after solving all problems
Compare predicted edge cases and real bugs:
For Sleepy Cow Sorting, I almost mistook “increasing sequence” for “consecutive +1 sequence” — this rule misunderstanding was the only bug. No unexpected edge cases popped up. For Guess the Animal, no bugs appeared because the core transformation (the bottleneck is the most similar pair) was correct from the start.
________________________________________
Did the 5-step modeling process help catch errors in advance?
Partially yes. It forced me to stop and analyze what the operation really does before coding, which helped avoid writing unnecessary simulation code. But I did not fully verify the rule with multiple small test cases at first.
________________________________________
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today):
After deriving a candidate formula/rule, test it manually on 2–3 custom tiny test cases (not only the sample input) before writing any code.
________________________________________
## 4. Quick Reflection
Which step of the 5-step process worked poorly today?
The step of verifying the derived conclusion on self-made edge cases. I relied too much on the sample to confirm correctness.
________________________________________
## 5. Git & File Update Check
- [ ] New problem markdown added to /problems
- [ ] Source code added to /solutions
- [ ] This daily log saved
- [ ] Git commit completed
## 6. Tomorrow's Simple Plan
Practice another 2 Bronze problems, focus on distinguishing when to simulate and when to find a mathematical shortcut; add custom small test cases during modeling.
________________________________________
