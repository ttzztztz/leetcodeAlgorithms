class Solution {
public:
    int hIndex(vector<int>& citations) {
        const int N = citations.size();
        if (N == 0) {
            return 0;
        }

        int left = 0, right = N - 1;
        while (left <= right) {
            const int middle = (left + right) >> 1;

            if (N - (middle + 1) > citations[middle]) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        return min(citations[right + 1], N - (right + 1));
    }
};