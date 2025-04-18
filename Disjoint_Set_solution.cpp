class Solution {
public:
    vector<int> parents; // Stores the parent of each node for DSU
    vector<int> ranks;   // Stores the rank (depth) of each set

    // DSU find operation with path compression
    int find(int x) {
        if (parents[x] != x)
            parents[x] = find(parents[x]);
        return parents[x];
    }

    // DSU union operation by rank
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;

        if (ranks[px] < ranks[py]) {
            parents[px] = py;
        } else if (ranks[px] > ranks[py]) {
            parents[py] = px;
        } else {
            parents[py] = px;
            ranks[px]++;
        }
    }

    // Check if two strings are similar (at most two different positions)
    bool issimilar(string s1, string s2) {
        if (s1.length() != s2.length()) return false;

        int first = -1, second = -1;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                if (second != -1) return false; // More than 2 mismatches
                if (first == -1)
                    first = i;
                else
                    second = i;
            }
        }

        if (first == -1) return true; // Strings are identical

        // Swap and check
        swap(s1[first], s1[second]);
        return s1 == s2;
    }

    // Main function to count number of similar groups
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        parents.resize(n);
        ranks.resize(n);

        // Initialize DSU structures
        for (int i = 0; i < n; i++) {
            parents[i] = i;
            ranks[i] = 0;
        }
              int count=n;
        // Union all similar string indices
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (issimilar(strs[i], strs[j]) and find(j)!=find(i)) {
                    unite(i, j);
                       count--;
                }
            }
        }
        return count;
    }
};
