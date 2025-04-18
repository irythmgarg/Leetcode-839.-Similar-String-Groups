# Leetcode-839.-Similar-String-Groups

# 🌐 Similar String Groups

This repository provides two elegant solutions to the **Similar String Groups** problem using:

- 🔍 **DFS (Depth-First Search)**
- 🧱 **DSU (Disjoint Set Union)**

The goal is to group similar strings together and count the number of such groups.

---

## 🧩 Problem Statement

Given an array of strings, a **group** is defined by strings that are **similar** — i.e., you can make one equal to the other by **swapping exactly two characters**, or the strings are already identical.

Return the number of groups formed.

---

## 🔍 Approach 1: DFS (Graph Traversal)

We build a **graph** where each string is a node. Two nodes are connected if the strings are similar.

Then, we use **DFS** to traverse and count the number of connected components.

### 💡 Key Functions

- **`bool issimilar(s1, s2)`**: Returns `true` if `s1` and `s2` are similar (only 0 or 2 mismatches allowed).
- **`void dfs(node, graph, visited)`**: Marks all nodes reachable from a starting node.
- **`int numSimilarGroups()`**: Builds the graph and counts the number of connected components.

---

## 🧱 Approach 2: DSU (Union-Find)

We treat each string as a node and **union** the indices if their corresponding strings are similar. Finally, we count how many unique parent nodes exist.

### 💡 Key Functions

- **`bool issimilar(s1, s2)`**: Checks similarity as above.
- **`int find(x)`**: Finds the root of `x` with path compression.
- **`void unite(x, y)`**: Merges two sets based on rank.
- **`int numSimilarGroups()`**: Unions similar nodes and counts unique parents.

---

## 🧪 Example

```cpp
Input: ["tars", "rats", "arts", "star"]

Groups:
1. "tars", "rats", "arts"
2. "star"
Output: 2
