Problem Template
Problem Info

Name: Angry Cows (Bessie's game, chain explosion version)
Source: USACO
Difficulty (self-rated): 4/10
Date attempted: 2026-10-11
Status: Solved
Time spent: 20 min


Step 1 — Read & Restate

We have hay bales placed at distinct integer positions on a number line. If we pick one haybale to start the explosion chain reaction:At time t (starting t=1 for the initial explosion), exploding haybales have blast radius = t. All haybales within radius t of an exploding bale get engulfed and explode at the next time step t+1, radius becomes t+1. All explosions in same time step happen simultaneously.We need to try starting on every haybale, simulate the chain reaction, find the maximum total haybales that can explode.

表格ItemValueInputFirst line integer N. Next N lines: each line is position of a haybale.OutputThe maximum count of haybales that explode, choosing best starting haybale.Constraint on N\(1 \le N \le 100\)Edge casesN=1 (only one haybale, answer=1); haybales spread too far to trigger chain reaction; explosions only propagate left OR only right.

Step 2 — Model

Model type: simulation / brute force
Explanation:Since N ≤ 100, we can brute force: try each haybale as the starting point.For each starting point, simulate the explosion step by step to count how many haybales blow up.Sort the hay positions first, this makes checking which haybales are in range much easier.


Step 3 — Algorithm

Algorithm chosen: Brute force simulation


Sort the list of haybale positions.
For every index start_idx (try each haybale as starting explosion):
Keep a boolean array exploded[] to track which haybales have exploded.
Initialize: mark start as exploded, time step t = 1.
Loop: collect all haybales that will explode in this step (radius t), mark them exploded.
Increase t by 1, repeat until no new haybales explode in a round.
Count total exploded haybales for this start.


Take maximum count over all starting positions, output it.


Time complexity: \(O(N^3)\) worst case. Since N=100 this is trivial, no performance problem.
Space complexity: \(O(N)\) for exploded array and sorted positions list.
Why it fits the constraints: N is only up to 100, brute force simulation is simple and fast enough.


Step 4 — Implementation Notes

Data structures used: sorted list of positions, boolean exploded array.
Pitfalls / bugs I hit:
Simultaneous explosion: cannot mark haybales exploded immediately as we scan them. Must collect all new haybales for current t first, then mark all of them exploded at once. If you mark them early, they affect the current step's blast incorrectly.
Sorting is mandatory; without sorted positions checking nearby haybales is messy.
Blast radius increases by exactly 1 each time step. Initial explosion t=1, radius=1; next step t=2 radius=2, etc.




Step 5 — Verification

 Passes provided samplesSample input:
6
8
5
6
13
3
4

Sorted positions: [3,4,5,6,8,13]Start at position 5 (index 2):t=1 radius 1: explode 5.t=2 radius2: hay within 2 of exploded bales → 4 and 6 explode.t=3 radius3: hay within3 of {4,6} → 3 and8 explode.t=4 radius4: check, no new hay (13 is too far). Total exploded = 5, matches sample output.

 Passes my edge casesEdge case N=1 → output=1.Edge case haybales far apart: each start only explodes itself, answer=1.
 Within time limit
 Brute-force cross-check (if applicable)


Reflection (fill AFTER solving)

What was the hardest part? Handling simultaneous explosions correctly. If you explode haybales one by one mid-step, you accidentally use newly exploded haybales in the same time step, which violates problem statement.
Did I follow the workflow, or skip a step? I followed the workflow, modeled first then coded.
If stuck: where did I get stuck and what unblocked me? The simultaneous explosion rule is the trick. Need a temporary list for newly exploded haybales each round.
One thing to improve next time: separate left and right propagation optimization, but for N=100 brute force is simpler.
