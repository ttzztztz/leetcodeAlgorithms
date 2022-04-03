class Solution {
public:
    int convertTime(string current, string correct) {
        const int a = convert(current), b = convert(correct);
        int d = b - a, ans = 0;
        ans += d / 60; d = d % 60;
        ans += d / 15; d = d % 15;
        ans += d / 5; d = d % 5;
        ans += d;
        return ans;
    }
private:
    int convert(const string& s) {
        const int h = stoi(string{s[0], s[1]}), m = stoi(string{s[3], s[4]});
        return h * 60 + m;
    }
};
