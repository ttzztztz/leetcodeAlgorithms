class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int len1 = 0, len2 = 0;
        for (const string& word : word1) len1 += word.size();
        for (const string& word : word2) len2 += word.size();
        if (len1 != len2) return false;
        
        pair<int, int> ptr1 = {0, 0}, ptr2 = {0, 0};
        const pair<int, int> final_ptr = { word1.size(), 0 };
        
        auto advance = [&](const vector<string>& word, pair<int, int> ptr) -> pair<int, int> {
            ptr.second++;
            if (ptr.second == word[ptr.first].size()) {
                ptr.first++;
                ptr.second = 0;
            }
            return ptr;
        };
        
        for (; ptr1 != final_ptr; ptr1 = advance(word1, ptr1), ptr2 = advance(word2, ptr2)) {
            if (word1[ptr1.first][ptr1.second] != word2[ptr2.first][ptr2.second]) return false;
        }
        
        return true;
    }
};
