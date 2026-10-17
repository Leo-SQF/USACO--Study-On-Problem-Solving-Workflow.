Problem Info
Name: Milk Measurement

Source: USACO 2017 US Open Bronze P3

Difficulty (self-rated): 4

Date attempted: 2026-10-17

Status: Solved

Time spent: 15 min

Step 1 — Read & Restate
<!-- Paraphrase the problem in your own words. -->
Farmer John has 3 cows, each initially producing 7 gallons of milk. He takes N measurements, but inputs are given in a random order. Each measurement records the day, the cow's name, and the change in her milk output. FJ displays a picture of the cow(s) with the highest milk output on his barn wall. If there is a tie, he displays all tied cows. We need to determine how many times FJ has to change the pictures on the wall.

Item	Value
Input	The first line is N. The next N lines contain: an integer day (1-100), a string name, and a non-zero integer change in milk.
Output	A single integer representing the number of days FJ needs to adjust his display.
Constraint on N	N ≤ 100
Edge cases	1. Inputs are unsorted, so they must be sorted by day.
2. Ties: If multiple cows are tied for first place, the display shows all of them. Any change in this specific set of top cows counts as a display change.
Step 2 — Model
<!-- What kind of problem is this? Which model type? -->
Model type: Simulation + Sorting

Explanation: Since N is very small (≤ 100), we can directly simulate the process. The main challenges are handling the unsorted inputs and correctly tracking the tied highest-producing cows. Sorting the measurements by day creates a chronological timeline. A bitmask (state compression) is an elegant way to represent the set of cows currently leading.

Step 3 — Algorithm
Algorithm chosen:

Store the input in a struct (day, cow_id, delta) and put them into a vector.
Sort the vector in ascending order by day.
Use an array milk[3] initialized to {7, 7, 7} to track current milk outputs.
Use an integer mask (e.g., 0b001) to represent which cows are currently leading.
Iterate through the sorted measurements, update the specific cow's milk output, and recalculate the highest milk output.
Recalculate the new mask. If new_mask != cur_mask, increment the answer and update cur_mask.
Time complexity: O(N log N) — Dominated by sorting. The simulation loop takes O(N).

Space complexity: O(N) — To store the measurements in the vector.

Why it fits the constraints: N ≤ 100, so O(N log N) will easily run within the 1-second time limit.

Step 4 — Implementation Notes
Data structures used:

struct Measurement { int day, cow_id, delta; }

std::vector<Measurement>

Bitmask (integer) to track the leading cows.

Pitfalls / bugs I hit:

Forgetting to sort: I initially overlooked the fact that inputs were not chronological, which led to incorrect simulation results.

Tie handling: Using a simple max_element is not enough because the display shouldn't change if a cow drops out of a tie but another cow remains at the top. The bitmask perfectly solves this. For example, if Cow A and B are tied (mask = 0b011), and A drops (mask = 0b010), the mask changes, meaning the display must be updated.

Step 5 — Verification
☑ Passes provided samples
☑ Passes my edge cases (tested unsorted inputs, multiple ties, and cows dropping from the lead)
☑ Within time limit
☑ Brute-force cross-check (if applicable)
Reflection (fill AFTER solving)
What was the hardest part?
Figuring out an efficient and accurate way to track the top cow(s) and determine if the display changed. My first thought was to use a std::set, but using a bitmask (0b001, 0b101, etc.) turned out to be much cleaner and computationally cheaper.

Did I follow the workflow, or skip a step?
I followed the workflow, but in Step 1, I almost missed the "unsorted" condition. I had to go back and re-read the input format carefully.

If stuck: where did I get stuck and what unblocked me?
I didn't get completely stuck. I recognized the pattern of "track state changes over time," which usually requires sorting the events first.

One thing to improve next time:
When reading the problem, I should actively highlight all hidden conditions (like unsorted input, small constraints, and specific tie-breaking rules). Also, for problems involving multiple elements sharing a state, always consider state compression (Bitmask) first.

