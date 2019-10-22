class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        int maxNumber = -1, mask = 1;
        for (int number : A) {
            maxNumber = std::max(number, maxNumber);
        }
        while (mask <= maxNumber) {
            mask <<= 1;
        }
        mask -= 1;

        unordered_set<int> set;
        for (int ptr1 = 0; ptr1 < A.size(); ptr1++) {
            int number = A[ptr1];
            set.insert(number);

            for (int ptr2 = ptr1 - 1; ptr2 >= 0 && number != mask; ptr2--) {
                number |= A[ptr2];
                set.insert(number);
            }
        }

        return set.size();
    }
};