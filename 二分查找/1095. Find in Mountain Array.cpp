/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        const int N = mountainArr.length();
        // find the top

        int left = 0, right = N - 1, middleIndex = 0;
        while (left <= right) {
            const int middle = (left + right) >> 1;

            const int middleVal = mountainArr.get(middle);
            const int leftVal = middle - 1 < 0 ? -999999 : mountainArr.get(middle - 1);
            const int rightVal = middle + 1 > N ? -999999 : mountainArr.get(middle + 1);

            if (middleVal > rightVal && middleVal > leftVal) {
                middleIndex = middle;
                break;
            } else if (leftVal < middleVal && middleVal < rightVal) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        // find at the left
        left = 0, right = middleIndex;
        while (left <= right) {
            const int middle = (left + right) >> 1;
            const int middleVal = mountainArr.get(middle);

            if (middleVal == target) {
                return middle;
            } else if (middleVal < target) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        // find at the right
        left = middleIndex, right = N - 1;
        while (left <= right) {
            const int middle = (left + right) >> 1;
            const int middleVal = mountainArr.get(middle);

            if (middleVal == target) {
                return middle;
            } else if (middleVal > target) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        // not find in all
        return -1;
    }
};