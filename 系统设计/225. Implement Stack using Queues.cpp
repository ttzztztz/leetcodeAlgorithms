class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        data.push_back(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int answer = data.back();
        data.pop_back();
        return answer;
    }
    
    /** Get the top element. */
    int top() {
        return data.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return data.empty();
    }
private:
    deque<int> data;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
