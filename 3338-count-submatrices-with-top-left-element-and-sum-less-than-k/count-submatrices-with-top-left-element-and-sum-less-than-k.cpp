class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int count =0;

        vector<vector<int>> temp(n,vector<int>(m,0));

        for(int i=0; i<n;i++){
            for(int j =0; j<m; j++){
                int top = (i > 0) ? temp[i-1][j] : 0;
                int left = (j > 0) ? temp[i][j-1] : 0;
                int diagonal = (i > 0 && j > 0) ? temp[i-1][j-1] : 0;

                temp[i][j] =grid[i][j]+top+left-diagonal;

                if(temp[i][j] <= k) count++;
            }
        }
        return count;
    }
};