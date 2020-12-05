class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int k) {
        const int n = flowerbed.size();
        for (int i = 0; i < n; i++) {
            if (flowerbed[i] == 1) continue;
            if ((i == 0 || (i - 1 >= 0 && flowerbed[i - 1] == 0)) && (i + 1 >= n || (i + 1 < n && flowerbed[i + 1] == 0))) {
                k--;
                flowerbed[i] = 1;
            }
        }
        return k <= 0;
    }
};
