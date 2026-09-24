class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n,0);
        stack<int> st;
        // for(int i=0; i< n; i++){
        //     int large =0;
        //     for(int j=i+1; j<n ;j++){
        //         if(((heights[i] > heights[j]) && large < heights[j]) || (heights[i] < heights[j]) && large < heights[i]){
        //             ans[i]++;
        //             large= max(large, heights[j]);
        //         }
        //     }
        // }
        for(int i= n-1; i>=0; i--){
            int count =0;

            while(!st.empty() && st.top() < heights[i]){
                count++;
                st.pop();
            }
            if(!st.empty()) count++;
              
            ans[i] = count;
            st.push(heights[i]);
        }

        return ans;
    }
};