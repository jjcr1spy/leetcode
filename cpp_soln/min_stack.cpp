#include <vector>
#include <utility>
#include <climits>
#include <algorithm>

class MinStack {
public:
    std::vector<std::pair<int, int>> myvec;

    MinStack() {
    
    }
    
    void push(int val) {
        if (myvec.empty()) myvec.push_back({val, val});
        else myvec.push_back({val, std::min(val, myvec.back().second)});
    }
    
    void pop() {
        myvec.pop_back();
    }
    
    int top() {
        return myvec.back().first;
    }
    
    int getMin() {
        return myvec.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */