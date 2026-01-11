class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> height(m,0);
        int maxarea= 0;
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(matrix[i][j] == '1') height[j] += 1;
                else height[j] = 0;
            }
            maxarea = max(maxarea, solve(height));
        }
        return maxarea;
    }
    int solve(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk;
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            int current = (i == n) ? 0 : heights[i];

            while (!stk.empty() && current < heights[stk.top()]) {
                int height = heights[stk.top()];
                stk.pop();

                int left = stk.empty() ? -1 : stk.top();
                int width = i - left - 1;

                maxArea = max(maxArea, height * width);
            }
            stk.push(i);
        }

        return maxArea;
    }
};