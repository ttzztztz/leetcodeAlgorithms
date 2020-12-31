class Node {
public:
    string val;
    Node* left;
    Node* right;
        
    Node() : left(nullptr), right(nullptr) {};
    Node(string v) : val(v), left(nullptr), right(nullptr) {};
};

class Solution {
public:
    /**
     * @param str: the prefix notation.
     * @return: return the postfix notation.
     */
    string prefixNotationToPostfixNotation(string &str) {
        // write your code here.
        stringstream ss(str);
        string tmp;
        
        while (ss >> tmp) {
            all.push_back(tmp);
        }
        
        const int N = all.size();
        Node* root = build(all);
        dfs(root);
        answer.pop_back();
        return answer;
    }
private:
    string answer;
    vector<string> all;
    int ptr = 0;
    Node* build(const vector<string>& str) {
        if (ptr >= all.size()) return nullptr;
        Node* u = new Node(all[ptr++]);
        if (opt.count(u->val)) {
            u->left = build(str);
            u->right = build(str);
        }
        return u;
    }
    void dfs(Node* u) {
        if (u == nullptr) return;
        
        dfs(u->left);
        dfs(u->right);
        answer += u->val + " ";
    }

    const unordered_set<string> opt = {
        "+", "-", "*", "/"
    };
};
