class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int i = k, j = k;
        int current_min = nums[k];
        int max_score = current_min; // Initial score for a subarray of size 1

        // Expand the window until it covers the entire array
        while (i > 0 || j < n - 1) {
            // If the left boundary is reached, we can only expand right
            if (i == 0) {
                j++;
            } 
            // If the right boundary is reached, we can only expand left
            else if (j == n - 1) {
                i--;
            } 
            // Greedily expand towards the larger adjacent element
            else if (nums[i - 1] > nums[j + 1]) {
                i--;
            } else {
                j++;
            }

            // Dynamically update the minimum in the current window
            current_min = min({current_min, nums[i], nums[j]});
            
            // Calculate and maximize the score
            max_score = max(max_score, current_min * (j - i + 1));
        }

        return max_score;
    }
};
