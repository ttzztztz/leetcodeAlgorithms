class TrieNode {
public:
    bool remove = false;
    map<string, TrieNode*> nxt;
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        for (auto& path : paths) insert(path);
        
        remove_duplicate(root);
        get_answer(root);
        return ans;
    }
private:
    TrieNode* root = new TrieNode();
    vector<vector<string>> ans;
    unordered_map<string, TrieNode*> dup;
    vector<string> cur;
    
    vector<vector<string>> remove_duplicate(TrieNode* u) {
        if (u == nullptr) return {};
        
        vector<vector<string>> t;
        for (auto& [k, v] : u->nxt) {
            cur.push_back(k);
            auto res = remove_duplicate(v);
            for (auto& path : res) {
                path.insert(path.begin(), k);
                t.push_back(path);
            }
            cur.pop_back();
        }
        
        if (u->nxt.empty()) {
            t = { {} };
        } else {
            string hash = h(t);
            if (dup.count(hash)) {
                u->remove = true;
                dup[hash]->remove = true;
            } else {
                dup[hash] = u;
            }
        }
        
        return t;
    }
    
    string h(const vector<vector<string>>& t) {
        string ans;
        for (auto& u : t) {
            for (auto& v : u) {
                ans += v + ",";
            }
            ans += "|";
        }
        
        return ans;
    }
    
    void get_answer(TrieNode* u) {
        if (u == nullptr || u->remove) return;
        
        if (!cur.empty()) ans.push_back(cur);
        for (auto& [k, v] : u->nxt) {
            cur.push_back(k);
            get_answer(v);
            cur.pop_back();
        }
    }
    
    void insert(vector<string>& path) {
        TrieNode* cur = root;
        for (string& name : path) {
            if (!cur->nxt.count(name)) cur->nxt[name] = new TrieNode();
            cur = cur->nxt[name];
        }
    }
};