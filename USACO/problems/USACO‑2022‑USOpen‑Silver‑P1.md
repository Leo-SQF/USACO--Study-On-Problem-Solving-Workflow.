# Problem Info
- Name: Circular Barn Revisited / Moo Network
- Source: USACO 2022 US Open Silver P1
- Difficulty (self‑rated): ____ (1–10)
- Date attempted: ____ (YYYY‑MM‑DD)
- Status: ____ (Not started / In progress / Solved / Stuck / Solved with help)
- Time spent: ____ min

## Step 1 — Read & Restate
We have N nodes. Each node `i` points to exactly one other node `a[i]`.
Every node has a value `v[i]`. Total sum `sum_total = sum(v[i])`.
This structure is a functional graph: each component consists of exactly **one cycle with trees feeding into the cycle**.

Traverse each unvisited component with 3‑state visited marker:
- `vis=0`: unvisited
- `vis=1`: visiting, inside current DFS‑path
- `vis=2`: fully processed / finished

When we hit a node marked `vis=1`: we have found a cycle inside current `path` list.
Find position `pos` where `cur` appears in path.
For all nodes from `pos` to end of path (the cycle nodes), take minimum value `minv` on that cycle.
Add this cycle‑minimum to `subtract`.
All tree nodes leading into cycle are kept in full.

Final answer: `sum_total − subtract`.
Logic: For each cycle in functional graph, we must remove the minimal‑value node from that cycle; keep everything else.

| Item | Value |
|------|-------|
| Input | N; N pairs `a[i], v[i]`. `a[i]` is target node that i points to. 1‑based indexing |
| Output | `sum_total − subtract` maximum achievable sum |
| Constraints | N ≤ 1e5; use long long for sum variables |
| Edge cases | Self‑loop cycle (single‑node cycle); multiple separate components / cycles; long‑tail trees leading into cycle |

## Step 2 — Model
- Model type: Functional‑graph traversal, 3‑state visited detection for cycles
- Explanation:
Functional graph: every node has exactly one outgoing edge. Structure: trees directed towards cycles.
For each cycle in functional graph: we have to discard the node with minimal `v` value on that cycle. Tree nodes attached to cycle are all kept.
Algorithm:
1. Three‑color `vis` array: 0‑unvisited,1‑visiting(in current path),2‑done.
2. Iterate each starting node i. If not visited, follow `cur = a[cur]`, record `path`.
3. When we encounter a node with `vis ==1`: we found a cycle. Locate where this node occurs inside path. Take min `v` over cycle segment, add to `subtract`.
4. Mark all nodes in path as `vis=2` (finished).
5. Answer = total sum of all v minus sum of each cycle’s minimal value.

## Step 3 — Algorithm
- Algorithm chosen: Functional‑graph cycle detection with three‑state visited and explicit path storage
- Time complexity: O(N). Every node added to path exactly once.
- Space complexity: O(N) for vis, a, v, path vector.
- Why it fits: Functional‑graph property guarantees each node exactly one outgoing edge; three‑state marker correctly distinguishes “in‑current‑stack” vs fully‑processed nodes.

## Step 4 — Implementation Notes
- Data structures used: `a[]` target each node points to; `v[]` value array; `vis[]` three‑state 0/1/2; `path` vector stores current traversal chain; `sum_total`, `subtract` long long.
- Pitfalls / bugs I hit: ____
  1. Nodes are **1‑based**.
  2. Three states critical: `vis=1` means node is on current exploring path; `vis=2` means fully processed from earlier run.
  3. When hitting `vis==1`: find index `pos` inside `path` where `cur` is located; cycle is `path[pos ... end]`.
  4. `subtract` accumulates **minimum v of each cycle**.
  5. All sum variables (`sum_total`, `subtract`, `minv`) must be `long long`.
  6. After processing component, mark every node in `path` to `vis=2`.

## Step 5 — Verification
- [ ] Pass official sample input
- [ ] Test self‑loop single‑node cycle
- [ ] Test multiple independent cycles
- [ ] Test long tree‑chains leading into cycle

## Reflection (fill AFTER solving)
- What was the hardest part? ____
- Did I follow the workflow, or skip a step? ____
- If stuck: where did I get stuck and what unblocked me? ____
- One thing to improve next time: ____
