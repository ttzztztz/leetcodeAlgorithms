class RangeFreqQuery {
public:
    RangeFreqQuery(vector<int>& arr) {
        const int n = arr.size();
        for (int i = 0; i < n; i++) {
            idx[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        auto& data = idx[value];
        auto l = lower_bound(data.begin(), data.end(), left);
        auto r = upper_bound(data.begin(), data.end(), right);
        return r - l;
    }
private:
    unordered_map<int, vector<int>> idx;
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
