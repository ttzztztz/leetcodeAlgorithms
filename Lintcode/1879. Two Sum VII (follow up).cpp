class Solution {
public:
    /**
     * @param nums: the input array
     * @param target: the target number
     * @return: return the target pair
     */
    vector<vector<int>> twoSumVII(vector<int> &nums, int target) {
        const int N = nums.size();
        int smallPtr = min_element(nums.begin(), nums.end()) - nums.begin(), bigPtr = max_element(nums.begin(), nums.end()) - nums.begin();
        
        int dist = N;
        
        vector<vector<int>> answer;
        auto moveSmall = [&]() -> void {
            dist--;
            const int prev = nums[smallPtr];
            if (prev < 0) { // to left
                smallPtr--;
                while (smallPtr >= 0) {
                    if (nums[smallPtr] < 0 && nums[smallPtr] > prev) {
                        break;
                    }
                    smallPtr--;
                }
            } 
            
            if (prev >= 0 || smallPtr < 0) { // to right
                smallPtr++;
                while (smallPtr < N) {
                    if (nums[smallPtr] > 0 && nums[smallPtr] > prev) {
                        break;
                    }
                    smallPtr++;
                }
            }
        };
        
        auto moveBig = [&]() -> void {
            dist--;
            const int prev = nums[bigPtr];
            if (prev > 0) { // to left
                bigPtr--;
                while (bigPtr >= 0) {
                    if (nums[bigPtr] > 0 && nums[bigPtr] < prev) {
                        break;
                    }
                    bigPtr--;
                }
            } 
            
            if (prev <= 0 || bigPtr < 0) { // to right
                bigPtr++;
                while (bigPtr < N) {
                    if (nums[bigPtr] < 0 && nums[bigPtr] < prev) {
                        break;
                    }
                    bigPtr++;
                }
            }
        };
        
        while (dist >= 2) {
            if (nums[smallPtr] + nums[bigPtr] == target) {
                if (smallPtr < bigPtr) {
                    answer.push_back(vector<int>{smallPtr, bigPtr});
                } else {
                    answer.push_back(vector<int>{bigPtr, smallPtr});
                }
                moveSmall();
                moveBig();
            } else if (nums[smallPtr] + nums[bigPtr] > target) {
                moveBig();
            } else {
                moveSmall();
            }
        }
        
        return answer;
    }
};
