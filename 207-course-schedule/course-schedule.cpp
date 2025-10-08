class Solution {
private:
    bool dfs(int i, vector<vector<int>>& adj, unordered_set<int>& set, vector<bool>& visited) {
        set.insert(i);
        visited[i] = true;

        for (int num : adj[i]) {
            if (!visited[num]) {
                if (!dfs(num, adj, set, visited))
                    return false;
            } else if (set.count(num)) {
                return false;
            }
        }

        set.erase(i);
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(numCourses, false);
        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i]) {
                unordered_set<int> set;
                if (!dfs(i, adj, set, visited))
                    return false;
            }
        }

        return true;
    }
};