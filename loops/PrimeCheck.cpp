#include <iostream>

using namespace std;

int main() {
    int num = 2;

    cout << "Prime numbers between 2 and 100 are:" << endl;

    while (num <= 100) {
        bool isPrime = true;
        int divisor = 2;

        while (divisor <= num / 2) {
            if (num % divisor == 0) {
                isPrime = false;
                break;
            }
            divisor++;
        }

        if (isPrime) {
            cout << num << " ";
        }

        num++;
    }

    cout << endl;

    return 0;
}

