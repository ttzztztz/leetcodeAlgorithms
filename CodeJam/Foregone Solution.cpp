#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());

        string s1, s2;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '4') {
                s1 += '2';
                s2 += '2';
            } else {
                s1 += s[i];
                s2 += '0';
            }
        }

        for (int i = s1.size() - 1; i > 0; i--) {
            if (s1[i] == '0') {
                s1.pop_back();
            } else {
                break;
            }
        }

        for (int i = s2.size() - 1; i > 0; i--) {
            if (s2[i] == '0') {
                s2.pop_back();
            } else {
                break;
            }
        }

        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        printf("Case #%d: ", _);
        printf("%s %s", s1.c_str(), s2.c_str());
        printf("\n");
    }

    return 0;
}
