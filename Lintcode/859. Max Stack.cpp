class MaxStack {
public:
    MaxStack() {
        // do intialization if necessary
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        stk.push_back(number);
        m.insert(number);
    }

    /*
     * @return: An integer
     */
    int pop() {
        int t = stk.back();
        stk.pop_back();
        m.erase(m.lower_bound(t));
        return t;
    }

    /*
     * @return: An integer
     */
    int top() {
        // write your code here
        return stk.back();
    }
    
    /*
     * @return: An integer
     */
    int peekMax() {
        // write your code here
        return *m.rbegin();
    }
    
    /*
     * @return: An integer
     */
    int popMax() {
        // write your code here
        int me = *m.rbegin();
        for (int i = stk.size() - 1; i >= 0; i--) {
            if (stk[i] == me) {
                stk.erase(stk.begin() + i);
                m.erase(m.lower_bound(me));
                break;
            }
        }
        return me;
    }
private:
    vector<int> stk;
    multiset<int> m;
};
