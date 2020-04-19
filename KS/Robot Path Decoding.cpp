#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <tuple>
#include <array>

using namespace std;

typedef array<int, 4> State;
unordered_map<char, int> charMap = {
        {'N', 0},
        {'S', 1},
        {'W', 2},
        {'E', 3}
};

State decodeString(string s) {
    const int N = s.size();

    string currentNumber;
    State currentString;
    State emptyState = {0, 0, 0, 0};

    vector<pair<State, int>> leftStack;
    for (int i = 0; i < N; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            currentNumber += s[i];
        } else if (s[i] == '(') {
            leftStack.emplace_back(currentString, stoi(currentNumber));
            currentNumber = "", currentString = emptyState;
        } else if (s[i] == ')') {
            pair<State, int> top = leftStack.back();
            leftStack.pop_back();

            State prev_string = currentString;
            for (int k = 0; k < top.second - 1; k++) {
                for (int q = 0; q < 4; q++) currentString[q] += prev_string[q];
            }

            for (int q = 0; q < 4; q++) currentString[q] += top.first[q];
        } else {
            currentString[charMap[s[i]]]++;
        }
    }

    return currentString;
}

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        long long answer = 0;
        string a;
        cin >> a;
        State decoded = decodeString(a);

        const long long LIM = 1e9;
        long long x = 1, y = 1;
        x -= decoded[0];
        while (x <= 0) x += LIM;
        x += decoded[1];
        while (x > LIM) x -= LIM;
        y -= decoded[2];
        while (y <= 0) y += LIM;
        y += decoded[3];
        while (y > LIM) y -= LIM;

        printf("Case #%d: %lld %lld\n", _, y, x);
    }
    return 0;
}
