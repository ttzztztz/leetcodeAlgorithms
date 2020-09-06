class Solution {
public:
    bool haveZero(int i) {
        while (i) {
            if (i % 10 == 0) return true;
            i /= 10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> answer = {1, n - 1};
        while (haveZero(answer[0]) || haveZero(answer[1])) {
            answer[0]++;
            answer[1]--;
        }
        return answer;
    }
};
