/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    Node* expTree(string s) {
        vector<char> expr_str = convert(s);
        idx = expr_str.size() - 1;
        return build(expr_str);
    }
private:
    int idx;
    Node* build(const vector<char>& expr) {
        if (idx < 0) return nullptr;
        
        const char ch = expr[idx];
        Node* root = new Node(ch);
        idx--;
        if (ch >= '0' && ch <= '9') return root;
        root->right = build(expr);
        root->left = build(expr);
        return root;
    }
    vector<char> convert(const string& str) {
        vector<char> ans, stk;
        unordered_map<char, int> prior = {
            {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}
        };
        
        for (const char ch : str) {
            if (prior.count(ch)) {
                const int p1 = prior[ch];
                while (!stk.empty()) {
                    const char t = stk.back();
                    
                    if (prior.count(t)) {
                        const int p2 = prior[t];
                        if (p2 >= p1) {
                            ans.push_back(stk.back());
                            stk.pop_back();
                        } else break;
                    } else if (t == '(') {
                        break;
                    }
                }
                stk.push_back(ch);
            } else if (ch == '(') {
                stk.push_back('(');
            } else if (ch == ')') {
                while (!stk.empty()) {
                    const char t = stk.back();
                    stk.pop_back();
                    if (t == '(') {
                        break;
                    } else {
                        ans.push_back(t);
                    }
                }
            } else {
                ans.push_back(ch);
            }
        }
        
        while (!stk.empty()) {
            ans.push_back(stk.back());
            stk.pop_back();
        }
        return ans;
    }
};/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    Node* expTree(string s) {
        vector<char> expr_str = convert(s);
        idx = expr_str.size() - 1;
        return build(expr_str);
    }
private:
    int idx;
    Node* build(const vector<char>& expr) {
        if (idx < 0) return nullptr;
        
        const char ch = expr[idx];
        Node* root = new Node(ch);
        idx--;
        if (ch >= '0' && ch <= '9') return root;
        root->right = build(expr);
        root->left = build(expr);
        return root;
    }
    vector<char> convert(const string& str) {
        vector<char> ans, stk;
        unordered_map<char, int> prior = {
            {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}
        };
        
        for (const char ch : str) {
            if (prior.count(ch)) {
                const int p1 = prior[ch];
                while (!stk.empty()) {
                    const char t = stk.back();
                    
                    if (prior.count(t)) {
                        const int p2 = prior[t];
                        if (p2 >= p1) {
                            ans.push_back(stk.back());
                            stk.pop_back();
                        } else break;
                    } else if (t == '(') {
                        break;
                    }
                }
                stk.push_back(ch);
            } else if (ch == '(') {
                stk.push_back('(');
            } else if (ch == ')') {
                while (!stk.empty()) {
                    const char t = stk.back();
                    stk.pop_back();
                    if (t == '(') {
                        break;
                    } else {
                        ans.push_back(t);
                    }
                }
            } else {
                ans.push_back(ch);
            }
        }
        
        while (!stk.empty()) {
            ans.push_back(stk.back());
            stk.pop_back();
        }
        return ans;
    }
};/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    Node* expTree(string s) {
        vector<char> expr_str = convert(s);
        idx = expr_str.size() - 1;
        return build(expr_str);
    }
private:
    int idx;
    Node* build(const vector<char>& expr) {
        if (idx < 0) return nullptr;
        
        const char ch = expr[idx];
        Node* root = new Node(ch);
        idx--;
        if (ch >= '0' && ch <= '9') return root;
        root->right = build(expr);
        root->left = build(expr);
        return root;
    }
    vector<char> convert(const string& str) {
        vector<char> ans, stk;
        unordered_map<char, int> prior = {
            {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}
        };
        
        for (const char ch : str) {
            if (prior.count(ch)) {
                const int p1 = prior[ch];
                while (!stk.empty()) {
                    const char t = stk.back();
                    
                    if (prior.count(t)) {
                        const int p2 = prior[t];
                        if (p2 >= p1) {
                            ans.push_back(stk.back());
                            stk.pop_back();
                        } else break;
                    } else if (t == '(') {
                        break;
                    }
                }
                stk.push_back(ch);
            } else if (ch == '(') {
                stk.push_back('(');
            } else if (ch == ')') {
                while (!stk.empty()) {
                    const char t = stk.back();
                    stk.pop_back();
                    if (t == '(') {
                        break;
                    } else {
                        ans.push_back(t);
                    }
                }
            } else {
                ans.push_back(ch);
            }
        }
        
        while (!stk.empty()) {
            ans.push_back(stk.back());
            stk.pop_back();
        }
        return ans;
    }
};
