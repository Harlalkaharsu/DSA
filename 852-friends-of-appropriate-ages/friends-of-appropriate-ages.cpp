class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int n = ages.size();
        int ans = 0;

        int left = 0, right = 0;

        for (int i = 0; i < n; i++) {
            int age = ages[i];
            if (age < 15) continue;  // below 15 can't send requests

            // move left pointer until it satisfies: ages[left] > 0.5 * age + 7
            while (left < n && ages[left] <= 0.5 * age + 7)
                left++;

            // move right pointer while next person is still <= age
            while (right + 1 < n && ages[right + 1] <= age)
                right++;

            // count how many are in (left, right]
            ans += right - left;

        }

        return ans;
    }
};