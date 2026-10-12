# Daily Experiment Log

Week: ___ | Day: ___
Date: 2026-10-12
Active modeling version: v0.0

## 1. Today's Experiment Objective

What is the goal of today’s experiment?
Example: Test 2 Bronze greedy problems using the 5-step modeling process.
Pre-set hypothesis:

> 
> Using the 5-step modeling template before coding will reduce debugging time and help catch logical bugs early. Simulation problems can be solved cleanly by tracking state and recording timestamps.

---

Selected problems for today:

1. USACO Jan 2016 Bronze: Mowing
2. (leave blank or add a second problem later)

## 2. Experiment Records

表格

| Problem Link | Modeling Time | Coding Time | Debug Time | Result (AC/WA/TLE) | Bug Type (A/B/C/D) |
| --- | --- | --- | --- | --- | --- |
| USACO Jan 2016 Bronze Mowing | 15 min | 12 min | 13 min | AC | Syntax (C++11 range for loop incompatible with C++98) |

## 3. Review after solving all problems

Compare predicted edge cases and real bugs:

> 
> Predicted edge cases: no repeated cells, multiple revisits to same coordinate. The actual bug was not a logic bug but a compiler syntax issue (C++ version mismatch), which I had not predicted.

---

Did the 5-step modeling process help catch errors in advance?

> 
> Yes. The modeling step clarified that I must update the cell’s last visit time every step, which prevented the main logical bug. However, it could not predict compiler/syntax-related bugs.

---

Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today):

> 
> Add a small pre-coding checklist for C++ syntax compatibility when using older compilers.

---

## 4. Quick Reflection

Which step of the 5-step process worked poorly today?

> 
> Verification step did not account for compiler-level syntax errors; I only tested logic, not compiler standard compatibility.

---

## 5. Git & File Update Check

- New problem markdown added to /problems
- Source code added to /solutions
- This daily log saved
- Git commit completed

## 6. Tomorrow's Simple Plan

> 
> Complete one more USACO Bronze simulation problem with the same 5-step template. Practice identifying edge cases before writing code.
