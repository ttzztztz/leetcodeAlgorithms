class Solution {
public:
    string largestMerge(string word1, string word2) {
        int i = 0, j = 0;
        string ans;
        n = word1.size(), m = word2.size();

        while (i < n && j < m) {
            // x + y > y + x
            if (ok(word1, word2, i, j)) {
                ans += word1[i];
                i++;
            } else {
                ans += word2[j];
                j++;
            }
        }
        
        while (i < n) {
            ans += word1[i];
            i++;
        }
        
        while (j < m) {
            ans += word2[j];
            j++;
        }
        return ans;
    }
private:
    int n, m;
    bool ok(string& w1, string& w2, int i, int j) {
        int s = 0;
        auto get_char = [&]() -> char {
            if (s == 0) {
                if (j < w2.size()) {
                    char ans = w2[j];
                    j++;
                    return ans;
                } else {
                    j = i;
                    s = 1;

                    char ans = w1[j];
                    j++;
                    return ans;
                }
            } else { // s == 1
                char ans = w1[j];
                j++;
                return ans;
            }
        };
        
        for (int x = i; x < n; x++) {
            char y = get_char();
            if (w1[x] > y) {
                return true;
            } else if (w1[x] == y) {
                continue;
            } else {
                return false;
            }
        }
        for (int x = j; x < m; x++) {
            char y = get_char();
            if (w2[x] > y) {
                return true;
            } else if (w2[x] == y) {
                continue;
            } else {
                return false;
            }
        }
        return false;
    }
};
