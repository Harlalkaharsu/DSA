class Solution {
public:
    int secondHighest(string s) {
        set<int> st;
        vector<int> ans;

        for(auto x:s){
            if(isdigit(x)){
                st.insert(x-'0');
            }
        }
        for(auto x:st) ans.push_back(x);

        sort(ans.begin(),ans.end());

        if(ans.size()<2) return -1;
        if(ans.size() == 2 ) return ans[0];
        else return ans[ans.size()-2];
    }
};