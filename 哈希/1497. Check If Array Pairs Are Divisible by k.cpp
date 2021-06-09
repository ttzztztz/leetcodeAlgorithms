class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        const int n = arr.size();
        unordered_map<int, int> mod;
        for (int i : arr) {
            mod[((i % k) + k) % k]++;
        }
        
        for (auto&[val, cnt] : mod) {
            if (val == 0) continue;
            
            if (k - val == val) {
                if (cnt % 2 == 1) return false;
            } else {
                if (cnt != mod[k - val]) {
                    return false;
                }
            }
        }
        
        return mod[0] % 2 == 0;
    }
};