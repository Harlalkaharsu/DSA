class Solution {
public:
    const int mod = 1e9+7; 
    long long solve(long long x, long long n)
    {
        if(n == 0) return 1;
        if(n%2 == 0)  //if power is even
        {
            return solve((x*x)%mod, n/2);
        }
        else   //if power if odd
        {
            return (x*solve(x, n-1))%mod;
        }  
    }
    int countGoodNumbers(long long n) 
    {
        long long even = (n+1)/2; 
        long long odd = n/2;      
        long long ans = (solve(5,even)*solve(4,odd)) % mod;
        return ans;
    }
};