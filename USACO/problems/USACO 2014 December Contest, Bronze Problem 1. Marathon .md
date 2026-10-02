# Problem Template

<!-- One copy of this file per problem. Save as:
  problems/<topic>/<problem-name>.md
Fill every section BEFORE coding (model first!), and reflect AFTER. -->

## Problem Info

- **Name:** `Marathon`
- **Source:** `USACO 2014 December Contest, Bronze
Problem 1`
- **Difficulty (self-rated):** `4`
- **Date attempted:** `2026-10-2`
- **Status:** `Solved with help`
- **Time spent:** `32 min`

---

## Step 1 — Read & Restate

<nhappy with the poor health of his cows, Farmer John enrolls them in
an assortment of different physical fitness activities.  His prize cow
Bessie is enrolled in a running class, where she is eventually
expected to run a marathon through the downtown area of the city near
Farmer John's farm!

The marathon course consists of N checkpoints (3 <= N <= 100,000) to
be visited in sequence, where checkpoint 1 is the starting location
and checkpoint N is the finish.  Bessie is supposed to visit all of
these checkpoints one by one, but being the lazy cow she is, she
decides that she will skip up to one checkpoint in order to shorten
her total journey.  She cannot skip checkpoints 1 or N, however, since
that would be too noticeable.

Please help Bessie find the minimum distance that she has to run if
she can skip up to one checkpoint.  

Note that since the course is set in a downtown area with a grid of
streets, the distance between two checkpoints at locations (x1, y1)
and (x2, y2) is given by |x1-x2| + |y1-y2|.  This way of measuring
distance -- by the difference in x plus the difference in y -- is
sometimes known as "Manhattan" distance because it reflects the fact
that in a downtown grid, you can travel parallel to the x or y axes,
but you cannot travel along a direct line "as the crow flies".
>

> ...

| Item | Value |
|------|-------|
| Input | 4|
| Output | 12|
| Constraint on N |none |
| Edge cases | |

---

## Step 2 — Model

<simple vector calculations>

- Model type: `vector`
- Explanation:

---

## Step 3 — Algorithm

- Algorithm chosen: `...`
- Time complexity: `O(?)`
- Space complexity: `O(?)`
- Why it fits the constraints:

---

## Step 4 — Implementation Notes

- Data structures used: `double / combining for if and else`
- Pitfalls / bugs I hit: `the part where "	if ( ( calc (a[i+1], a[i+2]) - calc (a[i+1], a[i+3]) ) > ( calc (a[i],a[i+1]) - calc (a[i],a[i+2])) )" is flawed because the number i+3 is not included in the vector and will result in problems`
- 

---

## Step 5 — Verification

- [ ] Passes provided samples
- [ ] Passes my edge cases
- [ ] Within time limit
- [ ] Brute-force cross-check (if applicable)

---

## Reflection (fill AFTER solving)

- What was the hardest part? `the two vectors cnbination`
- Did I follow the workflow, or skip a step? `yes`
- If stuck: where did I get stuck and what unblocked me? `...`
- One thing to improve next time: `...`
