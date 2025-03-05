class MovingAverage {
public:
    MovingAverage(int size) {
        this->size = size;
    }
    
    double next(int val) {
        q.push_back(val);
        sum += val;

        if (q.size() > size) {
            sum -= q.front();
            q.pop_front();
        }

        return 1.0 * sum / q.size();
    }
private:
    deque<int> q;
    int size = 0, sum = 0;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */