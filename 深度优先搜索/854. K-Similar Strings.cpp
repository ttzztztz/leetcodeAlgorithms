class Solution {
public:
    int kSimilarity(string &A, string &B) {
        N = B.size();
        dfs(B, A, 0, 0);
        return answer;
    }
private:
    int answer = 9999999;
    int N;
    unordered_map<string, int> visited;
    void dfs(const string& B, string& A, int i, int step) {
        if (step > answer) return;
        if (visited.count(A) && visited[A] < step) return;
        if (i == N) {
            answer = min(answer, step);
            return;
        }
        
        visited[A] = step;
        if (B[i] == A[i]) {
            dfs(B, A, i + 1, step);
            return;
        }
        
        for (int j = i + 1; j < N; j++) {
            if (A[j] == B[i]) {
                swap(A[i], A[j]);
                dfs(B, A, i + 1, step + 1);
                swap(A[i], A[j]);
            }
        }
    }
};
