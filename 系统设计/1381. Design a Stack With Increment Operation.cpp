class CustomStack {
public:
    CustomStack(int maxSize) {
        max_size = maxSize;
    }
    
    void push(int x) {
        if (data.size() == max_size) return;
        data.push_back(x);
        
        if (!diff.empty()) diff.back() += cur;
        diff.push_back(0);
        cur = 0;
    }
    
    int pop() {
        if (data.empty()) return -1;
        else {
            const int t = data.back();
            data.pop_back();
            cur += diff.back();
            diff.pop_back();
            return t + cur;
        }
    }
    
    void increment(int k, int val) {
        if (data.empty()) return;
        const int n = data.size();
        diff[min(k - 1, n - 1)] += val;
    }
private:
    int max_size = 0;
    vector<int> data, diff;
    int cur = 0;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */