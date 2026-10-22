// class Solution {
// public:
//     int minOperations(auto& A) {
//         int n = A.size();
//         int asc = 1, dsc = 1;

//         for (int i = 1; i < n; i++) {
//             asc += A[i] == (A[i - 1] + 1) % n;
//             dsc += A[i - 1] == (A[i] + 1) % n;
//         }

//         if (asc == n)
//             return A.front() ? min(n - A.front(), A.front() + 2) : 0;

//         if (dsc == n)
//             return min(n - A.back(), A.back()) + 1;

//         return -1;
//     }
// };
class Solution {
public:
    int minOperations(vector<int>& A) {
        int n = A.size();
        int asc = 1;
        int dsc = 1;

        // Check if the array elements follow a circular ascending or descending pattern
        for (int i = 1; i < n; i++) {
            // Check ascending: is the current element the next logical step after the previous?
            if (A[i] == (A[i - 1] + 1) % n) {
                asc++;
            }
            // Check descending: is the previous element the next logical step after the current?
            if (A[i - 1] == (A[i] + 1) % n) {
                dsc++;
            }
        }

        // Case 1: The array is fully sorted in a circular ascending order
        if (asc == n) {
            if (A.front() == 0) {
                return 0; // Already perfectly sorted
            }
            // Calculate minimum steps using shifts or a reverse operation
            int stepsToShift = n - A.front();
            int stepsToReverse = A.front() + 2;
            return min(stepsToShift, stepsToReverse);
        }

        // Case 2: The array is fully sorted in a circular descending order
        if (dsc == n) {
            int stepsToShift = n - A.back();
            int stepsToReverse = A.back();
            return min(stepsToShift, stepsToReverse) + 1;
        }

        // Case 3: The array cannot be sorted using these operations
        return -1;
    }
};
