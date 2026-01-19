class Solution {
public:
    long long int minimumMoves(vector<int>& nums, int k, int maxChanges) {
        int n = nums.size(); vector<int> ones;
        long long ans = LONG_MAX;
        bool flag = 0;
        for(int i = 0; i < n; i++){
            int curr = nums[i], moves = 0;
            if(  nums[i] ) ones.push_back(i);
            if( i > 0 && nums[i-1] == 1 && curr < k ){
                moves++;curr++;
            }
            if( i + 1 < n && nums[i+1] == 1 && curr < k ){
                moves++;curr++;
            }
            if( curr + maxChanges >= k ){
                flag = 1;
                moves += ( k - curr )*2;
                ans = min(ans, 1LL*moves);
            }
        }
        if( flag ) return ans;
        int rem = k - maxChanges, noOfOnes = ones.size(), l = 0, r = rem-1;
        long long currMoves = 2*maxChanges;
        for(int i = 0; i < rem; i++){
            currMoves += abs(ones[r/2] - ones[i]);
        }
        ans = min(ans, currMoves);
        l++; r++;
        while( r < noOfOnes ){
            int mid = (l+r)/2;
            int curr = ones[mid], prev = ones[mid-1], lc = mid - l, rc = r - mid;
            currMoves = currMoves - curr*(rc-lc+1) + prev*(rc-lc-1) + ones[l-1] + ones[r];
            ans = min(ans, currMoves);
            l++; r++;
        }
        return ans;
    }
};