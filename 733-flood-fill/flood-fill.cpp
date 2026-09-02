class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int n, int m, int color, int originalColor){
        if(i < 0 || i >= n || j < 0 || j >= m || image[i][j] != originalColor) return;
        
        image[i][j] = color;
        
        dfs(image, i - 1, j, n, m, color, originalColor);
        dfs(image, i + 1, j, n, m, color, originalColor);
        dfs(image, i, j - 1, n, m, color, originalColor);
        dfs(image, i, j + 1, n, m, color, originalColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int originalColor = image[sr][sc];
        
        if (originalColor == color) return image;
        
        dfs(image, sr, sc, n, m, color, originalColor);
        return image;
    }
};
