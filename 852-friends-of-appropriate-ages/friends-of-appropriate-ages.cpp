class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> count(121, 0);
        for (int age : ages)
            count[age]++;

        vector<int> prefix(121, 0);
        for (int i = 1; i <= 120; i++)
            prefix[i] = prefix[i - 1] + count[i];

        int ans = 0;
        for (int ageA = 15; ageA <= 120; ageA++) { // below 15 no requests possible
            if (count[ageA] == 0) continue;

            int minAge = ageA / 2 + 7;

            // valid range: (minAge, ageA]
            int total = prefix[ageA] - prefix[minAge];

            // subtract self
            total -= 1;

            ans += count[ageA] * total;
        }

        return ans;
    }
};
