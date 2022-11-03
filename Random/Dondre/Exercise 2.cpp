//Exercise 2
#include <iostream>
using namespace std;

int main() {
    int a[4] = { 3, 6, 1, 0 };
    int largest = INT_MIN;
    for (int i = 0; i < 4; i++) {
        if (a[i] > largest) {
            largest = a[i];
        }
    }
    for (int i = 0; i < 4; i++) {
        if (largest > (a[i] * 2)) {
            cout << largest;
        }
        else {
            return -1;
        }
    }
}