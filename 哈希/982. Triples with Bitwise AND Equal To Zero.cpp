class Solution {
public:
    int countTriplets(vector<int>& A) {
        int answer = 0;

        const int N = A.size();
        unordered_map<int, int> map;
        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < N; j++) {
                map[A[i] & A[j]]++;
            }
        }

        for (int i = 0; i < N; i++) {
            for (pair<int, int> p : map) {
                if ((p.first & A[i]) == 0) {
                    answer += p.second;
                }
            }
        }

        return answer;
    }
};