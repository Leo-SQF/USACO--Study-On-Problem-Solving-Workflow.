## Problem Info

- **Name:** `Guess the Animal`
- **Source:** `USACO Jan 2019 Bronze P3`
- **Difficulty (self-rated):** `3`
- **Date attempted:** `2026-10-22`
- **Status:** `Solved`
- **Time spent:** `12 min`

---

## Step 1 — Read & Restate

> 
> We have several animals, each with a unique set of characteristics. Elsie asks yes/no questions about characteristics. She stops when only one animal matches all answers so far. We need to find the maximum possible number of "yes" answers she can receive before the game must end.
> 
> 
> | Item | Value |
> | --- | --- |
> | Input | First line N. Next N lines: animal name, K, then K characteristic strings. |
> | Output | The maximum possible count of "yes" answers. |
> | Constraint on N | $2 \le N \le 100$ |
> | Edge cases | Two animals share all their traits; N=2; one animal has only 1 trait; animals with zero overlapping traits |

---

## Step 2 — Model

- Model type: `brute force / set intersection`
- Explanation:
The limiting factor for maximum yes answers comes from the two most similar animals. We can keep answering "yes" for all traits shared by this pair, and still cannot tell them apart. One more yes (a trait only one of them has) will separate them. So answer = (size of largest trait intersection between any pair of animals) + 1.

---

## Step 3 — Algorithm

- Algorithm chosen: `Enumerate all pairs of animals, compute the size of the intersection of their trait sets, take maximum intersection + 1`
- Time complexity: $O(N^2 \cdot K)$
- Space complexity: $O(N\cdot K)$
- Why it fits the constraints:
$N \le 100$, total pairs are at most $100\times99/2 = 4950$. K is at most 100. Total operations are tiny, easily acceptable.

---

## Step 4 — Implementation Notes

- Data structures used: `unordered_set<string>` to store each animal's traits for O(1) lookups
- Pitfalls / bugs I hit: `Initially I almost misunderstood the problem as counting total questions instead of counting only "yes" answers; also need to remember to +1 at the end.`

---

## Step 5 — Verification

- Passes provided samples
- Passes my edge cases
- Within time limit
- Brute-force cross-check (if applicable)

---

## Reflection (fill AFTER solving)

- What was the hardest part? `Transforming the original question into "find the pair with the most shared traits". It is not obvious at first glance why the worst case always comes from a pair of two animals.`
- Did I follow the workflow, or skip a step? `Followed the workflow. First modeled the logic before writing code.`
- If stuck: where did I get stuck and what unblocked me? `Not stuck. I reasoned: as long as two animals are still both in the feasible set, the game hasn't ended, and all shared traits can produce yes answers.`
- One thing to improve next time: `When asked for a maximum/worst-case value, actively ask: "What pair of items is hardest to distinguish?"`
