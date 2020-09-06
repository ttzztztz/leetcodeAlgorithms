class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> a;
        for (int i = 0; i < order.size(); i++) {
            a[order[i]] = i;
        }
        a[0] = -1;
        
        vector<string> k = words;
        sort(k.begin(), k.end(), [&](const string& $1, const string& $2) -> bool {
            int ptr = 0;
            while ($1[ptr] == $2[ptr]) {
                ptr++;
            }
            return a[$1[ptr]] < a[$2[ptr]];
        });
        return k == words;
    }
};
