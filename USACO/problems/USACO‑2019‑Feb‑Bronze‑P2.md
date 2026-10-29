# Problem Info
- Name: The Bucket List‑Coloring (Paint the Barn / 4‑color assignment)
- Source: USACO 2019 February Bronze P2
- Difficulty (self‑rated): ____ (1–10)
- Date attempted: ____ (YYYY‑MM‑DD)
- Status: ____ (Not started / In progress / Solved / Stuck / Solved with help)
- Time spent: ____ min

## Step 1 — Read & Restate
We have N nodes and M undirected edges. Each edge connects two nodes. Assign each node an integer color from {1,2,3,4}.
Rule: adjacent connected nodes cannot share the same color. We just need any valid coloring solution.
Output the color for each node 1…N.

| Item | Value |
|------|-------|
| Input | N M; M pairs a b for undirected edges |
| Output | Sequence of N integers, color of each node 1~N |
| Constraints | N ≤ 100, M small; graph is guaranteed to have valid 4‑color assignment |
| Edge cases | Isolated node (no edges, can pick any color 1‑4); node with many neighbors; chain‑shaped graph |

## Step 2 — Model
- Model type: Greedy graph coloring
- Explanation:
Process nodes one‑by‑one from 1 to N.
For current node i, try color c starting from 1 upwards to 4.
Check all adjacent neighbors of i: if none of neighbors already use color c, assign color c to node i and move on.
Since problem guarantees a solution exists, we will always find one color in 1‑4.

## Step 3 — Algorithm
- Algorithm chosen: Greedy sequential graph coloring
- Time complexity: O(N*(D)), D is average degree of nodes, N ≤100 very small
- Space complexity: O(N+M), adjacency list `g[]` and color array `col[]`
- Why it fits: We do not need optimal/minimum colors; only need any valid 4‑color result. Simple greedy pass works. No complex back‑tracking needed.

## Step 4 — Implementation Notes
- Data structures used: adjacency list `vector<int> g[105]`, integer color array `col[105]`
- Pitfalls / bugs I hit: ____
  1. Graph is undirected: add edge a→b and b→a both ways.
  2. Nodes are numbered starting from **1**, not 0.
  3. Check already‑colored neighbors only; iterate color c from 1 to 4 in order.
  4. Do not break early before checking all adjacent vertices.

## Step 5 — Verification
- [ ] Pass official sample input
- [ ] Test isolated node with zero edges
- [ ] Test simple chain graph
- [ ] Confirm every edge pair has different colors

## Reflection (fill AFTER solving)
- What was the hardest part? ____
- Did I follow the workflow, or skip a step? ____
- If stuck: where did I get stuck and what unblocked me? ____
- One thing to improve next time: ____
