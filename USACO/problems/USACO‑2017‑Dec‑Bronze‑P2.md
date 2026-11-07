# Problem Info
- Name: The Bovine Shuffle
- Source: USACO 2017 December Bronze P2
- Difficulty (self‑rated): ____ (1–10)
- Date attempted: ____ (YYYY‑MM‑DD)
- Status: ____ (Not started / In progress / Solved / Stuck / Solved with help)
- Time spent: ____ min

## Step 1 — Read & Restate
We have N positions. Array `a[]` defines shuffle rule: position i gets its new value from position `a[i]` in previous round.
Given initial state `current_cows[1…N]`. Apply this shuffle transformation exactly 3 times. Output final array after three shuffles.
All arrays use 1‑based indexing.

| Item | Value |
|------|-------|
| Input | N; array a[1..N]; initial current_cows[1..N] |
| Output | array after applying shuffle 3 times |
| Constraints | 1‑based index; exactly three iterations of shuffle |
| Edge cases | N small; applying shuffle multiple times; must use previous‑step snapshot, cannot overwrite array while computing one step |

## Step 2 — Model
- Model type: Array permutation simulation
- Explanation:
Each shuffle step cannot overwrite `current_cows` while computing; we need a separate snapshot array `prev_cows` to store the result of this step.
For each position i: `prev_cows[i] = current_cows[ a[i] ]`
After filling entire `prev_cows`, assign `current_cows = prev_cows` to complete one shuffle round. Repeat for total of three steps.

## Step 3 — Algorithm
- Algorithm chosen: Direct simulation of permutation shuffle for exactly three rounds
- Time complexity: O(3*N) = O(N)
- Space complexity: O(N), two arrays for current and previous state
- Why it fits: Only need exactly three iterations; no need to compute permutation exponent / cycle decomposition; straightforward simulation is simplest.

## Step 4 — Implementation Notes
- Data structures used: `vector<int> a(N+1)`, `current_cows(N+1)`, `prev_cows(N+1)`, all 1‑based
- Pitfalls / bugs I hit: ____
  1. Must use separate `prev_cows` buffer for each step. Cannot compute in‑place on current_cows, otherwise values get overwritten mid‑step.
  2. Exactly run step loop 3 times, not N times, not until convergence.
  3. 1‑based indexing, do not access index 0.
  4. Assignment order: fill the whole prev_cows first, then copy to current_cows.

## Step 5 — Verification
- [ ] Pass official sample input
- [ ] Trace manually for tiny N case (N=2 or N=3)
- [ ] Confirm exactly three shuffle applications
- [ ] Check no in‑place overwrite corruption

## Reflection (fill AFTER solving)
- What was the hardest part? ____
- Did I follow the workflow, or skip a step? ____
- If stuck: where did I get stuck and what unblocked me? ____
- One thing to improve next time: ____
