/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        const int n = reader.length();
        
        int l = 0, r = n - 1;
        while (l < r) {
            const int mid = (l + r) / 2;
            const int len = r - l + 1;
            
            int res = 0;
            if (len % 2 == 1) { // odd
                res = reader.compareSub(l, mid - 1, mid + 1, r);
                
                if (res == 0) return mid;
                else if (res == 1) r = mid - 1;
                else l = mid + 1; // res == -1
            } else { // even
                res = reader.compareSub(l, mid, mid + 1, r);
                
                if (res == 1) r = mid;
                else l = mid + 1; // res == -1
            }
        }
        
        return l;
    }
};
