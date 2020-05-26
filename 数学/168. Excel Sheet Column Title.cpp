class Solution {
public:
    string convertToTitle(int n) {
        dfs(n);
        reverse(answer.begin(), answer.end());
        return answer;
    }
private:
    void dfs(int n) {
        if (n == 0) return;
        if (n == 1) {
            answer += 'A';
            return;
        }
        n--;
        
        answer += 'A' + (n % 26);
        dfs(n / 26);
    }
    string answer;
};
