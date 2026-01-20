class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<long long> left(n), right(n);
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && maxHeights[st.top()] > maxHeights[i]) st.pop();
            left[i] = (st.empty() ? 0 : left[st.top()]) + 1LL * (i - (st.empty() ? -1 : st.top())) * maxHeights[i];
            st.push(i);
        }
        while (!st.empty()) st.pop();
        
        long long ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && maxHeights[st.top()] > maxHeights[i]) st.pop();
            right[i] = (st.empty() ? 0 : right[st.top()]) + 1LL * ((st.empty() ? n : st.top()) - i) * maxHeights[i];
            st.push(i);
            ans = max(ans, left[i] + right[i] - maxHeights[i]);
        }
        return ans;
    }
};
