#include <vector>
#include <stack>

class Solution {
public:
    int sumSubarrayMins(std::vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;
        
        std::vector<long long> left(n), right(n);
        std::stack<int> s;
        
        // Step 1: Find distance to Previous Smaller Element (PSE)
        for (int i = 0; i < n; ++i) {
            // Maintain a strictly increasing stack
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            // If stack is empty, no smaller element on the left
            left[i] = s.empty() ? (i + 1) : (i - s.top());
            s.push(i);
        }
        
        while (!s.empty()) {
            s.pop();
        }
        
        // Step 2: Find distance to Next Smaller Element (NSE)
        for (int i = n - 1; i >= 0; --i) {
            // Note: Use strictly '>' here to properly handle duplicate elements
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            // If stack is empty, no smaller element on the right
            right[i] = s.empty() ? (n - i) : (s.top() - i);
            s.push(i);
        }
        
        // Step 3: Compute the total contribution of each element
        long long totalSum = 0;
        for (int i = 0; i < n; ++i) {
            // Total subarrays where arr[i] is the minimum = left[i] * right[i]
            long long count = (left[i] * right[i]) % MOD;
            long long contribution = (count * arr[i]) % MOD;
            
            totalSum = (totalSum + contribution) % MOD;
        }
        
        return totalSum;
    }
};
