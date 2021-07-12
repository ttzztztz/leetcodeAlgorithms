class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) {
        big_heap.push(num);
        const int n = big_heap.size() + small_heap.size();
        
        if (big_heap.size() > (n / 2)) {
            auto t = big_heap.top();
            big_heap.pop();
            small_heap.push(t);
        }
        
        while (!big_heap.empty() && !small_heap.empty() && big_heap.top() > small_heap.top()) {
            auto a = big_heap.top(), b = small_heap.top();
            big_heap.pop(), small_heap.pop();
            big_heap.push(b), small_heap.push(a);
        }
    }
    
    double findMedian() {
        const int n = big_heap.size() + small_heap.size();
        if (n % 2 == 0) {
            return 0.5 * (big_heap.top() + small_heap.top());
        } else {
            return small_heap.top();
        }
    }
private:
    priority_queue<int, vector<int>, less<>> big_heap;
    priority_queue<int, vector<int>, greater<>> small_heap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */