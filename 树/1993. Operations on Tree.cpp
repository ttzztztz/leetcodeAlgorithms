class LockingTree {
public:
    LockingTree(vector<int>& parent) {
        this->parent = parent;
        n = parent.size();
        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if (state.count(num)) {
            return false;
        } else {
            state[num] = user;
            return true;
        }
    }
    
    bool unlock(int num, int user) {
        if (state.count(num) && state[num] == user) {
            state.erase(num);
            return true;
        } else {
            return false;
        }
    }
    
    bool upgrade(int num, int user) {
        if (
            no_locked_ancestor(num, user)
            && at_least_one_locked_descendant(num, user)
        ) {
            unlock_all_descendant(num, user);
            state[num] = user;
            return true;
        }
        return false;
    }
private:
    int n;
    unordered_map<int, vector<int>> children;
    unordered_map<int, int> state;
    vector<int> parent;
    
    bool no_locked_ancestor(int node, int user) {
        if (node == -1) {
            return true;
        }

        if (state.count(node)) {
            return false;
        }
        
        return no_locked_ancestor(parent[node], user);
    }
    
    bool at_least_one_locked_descendant(int node, int user) {
        if (state.count(node)) {
            return true;
        }
        
        for (int u : children[node]) {
            if (at_least_one_locked_descendant(u, user)) return true;
        }
        return false;
    }
    
    void unlock_all_descendant(int node, int user) {
        state.erase(node);
        
        for (int u : children[node]) {
            unlock_all_descendant(u, user);
        }
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */