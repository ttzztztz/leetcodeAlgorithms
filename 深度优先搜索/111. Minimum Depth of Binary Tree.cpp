#include <iostream>
#include <sstream>

using namespace std;

long long pow(long long x, long long y) {
    long long result = 1L, pow = x;

    while (y) {
        if (y & 1) {
            result *= pow;
        }

        pow *= pow;
        y >>= 1;
    }

    return result;
}

long long solve(long long endNumber) {
    string tempString;
    stringstream ss;
    ss << endNumber;
    ss >> tempString;

    long long answer = 0L;
    for (int i = 0; i < tempString.size(); i++) {
        int startNumber = tempString[i] - '0';

        if (i == tempString.size() - 1) {
            for (long long number = endNumber - (endNumber % 10); number <= endNumber; number++) {
                if (number % 9) {
                    answer++;
                }
            }
        } else {
            answer += startNumber * pow(9L, tempString.size() - i - 2) * 8L;
        }
    }

    return answer;
}

int main() {
    int dataCount = 0;
    cin >> dataCount;
    for (int _ = 1; _ <= dataCount; _++) {
        long long start = 0, end = 0;
        cin >> start >> end;
        long long answer = solve(end) - solve(start) + 1;

        printf("Case #%d: %lld \n", _, answer);
    }
    return 0;
}