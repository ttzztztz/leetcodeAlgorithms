class Solution {
public:
    int compress(vector<char>& chars) {
        int r = 0, w = 0, last = 0;
        const int n = chars.size();
        for (; r < chars.size(); r++) {
            if (r + 1 == n || chars[r + 1] != chars[r]) {
                chars[w++] = chars[last];
                if (r - last + 1 > 1) {
                    string t = to_string(r - last + 1);
                    for (const char ch : t) chars[w++] = ch;
                }
                last = r + 1;
            }
        }
        
        chars.resize(w);
        return chars.size();
    }
};
