class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        data.insert(num);

        if (data.size() == 1) {
            it = data.begin();
        } else {
            if (num < *it) it--;
            if (data.size() % 2 == 0) it++;
        }
    }
    
    double findMedian() {
        if (data.size() % 2 == 1) {
            return *it;
        }

        return 0.5 * (*it) + 0.5 * (*prev(it, 1));
    }
private:
    multiset<int> data;
    multiset<int>::iterator it;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */