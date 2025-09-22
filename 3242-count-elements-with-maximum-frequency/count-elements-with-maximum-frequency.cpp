class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101] = {0};
        int maxf =0, f=0;
        for(int x:nums){
            f +=(++freq[x] == maxf);
            if(freq[x]>maxf) f=1, maxf =freq[x];
        }
        return f*maxf;
    }
};