class Solution {
public:

    int f(int i, int j, int cost, vector<vector<int>>& grid, int k,vector<vector<vector<int>>>& dp) {

        // base cases
        if (i < 0 || j < 0)
            return -1e9;

        //current cell cost
        int newCost = cost + (grid[i][j] != 0);
        if (newCost > k)
            return -1e9;

        // reached start
        if (i == 0 && j == 0)
            return grid[0][0];

        if (dp[i][j][newCost] != -1)
            return dp[i][j][newCost];

        int up = f(i - 1, j, newCost, grid, k, dp);
        int left = f(i, j - 1, newCost, grid, k, dp);

        return dp[i][j][newCost] =
               grid[i][j]+max(up, left);
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp( n, vector<vector<int>>(m,
  vector<int>(k + 1, -1)) );

        int ans = f(n - 1, m - 1, 0, grid, k, dp);
        return (ans < 0) ? -1 : ans;
    }
};