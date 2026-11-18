# Problem Info
- Name: Convention
- Source: USACO 2018 December Silver P2
- Difficulty (self‑rated): ____ (1–10)
- Date attempted: ____ (YYYY‑MM‑DD)
- Status: ____ (Not started / In progress / Solved / Stuck / Solved with help)
- Time spent: ____ min

## Step 1 — Read & Restate
We have N cows. Each cow has arrival time `a` and eating time `t`.
Cows arrive at their arrival time `a`. If the dining spot is free when a cow arrives, it starts eating immediately.
If multiple cows have arrived but are waiting, we pick the cow with the **smallest original input id** to eat next (min‑id priority queue).
`wait time = start_eat_time − arrival_time`.
Find the **maximum waiting time** among all cows.

| Item | Value |
|------|-------|
| Input | N; N pairs a t (arrival time, time to eat); each cow has original input id |
| Output | maximum wait time of any cow |
| Constraints | N ≤ 100 000; use long long for time variables |
| Edge cases | No cows waiting, now jumps forward to next arrival time; many cows pile‑up at same arrival time; one cow at a time, zero wait time |

## Step 2 — Model
- Model type: Event simulation + min‑heap(priority‑queue) greedy scheduling
- Explanation:
1. Keep original id and (a,t) info array. Sort cows by arrival time `a`.
2. Variable `now`: current simulation clock time.
3. `ptr`: pointer over sorted cow list. Add all cows whose `a <= now` into min‑id priority‑queue.
4. If heap is not empty: take smallest id cow, compute its wait time, update max_wait; advance `now` by its eating time `t`.
5. If heap empty: jump `now` directly to next cow’s arrival time `cows[ptr].a`.
6. Loop until all cows processed (ptr == N and pq empty).

## Step 3 — Algorithm
- Algorithm chosen: Sort arrival times + min‑id priority‑queue simulation
- Time complexity: O(N log N). Sort O(N log N); each heap push/pop O(log N).
- Space complexity: O(N)
- Why it fits: N up to 1e5; simulation with heap avoids O(N²) naive simulation.

## Step 4 — Implementation Notes
- Data structures used: `struct Cow{a,t,id}`; `info[]` store original a,t by id; min‑heap priority_queue (greater<int>) for cow id; `now, max_wait` long long
- Pitfalls / bugs I hit: ____
  1. Time variables (`now`, wait, a, t) must be `long long` to avoid integer overflow.
  2. Sort cows by arrival `a`; if arrival equal sort by id.
  3. Min‑heap stores **original input id**, not index in sorted array. Need separate info array to look up a,t by id.
  4. When pq empty: do not increment now; set `now = cows[ptr].a` jump to next arrival.
  5. Outer loop condition: `ptr < N OR !pq.empty()`.

## Step 5 — Verification
- [ ] Pass official sample input
- [ ] Test no waiting cows (max_wait = 0)
- [ ] Test multiple cows arrive at same time
- [ ] Test gaps between arrival events (heap empty jump forward)

## Reflection (fill AFTER solving)
- What was the hardest part? ____
- Did I follow the workflow, or skip a step? ____
- If stuck: where did I get stuck and what unblocked me? ____
- One thing to improve next time: ____
