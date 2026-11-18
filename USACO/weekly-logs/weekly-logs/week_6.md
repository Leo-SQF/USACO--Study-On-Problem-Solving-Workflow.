# Weekly Log
Week of `2026‑11‑16` (Week 6 / 16)

### Goals for this week
- [x] Practice Silver‑level problems under methodology v1.0; keep identical timing & bug‑classification schema for fair comparison
- [x] Reinforce Bronze foundational skills: interval counting, character frequency counting, USACO file I/O
- [x] Work through core Silver patterns: enumeration with binary‑search, brute‑force over a parameter, greedy two‑pointer matching
- [x] Practice event‑driven simulation using ordered map / min‑heap priority queue
- [x] Strictly follow the full 5‑step modeling workflow; do not skip pre‑code modeling steps
- [x] Aggregate Week 6 baseline experiment data at week‑end

### Problems attempted
| Problem | Source | Status | Total Time | Model type | Notes |
|---------|--------|--------|-----------|------------|-------|
| Interval Remove | 2018 Jan Bronze P2 | ____ | ____ min | Time‑stamp frequency counting | Day1, half‑open interval `[a,b)`, must delete exactly one interval |
| Blocks | 2016 Dec Bronze P2 | ____ | ____ min | Character frequency + file I/O | Day2, use `max(c1,c2)` per‑letter, NOT sum |
| Rectangular Pasture | 2020 Dec Silver P2 | ____ | ____ min | Enumerate x‑bounds + sorted y‑list + binary search | Day3, O(N²logN), `long long`, final +1 for empty rectangle |
| Berry Picking | 2020 Jan Silver P2 | ____ | ____ min | Brute‑force over parameter x + simulation | Day4: full baskets first → remainders → zero padding, sort descending |
| High Card | 2015 Dec Silver P2 | ____ | ____ min | Greedy two‑pointer card matching | Day5: sort both lists; win advances both pointers, else discard one |
| Milk Measurement | 2017 Dec Silver P2 | ____ | ____ min | Event simulation + dual‑map dynamic maximum | Day6, leader state = (max‑value, count‑at‑max); erase keys when frequency hits zero |
| Convention | 2018 Dec Silver P2 | ____ | ____ min | Event simulation + min‑id min‑heap scheduling | Day7, original‑id mapping; jump simulation time forward when heap is empty |

### Bug Classification Summary (Experiment Core Data)
| Bug type | Count | Example / note |
|----------|-------|----------------|
| A. Model error (wrong abstraction) | ____ | Using sum instead of max; misunderstanding “must delete exactly one interval” |
| B. Algorithm selection error | ____ | Trying O(N⁴) four‑corner enumeration; rescanning all cows on every event |
| C. Boundary / edge‑case bug | ____ | Half‑open interval boundary; failing to erase zero‑frequency map keys; not jumping time on empty heap; forgetting empty‑rectangle +1 correction |
| D. Code / syntax bug | ____ | Array size insufficient (2n vs 2n+1); missing `long long`; incorrect sort order (ascending / descending) |
| **Total** | ____ | across all 7 problems |

### Workflow check
- Which step took the longest? `____`
- Did I skip any step? `____`
- Rating of workflow this week (1–10): `____`

### Algorithm / pattern learned this week
- For interval problems: always confirm closed versus half‑open semantics; small boundary differences produce completely different results.
- For “choose one of two options” problems: derive the mathematical expression for each group first (e.g. per‑letter `max(c1,c2)`), then accumulate results. Do not rely on raw intuition.
- A key Bronze‑to‑Silver optimization trick: replace brute‑force O(N⁴) four‑corner enumeration with enumerating two bounds combined with sorted‑structure + binary‑search counting (reduces complexity to O(N² log N)).
- When objective value changes with a small‑range parameter: brute‑force every candidate parameter and fully simulate each case is often safer than deriving a complex mathematical formula.
- Optimal two‑set matching greedy strategy: use the smallest possible winning element to beat the opponent’s smallest element; discard elements that cannot win any remaining opponent item. Sort + two‑pointer gives O(n log n).
- To maintain dynamic maximum efficiently: use `map<value, frequency>`, retrieve maximum via `rbegin()`. Always erase map keys when their frequency drops to zero. Do not scan all elements for maximum on every update.
- Two critical parts for event‑driven simulation: ① when to jump the simulation clock forward (jump to next event when no tasks are waiting). ② what key to store inside heap (original input id, not sorted‑array index; maintain separate lookup table).

### Problems / blockers
- Most bugs this week came from careful data‑structure maintenance (Category C): forgetting to erase zero‑frequency keys, failing to advance simulation time on empty heap, mixing‑up original‑id versus sorted‑array indices.
- State‑change conditions need precise component‑wise comparison (e.g. leader state compares **both maximum value AND count of cows at maximum**); it is error‑prone to only compare the maximum value.
- Complexity estimation is still sometimes done too late; aim to decide acceptable complexity in Step 2 according to given N constraints.
- File‑I/O habits are established for USACO problems; avoid reflexively applying `fin/fout` to standard‑input Silver problems.

### Next week's plan
- Week 7: Start DFS / backtracking practice (subsets, permutations, grid search). In Step 3 explicitly write four components: **state, available choices, termination condition, restore‑state (back‑track)**.
- Keep methodology version v1.0; add new observation categories for recursion bugs: wrong termination condition, missing visited‑array restoration, pruning‑related TLE.
- Target: 5‑7 DFS / backtracking Bronze and easy‑Silver problems.

---
## Weekly Summary (to fill after finishing week)
| Metric | This week | Cumulative (W1–W6) |
|--------|-----------|--------------------|
| Problems attempted | 7 | ____ |
| Problems solved | ____ | ____ |
| Solve rate | ____ | ____ |
| Avg time to solve | ____ min | ____ min |
| Confidence (1–10) | ____ | ____ |
