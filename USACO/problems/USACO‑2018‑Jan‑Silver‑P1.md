# Problem Info
- Name: MooTube Monitoring (Monitoring)
- Source: USACO 2018 January Silver P1
- Difficulty (self‑rated): ____ (1–10)
- Date attempted: ____ (YYYY‑MM‑DD)
- Status: ____ (Not started / In progress / Solved / Stuck / Solved with help)
- Time spent: ____ min

## Step 1 — Read & Restate
We have N guards. Each guard works time interval `[s, e]`.
We sweep over start‑/end‑point events sorted by time.
`total`: total length of time covered by **at least one guard**.
`lost[i]`: amount of time where **guard i is the only active guard**.
If we remove exactly one guard i, the new covered time = `total − lost[i]`.
We want to maximize remaining covered time, which equals `total − min(lost[i])`.
Output that maximum value.

Event encoding rule:
- `(s, i)` → guard i starts working (id ≥0)
- `(e, -i‑1)` → guard i stops working (negative encoded id)

| Item | Value |
|------|-------|
| Input | N; N pairs s e (start, end time for each guard) |
| Output | maximum covered time after deleting exactly one guard |
| Constraints | Times can be large; use long long for all time variables |
| Edge cases | Multiple guards overlap; time segment with exactly one active guard; zero unique‑time for a guard; events with equal timestamp |

## Step 2 — Model
- Model type: Line sweep (scan‑line) over interval events
- Explanation:
1. Generate two events per guard: start event, encoded end event.
2. Sort all events by time t.
3. Iterate events, maintain `active` list of currently‑on guards, `cnt` active count.
4. Between `prev_t` and current t: if `cnt>0`, add duration to `total`.
   If `cnt == 1`, add this duration to `lost[only‑active‑guard]`.
5. Process event: start adds guard into active list; end removes guard from active list.
6. After sweep, find `min_lost = min(lost array)`. Answer = `total − min_lost`.

## Step 3 — Algorithm
- Algorithm chosen: Line sweep / event sweep
- Time complexity: O(N²) worst‑case, because erasing element from vector active is O(N). N ≤ 250 fits constraints.
- Space complexity: O(N)
- Why it fits: N small (250). Straightforward sweep‑line implementation.

## Step 4 — Implementation Notes
- Data structures used: `guard` store intervals; `events` vector of pair<ll,int>; `active` vector for current active guard ids; `lost[]` accumulate unique‑coverage time; `total` total covered time.
- Pitfalls / bugs I hit: ____
  1. Time variables `t, s, e, total, lost[]` must be `long long`.
  2. End‑event encoding: `-i‑1`; decode: `rid = -id -1`.
  3. Compute time segment `t‑prev_t` **before** processing current event.
  4. Only when `cnt == 1` we add duration to `lost[only‑active‑guard]`.
  5. Erase element from `active` vector: linear search to find id then erase.
  6. `prev_t != -1` guard for first segment (skip dummy initial prev_t).

## Step 5 — Verification
- [ ] Pass official sample input
- [ ] Test guard with zero unique‑time contribution
- [ ] Test multiple overlapping intervals
- [ ] Test events with equal timestamps

## Reflection (fill AFTER solving)
- What was the hardest part? ____
- Did I follow the workflow, or skip a step? ____
- If stuck: where did I get stuck and what unblocked me? ____
- One thing to improve next time: ____
