class Solution {
public:

    bool dfs(vector<vector<int>>& heights, vector<vector<bool>>& vis, int i, int j, int move, int n, int m){
        if( i ==n-1 && j == m-1) return true;
        vis[i][j] = true;
        if(i+1 < n && !vis[i+1][j] && abs(heights[i][j] - heights[i+1][j])<= move && dfs(heights, vis, i+1,j, move, n, m)) return true;
        if(i-1 >=0 && !vis[i-1][j] && abs(heights[i][j] - heights[i-1][j])<= move && dfs(heights, vis, i-1,j, move, n, m)) return true;
        if(j+1 < m && !vis[i][j+1] && abs(heights[i][j] - heights[i][j+1])<= move && dfs(heights, vis, i,j+1, move, n, m)) return true;
        if(j-1 >= 0 && !vis[i][j-1] && abs(heights[i][j] - heights[i][j-1])<= move && dfs(heights, vis, i,j-1, move, n, m)) return true;

        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        int ans =0;
        int low = 0, high = 1e6;
        while(low <= high){
            vector<vector<bool>> vis(n, vector<bool>(m, false));
            int mid = low + (high -low) /2;
            if(dfs(heights, vis, 0,0, mid, n, m)){
                ans =mid;
                high =mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};