# Weekly Log
Week of `2026-10-23` (Week 4 / 16)

### Goals for this week
- [x] Complete mixed Bronze review problems using the 5-step modeling process (v0.0)
- [x] Continue collecting baseline experiment data, cover simulation, greedy, array, permutation/constraint, event collision, graph coloring problems
- [x] No skipping pre-code modeling steps
- [x] Aggregate all Week1–Week4 baseline data at week end
- [x] Summarize bug distribution, decide revision plan for v1.0 methodology

### Problems attempted
| Problem | Source | Status(AC/WA/TLE) | Total Time | Model type | Notes |
|---------|--------|--------|------|------------|-------|
| Lineup | USACO Bronze | AC | 47 min | Permutation + adjacency constraint | Week4 Day1, brute force all permutations |
| Grazing Collision | USACO Bronze | ____ | ____ min | Event-driven collision timing | Week4 Day3, only E-N pairs can intersect, process events chronologically |
| Daisy Chains | USACO 2020 Dec Bronze P2 | ____ | ____ min | Brute-force subarray enumeration | Week4 Day4, triple loop, check average exists inside subarray |
| Social Distancing (Posts) | USACO 2020 Feb Bronze P1 | ____ | ____ min | Brute-force geometry enumeration | Week4 Day5, fourth rectangle corner does not need to exist in input |
| Word Processor | USACO 2020 Jan Bronze P1 | ____ | ____ min | Greedy line-wrapping simulation | Week4 Day6, spaces do not count toward width limit K |
| 4-Coloring Graph | USACO 2019 Feb Bronze P2 | ____ | ____ min | Greedy graph coloring | Week4 Day7, undirected graph, pick smallest available color from 1~4 |

### Bug Classification Summary (Experiment Core Data)
| Bug type | Count | Example / note |
|----------|-------|----------------|
| A. Model error (wrong abstraction) | ____ | Misinterpret rule / problem definition |
| B. Algorithm selection error | ____ | Wrong algorithm choice, overcomplicate or undercomplicate |
| C. Boundary / edge case | ____ | Off-by-one, forgotten last line, same arrival time collision |
| D. Code / syntax bug | ____ | Direction of graph edges, index base confusion |
| **Total** | ____ | across all Week4 problems |

### Workflow check
- Which step took the longest? `____`
- Did I skip any step? `____`
- Rating of workflow this week (1–10): `____`

### Algorithm / pattern learned this week
- When coordinates are huge (up to 1e9), we cannot simulate grid step-by-step; we must compute collision timings mathematically and process events sorted by time.
- For small N (N ≤ 100), brute triple loops (O(N³)) are acceptable in Bronze; no need for complex optimizations.
- Read rules carefully for counting traps: separators/spaces sometimes are excluded from the limit.
- Greedy coloring works when only any valid coloring is required (not minimal colors); 4-color guarantee means no backtracking needed.
- Undirected graphs require adding edges in both directions; 1-based indexing is a frequent source of off-by-one bugs.

### Problems / blockers
- It is easy to misread subtle problem rules (like whether spaces count, whether the 4th corner needs to exist, simultaneous arrival does not block cows). These belong to model abstraction bugs.
- When multiple collision events exist for one cow, it is easy to forget to check whether the blocker itself has already been blocked before this event.
- It takes extra effort to explicitly enumerate edge cases during Step4 before coding.

### Next week's plan
- Start Month 2 (Week 5), target recursive DFS / search problems
- Upgrade methodology to v1.0, add small improvements from Month1 baseline findings
- Keep all experiment recording rules unchanged
- Target: 4–6 DFS / recursive Bronze & easy Silver problems

---
## Weekly Summary (to fill at month end)
| Metric | This week | Cumulative (W1+W2+W3+W4) |
|--------|-----------|------------|
| Problems attempted | 6 | ____ |
| Problems solved | ____ | ____ |
| Solve rate | ____ | ____ |
| Avg time to solve | ____ min | ____ min |
| Confidence (1–10) | ____ | ____ |
