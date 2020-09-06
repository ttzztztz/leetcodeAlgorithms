class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int ptr1 = 0;
        for (int ptr2 = 0; ptr2 < typed.size(); ptr2++) {
            if (name[ptr1] == typed[ptr2]) {
                ptr1++;
            } else if (ptr2 >= 1 && typed[ptr2] == typed[ptr2 - 1]) {
                continue;
            } else {
                return false;
            }
        }
        
        return ptr1 == name.size();
    }
};
