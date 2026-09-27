# Templates

<!-- Reusable code skeletons so you never rewrite boilerplate. Add one file per
language / per need. -->

## Index

| File | Language | What it does |
|------|----------|--------------|
| `read_io.cpp` | C++ | USACO-style file input/output (filein/fileout) |
| `read_io.py` | Python | USACO-style file input/output |
| `debug.cpp` | C++ | fast I/O, debug macro |
| (add) | | |

## Template checklist (keep this in every template)

- [ ] USACO file input/output: read from `*.in`, write to `*.out`
- [ ] Fast I/O where needed (C++ `ios::sync_with_stdio(false)`)
- [ ] 64-bit types for large numbers
- [ ] BFS/DFS adjacency list snippet (for graph problems)
- [ ] Template for prefix sums / DP if you use them often

## How to use

Copy the relevant template, then fill only the parts that change per problem.
The goal: the workflow's Step 4 (implement) takes less time because boilerplate
is already done.
