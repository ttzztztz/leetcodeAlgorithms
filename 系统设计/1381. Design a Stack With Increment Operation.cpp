class CustomStack {
public:
    int maxSize;
    vector<int> data;
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if (data.size() >= maxSize) return;
        
        data.push_back(x);
    }
    
    int pop() {
        if (data.empty()) return -1;
        int answer = data.back();
        data.pop_back();
        return answer;
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < min(k, (int) data.size()); i++) data[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
