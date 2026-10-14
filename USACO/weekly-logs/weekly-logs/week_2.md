# Weekly Log Template
<!-- One copy per week. Save as:
  weekly-logs/YYYY-MM-DD-week.md   (use the Sunday date of that week)
Copy the whole file, fill it in, and commit at end of the week. -->
## Week of `2026-10-19` (Week 2 / 16)

### Goals for this week
- [√] Complete 4–6 Bronze greedy problems using 5-step modeling process (v0.0)
- [√] Record all timing and bug data for experiment baseline
- [√] No skipping of pre-code modeling steps
- [√] Focus on Step1 (abstraction) and Step2 (algorithm selection) for greedy

### Problems attempted
| Problem | Source | Status(AC/WA/TLE) | Total Time | Model type | Notes |
|---------|--------|--------|------|------------|-------|
| Example-P1 | USACO Bronze 2017 Jan | AC | 35 min | Greedy | step1 clear |
| Example-P2 | USACO Bronze 2016 Dec | WA→AC | 50 min | Greedy | misread constraint |
| Example-P3 | USACO Bronze 2016 Jan | AC | 30 min | Greedy + sort | easy |
| Example-P4 | USACO Bronze 2015 Dec | TLE→AC | 60 min | Greedy | picked wrong order |
| Example-P5 | USACO Bronze 2015 Jan | AC | 40 min | Greedy | fine |

### Bug Classification Summary (Experiment Core Data)
| Bug type | Count | Example / note |
|----------|-------|----------------|
| A. Model error (wrong abstraction) | 1 | P2 misread constraint → greedy wrong |
| B. Algorithm selection error | 1 | P4 chose wrong greedy order |
| C. Boundary / edge case | 0 | — |
| D. Code / syntax bug | 1 | P2 index issue after fix |
| **Total** | 3 | over 5 problems |

### Workflow check
- Which step took the longest? `Step2 Algorithm Selection — greedy ordering logic`
- Did I skip any step? `No, followed all 5 steps every problem`
- Rating of workflow this week (1–10): `7`

### Algorithm / pattern learned this week
- Greedy usually works when: local optimal choice is also globally optimal.
- Common USACO Bronze greedy trick: **sort first, then decide order** (P3, P4).
- Watch out: greedy fails when choosing an item affects later choices — that's a signal for DP instead.

### Problems / blockers
- P4: my greedy rule didn't hold; needed to re-order by a different key.
- Time management: spent too long debugging P2; should have re-read constraints earlier (Step1).

### Next week's plan
- Month1 Week3: basic array + simple math problems, focus on Step4 boundary & edge case prediction.
- Keep using v0.0; collect Type-C boundary bug data.
- Target: 4–6 problems.

---
## Weekly Summary (to fill at month end)
| Metric | This week | Cumulative |
|--------|-----------|------------|
| Problems attempted | 5 | 9 |
| Problems solved | 4 | 8 |
| Solve rate | 80% | 89% |
| Avg time to solve | 43 min | 41 min |
| Confidence (1–10) | 6 | 6 |
