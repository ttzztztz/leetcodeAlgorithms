class Solution {
public:
    int longestDecomposition(string text) {
        const int N = text.size();
        int leftPtr = 0, rightPtr = N - 1, answer = 0;
        string left, right;

        while (leftPtr <= rightPtr) {
            left = left + text[leftPtr];
            right = text[rightPtr] + right;

            if (left == right) {
                if (leftPtr == rightPtr) {
                    answer += 1;
                } else {
                    answer += 2;
                }

                left = "";
                right = "";
            }

            leftPtr++;
            rightPtr--;
        }

        if (left.size() > 0) {
            answer++;
        }

        return answer;
    }
};