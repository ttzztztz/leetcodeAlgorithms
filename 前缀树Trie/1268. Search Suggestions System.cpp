class TrieNode {
public:
    int flag;
    unordered_map<char, TrieNode*> next;
    TrieNode() : flag(0) {};
    TrieNode(bool flag) : flag(flag ? 1 : 0) {};
};

class Solution {
public:
    TrieNode* root;
    vector<string> oneAnswer;

    void insert(const string& word) {
        TrieNode* curr = root;
        for (const char ch : word) {
            if (!curr->next.count(ch)) {
                curr->next[ch] = new TrieNode();
            }
            curr = curr->next[ch];
        }
        curr->flag++;
    }

    void dfs(string& current, TrieNode* node) {
        if (node->flag) {
            for (int i = 0; i < node->flag; i++) {
                oneAnswer.push_back(current);
            }
        }

        for (const pair<char, TrieNode*>& dict : node->next) {
            current.push_back(dict.first);
            dfs(current, dict.second);
            current.pop_back();
        }
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root = new TrieNode(false);
        for (const string& product : products) {
            insert(product);
        }

        vector<vector<string>> answer;
        string _searchWord;
        for (const char& ch : searchWord) {
            oneAnswer.clear();
            _searchWord.push_back(ch);

            TrieNode* curr = root;
            bool isValid = true;
            for (const char& c : _searchWord) {
                if (!curr->next.count(c)) {
                    isValid = false;
                    break;
                } else {
                    curr = curr->next[c];
                }
            }

            if (!isValid) {
                answer.push_back(vector<string>());
                continue;
            }

            string current = _searchWord;
            dfs(current, curr);
            sort(oneAnswer.begin(), oneAnswer.end());
            if (oneAnswer.size() > 3) {
                oneAnswer.resize(3);
            }
            answer.push_back(oneAnswer);
        }

        return answer;
    }
};