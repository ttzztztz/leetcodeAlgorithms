#include <iostream>
#include <vector>

using namespace std;

string P, T;
vector<int> nxt;
int lenT, lenP;

void build() {
    nxt[0] = -1;
    nxt[1] = 0;

    int j = 0, i = 1;
    while (i < lenP) {
        if (j == -1 || P[i] == P[j]) {
            nxt[++i] = ++j;
        } else {
            j = nxt[j];
        }
    }
}

void kmp() {
    int i = 0, j = 0;

    while (i < lenT) {
        if (j == -1 || T[i] == P[j]) {
            i++;
            j++;
        } else {
            j = nxt[j];
        }

        if (j == lenP) {
            cout << (i - j + 1) << endl;
            j = nxt[j];
        }
    }
}

int main() {
    cin >> T >> P;
    lenT = T.size();
    lenP = P.size();

    nxt = vector<int>(lenP + 2, 0);
    build();
    kmp();

    for (int i = 1; i <= lenP; i++) {
        std::cout << nxt[i] << " ";
    }
    return 0;
}