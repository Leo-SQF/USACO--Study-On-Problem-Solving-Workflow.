# Daily Experiment Log

Week: __2_ | Day: _3__
Date: 2025-10-08
Active modeling version: v0.0

## 1. Today's Experiment Objective

What is the goal of today’s experiment?
Practice comprehensive C++ simulation problem integrating **struct, vector, custom sort comparator, string function, file freopen, and statistical counting** using the 5-step modeling workflow.

Pre-set hypothesis:
Struct custom sorting with double conditions and boundary score judgment are the most error-prone parts.

Selected problems for today:

1. Student Score Ranking and Level Statistics (self-designed comprehensive problem)

## 2. Experiment Records

表格

| Problem Link | Modeling Time | Coding Time | Debug Time | Result (AC/WA/TLE) | Bug Type (A/B/C/D) |
| --- | --- | --- | --- | --- | --- |
| Local Practice | 6 min | 12 min | 3 min | AC | Logic boundary + comparator |

## 3. Review after solving all problems

Compare predicted edge cases and real bugs:
Predicted boundary errors on score 60/90 and tie-score sorting. Actual bugs occurred in comparator order and initialization of counters.

Did the 5-step modeling process help catch errors in advance?
Yes. Listing edge cases in advance avoided wrong level judgment and invalid input handling.

Suggestions to improve the modeling workflow:
Always write comparator logic clearly before coding; initialize all counting variables to zero explicitly.

## 4. Quick Reflection

Which step of the 5-step process worked poorly today?
Algorithm modeling for custom sorting still needs more precise written logic before coding.

## 5. Git & File Update Check

- New problem markdown added to /problems
- Source code added to /solutions
- This daily log saved
- Git commit completed

## 6. Tomorrow's Simple Plan

Practice one new comprehensive problem combining struct, multi-condition sorting and file input/output to consolidate modeling and coding standardization.
