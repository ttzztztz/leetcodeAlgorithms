class TrieNode {
public:
    unordered_map<char, TrieNode*> next;
    map<int, vector<int>> contents;
};

class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        for (int i = 0; i < sentences.size(); i++) {
            words.emplace_back(sentences[i], times[i]);
            appear[sentences[i]] = times[i];
        }
        sort(words.begin(), words.end());
        root = new TrieNode();
        node = root;
        for (int i = 0; i < words.size(); i++) {
            auto& [str, cnt] = words[i];
            insert(str, cnt, i);
        }
    }
    
    vector<string> input(char c) {
        vector<string> ans;
        if (c != '#') {
            if (!node->next.count(c)) {
                node->next[c] = new TrieNode();
            }
            node = node->next[c];
            if (!node->contents.empty()) {
                auto it = --node->contents.end();
                while (ans.size() < 3) {
                    const vector<int>& v = it->second;
                    for (int i = 0; i < v.size() && ans.size() < 3; i++) {
                        ans.push_back(words[v[i]].first);
                    }

                    if (it == node->contents.begin()) break;
                    else it--;
                }
            }
        }
        
        if (c == '#') {
            appear[history]++;
            int idx = -1;
            for (idx = 0; idx < words.size(); idx++) {
                if (words[idx].first == history) {
                    break;
                }
            }
            
            if (idx == words.size()) {
                words.emplace_back(history, appear[history]);
            } else {
                words[idx].second = appear[history];
            }
            
            update(history, appear[history], idx);
            history.clear();
            node = root;
        } else {
            history += c;
        }
        return ans;
    }
private:
    string history;
    TrieNode* root = nullptr;
    TrieNode* node = nullptr;
    vector<pair<string, int>> words;
    unordered_map<string, int> appear;
    
    void insert(const string& str, int times, int idx) {
        TrieNode* cur = root;
        for (int i = 0; i < str.size(); i++) {
            cur->contents[times].push_back(idx);
            if (!cur->next.count(str[i])) {
                cur->next[str[i]] = new TrieNode();
            }
            cur = cur->next[str[i]];
        }
        cur->contents[times].push_back(idx);
    }
    
    void update(const string& str, int times, int idx) {
        TrieNode* cur = root;
        for (int i = 0; i <= str.size(); i++) {
            if (times >= 2) {
                auto old_it = find(cur->contents[times - 1].begin(), cur->contents[times - 1].end(), idx);
                if (old_it != cur->contents[times - 1].end()) {
                    cur->contents[times - 1].erase(old_it);
                }

                if (cur->contents[times - 1].empty()) cur->contents.erase(times - 1);
            }
            cur->contents[times].push_back(idx);
            
            sort(cur->contents[times].begin(), cur->contents[times].end(), [&](const auto& lhs, const auto& rhs) -> bool {
                return words[lhs].first < words[rhs].first;
            });
            
            if (i != str.size()) {
                if (!cur->next.count(str[i])) {
                    cur->next[str[i]] = new TrieNode();
                }
                cur = cur->next[str[i]];
            }
        }
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
