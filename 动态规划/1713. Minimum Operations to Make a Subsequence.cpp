class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        const int n = target.size();
        unordered_map<int, int> ref;
        for (int i = 0; i < n; i++) ref[target[i]] = i;
        
        vector<int> process;
        for (int i : arr) {
            if (ref.count(i)) {
                process.push_back(ref[i]);
            }
        }
        
        int ans = 0;
        vector<int> stk;
        for (int i = 0; i < process.size(); i++) {
            if (stk.empty() || stk.back() < process[i]) stk.push_back(process[i]);
            else {
                auto it = lower_bound(stk.begin(), stk.end(), process[i]);
                *it = process[i];
            }
            
        }
        ans = stk.size();
        return n - ans;
    }
};
