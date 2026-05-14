class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());

        // size must be n + 1
        if(nums.size() != n + 1)
            return false;

        vector<int> freq(n + 1, 0);

        for(int x : nums) {
            // invalid number
            if(x < 1 || x > n)
                return false;
            freq[x]++;
        }

        // 1 to n-1 should appear once
        for(int i = 1; i < n; i++) {
            if(freq[i] != 1)
                return false;
        }
        // n should appear twice
        return freq[n] == 2;
    }
};