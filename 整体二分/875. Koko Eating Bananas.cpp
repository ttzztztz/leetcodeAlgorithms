class Solution {
public:
    int judge(const vector<int>& piles, int K) {
        int answer = 0;

        for (int pile : piles) {
            answer += pile / K;
            if (pile % K) {
                answer++;
            }
        }

        return answer;
    }
    int minEatingSpeed(vector<int>& piles, int H) {
        int left = 1, right = 1;
        for (int pile : piles) {
            right = max(right, pile);
        }

        while (left <= right) {
            const int middle = (left + right) >> 1;

            if (judge(piles, middle) <= H) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }

        return right + 1;
    }
};