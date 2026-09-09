// class Solution {
// public:
//     long long countCommas(long long n) {
//         long long count =0;
//         // for(long long i=0; i<=n; i++){
//         //     if(i>=1000)count++;
//         // }
//         if(n<1000) count =0;
//         else count =((n-1000)+1);
//         return count;
//     }
// };
class Solution {
public:
    int64_t countCommas(auto& n) {
        int64_t count = 0;
        for (int64_t p = 1000; p <= n; p *= 1000)
            count += n - p + 1;

        return count;
    }
};