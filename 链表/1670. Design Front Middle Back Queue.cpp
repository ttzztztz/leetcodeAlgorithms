class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        const int n = data.size();
        data.push_front(val);
        if (n == 0) {
            it = data.begin();
        } else if (n % 2 == 1) {
            //  [n] x [m] x
            it--;
        } else { // n % 2 == 0
            // [n] [m] x
        }
    }
    
    void pushMiddle(int val) {
        const int n = data.size();
        if (n == 0) {
            data.push_back(val);
            it = data.begin();
        } else if (n % 2 == 1) {
            // x [n] [m] x
            data.insert(it, val);
            it--;
        } else { // n % 2 == 0
            // [m] x
            data.insert(next(it), val);
            it++;
        }
    }
    
    void pushBack(int val) {
        const int n = data.size();
        data.push_back(val);
        if (n == 0) {
            it = data.begin();
        } else if (n % 2 == 1) {
            //  x [m] x [n]
        } else { // n % 2 == 0
            // [m] x [n]
            it++;
        }
    }
    
    int popFront() {
        if (data.empty()) return -1;
        const int n = data.size();
        
        int t = -1;
        if (n % 2 == 1) {
            // [x] [m] x
            t = data.front();
            data.pop_front();
        } else { // n % 2 == 0
            // [m] x
            t = data.front();
            auto nxt = next(it);
            data.pop_front();
            it = nxt;
        }
        return t;
    }
    
    int popMiddle() {
        if (data.empty()) return -1;
        const int n = data.size();
        
        int t = -1;
        if (n % 2 == 1) {
            // x [m] x
            auto nxt = prev(it);
            t = *it;
            data.erase(it);
            it = nxt;
        } else { // n % 2 == 0
            // x [m] x x
            auto nxt = next(it);
            t = *it;
            data.erase(it);
            it = nxt;
        }
        return t;
    }
    
    int popBack() {
        if (data.empty()) return -1;
        const int n = data.size();
        
        int t = -1;
        if (n % 2 == 1) {
            // x [m] [x]
            t = data.back();
            data.pop_back();
            if (!data.empty()) it--;
        } else { // n % 2 == 0
            // x [x] x x
            t = data.back();
            data.pop_back();
        }
        return t;
    }
private:
    list<int> data;
    list<int>::iterator it;
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
