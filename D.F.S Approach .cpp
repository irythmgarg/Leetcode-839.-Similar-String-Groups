class Solution {
public:
    // Function to check if two strings are similar
    bool issimilar(string s1, string s2) {
        if (s1.length() != s2.length()) return false;

        int first = -1, second = -1;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                if (second != -1) return false; // More than two mismatches
                if (first == -1)
                    first = i;
                else
                    second = i;
            }
        }

        // Identical strings
        if (first == -1) return true;

        // Swap the mismatched characters and check equality
        swap(s1[first], s1[second]);
        return s1 == s2;
    }

    // DFS function to visit all nodes in the same group
    void dfs(int i, unordered_map<int, vector<int>>& mp, vector<bool>& visited) {
        visited[i] = true;
        for (int neighbor : mp[i]) {
            if (!visited[neighbor]) {
                dfs(neighbor, mp, visited);
            }
        }
    }

    // Main function to count the number of similar groups using DFS
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        unordered_map<int, vector<int>> mp;

        // Build adjacency list graph where each node is connected if similar
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (issimilar(strs[i], strs[j])) {
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n, false);
        int count = 0;

        // Count connected components using DFS
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, mp, visited);
                count++;
            }
        }

        return count;
    }
};
