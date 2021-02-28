class FreqStack {
public:
    FreqStack() {
        
    }
    
    void push(int x) {
        int freq = 1;
        if (rev_data.count(x)) {
            freq = rev_data[x] + 1;
        }
        
        data[freq].push_back(x);
        rev_data[x] = freq;
        max_freq = max(max_freq, freq);
    }
    
    int pop() {
        int ans = data[max_freq].back();
        rev_data[ans]--;
        data[max_freq].pop_back();
        if (data[max_freq].empty()) max_freq--;
        return ans;
    }
private:
    unordered_map<int, vector<int>> data;
    unordered_map<int, int> rev_data;
    int max_freq = 0;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
