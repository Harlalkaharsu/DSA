class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int temp=0;
        for(int i=0; i< n; i++){
            if(grumpy[i] == 0) temp += customers[i];
        }
        int ans = 0;
        int req = temp;
        for(int i=0; i<= n-minutes; i++){
            for(int j=i; j< i+minutes; j++){
                if(grumpy[j] ==1) temp+= customers[j];
            }
            ans = max(ans, temp);
            temp = req;
        }
        return ans;
    }
};