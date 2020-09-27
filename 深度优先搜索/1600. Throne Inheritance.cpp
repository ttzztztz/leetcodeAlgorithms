class ThroneInheritance {
public:
    ThroneInheritance(string kingName) {
        this->king = kingName;
    }
    
    void birth(string parentName, string childName) {
        edges[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(ans, king);
        return ans;
    }
private:
    unordered_set<string> dead;
    unordered_map<string, vector<string>> edges;
    string king;
    
    void dfs(vector<string>& ans, string cur) {
        if (!dead.count(cur)) ans.push_back(cur);
        for (const string& str : edges[cur]) {
            dfs(ans, str);
        }
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
