#include <queue>

class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (left.empty()) {
            left.push(num);
            return;
        }

        if (left.size() > right.size()) {
            if (left.top() < num) {
                right.push(num);
            } else {
                int l = left.top();
                left.pop();
                left.push(num);
                right.push(l);
            }
        } else { // can be equal size or right greater
            if (right.top() > num) {
                left.push(num);
            } else {
                int r = right.top();
                right.pop();
                right.push(num);
                left.push(r);
            }
        }
    }
    
    double findMedian() {
        if (left.size() == right.size()) return ((double) right.top() + left.top()) / 2;
        
        return right.size() > left.size() ? right.top() : left.top();
    }
private:
    std::priority_queue<int> left;
    std::priority_queue<int, std::vector<int>, std::greater<int>> right;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */