class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> d;
        while (n) {
            d.push_back(n % 10);
            n /= 10;
        }
        reverse(d.begin(), d.end());

        int ptr1 = d.size() - 1;
        while (ptr1 - 1 >= 0 && d[ptr1 - 1] >= d[ptr1]) ptr1--;
        if (ptr1 == 0) return -1; // decreasing
        int ptr2 = d.size() - 1;
        while (ptr1 < ptr2 && d[ptr1 - 1] >= d[ptr2]) ptr2--;
        swap(d[ptr1 - 1], d[ptr2]);
        reverse(d.begin() + ptr1, d.end());

        long long ans = 0;
        for (int i : d) {
            ans = ans * 10 + i;
            if (ans > numeric_limits<int>::max()) return -1;
        }
        return ans;
    }
};