class TrieNode {
public:
    bool flag;
    int weight;
    unordered_map<char, TrieNode*> next;
    
    TrieNode() : flag(false), weight(0) {};
};

class WordFilter {
public:
    TrieNode* root;
    WordFilter(vector<string>& words) {
        root = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            const string& word = words[i];
            
            TrieNode* curr = root;
            for (const char& ch : word) {
                if (!curr->next.count(ch)) {
                    curr->next[ch] = new TrieNode();
                }
                curr = curr->next[ch];
            }
            
            curr->flag = true;
            curr->weight = max(i, curr->weight);
        }
    }
    
    int f(string prefix, string suffix) {
        TrieNode* curr = root;
        string state;
        
        for (const char& ch : prefix) {
            if (!curr->next.count(ch)) {
                return -1;
            } else {
                curr = curr->next[ch];
                state.push_back(ch);
            }
        }
        
        int answer = -1;
        dfs(suffix, curr, state, answer);
        return answer;
    }
    bool stateValid(const string& suffix, const string& state) {
        const int N = suffix.size(), M = state.size();
        
        if (M < N) {
            return false;
        }
        for (int i = 0; i < N; i++) {
            if (suffix[N - i - 1] != state[M - i - 1]) {
                return false;
            }
        }
        return true;
    }
    void dfs(const string& suffix, TrieNode* curr, string state, int& answer) {
        if (curr->flag && stateValid(suffix, state)) {
            answer = max(answer, curr->weight);
        }
        
        for (const pair<const char, TrieNode*>& p : curr->next) {
            string nextState = state;
            nextState.push_back(p.first);
            
            dfs(suffix, p.second, nextState, answer);
        }
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */