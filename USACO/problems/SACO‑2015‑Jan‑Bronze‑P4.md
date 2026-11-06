# Problem Info
- Name: Cow Route
- Source: USACO 2015 January Bronze P4
- Difficulty (self‑rated): ____ (1–10)
- Date attempted: ____ (YYYY‑MM‑DD)
- Status: ____ (Not started / In progress / Solved / Stuck / Solved with help)
- Time spent: ____ min

## Step 1 — Read & Restate
We have A (start city), B (target city), N bus routes.
Each bus route has a cost, and an ordered list of cities the bus visits in sequence.
A bus route is usable only if city A appears **before** city B in its city list.
We want the minimum cost among all valid bus routes.
If no valid route exists, output -1.

| Item | Value |
|------|-------|
| Input | A B N; for each route: cost m followed by m city numbers |
| Output | minimum cost of valid route; -1 if none |
| Constraints | Small N and m; brute‑force check every route is acceptable |
| Edge cases | A and B appear consecutively; A appears but B comes before A in list; A or B missing in route; no valid route → output‑1; multiple valid routes pick smallest cost |

## Step 2 — Model
- Model type: Brute‑force enumeration over bus routes, sequential scan for order condition
- Explanation:
Iterate each bus route:
Scan its city list from left to right.
Set flag `foundA=true` once we encounter city A.
After we have seen A, if we later encounter B → this route is valid.
Record minimal cost among all valid routes.
If ans remains initial large sentinel value, output -1.

## Step 3 — Algorithm
- Algorithm chosen: Brute‑force check each bus route, linear scan city sequence
- Time complexity: O(N * m), N routes, m average cities per route
- Space complexity: O(m), store city list for single route
- Why it fits: Input scale small; no need for graph / shortest‑path algorithm; only direct single‑bus routes are allowed.

## Step 4 — Implementation Notes
- Data structures used: `vector<int> cities` for one route’s city list; boolean flags `foundA, valid`; `ans = INT_MAX` as sentinel
- Pitfalls / bugs I hit: ____
  1. Condition: A must appear **before** B, not just both present in list. If B comes before A, route invalid.
  2. Sentinel initial value `INT_MAX` from `<climits>`. Must check if ans unchanged to output -1.
  3. Once `foundA && city==B`, set valid and break scanning early.
  4. Do not misinterpret problem: we can only take one single bus route, cannot transfer across multiple buses.

## Step 5 — Verification
- [ ] Pass official sample input
- [ ] Test case B appears before A in route → invalid
- [ ] Test A and B consecutive in order A then B
- [ ] Zero valid routes → output -1
- [ ] Multiple valid routes, select minimum cost

## Reflection (fill AFTER solving)
- What was the hardest part? ____
- Did I follow the workflow, or skip a step? ____
- If stuck: where did I get stuck and what unblocked me? ____
- One thing to improve next time: ____
