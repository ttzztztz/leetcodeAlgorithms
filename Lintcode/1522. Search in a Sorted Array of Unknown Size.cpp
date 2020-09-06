class Solution {
public:
    /**
     * @reader: reader.get(k) returns the element of the array at index k (0-indexed).
     * @return: return target index
     */
    int search(ArrayReader reader, int target) {
        const int INVALID = 2147483647;
        int len = 0;
        for (int i = 30; i >= 0; i--) {
            if (reader.get(len | (1 << i)) != INVALID) {
                len |= 1 << i;
            }
        }
        
        int left = 0, right = len;
        while (left <= right) {
            const int mid = (left + right) >> 1;
            const int _val = reader.get(mid);
            if (_val == target) return mid;
            else if (_val < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};
