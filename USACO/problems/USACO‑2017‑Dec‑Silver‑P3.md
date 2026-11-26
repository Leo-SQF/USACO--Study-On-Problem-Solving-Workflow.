# Problem Info
- Name: Milk Visits / Count Cycle Sizes
- Source: USACO 2017 December Silver P3
- Difficulty (self‑rated): ____ (1–10)
- Date attempted: ____ (YYYY‑MM‑DD)
- Status: ____ (Not started / In progress / Solved / Stuck / Solved with help)
- Time spent: ____ min

## Step 1 — Read & Restate
Given N‑node functional graph: every node `i` has exactly one outgoing edge `a[i]`.
Graph components consist of trees directed into cycles.
We need to compute **sum of the lengths of every cycle** across all components.

Three‑state visited marking:
- `vis = 0`: unvisited
- `vis = 1`: visiting, inside current traversal path
- `vis = 2`: fully processed

When we hit a node with `vis == 1`, we locate its position `pos` inside current `path`.
Cycle length = `path.size() − pos`. Add this value to answer.
Mark all nodes in path as `vis=2` after finishing component.

| Item | Value |
|------|-------|
| Input | N; array `a[1…N]`, `a[i]` is the node i points to; 1‑based indexing |
| Output | sum of lengths of all cycles in functional graph |
| Constraints | N up to 1e5; iterative traversal avoids recursion stack overflow |
| Edge cases | self‑loop single‑node cycle; multiple disconnected cycles; long tree prefix leading into cycle |

## Step 2 — Model
- Model type: Functional‑graph iterative cycle‑detection, three‑color visited marker
- Explanation:
Each node has exactly one outgoing edge → functional‑graph structure: in‑trees feeding into cycles.
1. Iterate each starting node i. If `vis[i]==0`, start traversing `cur = a[cur]`, build `path`.
2. Mark nodes in current path as `vis=1`.
3. Encounter `vis[cur]==1`: found a cycle inside current path.
    - `pos`: index where cur appears in path.
    - cycle length = `path.size() - pos`. Add to total answer.
4. If encounter `vis[cur]==2`: this path leads to an already‑processed component, no new cycle here.
5. After processing component, mark every node in `path` to `vis=2`.

## Step 3 — Algorithm
- Algorithm chosen: Iterative functional‑graph walk with three‑state visited + explicit path storage
- Time complexity: O(N). Each node added to path exactly once.
- Space complexity: O(N) for `a`, `vis`, `path`.
- Why it fits: Iterative implementation avoids DFS recursion stack overflow for large N. Straight‑forward extraction of cycle length from path vector.

## Step 4 — Implementation Notes
- Data structures used: `a[]` outgoing edge array; `vis[]` three‑state 0/1/2; `path` stores current traversal chain; `ans` accumulate total sum of cycle lengths.
- Pitfalls / bugs I hit: ____
  1. Nodes are **1‑based**.
  2. Three states: `vis=1` means node belongs to current exploring path; `vis=2` means fully‑processed from earlier component. Cannot use only two‑state visited.
  3. Cycle length calculation: `path.size() − pos`.
  4. Syntax bug risk: condition `if(vis[i==0])` is a common typo; correct is `if (vis[i]==0)`.
  5. After processing component, mark **all nodes in path** as vis=2.

## Step 5 — Verification
- [ ] Pass official sample input
- [ ] Test self‑loop single‑node cycle (cycle length =1)
- [ ] Test multiple independent cycles
- [ ] Test long tree‑chain leading into cycle

## Reflection (fill AFTER solving)
- What was the hardest part? ____
- Did I follow the workflow, or skip a step? ____
- If stuck: where did I get stuck and what unblocked me? ____
- One thing to improve next time: ____
