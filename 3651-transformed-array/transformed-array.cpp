class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                result[i] = nums[i];
            } else {
                int steps = abs(nums[i]);
                int pos = i;

                if (nums[i] > 0) {
                    for (int j = 0; j < steps; j++) {
                        pos = (pos + 1) % n;
                    }
                } else {
                    for (int j = 0; j < steps; j++) {
                        pos = (pos - 1 + n) % n;
                    }
                }

                result[i] = nums[pos];
            }
        }

        return result;
    }
};