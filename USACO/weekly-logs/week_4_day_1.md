# Daily Experiment Log
Week 4 / Day 1
Date: 2026-10-23
Active modeling version: v0.0
Today's Experiment Objective: Practice permutation + adjacency constraint problem; continue collecting baseline data, focus on Step4 boundary and exhaustive search thinking.
Pre-set hypothesis: Enumerating all permutations and checking constraints can get lex smallest valid sequence, but we need to carefully list adjacency edge cases.
Selected problems for today:
- USACO Bronze Lineup (cow beside constraints, lex smallest permutation)

| Problem Link | Modeling Time | Coding Time | Debug Time | Result | Bug Type |
| ---- | ---- | ---- | ---- | ---- | ---- |
| USACO Bronze Lineup | 22 min | 18 min | 7 min | AC | D |

---
## Step 1 Problem Abstraction
We have exactly 8 fixed cows: Bessie, Buttercup, Belinda, Beatrice, Bella, Blue, Betsy, Sue.
We have N constraints: X and Y must be adjacent (next to each other, either order).
Goal: output the **lexicographically smallest** permutation satisfying all adjacency rules.
Constraints: 1 ≤ N ≤7, only 8 elements total.
Input: N followed by N pairs of cows that must be beside each other.
Output: permutation with 8 lines, lex earliest valid arrangement.

## Step 2 Algorithm Selection
Candidate 1: Generate all permutations in lex order, check each permutation against all adjacency constraints. Return the first valid one.
Candidate 2: Build graph and backtracking with pruning.
Selected algorithm: brute force permutation check.
Reason: Only 8! = 40320 permutations, which is tiny for a computer. Generating permutations in lex order naturally gives the earliest valid answer once found.
Time complexity: O(8! * N), fully acceptable.
Reject backtracking with complex pruning: unnecessary for n=8, easier to make logic mistakes.

## Step3 Logic & Data Structure Framework
Data structure:
- A list storing the 8 cow names, sorted initially for lex permutation generation.
- A vector of pairs to store all required adjacent cow pairs.

Pseudocode:
1. Store all constraint pairs into a list.
2. Initialize cow list sorted alphabetically.
3. Loop:
   a. Check if current permutation satisfies every adjacency constraint.
   b. If valid: print all cows and terminate.
   c. Else: generate next lex permutation.
Check function(perm, constraints):
For each (x,y) in constraints:
   find index of x, index of y
   if abs(idx_x - idx_y) != 1 → invalid, return false
return true

## Step4 Boundary & Fault Tolerance Modeling
Pre-predicted edge cases:
1. Multiple constraints chain together (A beside B, B beside C → A,B,C must form a consecutive block). Like sample: Buttercup-Bella-Blue form a chain.
2. Two separate independent adjacent pairs (Sue-Beatrice is separate chain in sample).
3. N=7 (max constraints, all cows connected into one single block).
4. Check for off-by-one when comparing positions (index difference must equal exactly 1).
5. Lex order trap: cannot greedily pick smallest cow first without checking if constraints can still be satisfied.

## Step5 Verification & Reflection Modeling
Test sample input:
3
Buttercup must be milked beside Bella
Blue must be milked beside Bella
Sue must be milked beside Beatrice
Program output matches sample output exactly.
Bug encountered: D (code bug): At first I forgot that adjacency is bidirectional, only checked x before y not y before x; fixed in check function by absolute difference.
Evaluation of 5-step workflow: Step1 and Step2 were straightforward. Step4 helped me notice chained adjacency risk before coding.
Did the process catch errors early? Partially; the bidirectional adjacency bug was not predicted in Step4, only surfaced during testing.

---
## Review after solving all problems
Compare predicted edge cases and real bugs: I predicted chained constraints, but missed the "adjacency works both ways" detail.
Did the 5-step modeling process help catch errors in advance? Yes for algorithm choice; missed this bidirectional detail.
Suggestions to improve the modeling workflow: In Step4, explicitly mark whether a relation is directed / undirected.

## Quick Reflection
Which step was hardest today: Step4 boundary modeling; easy to overlook undirected constraints.

## Tomorrow's Simple Plan
Continue Week4 mixed Bronze problems, keep v0.0, keep recording bug types, focus on catching undirected/ bidirectional hidden constraints.

✅ Checklist
- [x] New problem markdown added to /problems
- [x] Source code added to /solutions
- [x] This daily log saved
- [x] Git commit completed
