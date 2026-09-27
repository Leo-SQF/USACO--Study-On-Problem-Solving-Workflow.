# Methodology — The Standardized Modeling Workflow

<!-- This is the CORE document of the research project. It defines the
standardized workflow you are designing, testing, and refining. Version it and
log every change you make. -->

**Current version:** `v0.1`
**Last updated:** `YYYY-MM-DD`
**Status:** `Draft / In testing / Final`

---

## The Workflow (5 steps)

The hypothesis: every USACO problem can be solved by following these steps in
order. Each step has inputs and outputs.

### Step 1 — Read & Restate

- **Do:** Read the problem carefully. Underline constraints, inputs, outputs, edge cases.
- **Output:** a one-paragraph restatement in your own words.

| Question to answer | Your answer |
|--------------------|-------------|
| What is the input? | |
| What is the output? | |
| What is the constraint on N? | |
| Any edge cases? | |

### Step 2 — Model (the key step)

- **Do:** Translate the problem into math / data structures. Identify the "thing" being optimized.
- **Output:** a model statement (e.g. "this is a shortest path on a graph", "this is a DP over positions").

Model types I know so far:
- [ ] Brute force / simulation
- [ ] Sorting / greedy
- [ ] Graph (BFS/DFS/shortest path)
- [ ] Dynamic programming
- [ ] Binary search
- [ ] Prefix sums / two pointers
- [ ] Other: ______

### Step 3 — Design Algorithm

- **Do:** Choose the algorithm and reason about complexity vs. constraints.
- **Output:** algorithm name + time complexity `O(?)`, and why it fits the constraints.

| Constraint (N) | Allowed complexity |
|----------------|--------------------|
| N ≤ 10 | O(n!) or O(2^n) |
| N ≤ 1000 | O(n^2) |
| N ≤ 10^5 | O(n log n) |
| N ≤ 10^6+ | O(n) or better |

### Step 4 — Implement

- **Do:** Code it cleanly using the templates in `templates/`.
- **Output:** a working program that passes the sample test.

Checklist:
- [ ] Correct input / output file handling (USACO style)
- [ ] Edge cases handled
- [ ] No infinite loops
- [ ] Data types big enough (overflow)

### Step 5 — Verify

- **Do:** Test sample, then extra edge cases, then (if possible) brute-force compare.
- **Output:** a verified solution.

Checklist:
- [ ] Passes provided samples
- [ ] Passes my own edge cases
- [ ] Complexity is within limits
- [ ] Brute-force cross-check (if applicable)

---

## Version History

<!-- Log every change to the workflow. This is the "research" part. -->

| Version | Date | Change | Why |
|---------|------|--------|-----|
| v0.1 | YYYY-MM-DD | Initial 5-step draft | Starting point |
| v0.2 | | | |
| v0.3 | | | |
| final | | | |

## What I observed (running notes)

<!-- During testing, write down what works and what breaks. -->

- Step that costs the most time: ______
- Step most likely to be skipped under pressure: ______
- Common mistake: ______
