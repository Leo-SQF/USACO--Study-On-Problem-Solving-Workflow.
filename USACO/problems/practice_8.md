# Problem Template

## Problem Info

- **Name:** `Student Score Ranking and Level Statistics`
- **Source:** `Self-designed C++ struct practice problem`
- **Difficulty (self-rated):** `4`
- **Date attempted:** `2026-10-08`
- **Status:** `Not started`
- **Time spent:** `XX min`

---

## Step 1 — Read & Restate

> 
> Read multiple lines of student ID and score from an input file. Stop reading when the line `-1 -1` is encountered. For each student record, calculate the corresponding level by score. Store all records in a vector. Sort records with custom rules: higher scores first; if scores are equal, sort by ID ascending. Write sorted records to an output file, then count and print the number of students in each level (Excellent, Pass, Fail).

| Item | Value |
| --- | --- |
| Input | input.txt. Each line contains two integers: id, score. Terminate on `-1 -1`. |
| Output | output.txt. Print id, score and level for each student. Finally output counts of Excellent, Pass and Fail. |
| Constraint on N | No hard upper limit; N is determined by input. Vector can handle normal input size. |
| Edge cases | 1. Multiple students share identical scores. 2. Scores exactly equal to boundary values 90 and 60. 3. Only one student record. 4. The first input line is `-1 -1` (no valid student data). |

---

## Step 2 — Model

- Model type: `Simulation`
- Explanation:
This is a straightforward simulation problem. It focuses on data reading, storage, calculation, custom sorting and statistics. No advanced algorithms like greedy or DP are required. It tests struct, custom comparator, file I/O, loops and counters.

---

## Step 3 — Algorithm

- Algorithm chosen: `Brute force simulation + standard sort with custom comparator`
- Time complexity: `O(N log N)`
- Space complexity: `O(N)`
- Why it fits the constraints:
The dominant cost comes from `sort`, which is `O(N log N)`. For normal input size, this is fast enough. We store all N records in vector, so space is linear with N.

---

## Step 4 — Implementation Notes

- Data structures used: `struct, vector<struct>, string`
- Pitfalls / bugs I hit:
  1. Forget semicolon after struct definition.
  2. Wrong comparator logic for sorting order.
  3. Boundary mistakes when judging score levels.
  4. Incorrect termination condition `-1 -1`.
  5. File I/O missing `freopen` or `fclose`.
  6. Counter variables not initialized to zero.

---

## Step 5 — Verification

- Passes provided samples
- Passes my edge cases
- Within time limit
- Brute-force cross-check (if applicable)

---

## Reflection (fill AFTER solving)

- What was the hardest part? `...`
- Did I follow the workflow, or skip a step? `...`
- If stuck: where did I get stuck and what unblocked me? `...`
- One thing to improve next time: `...`
