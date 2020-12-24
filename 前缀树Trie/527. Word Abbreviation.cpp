class Trie {
public:
    unordered_map<char, Trie*> next;
    unordered_map<string, vector<int>> word;
};

class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        dict_ = dict;
        root_ = new Trie();
        for (int i = 0; i < dict.size(); i++) {
            insert(dict[i], i);
        }
        
        vector<string> ans;
        for (int i = 0; i < dict.size(); i++) {
            Trie* node = root_;
            const string& word = dict[i];
            
            bool ok = false;
            string cur;
            for (int j = 0; j < word.size(); j++) {
                node = node->next[word[j]];
                cur.push_back(word[j]);
                
                string key = to_string(word.size()) + "," + word.back(); 
                if (node->word[key].size() <= 1) {
                    const int t = word.size() - cur.size() - 1;
                    cur += to_string(t) + word.back();
                    if (cur.size() < word.size()) {
                        ans.push_back(cur);
                        ok = true;
                    }
                    break;
                }
            }
            if (!ok) ans.push_back(word);
        }
        return ans;
    }
private:
    vector<string> dict_;
    Trie* root_;
    void insert(const string& word, int idx) {
        string key = to_string(word.size()) + "," + word.back();

        Trie* node = root_;
        root_->word[key].push_back(idx);

        for (int i = 0; i < word.size(); i++) {
            if (!node->next.count(word[i])) {
                node->next[word[i]] = new Trie();
            }
            node = node->next[word[i]];
            node->word[key].push_back(idx);
        }
    }
};
