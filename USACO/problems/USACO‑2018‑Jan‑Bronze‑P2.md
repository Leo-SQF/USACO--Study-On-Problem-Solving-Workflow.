# Problem Info
- Name: MooTube (Bronze Time‑interval counting)
- Source: USACO 2018 January Bronze P2
- Difficulty (self‑rated): ____ (1–10)
- Date attempted: ____ (YYYY‑MM‑DD)
- Status: ____ (Not started / In progress / Solved / Stuck / Solved with help)
- Time spent: ____ min

## Step 1 — Read & Restate
We are given n time intervals `[start[i], end_time[i])` (half‑open interval, include start, exclude end).
`count[t]`: how many intervals cover time t.
`total_covered`: total number of distinct time points covered by any interval.
If we remove exactly one interval i: some time‑points that were **only covered by interval i(count[t]==1)** will be lost.
`lost_time` = number of such unique‑coverage time points belonging to interval i.
Answer = maximum value of `total_covered − lost_time` over removing each one interval.

| Item | Value |
|------|-------|
| Input | n; n pairs start, end_time; time range 0~1000 |
| Output | max covered time after deleting exactly one interval |
| Constraints | time value ≤1000, brute‑force array simulation feasible |
| Edge cases | intervals fully overlapping; interval contributes zero unique time; disjoint intervals; multiple intervals share all time points |

## Step 2 — Model
- Model type: Time‑stamp frequency counting / brute‑force interval simulation
- Explanation:
1. Populate count array: for each interval increment count[t] for every t in [start, end).
2. Compute total_covered: count t where count[t]>0.
3. For each candidate interval i to delete:
    count how many time t inside this interval have count[t]==1 → lost_time.
    After removing i, those t disappear from total coverage.
    candidate result = total_covered − lost_time.
4. Take maximum candidate result as answer.

## Step 3 — Algorithm
- Algorithm chosen: Brute‑force time‑array counting
- Time complexity: O(n * T), T max time =1000
- Space complexity: O(1001), fixed‑size count array
- Why it fits: Upper bound of time is small (1000). No need for difference‑array optimization for Bronze constraints.

## Step 4 — Implementation Notes
- Data structures used: `vector<int> start, end_time`; `vector<int> count(1001,0)`
- Pitfalls / bugs I hit: ____
  1. Interval is half‑open `[start, end)`, loop condition `t < end_time`, not `t <= end_time`.
  2. `lost_time` only counts t with `count[t]==1`: those time points will vanish if we remove this interval.
  3. We must remove **exactly one interval**, cannot choose remove zero intervals.
  4. Time domain is bounded 0‑1000; array size need cover up to 1000.

## Step 5 — Verification
- [ ] Pass official sample input
- [ ] Test fully overlapping intervals (lost_time=0 for inner interval)
- [ ] Test disjoint intervals: removing one loses all its own time
- [ ] Verify half‑open interval boundary

## Reflection (fill AFTER solving)
- What was the hardest part? ____
- Did I follow the workflow, or skip a step? ____
- If stuck: where did I get stuck and what unblocked me? ____
- One thing to improve next time: ____
