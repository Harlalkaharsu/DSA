class Solution {
public:
    bool rotateString(string s, string goal) {
        string result;
        result = s;
        if(s.size()!=goal.size()) return false;
        for(int i =0; i< s.size();i++){

            char x = result[0];
            result = result.substr(1,result.size());
            result = result + x;
            cout<<result<<endl;
            if(result == goal) return true;
        }
        return false;
    }
};