class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> numberSet(nums.begin(), nums.begin() + k);
        auto it = next(numberSet.begin(), k / 2);

        vector<double> answer;
        const int N = nums.size();
        for (int left = 0, right = k - 1; right < N; right++, left++) {
            if (k % 2) {
                answer.push_back(*it);
            } else {
                answer.push_back(0.5 * (*it) + 0.5 * (*prev(it, 1)));
            }

            if (right + 1 == N) {
                break;
            }
            // insert right
            numberSet.insert(nums[right + 1]);
            if (nums[right + 1] < *it) {
                it--;
            }

            // delete left
            if (nums[left] <= *it) {
                it++;
            }
            numberSet.erase(numberSet.lower_bound(nums[left]));
        }

        return answer;
    }
};