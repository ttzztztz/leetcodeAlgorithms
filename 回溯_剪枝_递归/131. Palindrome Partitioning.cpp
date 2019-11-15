class Solution {
public:
    int N;
    vector<vector<int>> isPalindrome;
    vector<vector<string>> answer;

    int dp(const string& s, int i, int j) {
        if (i >= j) {
            return isPalindrome[i][j] = 1;
        }

        if (isPalindrome[i][j] != -1) {
            return isPalindrome[i][j] == 1;
        }

        if (s[i] != s[j]) {
            return isPalindrome[i][j] = false;
        } else {
            return isPalindrome[i][j] = dp(s, i + 1, j - 1);
        }
    }

    void dfs(const string& s, vector<string>& temp, int index) {
        if (index == N) {
            answer.push_back(temp);
            return;
        }

        for (int i = index; i < N; i++) {
            if (dp(s, index, i)) {
                temp.push_back(s.substr(index, i - index + 1));
                dfs(s, temp, i + 1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        N = s.size();
        isPalindrome = vector<vector<int>>(N + 5, vector<int>(N + 5, -1));
        // do dfs
        vector<string> temp;
        dfs(s, temp, 0);

        return answer;
    }
};