#include <vector>
#include <queue>

class KthLargest {
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int kth;
public:
    KthLargest(int k, std::vector<int>& nums) : pq (nums.begin(), nums.end()), kth {k} {    
        while (pq.size() > k) pq.pop();
    }
    
    int add(int val) {
        pq.push(val);

        if (pq.size() > kth) pq.pop();

        return pq.top();        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */