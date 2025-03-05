class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        const int len1 = word.size(), len2 = abbr.size();
        int ptr1 = 0;
        for (int ptr2 = 0; ptr2 < len2; ptr2++) {
            if ('a' <= abbr[ptr2] && abbr[ptr2] <= 'z') {
                if (word[ptr1] != abbr[ptr2]) return false;
                ptr1++;
                continue;
            }

            int buf = abbr[ptr2] - '0';
            if (buf == 0) return false;
            while (ptr2 + 1 < len2 && '0' <= abbr[ptr2 + 1] && abbr[ptr2 + 1] <= '9') {
                buf = buf * 10 + abbr[ptr2 + 1] - '0';
                ptr2++;
            }
            if (ptr1 + buf > len1) return false;
            ptr1 += buf;
        }
        return ptr1 == len1;
    }
};