class Solution {
public:
    /**
     * @param flowers: the place where the flower will open in that day
     * @param k:  an integer
     * @return: in which day meet the requirements
     */
    int kEmptySlots(vector<int> &flowers_raw, int k) {
        const int N = flowers_raw.size();
        vector<int> flowers(N);
        for (int i = 0; i < N; i++) {
            flowers[flowers_raw[i] - 1] = i + 1;
        }
        
        int answer = numeric_limits<int>::max();
        if (k == 0) {
            for (int i = 1; i < N; i++) {
                answer = min(answer, max(flowers[i], flowers[i - 1]));
            }
            return answer;
        }
        
        set<int> flowerSet;
        int leftPtr = 0, rightPtr = k + 1;
        for (int i = 1; i <= k; i++) flowerSet.insert(flowers[i]);
        
        while (rightPtr < N) {
            if (leftPtr != 0) {
                flowerSet.erase(flowers[leftPtr]);
                flowerSet.insert(flowers[rightPtr - 1]);
            }
            
            auto it = flowerSet.begin();
            if (*it > max(flowers[leftPtr], flowers[rightPtr])) {
                answer = min(answer, max(flowers[leftPtr],  flowers[rightPtr]));
            }
            
            leftPtr++, rightPtr++;
        }
        
        if (answer == numeric_limits<int>::max()) return -1;
        else return answer;
    }
};
