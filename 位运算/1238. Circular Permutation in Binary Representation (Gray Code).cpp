class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> answer;

        for (int i = 0; i < (1 << n); i++) {
            answer.push_back(start ^ i ^ (i >> 1));
        }

        return answer;
    }
};