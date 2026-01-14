class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string> ans;
        map<string, int> mpp;

        for(int i = 0; i<n-9; i++){
            string temp = "";
            for(int j =i; j<i+10;j++){
                temp.push_back(s[j]);
            }
            mpp[temp]++;
        }
        for(auto x: mpp){
            if(x.second>1){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};