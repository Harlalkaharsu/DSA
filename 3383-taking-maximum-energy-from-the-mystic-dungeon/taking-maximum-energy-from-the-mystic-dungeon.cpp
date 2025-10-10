class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int max_energy = INT_MIN;
        for (int i = n-1; i >= n-k && i >=0; i--) {
            int sum = 0;
            for (int j = i; j >= 0; j -= k) {
                sum += energy[j];
                max_energy = max(max_energy, sum);
            }
        }
        return max_energy;
    }
};