/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long left = 1, right = n;
        while (left <= right) {
            const long long mid = (left + right) >> 1;
            
            const int result = guess(mid);
            if (result == -1) {
                right = mid - 1;
            } else if (result == 1) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        
        return -1; // never reach this branch
    }
};