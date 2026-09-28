class Solution {
public:
    
    bool dfs(vector<vector<int>>& heights, vector<vector<bool>>& vis, int k, int n, int m, int i = 0, int j = 0){
        if(i == heights.size()-1 && j == heights[0].size()-1) return true;
        vis[i][j] = true;
        if(i + 1 < n && !vis[i + 1][j] && abs(heights[i][j] - heights[i + 1][j]) <= k && dfs(heights, vis, k, n, m, i +1, j))
            return true;
        if(i - 1 >= 0 && !vis[i - 1][j] && abs(heights[i][j] - heights[i - 1][j]) <= k && dfs(heights, vis, k, n, m, i -1, j))
            return true;
        if(j - 1 >= 0 && !vis[i][j-1] && abs(heights[i][j] - heights[i][j - 1]) <= k && dfs(heights, vis, k, n, m, i, j-1))
            return true;
        if(j + 1 < m && !vis[i][j + 1] && abs(heights[i][j] - heights[i][j + 1]) <= k &&  dfs(heights, vis, k, n, m, i, j + 1))
            return true;
        return false;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size(), ans = 0;
        int left = 0, right = 1e6;
        while(left <= right){
            vector<vector<bool>> vis(n, vector<bool>(m, false));
            int mid = (left + right)/2;
            if(dfs(heights, vis, mid, n, m)){
                ans = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return ans;
    }
};