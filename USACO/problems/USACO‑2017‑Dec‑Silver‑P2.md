# Problem Info
- Name: Milk Measurement
- Source: USACO 2017 December Silver P2
- Difficulty (self‑rated): ____ (1–10)
- Date attempted: ____ (YYYY‑MM‑DD)
- Status: ____ (Not started / In progress / Solved / Stuck / Solved with help)
- Time spent: ____ min

## Step 1 — Read & Restate
We have N event records. Each record: `day, cow_id, delta` — on given day, change milk production of one cow by delta value.
All events are first sorted by day.
A cow’s default milk production is **G**.
We maintain global leader state:
- If the current maximum milk value among cows > G: leader value = this maximum value.
- Else: leader value = G (meaning no cow exceeds baseline).

Every time after processing an event, if the global leader state (leader_value, count_of_cows_with_that_max) changes, increment answer by one.
Output total number of leader‑state changes.

| Item | Value |
|------|-------|
| Input | N G; N lines day cow_id delta |
| Output | total number of leader‑state transitions |
| Constraints | N ≤ 100 000; cow_id can be large long long; need fast ordered map for frequency statistics |
| Edge cases | cow appears for first time; multiple cows share maximum value; max value drops back ≤G; frequency count becomes zero must erase key from map |

## Step 2 — Model
- Model type: Offline event‑simulation, two‑hash‑map / ordered‑map for frequency tracking
- Explanation:
1. Sort all events by day.
2. `cow_milk`: unordered_map, map cow_id → current milk value (default G if not present).
3. `freq`: ordered map(map<ll,int>): key=milk‑value, value=how many cows currently have this milk value.
4. Lambda `get_state()` returns current leader state pair `(leader_value, count_at_leader)`.
5. For each event:
    - Read old milk value of this cow.
    - Decrement freq[oldv]; erase key if count becomes zero.
    - Compute newv = oldv + delta; update cow_milk, increment freq[newv].
    - Compare `old_state` and `new_state`. If different → ans += 1.

## Step 3 — Algorithm
- Algorithm chosen: Sort events; simulate day‑by‑day using hash‑map for cow values + ordered map for value frequency.
- Time complexity: O(N log N). Sort events O(N log N); each map insert/erase O(log M), M distinct milk values.
- Space complexity: O(N)
- Why it fits: N up to 1e5, need O(logN) per‑event operations; cannot brute scan all cows every event.

## Step 4 — Implementation Notes
- Data structures used:
  `vector<tuple<int,ll,int>> records`;
  `unordered_map<ll,ll> cow_milk` cow id → milk value;
  `map<ll,int> freq` ordered map milk‑value → cow‑count.
- Pitfalls / bugs I hit: ____
  1. Cow’s initial value is G; do not store G inside cow_milk until first modification.
  2. When `freq[oldv]--` reaches zero: **must erase key from freq**, otherwise rbegin() gives stale entries.
  3. `get_state()`: if freq empty OR max_val ≤ G → leader state is (G, 1e18).
  4. State is pair **(max_value, number_of_cows_at_max)**, both parts must be equal to count as unchanged.
  5. Types: cow_id, milk value use `long long` to avoid overflow.
  6. Events must be sorted by day before processing.

## Step 5 — Verification
- [ ] Pass official sample input
- [ ] Test cow appearing for first‑time modification
- [ ] Test multiple cows share maximum value
- [ ] Test maximum falls back below or equal G
- [ ] Test freq key erase when count zero

## Reflection (fill AFTER solving)
- What was the hardest part? ____
- Did I follow the workflow, or skip a step? ____
- If stuck: where did I get stuck and what unblocked me? ____
- One thing to improve next time: ____
