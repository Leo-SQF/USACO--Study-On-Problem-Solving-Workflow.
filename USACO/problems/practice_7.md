# Problem Template

## Problem Info

- **Name:** `Cow Group Selection`
- **Source:** `Self-made USACO Bronze practice`
- **Difficulty (self-rated):** `4`
- **Date attempted:** `2026-10-07`
- **Status:** `Not started`
- **Time spent:** `XX min`

---

## Step 1 — Read & Restate

> 
> We have N cows. Each cow has a weight w and an ID number. We need to pick a group of cows. Every pair of cows in this group must have a GCD of their weights greater than 1. Find the maximum possible size of this group.
> 
> 
> | Item | Value |
> | --- | --- |
> | Input | First line: integer N. Next N lines each have two integers w, id (weight and cow id). |
> | Output | Print the maximum number of cows we can select satisfying the rule. |
> | Constraint on N | $1 \le N \le 1000$ |
> | Edge cases | N=1 (only one cow, answer=1); all weights are primes with no common factors; multiple cows share same weight. |

---

## Step 2 — Model

- Model type: `Brute Force / Enumeration`
- Explanation:
We test all possible groups of cows, check the GCD condition for every pair inside a group, keep track of the largest valid group size. Since N=1000 we will use a smarter enumeration strategy: group cows by prime divisors. We count how many numbers are divisible by each prime; the maximum count is our answer.

---

## Step 3 — Algorithm

- Algorithm chosen: `Brute force enumeration + GCD`
- Time complexity: $O(N^2)$
- Space complexity: $(O(N))$
- Why it fits the constraints:
N ≤ 1000, $N^2=1,000,000$ operations, which is well within time limits for USACO Bronze.

---

## Step 4 — Implementation Notes

- Data structures used: `struct Cow array`
- Pitfalls / bugs I hit: `Forget that N=1 gives answer 1; integer overflow when calculating GCD; mixing up 1 as a special case (gcd(1, x)=1)`

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

---
