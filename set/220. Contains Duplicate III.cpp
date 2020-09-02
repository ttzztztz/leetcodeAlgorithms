class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nu, int k, int t) {
        vector<long long> nums;
        for (int i : nu) nums.push_back(i);
        const int n = nums.size();
        multiset<long long> s;
        
        for (int l = 0, r = 0; r < n; r++) {
            while (r - l > k) {
                s.erase(s.lower_bound(nums[l]));
                l++;
            }
            
            if (s.size() >= 1) {
                auto it1 = s.lower_bound(nums[r] - t);
                if (it1 != s.end() && nums[r] >= *it1) {
                    return true;
                }
                
                auto it2 = s.upper_bound(nums[r] + t);
                if (it2 != s.begin()) {
                    it2--;
                    
                    if (nums[r] <= *it2) return true;
                }
            }
            
            s.insert(nums[r]);
        }
        
        return false;
    }
};
