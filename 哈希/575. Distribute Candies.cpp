class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        const size_t N = candies.size();
        unordered_set<int> kind;
        for (int candy : candies) kind.insert(candy);
        
        return min(N / 2, kind.size());
    }
};
