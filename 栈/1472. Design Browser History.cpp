class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        stk = {homepage};
        ptr = 0;
    }
    
    void visit(string url) {
        ptr++;
        if (ptr >= stk.size()) stk.push_back(url);
        else {
            stk[ptr] = url;
            while (stk.size() > ptr + 1) stk.pop_back();
        }
    }
    
    string back(int steps) {
        if (steps > ptr) {
            ptr = 0;
            return stk[ptr];
        } else {
            ptr -= steps;
            return stk[ptr];
        }
    }
    
    string forward(int steps) {
        if (ptr + steps >= stk.size()) {
            ptr = stk.size() - 1;
            return stk[ptr];
        } else {
            ptr += steps;
            return stk[ptr];
        }
    }
private:
    vector<string> stk;
    int ptr = 0;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
