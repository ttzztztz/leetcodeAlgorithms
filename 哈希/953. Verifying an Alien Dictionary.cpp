class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if (words.size() <= 1) return true;

        unordered_map<char, int> ord;
        for (int i = 0; i < order.size(); i++) ord[order[i]] = i;
        
        for (int i = 1; i < words.size(); i++) {
            if (!judge(ord, words[i - 1], words[i])) return false;
        }
        return true;
    }
private:
    bool judge(unordered_map<char, int>& ord, const string& w1, const string& w2) {
        const int len1 = w1.size(), len2 = w2.size();
        int ptr = 0;
        while (ptr < len1 && ptr < len2 && w1[ptr] == w2[ptr]) ptr++;

        if (ptr < len1 && ptr < len2) return ord[w1[ptr]] < ord[w2[ptr]];
        return w1.size() <= w2.size();
    }
};