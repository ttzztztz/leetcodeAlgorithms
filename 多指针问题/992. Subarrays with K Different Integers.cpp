class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        const int N = A.size();
        int left1 = 0, left2 = 0, right = 0, answer = 0;

        unordered_map<int, int> appear1, appear2;
        while (right < N) {
            appear1[A[right]]++, appear2[A[right]]++;

            while (appear1.size() > K) {
                if (--appear1[A[left1]] == 0) {
                    appear1.erase(A[left1]);
                }
                left1++;
            }

            while (appear2.size() >= K) {
                if (--appear2[A[left2]] == 0) {
                    appear2.erase(A[left2]);
                }
                left2++;
            }

            answer += left2 - left1;
            right++;
        }

        return answer;
    }
};