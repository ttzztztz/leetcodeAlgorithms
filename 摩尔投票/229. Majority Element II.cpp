class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> answer;

        int candidate1 = 0, candidate2 = 0;
        int vote1 = 0, vote2 = 0;
        for (const int num : nums) {
            if (num == candidate1) {
                vote1++;
            } else if (num == candidate2) {
                vote2++;
            } else if (0 == vote1) {
                vote1 = 1;
                candidate1 = num;
            } else if (0 == vote2) {
                vote2 = 1;
                candidate2 = num;
            } else {
                vote1--;
                vote2--;
            }
        }

        vote1 = 0, vote2 = 0;
        for (int num : nums) {
            if (num == candidate1) {
                vote1++;
            } else if (num == candidate2) {
                vote2++;
            }
        }

        if (vote1 > (nums.size() / 3)) {
            answer.push_back(candidate1);
        }
        if (vote2 > (nums.size() / 3)) {
            answer.push_back(candidate2);
        }

        return answer;
    }
};