# Problem Info
- Name: Closing the Farm
- Source: USACO 2016 US Open Silver P3
- Difficulty (self‑rated): ____ (1–10)
- Date attempted: ____ (YYYY‑MM‑DD)
- Status: ____ (Not started / In progress / Solved / Stuck / Solved with help)
- Time spent: ____ min

## Step 1 — Read & Restate
We have an undirected graph with N nodes and M edges.
Nodes get **removed one‑by‑one** in given `order[]` sequence.
After each removal, answer: is the remaining active graph all in **one single connected component**?

Direct deletion is hard for DSU(Union‑Find). Trick: process in reverse:
- Reverse the process: start with all nodes inactive; add nodes in reverse‑delete‑order.
- `active[]`: whether node is turned‑on(added).
- `comp`: count number of connected components among active nodes.
When adding a node u: comp +=1. For each neighbor v of u, if v is already active, union u and v; each successful union decreases comp by 1.
After each reverse‑step: if comp == 1 → push "YES", else push "NO".
Finally reverse the answer list to restore original time‑order and print.

| Item | Value |
|------|-------|
| Input | N M; M undirected edges; N‑length deletion order array `order` |
| Output | N lines: YES / NO. After each deletion: is remaining graph fully connected |
| Constraints | N ≤ 3000; DSU / Union‑Find with path compression |
| Edge cases | Only one node left(comp=1 → YES); multiple disconnected components; adding node connects several components together |

## Step 2 — Model
- Model type: Reverse‑simulation + DSU(Disjoint Set Union / Union‑Find)
- Explanation:
DSU cannot efficiently support node deletion, so invert the problem:
1. Original: delete nodes in given order.
2. Reversed simulation: start empty, add nodes in reverse deletion order.
3. Maintain `active[]` mark for nodes that have been added.
4. `comp`: number of connected components of active nodes.
5. When activating node u: component count increases by one. Iterate its neighbors; if neighbor already active, perform union. Each successful merge reduces component count.
6. Record answer for reversed process; reverse answer list to match original deletion sequence for output.

## Step 3 — Algorithm
- Algorithm chosen: Reverse simulation + DSU with path‑compression
- Time complexity: O(N + M α(N)), α is inverse‑Ackermann (almost constant)
- Space complexity: O(N+M) for adjacency list, parent array
- Why it fits: DSU supports union/find fast but no delete‑node. Reversing deletions into additions is classic trick for this problem.

## Step 4 — Implementation Notes
- Data structures used: adjacency list `adj[]`; DSU `parent[]`; boolean `active[]`; `order[]` deletion sequence; `comp` component counter; `rev_ans` store reversed‑phase answers.
- Pitfalls / bugs I hit: ____
  1. DSU parent array initialization: `parent[i]=i` for 1‑based nodes 1…N.
  2. Process loop runs `i = N‑1 downto 0` over deletion order.
  3. Only union neighbor v **if v is already active**.
  4. `comp++` when node is activated; only decrease comp on actual successful union(find(u) != find(v)).
  5. Collect answers in reverse order, then **reverse rev_ans before output**.
  6. Graph nodes are 1‑based indexing.

## Step 5 — Verification
- [ ] Pass official sample input
- [ ] Test final state with single remaining node (output YES)
- [ ] Test adding node connects multiple separate components
- [ ] Check answer list reversal step

## Reflection (fill AFTER solving)
- What was the hardest part? ____
- Did I follow the workflow, or skip a step? ____
- If stuck: where did I get stuck and what unblocked me? ____
- One thing to improve next time: ____
