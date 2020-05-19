class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        const int index = data.size();
        
        while (!stk.empty() && data[stk.back()] <= price) stk.pop_back();
        
        const int bk = stk.empty() ? -1 : stk.back();
        stk.push_back(index);
        data.push_back(price);
        return index - bk;
    }
private:
    vector<int> stk, data;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
