class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.size() == 0) {
            return 0;
        }

        std::sort(pairs.begin(), pairs.end(), [](const vector<int>& $1, const vector<int>& $2)->bool{
            return $1[1] < $2[1];
        });

        int answer = 0, last = 1 << 32 - 1;
        for (int i = 0; i < pairs.size(); i++) {
            int start = pairs[i][0], end = pairs[i][1];

            if (start > last) {
                last = end;
                answer++;
            }
        }

        return answer;
    }
};