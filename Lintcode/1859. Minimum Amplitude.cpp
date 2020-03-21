class Solution {
public:
    /**
     * @param A: a list of integer
     * @return: Return the smallest amplitude
     */
    int MinimumAmplitude(vector<int> &A) {
        sort(A.begin(), A.end());
        const int N = A.size();
        if (N <= 4) return 0;
        int left = 0, right = N - 4;
        
        int answer = 99999999;
        while (right < N) {
            answer = min(answer, A[right] - A[left]);
            left++, right++;
        }
        return answer;
    }
};
