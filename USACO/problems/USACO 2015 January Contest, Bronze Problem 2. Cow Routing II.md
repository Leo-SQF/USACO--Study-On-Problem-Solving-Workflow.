# Problem Template

<!-- One copy of this file per problem. Save as:
problems/<topic>/<problem-name>.md
Fill every section BEFORE coding (model first!), and reflect AFTER. -->## Problem Info

- **Name:** `Cow Routes`
- **Source:** `USACO 2015 January Bronze P3`
- **Difficulty (self-rated):** `4/10`
- **Date attempted:** `2026-10-09`
- **Status:** `Not started`
- **Time spent:** `XX min`

---

## Step 1 — Read & Restate

> 
> Bessie can use at most two airline routes to travel from city A to city B.
> Each route is a sequence of unique cities. If Bessie uses any segment of a route, she pays the full cost of that route.
> On one route, she may board at an earlier city and get off at a later city along the sequence.
> Two routes can be connected by transferring at a shared city: she arrives at transfer city X on route 1, then departs X on route 2.
> We need to find the minimal total cost. If no valid trip exists, output -1.

表格

| Item | Value |
| --- | --- |
| Input | First line: A, B, N. Next 2N lines describe N routes. For each route: one line with cost and number of cities; next line lists cities in travel order. |
| Output | Minimum cost using at most two routes; output -1 if impossible. |
| Constraint on N | \(1 \le N \le 500\); each route has at most 500 cities. City IDs: \(1\ldots10000\) |
| Edge cases | Direct trip with only one route; no valid routes; multiple transfer cities; transfer city equals A or B. |

---

## Step 2 — Model

- Model type: `precomputation / graph cost lookup`
- Explanation:
We maintain two arrays:

1. `distA[X]`: minimum cost of a single route that can take Bessie from A to city X.
2. `distB[X]`: minimum cost of a single route that can take Bessie from city X to B.

We have two possible cases:

1. **Single route**: A appears before B on the same route. Cost = route cost.
2. **Two routes**: A → X using route 1, then X → B using route 2. Total cost = `distA[X] + distB[X]`.
The final answer is the minimum value over all valid options.

---

## Step 3 — Algorithm

- Algorithm chosen: `precompute minimum cost tables, then check all transfer cities`
- Time complexity: \(O(N \cdot M)\), N = number of routes, M = maximum cities per route.
- Space complexity: \(O(C)\), \(C = 10000\), for storing `distA` and `distB`.
- Why it fits the constraints:
\(N=500, M=500\), total operations are 250,000. This is very fast and well within time limits.

---

## Step 4 — Implementation Notes

- Data structures used: `vector<int> for routes; two arrays distA, distB initialized to INT_MAX`
- Pitfalls / bugs I hit:

1. City IDs can be up to 10000, so array size must be at least 10001.
2. Do NOT forget the single-route case.
3. For `distA[X]`: if A is found at position posA on a route, all cities after posA can be reached from A on this route. Update if cheaper.
4. For `distB[X]`: if B is found at position posB on a route, all cities before posB can reach B on this route. Update if cheaper.
5. Avoid integer overflow when adding two INT_MAX values. Only sum when both values are not infinity.

---

## Step 5 — Verification

- Passes provided samples
- Passes my edge cases
- Within time limit
- Brute-force cross-check (if applicable)

---

## Reflection (fill AFTER solving)

- What was the hardest part? `...`
- Did I follow the workflow, or skip a step? `...`
- If stuck: where did I get stuck and what unblocked me? `...`
- One thing to improve next time: `...`
