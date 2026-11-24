# Problem Info
- Name: Comfortable Cows
- Source: USACO 2021 February Silver P1
- Difficulty (self‑rated): ____ (1–10)
- Date attempted: ____ (YYYY‑MM‑DD)
- Status: ____ (Not started / In progress / Solved / Stuck / Solved with help)
- Time spent: ____ min

## Step 1 — Read & Restate
We add N cows one‑by‑one onto infinite 2‑D grid.
A cow is **comfortable** if exactly three of its four orthogonal neighbours are occupied by other cows.
Whenever a cow becomes comfortable, we must immediately spawn a new cow into its single empty adjacent cell.
This newly‑added cow may in turn make other cows comfortable, triggering further forced spawns (chain reaction).
If we try to place a cow onto a cell that already has a cow, nothing new is added.
After processing each of the N input placements, output `total − i`: number of extra cows that were automatically spawned (total cows minus the i input cows we have placed so far).

Coordinate shift trick: coordinates can be negative; add `SHIFT=2000` to map negative coordinates into non‑negative array indices `[0,4000]`.
`has[x][y]`: true if cell contains a cow (original or spawned).
Queue processes cells that need to be re‑checked for “comfortable” condition.

| Item | Value |
|------|-------|
| Input | N; N pairs (x,y) coordinates for manually‑placed cows |
| Output | After each i‑th input cow: print count of automatically‑generated extra cows |
| Constraints | Grid bounded by offset SHIFT=2000, array size MAX=4005 |
| Edge cases | Input cow placed on already‑occupied cell; multi‑step chain spawning; newly‑spawned cow’s neighbours become comfortable and enqueued; avoid spawning duplicate cows |

## Step 2 — Model
- Model type: Simulation with work‑queue / BFS‑style event‑driven chain reaction
- Explanation:
1. Shift all input coordinates by +2000 to handle negative values for array indexing.
2. `total`: total cows including manually placed + auto‑spawned cows.
3. For each input cow (x,y):
    - If cell already occupied: print `total‑i` and continue.
    - Mark cell as occupied, increment total, push into queue.
    - Process queue: pop cell, count its four neighbours.
    - If exactly three neighbours occupied → it is comfortable: find the one empty neighbour cell. Spawn new cow there if empty.
    - When we spawn a new cow: mark occupied, total++, push new cell to queue. Also enqueue **four neighbours of the newly‑spawned cow**, because they may now become comfortable.
4. After finishing queue processing for this step, output `total‑i`.

## Step 3 — Algorithm
- Algorithm chosen: Event‑driven simulation using queue for re‑checking comfortable condition
- Time complexity: Bounded by grid size MAX=4005; each cell enqueued limited times, feasible.
- Space complexity: O(MAX²) boolean grid array
- Why it fits: Spawning creates chain‑reactions; queue ensures every affected cell gets re‑evaluated for comfortable status.

## Step 4 — Implementation Notes
- Data structures used: `has[MAX][MAX]` boolean grid; queue of coordinate pairs; helper `count_nei()` count occupied neighbours; helper `find_empty()` return the single empty adjacent cell; constant SHIFT=2000.
- Pitfalls / bugs I hit: ____
  1. Negative input coordinates: must add SHIFT offset before indexing into array.
  2. Input cow may land on an already‑occupied cell: do not add to total, skip spawn logic.
  3. After spawning a new cow, enqueue its four existing neighbours; those neighbours may now turn comfortable.
  4. Check target cell is empty before spawning a new cow, prevent duplicate spawn.
  5. Output value = `total − i`: total cows minus number of manually‑input cows so far.
  6. Queue only triggers spawn when neighbour count == 3 exactly.

## Step 5 — Verification
- [ ] Pass official sample input
- [ ] Test input cow on already‑occupied position
- [ ] Test multi‑level chain spawn reaction
- [ ] Verify coordinate offset for negative numbers

## Reflection (fill AFTER solving)
- What was the hardest part? ____
- Did I follow the workflow, or skip a step? ____
- If stuck: where did I get stuck and what unblocked me? ____
- One thing to improve next time: ____
