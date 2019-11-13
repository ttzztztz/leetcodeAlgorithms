class TrieNode {
public:
    bool flag;
    unordered_map<char, TrieNode*> next;
    TrieNode() : flag(false) {};
    TrieNode(bool f) : flag(f) {};
};

class Solution {
public:
    TrieNode* root;
    set<string> answer;
    vector<vector<bool>> visited;
    int N, M;
    bool pointValid(int x, int y) {
        return x >= 0 && y >= 0 && x < N && y < M;
    }
    void dfs(vector<vector<char>>& board, int x, int y, string s, TrieNode* trie) {
        if (trie->flag) {
            answer.insert(s);
        }
        const int dx[] = {1, -1, 0, 0};
        const int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            const int nextX = x + dx[i], nextY = y + dy[i];

            if (pointValid(nextX, nextY) && !visited[nextX][nextY] && trie->next.count(board[nextX][nextY])) {
                visited[nextX][nextY] = true;
                string nextS = s;
                nextS.push_back(board[nextX][nextY]);
                dfs(board, nextX, nextY, nextS, trie->next[board[nextX][nextY]]);
                visited[nextX][nextY] = false;
            }
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // step 1 : init trie node & insert all words into the tree
        root = new TrieNode();
        for (const string& s : words) {
            TrieNode* curr = root;
            for (const char ch : s) {
                if (!curr->next.count(ch)) {
                    curr->next[ch] = new TrieNode();
                }
                curr = curr->next[ch];
            }
            curr->flag = true;
        }
        // step2 : dfs
        N = board.size(), M = board[0].size();
        visited = vector<vector<bool>>(N + 5, vector<bool>(M + 5, false));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (root->next.count(board[i][j])) {
                    visited[i][j] = true;

                    string initS;
                    initS.push_back(board[i][j]);

                    dfs(board, i, j, initS, root->next[board[i][j]]);
                    visited[i][j] = false;
                }
            }
        }

        // step3 : return the answer
        vector<string> strAnswer;
        for (const string& s : answer) {
            strAnswer.push_back(s);
        }
        return strAnswer;
    }
};