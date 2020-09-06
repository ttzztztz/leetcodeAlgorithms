class Solution {
public:
    string crackSafe(int n, int k) {
        string answer(n, '0');
        visited.insert(answer);
        
        this->n = n, this->k = k;
        this->finalState = pow(k, n);
        
        dfs(answer);
        return answer;
    }
private:
    unordered_set<string> visited;
    int n, k, finalState;
    bool dfs(string& state) {
        if (visited.size() == finalState) return true;
        
        string prefix = state.substr(state.size() + 1 - n, n - 1);
        for (int c = '0'; c < '0' + k; c++) {
            prefix.push_back(c);
            if (!visited.count(prefix)) {
                state.push_back(c);
                visited.insert(prefix);
                if (dfs(state)) return true;
                visited.erase(prefix);
                state.pop_back();
            }
            prefix.pop_back();
        }
        
        return false;
    }
};
