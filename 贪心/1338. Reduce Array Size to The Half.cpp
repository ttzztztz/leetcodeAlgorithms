class Solution {
public:
    int minSetSize(vector<int>& arr) {
        const int n = arr.size();
        unordered_map<int, int> appear;
        for (int i : arr) appear[i]++;
        
        vector<int> t;
        for (auto& [k, v] : appear) t.push_back(v);
        sort(t.begin(), t.end());
        
        int removed = 0, ans = 0, idx = t.size() - 1;
        const int should_remove = (n + 1) / 2;
        while (removed < should_remove) {
            removed += t[idx];
            idx--;
            ans++;
        }
        return ans;
    }
};