class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
    }
    
    double next(int val) {
        all.push_back(val);
        sum += 1.0 * val;
        while (all.size() > size) {
            const int t = all.front();
            all.pop_front();
            sum -= 1.0 * t;
        }
        
        return sum / (1.0 * all.size());
    }
private:
    double sum = 0.0;
    deque<int> all;
    int size = 0;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
