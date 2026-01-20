class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j]) q.emplace(i, j);
            }
        }
        if (q.empty() || q.size() == n * n) return -1;
        int dirs[5] = {0, 1, 0, -1, 0};
        int dist = -1;
        while (!q.empty()) {
            ++dist;
            int sz = q.size();
            while (sz--) {
                auto [x, y] = q.front(); q.pop();
                for (int d = 0; d < 4; ++d) {
                    int nx = x + dirs[d], ny = y + dirs[d + 1];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0) {
                        grid[nx][ny] = 1;
                        q.emplace(nx, ny);
                    }
                }
            }
        }
        return dist;
    }
};