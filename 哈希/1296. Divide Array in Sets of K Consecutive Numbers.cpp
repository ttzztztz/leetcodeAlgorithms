class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        const int n = nums.size();
        if (n % k != 0) return false;
        
        map<int, int> a;
        for (int i : nums) a[i]++;
        
        while (!a.empty()) {
            auto [last, v] = *a.begin();
            a[last]--;
            if (v - 1 == 0) a.erase(last);
            for (int i = 1; i < k; i++) {
                if (!a.count(last + i)) return false;
                a[last + i]--;
                if (a[last + i] == 0) a.erase(last + i);
            }
        }
        return true;
    }
};