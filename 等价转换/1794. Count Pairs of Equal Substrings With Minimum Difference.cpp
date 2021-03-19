class Solution {
public:
    int countQuadruples(string firstString, string secondString) {
        int ans = 0;
        
        const int n = firstString.size(), m = secondString.size();
        unordered_map<char, int> appear;
        for (int i = 0; i < m; i++) appear[secondString[i]] = i;
        int t = numeric_limits<int>::max();
        for (int i = 0; i < n; i++) {
            if (appear.count(firstString[i])) {
                const int dist = i - appear[firstString[i]];
                if (dist < t) {
                    ans = 1;
                    t = dist;
                } else if (dist == t) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
