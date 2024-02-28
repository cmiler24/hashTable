#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int hash_function(string text) {
    // Implement your own hash function here

    int x = ((text.length() + 1) * 22/7) % 50;
    // for (int i = 0; i < text.length(); i++) {
    //     if (text[0])
    // }

    cout << text[0] << endl;
    // switch (text[i]);

    return x;
}