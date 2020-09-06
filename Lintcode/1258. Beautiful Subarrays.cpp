class Solution {
public:
    /**
     * @param nums: an integer list
     * @param numOdds: an integer
     * @return: return the number of beautiful subarrays
     */
    int BeautifulSubarrays(vector<int> &nums, int numOdds) {
        int answer = 0;
        for (int left1 = 0, left2 = 0, right = 0, oddCnt1 = 0, oddCnt2 = 0; right < nums.size(); right++) {
            if (nums[right] % 2 == 1) oddCnt1++, oddCnt2++;
            
            while (oddCnt1 > numOdds) {
                if (nums[left1] % 2 == 1) oddCnt1--;
                left1++;
            }
            
            while (oddCnt2 >= numOdds) {
                if (nums[left2] % 2 == 1) oddCnt2--;
                left2++;
            }
            
            answer += left2 - left1;
        }
        return answer;
    }
};
