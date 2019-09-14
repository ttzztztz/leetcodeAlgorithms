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

            queue.push_back(newNumber);
            tempAnswer = std::max(tempAnswer, newNumber);
        }
        answer.push_back(tempAnswer);

        for (int i = k ; i < nums.size(); i++) {
            int newNumber = nums[i];
            int frontNumber = queue.front();

            queue.pop_front();
            queue.push_back(newNumber);

            tempAnswer = 1 << 32 - 1;
            for (int j = 0; j < k; j++) {
                tempAnswer = std::max(tempAnswer, queue[j]);
            }

            answer.push_back(tempAnswer);
        }

        return answer;
    }
};