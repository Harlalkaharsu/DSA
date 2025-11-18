class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, maxLen = 0, n = s.size(), maxCount = 0;
        int hash[26] = {0};
        for(int i = 0; i < n; i++){
            hash[s[i] - 'A']++;
            maxCount = max(maxCount, hash[s[i] - 'A']);
            if((i - left + 1) - maxCount> k){
                hash[s[left] - 'A']--;
                left++;
            }
            maxLen = max(maxLen, i - left + 1);
        }
        return maxLen;
    }
};