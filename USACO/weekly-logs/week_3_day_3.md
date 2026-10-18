Daily Experiment Log
Week: 3 | Day: 3
Date: 2026-10-17
Active modeling version: v0.1

1. Today's Experiment Objective
What is the goal of today’s experiment?
Example: Test 2 Bronze greedy problems using the 5-step modeling process.

Pre-set hypothesis:
Using the 5-step modeling process will help me identify hidden constraints (like unsorted inputs and tie-breaking rules) before writing any code, reducing the number of WA (Wrong Answer) submissions.

Selected problems for today:

USACO 2017 US Open Bronze - Milk Measurement

USACO 2016 US Open Bronze - Field Reduction (or a generic second problem)

2. Experiment Records
Problem Link	Modeling Time	Coding Time	Debug Time	Result (AC/WA/TLE)	Bug Type (A/B/C/D)
Milk Measurement	5 min	8 min	2 min	AC	A (Logic/Algorithm)
Field Reduction	7 min	12 min	3 min	AC	B (Implementation/Syntax)
(Note: Bug Types typically refer to A=Logic, B=Syntax/Implementation, C=Data Structure, D=Optimization)

3. Review after solving all problems
Compare predicted edge cases and real bugs:
I predicted the "tie handling" (multiple cows sharing the top spot) in Step 1, which successfully prevented a logic bug. However, I initially missed the "unsorted input" edge case in Problem 1, which caused a temporary failure before I realized the data needed sorting.

Did the 5-step modeling process help catch errors in advance?
Yes. Specifically, in Step 3 (Algorithm), forcing myself to define the "Bitmask" state before coding made the implementation much smoother and handled the tie logic flawlessly.

Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today):
Add a mandatory "Constraint Checklist" in Step 1 that explicitly asks: 1. Is the input sorted? 2. Are there ties? 3. What are the data limits?

4. Quick Reflection
Which step of the 5-step process worked poorly today?
Step 1 (Read & Restate). I skimmed the problem text too fast and missed the sentence saying "he does not necessarily write down his measurements in chronological order." This forced me to add the sorting step later during coding.

5. Git & File Update Check
☑ New problem markdown added to /problems
☑ Source code added to /solutions
☑ This daily log saved
☑ Git commit completed
6. Tomorrow's Simple Plan
Attempt 1 Silver-level problem (focusing on Graph traversal: DFS/BFS) and strictly apply the 5-step modeling. Focus heavily on Step 1 to ensure I catch all constraints before starting Step 2.

