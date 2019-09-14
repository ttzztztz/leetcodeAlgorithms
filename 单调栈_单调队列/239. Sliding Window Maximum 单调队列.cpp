class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return vector<int>();
        }

        vector<int> answer;
        deque<int> queue;
        int tempAnswer = 1 << 32 - 1;
        for (int i = 0; i < k; i++) {
            int newNumber = nums[i];

            while (!queue.empty() && nums[queue.back()] < nums[i]) {
                queue.pop_back();
            }

            queue.push_back(i);
            tempAnswer = std::max(tempAnswer, newNumber);
        }
        answer.push_back(nums[queue.front()]);

        for (int i = k; i < nums.size(); i++) {
            while (!queue.empty() && queue.front() <= i - k) {
                queue.pop_front();
            }
            while (!queue.empty() && nums[queue.back()] < nums[i]) {
                queue.pop_back();
            }

            queue.push_back(i);
            answer.push_back(nums[queue.front()]);
        }

        return answer;
    }
};