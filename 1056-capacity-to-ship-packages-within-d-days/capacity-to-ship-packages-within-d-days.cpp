class Solution {
private:
    int findDays(vector<int> &arr, int cap) {
    int days = 1; //First day.
    int load = 0;
    int n = arr.size(); //size of array.
    for (int i = 0; i < n; i++) {
        if (load + arr[i] > cap) {
            days += 1; //move to next day
            load = arr[i]; //load the weight.
        }
        else {
            //load the weight on the same day.
            load += arr[i];
        }
    }
    return days;
}
public:
    int shipWithinDays(vector<int>& arr, int days) {
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int numberOfDays = findDays(arr, mid);
        if (numberOfDays <= days) {
            //eliminate right half
            high = mid - 1;
        }
        else {
            //eliminate left half
            low = mid + 1;
        }
    }
    return low;
    }
};