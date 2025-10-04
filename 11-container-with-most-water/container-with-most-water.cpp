class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int n = height.size() - 1;
        int area = 0;
        while(i<n){
            area = max(area, (n-i)*min(height[i],height[n]));
            if (height[i] < height[n]) i++;
            else n--;
        }
        return area;
    }
};