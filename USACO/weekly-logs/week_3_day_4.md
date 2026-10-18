# Daily Experiment Log
Week: _3__ | Day: _4__
Date: 2026-10-18
Active modeling version: v0.0
## 1. Today's Experiment Objective
What is the goal of today’s experiment?
Example: Test 2 Bronze greedy problems using the 5-step modeling process.
Pre-set hypothesis:
> If I fully complete the 5-step modeling template BEFORE writing code, I can avoid major logical bugs and reduce total debug time compared to writing code first.
________________________________________
Selected problems for today:
1. Taming the Herd (USACO Jan 2018 Bronze P3)
2. (leave blank for today; can add a second bronze problem tomorrow)
## 2. Experiment Records
| Problem Link | Modeling Time | Coding Time | Debug Time | Result (AC/WA/TLE) | Bug Type (A/B/C/D) |
| ---- | ---- | ---- | ---- | ---- | ---- |
| Taming the Herd | 30 min | 25 min | 40 min | WA → AC | A: Syntax bug (= vs ==), B: Logical misunderstanding, C: Boundary missing |
> Bug Type legend:
> A = Syntax / typo bugs
> B = Misunderstand problem rules
> C = Edge case / boundary error
> D = Algorithm design flaw

## 3. Review after solving all problems
Compare predicted edge cases and real bugs:
> Predicted edge cases: N=1, all -1, conflicting fixed numbers. These were real failure points. The biggest unexpected bug was mixing up assignment `=` and equality `==`, which I did not anticipate before coding.
________________________________________
Did the 5-step modeling process help catch errors in advance?
> Partially. Modeling helped me understand the constraint propagation rule and the min/max breakout definition. However I skipped modeling fully and started coding early, so I missed the syntax bug and forgot the day 0 mandatory 0 rule.
________________________________________
Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today):
> Add a dedicated "known pitfalls" section inside the model template before coding, to write down easy syntax traps like `==` vs `=`. Also force a rule checklist for problem mandatory constraints.
________________________________________
## 4. Quick Reflection
Which step of the 5-step process worked poorly today?
> Step 1 & Step 2: I rushed through modeling and jumped into implementation before fully locking down all constraints, leading to fundamental logic errors in the original code.
________________________________________
## 5. Git & File Update Check
- [x] New problem markdown added to /problems
- [x] Source code added to /solutions
- [x] This daily log saved
- [ ] Git commit completed
## 6. Tomorrow's Simple Plan
> Pick one new USACO Bronze problem. Strictly finish the full 5-step markdown template **before writing any code**. Test all custom edge cases after coding.
________________________________________

