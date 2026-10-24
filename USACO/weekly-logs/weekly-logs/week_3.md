# Weekly Log Template
<!-- One copy per week. Save as:
  weekly-logs/YYYY-MM-DD-week.md   (use the Sunday date of that week)
Copy the whole file, fill it in, and commit at end of the week. -->
## Week of `2026-XX-XX` (Week 4 / 16)

### Goals for this week
- [x] Complete mixed Bronze review problems using the 5-step modeling process (v0.0)
- [x] Continue collecting baseline experiment data, cover simulation, greedy, array, permutation/constraint problems
- [x] No skipping pre-code modeling steps
- [x] Aggregate all Week1–Week4 baseline data at week end
- [x] Summarize bug distribution, decide revision plan for v1.0 methodology

### Problems attempted
| Problem | Source | Status(AC/WA/TLE) | Total Time | Model type | Notes |
|---------|--------|--------|------|------------|-------|
| Lineup | USACO Bronze | AC | 47 min | Permutation + adjacency constraint | Week4 Day1, brute force all permutations |
| Mix P2 | USACO Bronze | AC | 38 min | Greedy | Sorting key selection |
| Mix P3 | USACO Bronze | WA→AC | 52 min | Array / prefix sum | Off-by-one boundary error |
| Mix P4 | USACO Bronze | AC | 33 min | Simple simulation | Straightforward, few traps |
| Mix P5 | USACO Bronze | AC | 44 min | Greedy + math | Need to prove local optimality |

### Bug Classification Summary (Experiment Core Data)
| Bug type | Count | Example / note |
|----------|-------|----------------|
| A. Model error (wrong abstraction) | 1 | Misinterpreted implicit rule of a greedy problem |
| B. Algorithm selection error | 0 | — |
| C. Boundary / edge case | 1 | Prefix sum index boundary mistake |
| D. Code / syntax bug | 1 | Forgot adjacency is undirected (Lineup) |
| **Total** | 3 | over 5 problems |

### Workflow check
- Which step took the longest? `Step4 Boundary & Fault Tolerance Modeling`
- Did I skip any step? `No, all 5 steps followed for every problem`
- Rating of workflow this week (1–10): `7`

### Algorithm / pattern learned this week
- When the search space is tiny (like 8 cows → 40320 permutations), brute-force enumeration is clean and reliable, no need for complex backtracking pruning.
- Adjacency constraints are **undirected relations**; both orders are valid.
- Mixed review shows different bug types appear across Bronze categories: greedy tends to A bugs, array/prefix-sum tends to C boundary bugs.

### Problems / blockers
- It is hard to list all implicit edge cases fully during Step4 before coding. Some subtle undirected / bidirectional rules are easy to miss.
- Baseline observation: Step4 currently lacks a checklist item to mark whether a constraint is directed or undirected. This will be one revision point for v1.0.

### Next week's plan
- Start Month 2 (Week 5), target recursive DFS / search problems
- Upgrade methodology to v1.0, add small improvements from Month1 baseline findings
- Keep all experiment recording rules unchanged
- Target: 4–6 DFS / recursive Bronze & easy Silver problems

---
## Weekly Summary (to fill at month end)
| Metric | This week | Cumulative (W1+W2+W3+W4) |
|--------|-----------|------------|
| Problems attempted | 5 | 19 |
| Problems solved | 5 | 17 |
| Solve rate | 100% | 89.5% |
| Avg time to solve | 42.8 min | 41.2 min |
| Confidence (1–10) | 7 | 7 |
