class Solution {
public:
    /**
     * @param arr: an array of integers
     * @return: return the biggest value X, which occurs in A exactly X times.
     */
    int findX(vector<int> &arr) {
        // write your code here
        const int N = arr.size();
        unordered_map<int, int> f;
        for (const auto& i : arr) f[i]++;
        int answer = 0;
        for (const auto& p : f) {
            if (p.first == p.second) {
                answer = max(answer, p.first);
            }
        }
        return answer;
    }
};
