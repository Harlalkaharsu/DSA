class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        long long cnt =0, smallest = LLONG_MAX, sum =0;
        for(int i =0; i< n; i++){
            for(int j =0; j<m; j++){
                if(matrix[i][j] <0) cnt++;
                long long val = llabs(matrix[i][j]);
                smallest = min(smallest, val);
                sum += val;
            }
        }
        if(cnt % 2 == 0) return sum;
        return sum-(2*smallest);
    }
};