# Problem Info
- Name: Snow Boots (Bronze)
- Source: USACO 2018 February Bronze P2
- Difficulty (self‑rated): ____ (1–10)
- Date attempted: ____ (YYYY‑MM‑DD)
- Status: ____ (Not started / In progress / Solved / Stuck / Solved with help)
- Time spent: ____ min

## Step 1 — Read & Restate
We have n stones placed along one‑dimension line with given positions. After sorting positions, every stone will jump to its nearest neighbor.
If distances to left and right neighbor are equal: jump to left.
Edge stones: first stone can only jump right; last stone can only jump left.
This forms directed edges `i → to[i]`. Count total number of source nodes (in‑degree 0).
Special correction: for mutual‑pair cycles `i↔i+1` (two‑node cycle), if both nodes have in‑degree 1, add extra 1 to answer.

| Item | Value |
|------|-------|
| Input | n, followed by n integer stone positions |
| Output | total count of sources plus correction for 2‑node mutual cycles |
| Constraints | 2 ≤ n; handle n=1 special case |
| Edge cases | n=1 single stone; adjacent two‑stone mutual jump cycle; all nodes point toward one central node; equal left‑right distance pick left neighbor |

## Step 2 — Model
- Model type: Directed graph built from nearest‑neighbor jumps, in‑degree statistics
- Explanation:
1. Sort stone positions.
2. Build jump‑target array `to[]`:
   - `to[0]=1` first stone only jumps right
   - `to[n‑1]=n‑2` last stone only jumps left
   - middle i: compare `x[i]-x[i‑1]` and `x[i+1]-x[i]`. If left distance ≥ right distance → jump left(i‑1); else jump right(i+1).
3. Compute in‑degree array `indeg[]`: count how many nodes point to each vertex.
4. Base answer: count nodes with indeg[i]==0 (source nodes).
5. Correction pass: scan adjacent pairs i,i+1; if they form mutual two‑node cycle and both indeg equal 1, ans += 1.

## Step 3 — Algorithm
- Algorithm chosen: Sort + build directed jump graph + in‑degree counting + special two‑node‑cycle correction
- Time complexity: O(n log n) dominated by sort
- Space complexity: O(n) for x,to,indeg vectors
- Why it fits: n small; construct graph explicitly, use in‑degree to find source nodes; two‑node cycle cannot produce source so need manual correction.

## Step 4 — Implementation Notes
- Data structures used: `vector<int> x` store positions; `vector<int> to` jump target array; `vector<int> indeg` in‑degree counter
- Pitfalls / bugs I hit: ____
  1. Must sort stone position array first, input positions are unordered.
  2. Middle node tie‑break rule: equal distance → jump to **left neighbor**.
  3. Special early return for n == 1 case.
  4. Two‑node mutual cycle condition check: `to[i]==i+1 && to[i+1]==i` AND both indeg[i]==1, indeg[i+1]==1.
  5. Do not miss adding correction value for two‑node cycle.

## Step 5 — Verification
- [ ] Pass official sample input
- [ ] Test n=1 case
- [ ] Test exactly two‑stone mutual jump cycle
- [ ] Test middle point with equal left‑right distance

## Reflection (fill AFTER solving)
- What was the hardest part? ____
- Did I follow the workflow, or skip a step? ____
- If stuck: where did I get stuck and what unblocked me? ____
- One thing to improve next time: ____
