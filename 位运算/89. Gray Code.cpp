class Solution {
public:
    vector<int> grayCode(int n) {
        const int MAX_NUMBER = (1 << n) - 1;
        vector<int> answer(MAX_NUMBER + 1, 0);

        for (int i = 1; i <= MAX_NUMBER; i++) {
            answer[i] = i ^ (i >> 1);
        }

        return answer;
    }
};