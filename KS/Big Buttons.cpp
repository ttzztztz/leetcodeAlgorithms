#include <iostream>
#include <list>
#include <cstring>

//#define DEBUG 1

using namespace std;

long long fastPow(long long x, long long y) {
    long long result = 1, pow = x;
    while (y) {
        if (y & 1) {
            result *= pow;
        }
        pow *= pow;
        y >>= 1;
    }
    return result;
}

int main() {
    int dataCount = 0;
    cin >> dataCount;
    for (int _ = 1; _ <= dataCount; _++) {
        int N = 0, P = 0;
        cin >> N >> P;

        long long answer = fastPow(2L, N);

        list<string> disabledList;
        for (int i = 1; i <= P; i++) {
            string newString;
            cin >> newString;

            bool shouldInsert = true;
            for (string &oldString: disabledList) {
                if (oldString == newString) {
#ifdef DEBUG
                    cout << "SITUATION 1:" << oldString << ", " << newString << endl;
#endif
                    shouldInsert = false;
                    break;

                } else if (oldString.length() > newString.length()
                           && oldString.substr(0, newString.length()) == newString) {
#ifdef DEBUG
                    cout << "SITUATION 2:" << oldString << ", " << newString << endl;
#endif
                    oldString = newString;
                    shouldInsert = false;
                    break;

                } else if (newString.length() > oldString.length()
                           && newString.substr(0, oldString.length()) == oldString) {
#ifdef DEBUG
                    cout << "SITUATION 3:" << oldString << ", " << newString << endl;
#endif
                    shouldInsert = false;
                    break;

                }
            }
            if (shouldInsert) {
                disabledList.push_back(newString);
            }
        }


        for (const string &s : disabledList) {
            answer -= fastPow(2L, N - s.length());
        }

        printf("Case #%d: %lld \n", _, answer);
    }
    return 0;
}