class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        return make(countAndSay(n-1));
    }
    string make(const string& s){
        string result;
        int count= 1;
        for(int i =1; i<s.size(); i++){
            if(s[i] ==s[i-1]) count++;
            else{
                result += to_string(count) + s[i-1];
                count=1;
            }
        }
        result+=to_string(count) + s.back();
        return result;
    }
};