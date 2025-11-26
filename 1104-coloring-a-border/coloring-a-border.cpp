class Solution {
public:
    void dfs(vector<vector<int>>& grid , int i , int j , int target){
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] != target) return;
        grid[i][j] = -1;
        dfs(grid , i - 1 , j , target);
        dfs(grid , i , j - 1 , target);
        dfs(grid , i + 1 , j , target);
        dfs(grid , i , j + 1 , target);
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        vector<vector<int>> res = grid;
        dfs(grid , row , col , grid[row][col]);
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] < 0){
                    if(i == 0 || j == 0 || i == m - 1 || j == n - 1) res[i][j] = color;
                    else if(grid[i - 1][j] >= 0 || grid[i][j - 1] >= 0 || grid[i + 1][j] >= 0 || grid[i][j + 1] >= 0) res[i][j] = color;
                }
            }
        }
        return res;
    }
};