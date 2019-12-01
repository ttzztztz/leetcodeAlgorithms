class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> answer;

        int ptr1 = 0, ptr2 = 0;
        while (ptr1 < A.size() && ptr2 < B.size()) {
            const int left = max(A[ptr1][0], B[ptr2][0]), right = min(A[ptr1][1], B[ptr2][1]);
            if (left <= right) {
                answer.push_back(vector<int>{left, right});
            }

            if (A[ptr1][1] < B[ptr2][1]) {
                ptr1++;
            } else {
                ptr2++;
            }
        }

        return answer;
    }
};