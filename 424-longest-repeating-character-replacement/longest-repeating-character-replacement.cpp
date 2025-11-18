class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, maxLen = 0, n = s.size(), maxCount = 0;
        int hash[26] = {0};
        for(int right = 0; right < n; right++){
            hash[s[right] - 'A']++;
            maxCount = max(maxCount, hash[s[right] - 'A']);
            if((right - left + 1) - maxCount> k){
                hash[s[left] - 'A']--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};