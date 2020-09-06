class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        
        const int minNumber = *min_element(nums.begin(), nums.end());
        const int maxNumber = *max_element(nums.begin(), nums.end());
        
        if (maxNumber == minNumber) return 0;
        const int bucketCount = nums.size() + 1;
        const int bucketSize = ceil(1.0 * (maxNumber - minNumber) / nums.size());
        
        vector<vector<int>> buckets(bucketCount, vector<int>{});
        for (int i : nums) {
            const int index = (i - minNumber) / bucketSize;
            buckets[index].push_back(i);
        }
        
        int answer = 0;
        int previousMax = *max_element(buckets[0].begin(), buckets[0].end());
        
        for (int i = 1; i < bucketCount; i++) {
            if (buckets[i].empty()) continue;
            
            const int minBucket = *min_element(buckets[i].begin(), buckets[i].end());
            const int maxBucket = *max_element(buckets[i].begin(), buckets[i].end());
            
            answer = max(answer, minBucket - previousMax);
            previousMax = maxBucket;
        }
        
        return answer;
    }
};
