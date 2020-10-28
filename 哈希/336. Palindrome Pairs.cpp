class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string, vector<int>> h;
        
        const int n = words.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) h[words[i]].push_back(i);
        
        for (int i = 0; i < n; i++) {
            // case 1
            string str = words[i];
            reverse(str.begin(), str.end());
            if (h.count(str)) {
                for (int v : h[str]) {
                    if (v != i && !visited[i][v]) ans.push_back(vector<int>{ i, v }), visited[i][v] = true;
                }
            }
            
            // case 2
            for (int j = 0; j < words[i].size(); j++) {
                if (isPalindrome(words[i], j, words[i].size() - 1)) {
                    str.clear();
                    for (int k = 0; k < j; k++) str += words[i][k];
                    reverse(str.begin(), str.end());
                    
                    if (h.count(str)) {
                        for (int v : h[str]) {
                            if (v != i && !visited[i][v]) ans.push_back(vector<int>{ i, v }), visited[i][v] = true;
                        }
                    }
                }
            }
            
            // case 3
            for (int j = 0; j < words[i].size(); j++) {
                if (isPalindrome(words[i], 0, j)) {
                    str.clear();
                    for (int k = j + 1; k < words[i].size(); k++) str += words[i][k];
                    reverse(str.begin(), str.end());
                    
                    if (h.count(str)) {
                        for (int v : h[str]) {
                            if (v != i && !visited[v][i]) ans.push_back(vector<int>{ v, i }), visited[v][i] = true;
                        }
                    }
                }
            }
        }
        
        return ans;
    }
private:
    bool isPalindrome(const string& str, int i, int j) {
        for (int a = i, b = j; a < b; a++, b--) {
            if (str[a] != str[b]) return false;
        }
        return true;
    }
};
