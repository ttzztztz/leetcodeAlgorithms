#include <iostream>
#include <map>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

string hashUnorderedMap(const map<char, int> &collection) {
    stringstream ss;

    for (pair<char, int> item : collection) {
        ss << item.first << ":" << item.second << ";";
    }

    string answer;
    ss >> answer;
    return answer;
}

int main() {
    int dataCount = 0;
    cin >> dataCount;
    for (int _ = 1; _ <= dataCount; _++) {
        int L = 0, answer = 0;
        string A, B;
        cin >> L >> A >> B;

        unordered_map<string, int> BMap;
        for (int i = 1; i <= L; i++) {
            for (int j = i; j <= L; j++) {
                map<char, int> charMap;
                for (int k = i; k <= j; k++) {
                    char ch = B[k - 1];
                    if (!charMap[ch]) {
                        charMap[ch] = 1;
                    } else {
                        charMap[ch]++;
                    }
                }
                BMap[hashUnorderedMap(charMap)] = 1;
            }
        }

        for (int i = 1; i <= L; i++) {
            for (int j = i; j <= L; j++) {
                map<char, int> charMap;
                for (int k = i; k <= j; k++) {
                    char ch = A[k - 1];
                    if (!charMap[ch]) {
                        charMap[ch] = 1;
                    } else {
                        charMap[ch]++;
                    }
                }
                if (BMap[hashUnorderedMap(charMap)] == 1) {
                    answer++;
                }
            }
        }

        printf("Case #%d: %d \n", _, answer);
    }
    return 0;
}