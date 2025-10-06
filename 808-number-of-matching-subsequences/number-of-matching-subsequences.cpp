class Solution {
public:
    
    bool issubsequence(string& s, string t){
        int i = 0, j = 0, n = s.size(), m = t.size();

        while(i<n and j<m){
            if(s[i] == t[j]) j++;
            i++;
        }

        return j >= m;
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        unordered_map<string, int> mp;
        for(auto i : words) mp[i]++;

        for(auto i : mp) if(issubsequence(s, i.first)) ans += i.second;

        return ans;   
    }
};