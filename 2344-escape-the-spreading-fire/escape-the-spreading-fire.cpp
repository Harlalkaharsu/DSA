class Solution {
public:
    const int INF = 1e9 + 5;
    int dirs[5] = {1, 0, -1, 0, 1};

    vector<vector<int>> getFireTime(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> fire(m, vector<int>(n, INF));
        queue<pair<int,int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fire[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nx = x + dirs[d], ny = y + dirs[d + 1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if (grid[nx][ny] == 2) continue;
                if (fire[nx][ny] != INF) continue;

                fire[nx][ny] = fire[x][y] + 1;
                q.push({nx, ny});
            }
        }
        return fire;
    }

    bool canReach(vector<vector<int>>& grid, vector<vector<int>>& fire, int wait) {
        int m = grid.size(), n = grid[0].size();

        if (fire[0][0] != INF && wait >= fire[0][0]) return false;

        queue<tuple<int,int,int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        q.push({0, 0, wait});
        vis[0][0] = 1;

        while (!q.empty()) {
            auto [x, y, t] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nx = x + dirs[d], ny = y + dirs[d + 1];
                int nt = t + 1;

                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if (grid[nx][ny] == 2 || vis[nx][ny]) continue;

                if (nx == m - 1 && ny == n - 1) {
                    if (nt <= fire[nx][ny]) return true;
                    continue;
                }

                if (nt >= fire[nx][ny]) continue;

                vis[nx][ny] = 1;
                q.push({nx, ny, nt});
            }
        }
        return false;
    }

    bool infinitePath(vector<vector<int>>& grid, vector<vector<int>>& fire) {
        int m = grid.size(), n = grid[0].size();

        if (fire[0][0] != INF || fire[m - 1][n - 1] != INF) return false;

        queue<pair<int,int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        q.push({0, 0});
        vis[0][0] = 1;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == m - 1 && y == n - 1) return true;

            for (int d = 0; d < 4; d++) {
                int nx = x + dirs[d], ny = y + dirs[d + 1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if (vis[nx][ny] || grid[nx][ny] == 2) continue;
                if (fire[nx][ny] != INF) continue;

                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }

        return false;
    }

    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if (m == 1 && n == 1) return 1000000000;

        auto fire = getFireTime(grid);

        if (infinitePath(grid, fire)) return 1000000000;

        int lo = 0, hi = 1000000000, ans = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (canReach(grid, fire, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};
