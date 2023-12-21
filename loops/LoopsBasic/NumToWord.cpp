#include <iostream>
#include <string>

using namespace std;

string digitToWord(int digit) {
    switch (digit) {
        case 0:
            return "Zero";
        case 1:
            return "One";
        case 2:
            return "Two";
        case 3:
            return "Three";
        case 4:
            return "Four";
        case 5:
            return "Five";
        case 6:
            return "Six";
        case 7:
            return "Seven";
        case 8:
            return "Eight";
        case 9:
            return "Nine";
        default:
            return "";
    }
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int num = n;
    int len = to_string(n).length();
    string value[len];
    int i = 0;
    
    while (num != 0) {
        int number = num % 10;
        value[i] = digitToWord(number);
        num /= 10;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        cout << value[j] << " ";
    }

    cout << endl;
    return 0;
}
