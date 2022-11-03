#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main() {
    char str1[55], str2[55];
    int i = 0, j;

    cout << "Enter The First String: ";
    cin.getline(str1, 55);

    cout << "Enter The Second String: ";
    cin.getline(str2, 55);

    while (str1[i] != '\0') {
        if (str1[i] == str2[0]) {
            j = 1;

            while (str2[j] != '\0' && str1[j + 1] != '\0' || str2[j] == str1[j + 1]) {
                j++;
            }
            if (str2[j] == '\0') {
                cout << "True";
            }
            else {
                cout << "Flase";
            }
        }
        i++;
    }
}

