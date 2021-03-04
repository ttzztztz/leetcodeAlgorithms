/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
    virtual ~Node () {};
    virtual int evaluate() const = 0;
protected:
    // define your fields here
};

class RabbitNode : public Node {
public:
    int val = 0;
    string opt;
    
    RabbitNode* left = nullptr, *right = nullptr;
    
    virtual int evaluate() const {
        int result = 0;
        if (opt.empty()) {
            result = this->val;
        } else if (opt == "+") {
            result = this->left->evaluate() + this->right->evaluate();
        } else if (opt == "-") {
            result = this->left->evaluate() - this->right->evaluate();
        } else if (opt == "*") {
            result = this->left->evaluate() * this->right->evaluate();
        } else { // opt == "/"
            result = this->left->evaluate() / this->right->evaluate();
        }
        return result;
    }
};

/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
        reverse(postfix.begin(), postfix.end());
        this->post = postfix;
        return build();
    }
private:
    vector<string> post;
    int cur = 0;
    
    RabbitNode* build() {
        unordered_set<string> calc = {"+", "-", "*", "/"};
        if (calc.count(post[cur])) {
            RabbitNode* root = new RabbitNode();
            root->opt = post[cur];
            cur++;
            root->right = build();
            root->left = build();
            return root;
        } else {
            RabbitNode* root = new RabbitNode();
            root->val = stoi(post[cur]);
            cur++;
            return root;
        }
    }
};


/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */
