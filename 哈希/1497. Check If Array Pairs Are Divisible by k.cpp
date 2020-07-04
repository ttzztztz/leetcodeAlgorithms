class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> cnt;
        for (int& i : arr) {
            cnt[((i % k) + k) % k]++;
        }
        
        for (auto& p : cnt) {
            if (p.first == 0) continue;
            const int t = p.first;
            const int r = k - t;
            
            if (t == r) {
                if (cnt[t] % 2 == 1) return false;
            } else {
                if (cnt[t] != cnt[r]) return false;
            }
        }
        
        return true;
    }
};