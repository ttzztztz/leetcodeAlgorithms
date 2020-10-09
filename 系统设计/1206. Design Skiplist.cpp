class SkiplistNode {
public:
    int val;
    SkiplistNode *down, *next;
    
    SkiplistNode() : val(0), down(nullptr), next(nullptr) {};
    SkiplistNode(int v, SkiplistNode* d, SkiplistNode* n) : val(v), down(d), next(n) {};
};

class Skiplist {
public:
    Skiplist() {
        root = new SkiplistNode(-1, nullptr, nullptr);
    }
    
    bool search(int target) {
        for (SkiplistNode* ptr = root; ptr != nullptr; ptr = ptr->down) {
            while (ptr->next && ptr->next->val < target) ptr = ptr->next;
            if (ptr->next && ptr->next->val == target) return true;
        }
        
        return false;
    }
    
    void add(int num) {
        vector<SkiplistNode*> stk;
        
        for (SkiplistNode* ptr = root; ptr != nullptr; ptr = ptr->down) {
            while (ptr->next && ptr->next->val < num) ptr = ptr->next;
            stk.push_back(ptr);
        }
        
        bool insert = true;
        SkiplistNode* down = nullptr;
        while (insert && !stk.empty()) {
            SkiplistNode* t = stk.back();
            stk.pop_back();
            
            t->next = new SkiplistNode(num, down, t->next);
            down = t->next;
            
            insert = rand() % 2;
        }
        
        if (insert) {
            root = new SkiplistNode(-1, root, nullptr);
        }
    }
    
    bool erase(int num) {
        bool find = false;
        
        for (SkiplistNode* ptr = root; ptr != nullptr; ptr = ptr->down) {
            while (ptr->next && ptr->next->val < num) ptr = ptr->next;
            if (ptr->next && ptr->next->val == num) {
                find = true;
                SkiplistNode* will_delete = ptr->next;
                ptr->next = ptr->next->next;
                if (will_delete) delete will_delete;
            }
        }
        return find;
    }
private:
    SkiplistNode* root;
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
