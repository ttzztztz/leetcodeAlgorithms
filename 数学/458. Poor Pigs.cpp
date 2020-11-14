class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        const int m = minutesToTest / minutesToDie + 1;
        return ceil(log(buckets) / log(m));
    }
};
