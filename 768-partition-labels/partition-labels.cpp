class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        for(char a:s) mp[a]++;

        unordered_map<char, int> st;
        int count =0, start =0;
        vector<int> ans;
        for(int i =0 ; i<n; i++){
            char a = s[i];
            st[a]++;
            start++;
            if(st[a]==mp[a]) st.erase(a);
            if(st.size()==0){
                ans.push_back(start);
                start=0;
            }
        }
        return ans;
    }
};