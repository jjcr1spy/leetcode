#include <unordered_map>
#include <string>
#include <utility>
#include <vector>

class TimeMap {
private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> m;

public:
    TimeMap() : m {} {}

    void set(std::string key, std::string value, int timestamp) {
        m[key].push_back(std::make_pair(value, timestamp));
    }
    
    std::string get(std::string key, int timestamp) {
        if (m.find(key) == m.end() || m[key].front().second > timestamp) {
            return "";
        }

        if (m[key].back().second <= timestamp) {
            return m[key].back().first;
        } 

        int i = 0, j = m[key].size() - 1; 
        while (i <= j) {
            int mid = i + (j - i) / 2;

            if (m[key][mid].second == timestamp) {
                return m[key][mid].first;
            }
            
            if (m[key][mid].second > timestamp) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }   
        }

        return m[key][j].first;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * std::string param_2 = obj->get(key,timestamp);
 */