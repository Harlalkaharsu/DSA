class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
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