class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        const int N = A.size();

        vector<int> _1pos;
        vector<int> answer{-1, -1};
        for (int i = 0; i < N; i++) {
            if (A[i] == 1) {
                _1pos.push_back(i);
            }
        }

        if (_1pos.size() % 3) {
            return answer;
        }
        if (_1pos.size() == 0) {
            return vector<int>{0, 2};
        }

        const int partSize = _1pos.size() / 3;
        int end1 = _1pos[partSize - 1], end2 = _1pos[2 * partSize - 1], end3 = _1pos[3 * partSize - 1];
        const int endZeroCount = N - 1 - end3;

        if (end2 + endZeroCount >= end3) {
            return answer;
        } else {
            end2 += endZeroCount;
        }

        if (end1 + endZeroCount >= end2) {
            return answer;
        } else {
            end1 += endZeroCount;
        }

        end3 = N - 1;

        int ptr = 0;
        while (end1 - ptr >= 0 && end2 - ptr > end1 && end3 - ptr > end2) {
            if (A[end3 - ptr] == A[end2 - ptr] && A[end2 - ptr] == A[end1 - ptr]) {
                ptr++;
            } else {
                return answer;
            }
        }

        answer[0] = end1, answer[1] = end2 + 1;
        return answer;
    }
};