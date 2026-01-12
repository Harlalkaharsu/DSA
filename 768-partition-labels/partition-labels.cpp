class Solution {
public:
    vector<int> partitionLabels(string s) {
        int start = 0, end = 0;
        vector<int> ans;
        for(int i= 0; i<s.size(); i++){
            if(i>end) {ans.push_back(end-start+1);
            start = i;
            end = i;}
            for(int j = i; j<s.size(); j++){
                if(s[i]==s[j]&&j>end){
                    end = j;
                }
            }
        }
        ans.push_back(s.size()-start);
        return ans;
    }
};