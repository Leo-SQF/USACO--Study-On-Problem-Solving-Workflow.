# Daily Experiment Log
Week: _2__ | Day: _5__
Date: 2026-10-11
Active modeling version: v0.0
## 1. Today's Experiment Objective
What is the goal of today’s experiment?
Pre-set hypothesis:
I can correctly simulate the chain explosion rule of the Angry Cows problem. Common bugs will be index out-of-bounds and misunderstanding the simultaneous explosion rule. I will avoid using C++11 range-based for loops to prevent compilation errors.
________________________________________
Selected problems for today:
1. Angry Cows (Bronze, chain explosion simulation)
2. 
## 2. Experiment Records
| Problem Link | Modeling Time | Coding Time | Debug Time | Result (AC/WA/TLE) | Bug Type (A/B/C/D) |
| ---- | ---- | ---- | ---- | ---- | ---- |
| Angry Cows | 15 min | 25 min | 20 min | AC | Logic misunderstanding + Compile error |
|  |  |  |  |  |  |
## 3. Review after solving all problems
Compare predicted edge cases and real bugs:
Predicted edge case: index -1 out of bounds. Real bugs: (1) misunderstood explosion rule, thought explosion only spreads from the starting haybale; (2) used C++11 range for loops which failed in C++98 compiler; (3) accidentally counted explosions twice.
________________________________________
Did the 5-step modeling process help catch errors in advance?
Partially. It helped me clarify the simultaneous explosion rule before coding, but I missed checking C++ language version restrictions before writing the loop syntax.
________________________________________
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today):
Add a pre-coding check: confirm compiler standard. If C++98 is required, avoid C++11 syntax. Also explicitly list all index boundary risks before writing loops.
________________________________________
## 4. Quick Reflection
Which step of the 5-step process worked poorly today?
The syntax & implementation check step. I forgot to verify which C++ features are allowed, which caused compilation errors after finishing the logic.
________________________________________
## 5. Git & File Update Check
- [ ] New problem markdown added to /problems
- [ ] Source code added to /solutions
- [ ] This daily log saved
- [ ] Git commit completed
## 6. Tomorrow's Simple Plan
Practice another simulation problem. Focus on checking array/vector index boundaries before writing loops, and use only C++98 compatible syntax.
________________________________________
