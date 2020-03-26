class Solution {
public:
    /**
     * @param startString: 
     * @param endString: 
     * @return: Return true or false
     */
    bool canTransfer(string &startString, string &endString) {
        if (startString.size() != endString.size()) return false;
        if (startString == endString) return true;
        
        const int N = startString.size();
        for (int i = 0; i < N; i++) {
            if (!mapChar.count(startString[i])) {
                mapChar[startString[i]] = endString[i];
            } else if (mapChar.count(startString[i]) && mapChar[startString[i]] != endString[i]) {
                return false;
            }
        }
        
        if (haveCycle()) return false;
        return true;
    }
private:
    unordered_map<char, char> mapChar;
    unordered_map<char, int> visited;
    bool haveCycle() {
        for (auto& p : mapChar) {
            if (dfs(p.first)) return true;
        }
        return false;
    }
    bool dfs(char u) {
        if (visited[u] == 1) return false;
        
        visited[u] = -1;
        if (mapChar.count(u) && mapChar[u] != u) {
            const char v = mapChar[u];
        
            if (visited[v] == -1) return true;
            if (visited[v] == 0 && dfs(v)) return true;
        }
        visited[u] = 1;
        return false;
    }
};
