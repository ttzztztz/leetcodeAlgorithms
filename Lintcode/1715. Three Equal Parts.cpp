class Solution {
public:
    /**
     * @param A: an array
     * @return: divide the array into 3 non-empty parts
     */
    vector<int> threeEqualParts(vector<int> &A) {
        vector<int> invalid_ans = {-1, -1};
        const int n = A.size();
        vector<int> count1;
        for (int i = 0; i < n; i++) {
            if (A[i] == 1) count1.push_back(i);
        }
        const int m = count1.size();
        if (m % 3 != 0) return invalid_ans;
        if (m == 0) return vector<int>{ 0, 2 };
        
        int ptr1 = count1[(m / 3) - 1], ptr2 = count1[(2 * m / 3) - 1], ptr3 = count1[m - 1];
        const int trail_zero = n - 1 - ptr3;
        
        if (ptr1 + trail_zero >= count1[m / 3] || ptr2 + trail_zero >= count1[2 * m / 3]) return invalid_ans;
        
        ptr1 += trail_zero, ptr2 += trail_zero, ptr3 = n - 1;
        int ptr = 0;
        while (ptr1 - ptr >= 0 && ptr2 - ptr > ptr1 && ptr3 - ptr > ptr2) {
            if (A[ptr1 - ptr] == A[ptr2 - ptr] && A[ptr2 - ptr] == A[ptr3 - ptr]) {
                ptr++;
            } else {
                return invalid_ans;
            }
        }
        
        return vector<int>{ ptr1, ptr2 + 1 };
    } 
};
