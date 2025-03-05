class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        string t = s;
        sort(t.rbegin(), t.rend());

        int ptr1 = 0;
        while (ptr1 < s.size()) {
            if (s[ptr1] == t[ptr1]) {
                ptr1++;
            } else {
                break;
            }
        }

        if (ptr1 >= s.size()) return num;
        int ptr2 = 0, swap_pos = 0;
        while (ptr2 < s.size()) {
            if (s[ptr2] == t[ptr1]) {
                swap_pos = ptr2;
            }
            ptr2++;
        }

        swap(s[ptr1], s[swap_pos]);
        return stoi(s);
    }
};