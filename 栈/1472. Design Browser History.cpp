class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        history = { homepage };
        ptr = 0;
    }
    
    void visit(string url) {
        ptr++;
        history.resize(ptr + 1);
        history[ptr] = url;
    }
    
    string back(int steps) {
        ptr = max(0, ptr - steps);
        return history[ptr];
    }
    
    string forward(int steps) {
        ptr = min<int>(history.size() - 1, ptr + steps);
        return history[ptr];
    }
private:
    vector<string> history;
    int ptr = 0;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */