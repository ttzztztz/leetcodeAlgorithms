class Solution {
public:
    Solution(vector<int>& w) {
        for (int i = 0; i < w.size(); i++) {
            pref.push_back((pref.empty() ? 0 : pref.back()) + w[i]);
        }
        total = pref.back();
        N = w.size();
        uni = uniform_int_distribution<int>(0, total - 1);
    }
    
    int pickIndex() {
        const int r = random();
        int left = 0, right = pref.size() - 1;
        while (left <= right) {
            const int mid = (left + right) >> 1;
            
            if (pref[mid] <= r) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
private:
    vector<int> pref;
    int N, total;
    
    mt19937 rng{random_device{}()};
    uniform_int_distribution<int> uni;
    
    int random() {
        return uni(rng);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
