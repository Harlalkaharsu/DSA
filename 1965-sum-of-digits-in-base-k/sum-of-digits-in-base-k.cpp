class Solution {
public:
    int sumBase(int n, int k) {
        int answer = 0;
        // Convert n to base k and sum each digit
        while (n > 0) {
            answer += n % k; // Add the current digit (n mod k)
            n /= k; // Remove the processed digit
        }
        return answer;
    }
};