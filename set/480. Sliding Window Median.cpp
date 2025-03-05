class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;

        multiset<int> data(nums.begin(), nums.begin() + k);
        auto it = next(data.begin(), k / 2);
        if (k % 2 == 1) ans.push_back(*it);
        else ans.push_back(0.5 * (*it) + 0.5 * (*prev(it, 1)));
        
        for (int i = k; i < nums.size(); i++) {
            data.insert(nums[i]);
            if (nums[i] < *it) it--;
            if (nums[i - k] <= *it) it++;
            data.erase(data.lower_bound(nums[i - k]));

            if (k % 2 == 1) ans.push_back(*it);
            else ans.push_back(0.5 * (*it) + 0.5 * (*prev(it, 1)));
        }
        return ans;
    }
};