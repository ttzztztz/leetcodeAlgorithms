class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int countX_1 = 0, countY_1 = 0;
        int countX_2 = 0, countY_2 = 0;

        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == 'x') {
                countX_1++;
            } else {
                countY_1++;
            }
        }

        for (int i = 0; i < s2.size(); i++) {
            if (s2[i] == 'x') {
                countX_2++;
            } else {
                countY_2++;
            }
        }

        if ((countX_1 + countX_2) % 2 || (countY_1 + countY_2) % 2) {
            return -1;
        } else {
            int xy = 0, yx = 0;

            for (int i = 0; i < s1.size(); i++) {
                if (s1[i] == 'x' && s2[i] == 'y') {
                    xy++;
                } else if (s1[i] == 'y' && s2[i] == 'x') {
                    yx++;
                }
            }
            return xy / 2 + yx / 2 + ((xy % 2) + (yx % 2));
        }
    }
};