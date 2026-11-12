# Weekly Log
Week of `2026-11-02` (Week 5 / 16)

### Goals for this week
- [x] Run Month2 baseline under methodology v1.0, continue collecting experiment timing & bug data
- [x] Review foundational algorithms: prefix sum, same-direction two-pointer sliding window
- [x] Practice USACO Bronze classic linear scan, greedy, graph/in-degree, grid pattern checking problems
- [x] Strictly follow the 5-step modeling workflow for every problem, no skipping pre-code modeling
- [x] Aggregate all Week5 baseline data at week end, summarize bug distribution
- [x] Compare workflow performance between v0.0 (Month1) and v1.0 (Month2)

### Problems attempted
| Problem | Source | Status(AC/WA/TLE) | Total Time | Model type | Notes |
|---------|--------|--------|------|------------|-------|
| Prefix Sum Practice | Self-practice | ____ | ____ min | Prefix sum / static range sum | Week5 Day1, 1‑based, long long overflow guard |
| Same‑Direction Two‑Pointers Practice (Sliding Window) | Self-practice | ____ | ____ min | Sliding window / monotonic two pointers | Week5 Day2, positive array only, while vs if shrink trap |
| Uddered but not Herd | USACO 2021 Jan Bronze P1 | ____ | ____ min | Character rank mapping + linear scan | Week5 Day3, custom alphabet order, <= reset condition |
| Even More Odd Photos | USACO 2021 Jan Bronze P2 | ____ | ____ min | Greedy parity count simulation | Week5 Day4, even‑odd alternating sequence, final leftover correction |
| Nearest Neighbor Jump Graph | USACO 2018 Feb Bronze P2 | ____ | ____ min | Directed graph + in-degree counting + special case correction | Week5 Day5, sort first, tiebreak left, two-node cycle fix |
| Cow Route | USACO 2015 Jan Bronze P4 | ____ | ____ min | Brute force sequential condition check | Week5 Day6, single bus only, A must appear before B, no transfers |
| Clue | USACO 2014 Dec Bronze P2 | ____ | ____ min | Grid brute scan + boundary checking | Week5 Day7, 0‑based internal / 1‑based output, out‑of-bounds guard |

### Bug Classification Summary (Experiment Core Data)
| Bug type | Count | Example / note |
|----------|-------|----------------|
| A. Model error (wrong abstraction) | ____ | Misread problem rules, misinterpret allowed operations (e.g. allowing bus transfer) |
| B. Algorithm selection error | ____ | Overcomplicate simple check with Dijkstra / flood fill when brute force suffices |
| C. Boundary / edge case | ____ | Off-by-one, index base conversion, out-of-bounds array access, missing special correction logic |
| D. Code / syntax bug | ____ | Mixing up if/while, forgetting long long, wrong boolean comparison (< vs <=) |
| **Total** | ____ | across all Week5 problems |

### Workflow check
- Which step took the longest? `____`
- Did I skip any step? `____`
- Rating of workflow this week (1–10): `____`

### Algorithm / pattern learned this week
- Prefix sum gives O(1) range queries after O(n) precompute; static arrays, no updates. Always watch for integer overflow with long long.
- Same-direction sliding window only works safely when array sum is monotonic (all positive values). Shrink window with while, not if.
- Custom ordering problems are often solved by building a rank/position lookup table first, then one linear pass.
- Greedy simulation problems that alternate states often have a hidden final correction step after the main loop finishes.
- Small directed functional graphs (each node has exactly one outgoing edge) can be analyzed with in-degree counting, but 2-node cycles are a common special case that breaks simple source counting.
- When the problem only asks for a condition check on a sequence, do not automatically jump to shortest path algorithms — confirm whether transfers/multiple steps are permitted.
- Grid pattern checking needs strict boundary guards before accessing neighboring cells; separate internal 0‑based indices from 1‑based output coordinates.

### Problems / blockers
- The highest-frequency trap this week was **hidden special correction rules** (two-node cycle fix, leftover cow subtraction). These are easy to miss during initial reading and only surface after sample or edge-case testing.
- Logical condition nuance: `<` vs `<=`, `if` vs `while` are small syntax differences but completely change correctness.
- Grid and index conversion is a persistent source of boundary bugs, even when explicitly noted in Step4 modeling.
- Model abstraction error risk remains high when problems sound like standard graph/shortest-path problems but have restrictive rules (single bus only).

### Next week's plan
- Week 6: formal DFS / recursive search practice (backtracking subset & permutation search)
- Continue using methodology v1.0, keep identical data collection schema for fair comparison
- Focus new bug capture on recursion stack, visited marking, state reset in backtracking
- Target: 5–7 Bronze / easy Silver DFS/backtracking problems

---
## Weekly Summary (to fill)
| Metric | This week | Cumulative (W1+W2+W3+W4+W5) |
|--------|-----------|------------|
| Problems attempted | 7 | ____ |
| Problems solved | ____ | ____ |
| Solve rate | ____ | ____ |
| Avg time to solve | ____ min | ____ min |
| Confidence (1–10) | ____ | ____ |
