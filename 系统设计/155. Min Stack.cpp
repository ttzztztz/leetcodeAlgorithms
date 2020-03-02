class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        stk.push_back(x);
        if (helper.empty() || helper.back() > x) helper.push_back(x);
        else helper.push_back(helper.back());
    }
    
    void pop() {
        helper.pop_back();
        stk.pop_back();
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return helper.back();
    }
private:
    vector<int> helper;
    vector<int> stk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
