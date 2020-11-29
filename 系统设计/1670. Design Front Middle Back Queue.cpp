class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        data.push_front(val);
    }
    
    void pushMiddle(int val) {
        const int n = data.size();
        auto it = data.begin() + (n / 2);
        data.insert(it, val);
    }
    
    void pushBack(int val) {
        data.push_back(val);
    }
    
    int popFront() {
        if (data.empty()) return -1;
        
        const int t = data.front();
        data.pop_front();
        return t;
    }
    
    int popMiddle() {
        if (data.empty()) return -1;
        const int n = data.size();
        
        const int t = data[(n - 1) / 2];
        data.erase(data.begin() + ((n - 1) / 2));
        return t;
    }
    
    int popBack() {
        if (data.empty()) return -1;
        const int t = data.back();
        data.pop_back();
        return t;
    }
private:
    deque<int> data;
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
