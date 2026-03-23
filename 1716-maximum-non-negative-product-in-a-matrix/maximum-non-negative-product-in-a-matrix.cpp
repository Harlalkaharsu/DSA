class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        const long long MOD = 1e9 + 7;

        vector<vector<long long>> maxpro(n,vector<long long>(m));
        vector<vector<long long>> minpro(n,vector<long long>(m));

        maxpro[0][0] = minpro[0][0] = grid[0][0];

        for(int i = 1; i<n; i++){
            maxpro[i][0] = minpro[i][0] = grid[i][0] * maxpro[i-1][0];
        }
        for(int j = 1; j<m; j++){
            maxpro[0][j] = minpro[0][j] = grid[0][j] * maxpro[0][j-1];
        }


        for (int i =1; i<n; i++){
            for(int j =1; j<m; j++){
                long val = grid[i][j];

                long a = maxpro[i-1][j] * val;
                long b = minpro[i-1][j] * val;
                long c = maxpro[i][j-1] * val;
                long d = minpro[i][j-1] * val;

                maxpro[i][j] = max({a,b,c,d});
                minpro[i][j] = min({a,b,c,d});
            }
        }
        long ans =maxpro[n-1][m-1];
        if(ans<0) return -1;
        return ans % MOD;
    }
};