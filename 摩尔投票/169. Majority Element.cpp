class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int number = 0, vote = 0;

        for (int num : nums) {
            if (vote == 0) {
                number = num;
                vote = 1;
            } else if (number == num) {
                vote++;
            } else {
                vote--;
            }
        }

        return number;
    }
};