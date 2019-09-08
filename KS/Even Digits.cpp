#include <iostream>
#include <cstring>
#include <cmath>
#include <sstream>

using namespace std;

long long findLowerNumber(string s) {
    stringstream ss;
    ss << s;
    long long beginNumber = 0L;
    ss >> beginNumber;
    ss.clear();

    bool flag = false;
    for (unsigned int i = 0; i < s.size(); i++) {
        if (flag) {
            s[i] = '0' + 8;
        } else {
            int digest = s[i] - '0';
            if (digest & 1) {
                s[i]--;
                flag = true;
            }
        }
    }

    long long endNumber = 0L;
    ss << s;
    ss >> endNumber;
    return abs(beginNumber - endNumber);
}

long long findUpperNumber(string s) {
    stringstream ss;
    ss << s;
    long long beginNumber = 0L;
    ss >> beginNumber;
    ss.clear();

    bool flag = false;
    int addFactor = -1;
    for (unsigned int i = 0; i < s.size(); i++) {
        if (flag) {
            s[i] = '0' + 0;
        } else {
            int digest = s[i] - '0';
            if (digest & 1) {
                s[i]++;
                if (s[i] >= '0' + 10) {
                    s[i] = '0';
                    addFactor = i;
                }
                flag = true;
            }
        }
    }

    if (addFactor > 0) {
        bool needAdd1 = false;
        for (unsigned int i = addFactor - 1; i >= 0; i++) {
            int digest = s[i] - '0';

            if (digest == 9) {
                if (i == 0) {
                    needAdd1 = true;
                }

                s[i] = '0';
            } else {
                s[i]++;
                if ((s[i] - '0') & 1) {
                    s[i]++;
                }
                if (s[i] >= '0' + 10) {
                    s[i] = '0';
                    continue;
                }

                break;
            }
        }

        if (needAdd1) {
            s = "2" + s;
        }
    } else if (addFactor == 0) {
        s = "2" + s;
    }

    long long endNumber = 0L;
    ss << s;
    ss >> endNumber;
    return abs(beginNumber - endNumber);
}

int main() {
    int _ = 0;
    cin >> _;
    for (int i = 1; i <= _; i++) {
        string number;
        cin >> number;

        long long answer = std::min(findLowerNumber(number), findUpperNumber(number));
        printf("Case #%d: %lld \n", i, answer);
    }
    return 0;
}