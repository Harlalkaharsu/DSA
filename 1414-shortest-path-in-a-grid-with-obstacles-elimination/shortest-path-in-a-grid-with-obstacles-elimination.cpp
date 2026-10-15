class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();

        // steps, k left, i, j
        queue<vector<int>> q;
        q.push({0, k, 0, 0});

        vector<vector<int>> visited(row, vector<int>(col, -1));

        visited[0][0] = k;
        while (!q.empty()) {
            auto top = q.front();
            q.pop();

            int steps = top[0];
            int cellK = top[1];
            int i = top[2];
            int j = top[3];

            if (i == row - 1 && j == col - 1) 
               return steps;

            int dr[] = {0, 0, 1, -1};
            int dc[] = {1, -1, 0, 0};

            for (int k = 0; k < 4; k++) {
                int r = i + dr[k];
                int c = j + dc[k];

                if (r >= 0 && c >= 0 && c < col && r < row) {
                    int newK = cellK - grid[r][c];

                    if (newK > visited[r][c]) {
                        visited[r][c] = newK;
                        q.push({steps + 1, newK, r, c});
                    }
                }
            }
        }

        return -1;
    }
};