class Solution {
public:
    bool isreal(string s, string t){
        int i =0, j=0, n=s.size(), m=t.size();
        while(i<n && j<m){
            if(s[i] == t[j])j++;i++;
        }
        return j==m;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int cnt=0;
        unordered_map<string,int> mp;
        for(auto i:words)mp[i]++;
        for(auto i:mp){
            if(isreal(s,i.first)) cnt += i.second;
        }
        return cnt;
    }
};