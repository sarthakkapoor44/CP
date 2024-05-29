#include <iostream>
using namespace std;

int main() {
    // Optimize input/output
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Since the problem specifies the digits directly, we can precompute the answer.
    int A1 = 1, A2 = 2, A3 = 2;
    int count = 0;

    // Iterate over all possible values for X1 (1-digit number: 1 to 9)
    for (int X1 = 1; X1 <= 9; ++X1) {
        // Iterate over all possible values for X2 (2-digit number: 10 to 99)
        for (int X2 = 10; X2 <= 99; ++X2) {
            int X3 = X1 + X2;
            // Check if X3 is a 2-digit number
            if (X3 >= 10 && X3 <= 99) {
                count++;
            }
        }
    }

    // Output the total count of valid (X1, X2, X3) tuples
    cout << count << endl;

    return 0;
}
