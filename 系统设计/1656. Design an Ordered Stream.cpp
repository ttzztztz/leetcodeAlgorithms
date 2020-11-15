class OrderedStream {
public:
    OrderedStream(int n) {
        data = vector<string>(n + 1, "");
        used = vector<bool>(n + 1, false);
        ptr = 1;
    }
    
    vector<string> insert(int id, string value) {
        vector<string> ans;
        
        data[id] = value;
        used[id] = true;
        if (id == ptr) {
            for (; ptr < data.size(); ptr++) {
                if (!used[ptr]) break;
                ans.push_back(data[ptr]);
            }
        }
        
        return ans;
    }
private:
    vector<string> data;
    vector<bool> used;
    int ptr;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */
