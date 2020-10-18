class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> vis;
        
        string ans = s;
        deque<string> q = {s};
        while (!q.empty()) {
            string str = q.front();
            ans = min(ans, str);
            q.pop_front();
            
            vis.insert(str);
            // operation 1
            string nxt = str;
            for (int i = 1; i < str.size(); i += 2) {
                int d = nxt[i] - '0';
                d += a;
                if (d >= 10) d -= 10;
                nxt[i] = d + '0';
            }
            if (!vis.count(nxt)) vis.insert(nxt), q.push_back(nxt);
            
            // operation 2
            nxt.clear();
            for (int j = b; j < str.size(); j++) {
                nxt.push_back(str[j]);
            }
            for (int j = 0; j < b; j++) {
                nxt.push_back(str[j]);
            }
            if (!vis.count(nxt)) vis.insert(nxt), q.push_back(nxt);
        }
        return ans;
    }
};
