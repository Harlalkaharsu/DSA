class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int ans = letters[0];
        if(letters[letters.size() - 1] <= target ) return ans;

        for(int i =0; i<letters.size() ; i++){
            if(letters[i] > target){
                ans = letters[i];
                break;
            }else continue;
        }
        return ans;
    }
};