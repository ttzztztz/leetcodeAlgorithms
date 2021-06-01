class TrieNode {
public:
    vector<int> words;
    unordered_map<char, TrieNode*> next;
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        for (int i = 0; i < products.size(); i++) {
            insert(products[i], i);
        }
        
        vector<vector<string>> ans(searchWord.size());
        TrieNode* cur = root;
        for (int i = 0; i < searchWord.size(); i++) {
            vector<string> res;
            
            cur = cur->next[searchWord[i]];
            if (cur == nullptr) break;
            
            for (int i = 0; i < min<int>(cur->words.size(), 3); i++) {
                res.push_back(products[cur->words[i]]);
            }
            ans[i] = res;
        }
        return ans;
    }
private:
    TrieNode* root = new TrieNode();
    
    void insert(const string& str, int idx) {
        TrieNode* cur = root;
        for (int i = 0; i < str.size(); i++) {
            if (!cur->next.count(str[i])) {
                cur->next[str[i]] = new TrieNode();
            }
            cur = cur->next[str[i]];
            cur->words.push_back(idx);
        }
    }
};