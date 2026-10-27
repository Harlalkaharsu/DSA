class Solution {
    public String[] createGrid(int m, int n) {
        String[] grid = new String[m];
        
        for (int i = 0; i < m; i++) {
            StringBuilder row = new StringBuilder();
            for (int j = 0; j < n; j++) {
                // The path takes the first column and the bottom row
                if (j == 0 || i == m - 1) {
                    row.append('.');
                } else {
                    row.append('#');
                }
            }
            grid[i] = row.toString();
        }
        
        return grid;
    }
}
