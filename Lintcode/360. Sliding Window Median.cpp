class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        const int N = nums.size();
        
        vector<int> answer;
        if (N <= 0) return answer;
        
        multiset<int> mset(nums.begin(), nums.begin() + k);
        auto it = next(mset.begin(), (k - 1) / 2);
        answer.push_back(*it);
        for (int i = k; i < N; i++) {
            mset.insert(nums[i]);
            if (nums[i] < *it) {
                it--;
            }
            
            if (nums[i - k] <= *it) {
                it++;
            }
            mset.erase(mset.lower_bound(nums[i - k]));
            answer.push_back(*it);
        }
        
        return answer;
    }
};
