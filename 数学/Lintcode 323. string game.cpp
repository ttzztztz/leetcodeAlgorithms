class Solution {
public:
    /**
     * @param s: a string for this game 
     * @return: return whether Alice can win this game
     */
    bool stringGame(string &s) {
        // Write your code here
        unordered_map<char, int> a;
        for (int i = 0; i < s.size(); i++) a[s[i]]++;
        vector<int> app;
        for (auto& p : a) app.push_back(p.second);
        
        int answer = 0, single = 0;
        for (int i : app) answer ^= i, single += (i == 1);
        
        if (single == app.size()) return answer == 0;
        else return answer != 0;
    }
};
