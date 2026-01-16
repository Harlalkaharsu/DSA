#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        // Step 1: Add boundaries (1 and m/n) to the list of fences
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        // Step 2: Store all possible horizontal gaps in a fast hash set
        unordered_set<int> hGaps;
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                hGaps.insert(hFences[j] - hFences[i]);
            }
        }

        // Step 3: Find the largest vertical gap that also exists in horizontal gaps
        long long maxSide = -1;
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                int gap = vFences[j] - vFences[i];
                if (hGaps.count(gap)) {
                    maxSide = max(maxSide, (long long)gap);
                }
            }
        }

        // Step 4: Return area modulo 10^9 + 7
        if (maxSide == -1) return -1;
        long long MOD = 1000000007;
        return (maxSide * maxSide) % MOD;
    }
};
