using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalarea = 0;
        double mini = 2e9, maxi = -2e9; // Use large/small bounds for coordinates

        for (const auto& sq : squares) {
            double len = sq[2];
            totalarea += len * len;
            mini = min(mini, (double)sq[1]);
            maxi = max(maxi, (double)sq[1] + len);
        }

        double target = totalarea / 2.0;
        double low = mini, high = maxi;
        double ans = mini;

        // Perform Binary Search on the y-coordinate range
        // 100 iterations provide high precision (approx 10^-30)
        for (int i = 0; i < 100; ++i) {
            double mid = (low + high) / 2.0;
            if (areaBelow(mid, squares) < target) {
                low = mid;
            } else {
                ans = mid;
                high = mid;
            }
        }
        return ans;
    }

private:
    double areaBelow(double mid, const vector<vector<int>>& squares) {
        double area = 0;
        for (const auto& sq : squares) {
            double y = sq[1];
            double len = sq[2];
            if (mid >= y + len) {
                area += len * len;
            } else if (mid > y) {
                area += len * (mid - y);
            }
        }
        return area;
    }
};