# Weekly Log
Week of `2026‑11‑23` (Week 7 / 16)

### Goals for this week
- [x] Continue Silver‑level practice under methodology v1.0, keep timing & bug‑classification schema consistent
- [x] Cover core Silver patterns: greedy suffix‑max, line‑sweep interval, modified‑BFS, reverse‑simulation DSU, queue‑driven simulation, functional‑graph cycle detection
- [x] Strictly follow full 5‑step modeling workflow for each problem, no skipping pre‑code analysis
- [x] Aggregate Week 7 baseline experiment data at week‑end

### Problems attempted
| Problem | Source | Status | Total Time | Model type | Notes |
|---------|--------|--------|------------|------------|-------|
| Travel (suffix‑max greedy) | 2018 Feb Silver P1 | ____ | ____ min | Greedy suffix‑max linear scan | Day2, only visit suffix‑max enjoyment stops, long long for large coordinates |
| Monitoring | 2018 Jan Silver P1 | ____ | ____ min | Line‑sweep interval event scan | Day3, compute uniquely‑covered time for each guard; answer = total − min(lost[i]) |
| Switch on the Lights | 2015 Dec Silver P1 | ____ | ____ min | Modified BFS two‑state grid | Day4, separate `light`(light‑on) and `vis`(physically‑visited); 1‑based grid |
| Closing the Farm | 2016 USOpen Silver P3 | ____ | ____ min | Reverse‑simulation + DSU | Day5, turn node‑deletion into node‑addition; reverse answer list before output |
| Comfortable Cows | 2021 Feb Silver P1 | ____ | ____ min | Queue‑driven chain‑reaction simulation | Day6, coordinate offset SHIFT=2000 for negative coordinates; auto‑spawn chain |
| Functional‑Graph Cycle | 2022 USOpen Silver P1 | ____ | ____ min | Functional‑graph 3‑state iterative cycle detection | Day7, each cycle remove min‑value node; three‑color visited marker; 1‑based nodes |

> Note: Day 1 reserved for DFS / backtracking entry practice (not completed this week).

### Bug Classification Summary (Experiment Core Data)
| Bug type | Count | Example / note |
|----------|-------|----------------|
| A. Model error (wrong abstraction) | ____ | Confuse “light‑on” and “physically‑visited”; misunderstand functional‑graph rule for cycles |
| B. Algorithm selection error | ____ | Try repeated DFS after every deletion instead of reverse‑DSU; full‑grid rescan for comfortable‑cows |
| C. Boundary / edge‑case bug | ____ | Off‑by‑one; 1‑based / 0‑based mix‑up; forgetting to reverse answer array; missing coordinate offset for negative numbers; three‑state visited mis‑use |
| D. Code / syntax bug | ____ | Missing `long long` for sums / coordinates; wrong event encoding; mishandling component‑count updates |
| **Total** | ____ | across Week 7 solved problems |

### Workflow check
- Which step took the longest? `____`
- Did I skip any step? `____`
- Rating of workflow this week (1–10): `____`

### Algorithm / pattern learned this week
1. **Suffix‑max greedy**: When you only want optimal candidates going forward, pre‑compute suffix‑maximum array and one‑pass filter valid choices. Greedy justification is the main thinking hurdle.
2. **Line‑sweep for intervals**: Represent start/end as sorted events. Compute global metrics and per‑object contribution in one pass. Watch event processing order: calculate time segment **before** applying current event.
3. **Modified‑BFS two‑state grid**: Some grid problems separate “condition satisfied” from “physically reachable”. Do not merge the two boolean states into one array.
4. **Reverse‑simulation trick for DSU**: DSU cannot delete nodes. If problem gives deletion sequence, invert time‑direction and simulate additions; remember to reverse your final answers.
5. **Queue‑driven chain‑reaction simulation**: When changes trigger further changes, only enqueue cells whose local environment has changed, avoid brute‑force full‑space rescans. Use coordinate offset for negative indices in array‑based grid.
6. **Functional‑graph (each node exactly one outgoing edge)**: Structure = trees feeding into cycles. Iterative three‑color visited (0‑unvisited, 1‑visiting‑in‑path, 2‑processed) safely detects cycles without recursion stack‑overflow risk. For each cycle pick min/max element according to problem requirement.

### Problems / blockers
- Many Category‑C boundary bugs this week: index base confusion, answer‑list reversal, coordinate offset, mis‑using two‑state instead of three‑state visited. These are predictable in Step 4 but easy to overlook during coding.
- Conceptual‑model errors (Category A) happen when mixing‑up two separate logical states (light‑on vs visited; visiting vs processed node markers). Step 1 restatement needs to explicitly write‑out each independent boolean flag.
- For simulation problems, it is easy to forget which side of event‑loop to compute delta / contribution (before or after consuming event).
- Long‑long overflow risk persists for coordinate‑based and summation problems; should add to Step 4 invariant checklist.

### Next week's plan (Week 8)
- Week 8: Focus on DFS / backtracking, subset / permutation / combinatorial search, plus prefix‑sum & difference‑array harder Silver exercises.
- Keep methodology v1.0; for DFS explicitly write in Step 3: **state, available choices, termination condition, restore‑state(back‑track)**. Track recursion‑related bugs (wrong base‑case, missing restore‑state, visited‑array mistakes).
- Target: 6‑7 problems (mix of back‑tracking and prefix‑sum / difference‑array Silver).

---
## Weekly Summary (to fill after finishing week)
| Metric | This week | Cumulative (W1‑W7) |
|--------|-----------|--------------------|
| Problems attempted | 6 | ____ |
| Problems solved | ____ | ____ |
| Solve rate | ____ | ____ |
| Avg time to solve | ____ min | ____ min |
| Confidence (1–10) | ____ | ____ |

> Short take‑away Week 7: Moved further into classic Silver‑level patterns. Many bugs are no longer pure “read‑the‑text wrong”, but subtle invariant / boundary maintenance errors. Step 4 pre‑modeling edge‑case checklist becomes more important to catch these before coding.
