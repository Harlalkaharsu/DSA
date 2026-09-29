class Solution {
public:
    int mem[100][100][100];
    bool dfs(vector<vector<char>>& grid, int count, int n, int m, int i=0, int j=0){
        if(i>=n || j>= m) return false;
        if(grid[i][j] == '(') count++;
        else count--;
        if(count < 0) return false;

        int remaining_steps = (n - 1 - i) + (m - 1 - j);
        if (count > remaining_steps) return false;

        if (i == n - 1 && j == m - 1 ) {
            return count == 0;
        }
        if (mem[i][j][count] != -1) {
            return mem[i][j][count];
        }

        return mem[i][j][count] = dfs(grid, count, n, m, i+1, j) || dfs(grid, count, n, m, i, j+1);
        // return answer;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        if ((n + m - 1) % 2 != 0 && grid[0][0] == ')' && grid[n-1][m-1] == '(') return false;

        memset(mem, -1, sizeof(mem));

        return dfs(grid, 0, n, m );
    }
};