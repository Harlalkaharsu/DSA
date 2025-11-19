class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> temp(26, 0), curr(26, 0);
        for (auto ch : p) {
            temp[ch - 'a']++;
        }
        int left = 0;
        int right = 0;
        while (right < s.size()) {
            curr[s[right++]-'a']++;
            if((right-left)==p.size()){
                if(temp==curr){
                    ans.push_back(left);
                }
                curr[s[left]-'a']--;
                left++;
            }
        }
        return ans;
    }
};