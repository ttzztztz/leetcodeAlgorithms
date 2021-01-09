/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        const int kOverflow = 2147483647;
        
        int l = 0, r = 10005;
        while (l <= r) {
            const int mid = (l + r) / 2;
            
            const int res = reader.get(mid);
            if (mid == kOverflow) {
                r = mid - 1;
                continue;
            }
            
            if (res == target) return mid;
            if (res < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        if (reader.get(l) != target) return -1;
        else return l;
    }
};
