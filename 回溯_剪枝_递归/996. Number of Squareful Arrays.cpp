class Solution {
public:
    int N;
    bool isAvailable(const int left, const int right) {
        const int x = sqrt(left + right);

        return x * x == left + right;
    }
    int dfs(const vector<int>& A, unordered_map<int, int>& appearCount, int index, const int lastNumber) {
        if (index >= N) {
            return 1;
        }

        int answer = 0;
        for (pair<const int, int>& p : appearCount) {
            if (p.second > 0 && isAvailable(lastNumber, p.first)) {
                p.second--;
                answer += dfs(A, appearCount, index + 1, p.first);
                p.second++;
            }
        }
        return answer;
    }
    int numSquarefulPerms(vector<int>& A) {
        N = A.size();
        unordered_map<int, int> appearCount;
        for (int a : A) {
            appearCount[a]++;
        }

        int answer = 0;
        for (pair<const int, int>& p : appearCount) {
            p.second--;
            answer += dfs(A, appearCount, 1, p.first);
            p.second++;
        }
        return answer;
    }
};