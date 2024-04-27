#include <vector>
#include <utility>
#include <algorithm>

class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        int n = position.size();
        
        std::vector<std::pair<int, double>> cars;
        for (int i = 0; i < n; i++) cars.push_back({position[i], (double) (target - position[i]) / speed[i]});
        sort(cars.begin(), cars.end());
        
        double maxTime = 0.0;
        int result = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            double time = cars[i].second;
            if (time > maxTime) {
                maxTime = time;
                result++;
            }
        }
        
        return result;
    }
};