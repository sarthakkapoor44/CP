#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;


    int total_checkpoints = a * b;

 
    vector<int> results;

    for (int i = 1; i <= 9; ++i) {
        int percentage = (total_checkpoints * i + 9) / 10; // This ensures rounding up
        results.push_back(percentage);
    }

 
    for (int i = 0; i < 9; ++i) {
        cout << results[i];
        if (i != 8) cout << " ";
    }
    

    return 0;
}
