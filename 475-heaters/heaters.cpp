class Solution {
public:
    int findRadius(std::vector<int>& houses, std::vector<int>& heaters) {
        // Sort both arrays to allow sequential traversal
        std::sort(houses.begin(), houses.end());
        std::sort(heaters.begin(), heaters.end());
       
        int max_radius = 0;
        int heater_idx = 0;
        int num_heaters = heaters.size();
       
        // Iterate through each house
        for (int house : houses) {
            // Move the heater pointer forward if the NEXT heater
            // is closer to the current house than the CURRENT heater
            while (heater_idx + 1 < num_heaters &&
                   std::abs(heaters[heater_idx + 1] - house) <= std::abs(heaters[heater_idx] - house)) {
                heater_idx++;
            }
           
            // Calculate the distance from the house to its closest heater
            int current_dist = std::abs(heaters[heater_idx] - house);
           
            // Track the maximum radius needed to cover all houses
            max_radius = std::max(max_radius, current_dist);
        }
       
        return max_radius;
    }
};