class Solution {
public:
    /**
     * @param array: An given array.
     * @return: Return the number of "universal" subarrays.
     */
    int subarrays(vector<int> &array) {
        // write your code here.
        const int N = array.size();
        int answer = 0;
        for (int i = 0; i < N; i++) {
            int ptr1 = i;
            while (ptr1 + 1 < N && array[ptr1] == array[ptr1 + 1]) ptr1++;
            int ptr2 = ptr1 + 1;
            if (ptr2 >= N) break;
            while (ptr2 + 1 < N && array[ptr2] == array[ptr2 + 1]) ptr2++;
            const int len1 = ptr1 - i + 1;
            const int len2 = ptr2 - (ptr1 + 1) + 1;
            
            answer += min(len1, len2);
            i = ptr1;
        }
        return answer;
    }
};
