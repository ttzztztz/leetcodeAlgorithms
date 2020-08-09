class Solution {
public:
    char findKthBit(int n, int k) {
        string all[25];
        all[1] = "0";
        for (int i = 2; i <= n; i++) {
            string tmp = invert(all[i - 1]);
            reverse(tmp.begin(), tmp.end());
            all[i] = all[i - 1] + "1" + tmp;
        }
        
        return all[n][k - 1];
    }
private:
    string invert(string x) {
        for (int i = 0; i < x.size(); i++) {
            if (x[i] == '1') x[i] = '0';
            else x[i] = '1';
        }
        return x;
    }
};
