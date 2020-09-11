class TrieNode {
public:
    bool flag;
    unordered_map<char, TrieNode*> next;
    TrieNode() : flag(false) {};
};

class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> wordSearchII(vector<vector<char>> &board, vector<string> &words) {
        this->b = board;
        root = new TrieNode();
        for (const string& str : words) insert(str);
        this->n = board.size(), this->m = board[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visited = vector<vector<bool>>(n, vector<bool>(m, false));
                visited[i][j] = true;
                
                cur = string{b[i][j]};
                if (root->next.count(b[i][j])) dfs(i, j, root->next[b[i][j]]);
            }
        }
        
        return vector<string>(answer.begin(), answer.end());
    }
private:
    unordered_set<string> answer;
    string cur;
    int n, m;
    vector<vector<char>> b;
    vector<vector<bool>> visited;
    
    bool pointValid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    
    void dfs(int i, int j, TrieNode* u) {
        if (u->flag) answer.insert(cur);
        
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        
        for (int k = 0; k < 4; k++) {
            const int nx = i + dx[k], ny = j + dy[k];
            if (!pointValid(nx, ny) || visited[nx][ny] || !u->next.count(b[nx][ny])) continue;
            
            visited[nx][ny] = true;
            cur.push_back(b[nx][ny]);
            dfs(nx, ny, u->next[b[nx][ny]]);
            visited[nx][ny] = false;
            cur.pop_back();
        }
    }
    
    TrieNode* root = nullptr;
    void insert(const string& str) {
        TrieNode* u = root;
        for (const char ch : str) {
            if (!u->next.count(ch)) u->next[ch] = new TrieNode();
            u = u->next[ch];
        }
        u->flag = true;
    }
};
