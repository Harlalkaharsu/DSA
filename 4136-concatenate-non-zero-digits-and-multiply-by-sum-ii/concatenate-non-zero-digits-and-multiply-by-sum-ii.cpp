class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        long long MOD = 1e9 + 7;

        // Arrays to store prefix values for O(1) lookups
        vector<long long> pref_sum(n + 1, 0);
        vector<long long> pref_num(n + 1, 0);
        vector<long long> power10(n + 1, 1);
        vector<int> non_zero_count(n + 1, 0);

        // Precompute powers of 10 modulo (10^9 + 7)
        for (int i = 1; i <= n; i++) {
            power10[i] = (power10[i - 1] * 10) % MOD;
        }

        // Build the prefix tracking arrays
        for (int i = 0; i < n; i++) {
            long long x = s[i] - '0';
            
            // Standard prefix sum of digits
            pref_sum[i + 1] = pref_sum[i] + x;
            
            if (x != 0) {
                // If it's a non-zero digit, shift the previous hash and add x
                pref_num[i + 1] = ((pref_num[i] * 10) + x) % MOD;
                non_zero_count[i + 1] = non_zero_count[i] + 1;
            } else {
                // If it's zero, the number representation doesn't change
                pref_num[i + 1] = pref_num[i];
                non_zero_count[i + 1] = non_zero_count[i];
            }
        }

        int q = queries.size();
        vector<int> ans(q, 0);

        // Answer each query in O(1) time
        for (int i = 0; i < q; i++) {
            int L = queries[i][0];
            int R = queries[i][1];

            // 1. Get the range sum of digits in O(1)
            long long current_sum = pref_sum[R + 1] - pref_sum[L];

            // 2. Get the count of non-zero digits inside this specific range
            int total_non_zeros_in_range = non_zero_count[R + 1] - non_zero_count[L];

            // 3. Extract the sub-number formed by the non-zero digits in O(1)
            long long current_temp = (pref_num[R + 1] - (pref_num[L] * power10[total_non_zeros_in_range]) % MOD + MOD) % MOD;

            // 4. Calculate the final answer for the query
            long long need = (current_sum * current_temp) % MOD;
            ans[i] = need;
        }

        return ans;
    }
};
