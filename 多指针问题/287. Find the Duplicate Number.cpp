#include <iostream>
#include <sstream>
using namespace std;

int main () {
    long long x = 255;
    stringstream ss;
    ss << uppercase << hex  << x;
    string answer;
    ss >> answer;
    cout << answer;
    return 0;
}