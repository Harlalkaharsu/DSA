class Solution {
    public int countIslands(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        int count = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    // Get the sum of the entire island using DFS
                    long islandSum = getIslandSum(grid, i, j, m, n);
                    // Check if the total value is divisible by k
                    if (islandSum % k == 0) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
    
    private long getIslandSum(int[][] grid, int r, int c, int m, int n) {
        // Base case: Out of bounds or water cell (0)
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
            return 0;
        }
        
        // Add the current cell value to the island sum
        long sum = grid[r][c];
        
        // Sink the cell to mark it as visited
        grid[r][c] = 0;
        
        // Explore all 4 adjacent directions
        sum += getIslandSum(grid, r + 1, c, m, n);
        sum += getIslandSum(grid, r - 1, c, m, n);
        sum += getIslandSum(grid, r, c + 1, m, n);
        sum += getIslandSum(grid, r, c - 1, m, n);
        
        return sum;
    }
}
