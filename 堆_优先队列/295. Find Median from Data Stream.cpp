class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<>> lowHeap;
    priority_queue<int, vector<int>, less<>> highHeap;
    MedianFinder() {}

    void addNum(int num) {
        lowHeap.push(num);

        highHeap.push(lowHeap.top());
        lowHeap.pop();

        while (lowHeap.size() < highHeap.size()) {
            lowHeap.push(highHeap.top());
            highHeap.pop();
        }
    }

    double findMedian() {
        if (highHeap.size() != lowHeap.size()) {
            // odd
            return 1.0 * lowHeap.top();
        } else {
            // even
            return 1.0 * (highHeap.top() + lowHeap.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */