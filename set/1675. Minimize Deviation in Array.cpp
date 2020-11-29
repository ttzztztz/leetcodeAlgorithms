class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> v;
        for (int i : nums) {
            if (i % 2 == 1) i *= 2;
            v.insert(i);
        }
        
        int ans = *v.rbegin() - *v.begin();
        while (*v.rbegin() % 2 == 0) {
            const int val = *v.rbegin();
            v.erase(--v.end());
            v.insert(val / 2);
            
            ans = min(ans, *v.rbegin() - *v.begin());
        }
        return ans;
    }
};
