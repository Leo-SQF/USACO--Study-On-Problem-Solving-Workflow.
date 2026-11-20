# Problem Info
- Name: Snow Boots (Silver / Snow Boots on the Way)
- Source: USACO 2018 February Silver P1
- Difficulty (self‑rated): ____ (1–10)
- Date attempted: ____ (YYYY‑MM‑DD)
- Status: ____ (Not started / In progress / Solved / Stuck / Solved with help)
- Time spent: ____ min

## Step 1 — Read & Restate
Road total length L. There are N scenic stops along the road.
`stops[i] = (x, c)`: position x, enjoyment value c at this stop.
Forward speed rF, backward speed rB; `rF > rB`.
We travel from position 0 to L. We may turn back to visit stops, but optimal strategy only visits stops in order of increasing x, and only stops which have maximum enjoyment among all stops from current position onward.

`suf[i]`: suffix‑maximum array, `suf[i] = max(stops[i].c, suf[i+1])`.
When stop i satisfies `c == suf[i]`, this is a worthwhile stop.
Distance from previous worthwhile stop: `dx = x − last_x`.
Extra time cost for this segment: `dx * (rF − rB)`.
Add contribution `extra_time * c` to total answer.
Update `last_x = x`.
Output total maximum achievable enjoyment‑time product sum.

| Item | Value |
|------|-------|
| Input | L N rF rB; N pairs (x, c) for stops |
| Output | total maximum value (long long) |
| Constraints | Positions L, x are large; N ≤ 100 000; use long long for all calculations |
| Edge cases | No worthwhile stop after current point; first worthwhile stop at i=0; multiple stops share same suffix‑max value |

## Step 2 — Model
- Model type: Suffix‑maximum greedy scan
- Explanation:
Since forward speed is faster than backward speed `rF > rB`. It only makes sense to visit a stop if it is the maximum enjoyment stop remaining ahead.
1. Build suffix‑max array `suf[]` from right to left. `suf[i]` is maximum c from stop i to stop N‑1.
2. Iterate stops left‑to‑right. Whenever current stop’s c equals `suf[i]`, this is a selected stop.
3. Compute distance `dx` from last selected stop.
4. The extra time compared to just rushing forward: `dx*(rF‑rB)`. Multiply by enjoyment c and accumulate answer.
5. Update `last_x` to current stop position.

## Step 3 — Algorithm
- Algorithm chosen: Suffix‑maximum pre‑compute + one‑pass greedy linear scan
- Time complexity: O(N)
- Space complexity: O(N) for suffix array
- Why it fits: N up to 1e5; linear pass is optimal, no need for DP or complex simulation.

## Step 4 — Implementation Notes
- Data structures used: `vector<pair<ll,ll>> stops`; `vector<ll> suf(N+1,0)` suffix‑max; variables `ans, last_x` as long long
- Pitfalls / bugs I hit: ____
  1. All position / time / answer variables **must be `long long`**, values can be huge.
  2. Suffix array is built backwards: iterate i from N‑1 down to 0.
  3. Condition `c == suf[i]` selects worthwhile stops.
  4. `dx = x ‑ last_x`, not absolute value; x strictly increases.
  5. Formula: `extra_time = dx * (rF‑rB)`, contribution `extra_time * c`.
  6. `rF > rB` guaranteed by problem statement.

## Step 5 — Verification
- [ ] Pass official sample input
- [ ] Test first stop is worthwhile
- [ ] Test multiple consecutive non‑worthwhile stops skipped
- [ ] Test multiple stops share same suffix‑max enjoyment

## Reflection (fill AFTER solving)
- What was the hardest part? ____
- Did I follow the workflow, or skip a step? ____
- If stuck: where did I get stuck and what unblocked me? ____
- One thing to improve next time: ____
