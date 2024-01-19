#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX_INDEX 1000001
#define MAX_BIT 21
#define INVALID -1

// Function to process and solve each test case
void solve() {
    ll numElements; 
    cin >> numElements;
    vector<ll> elements(numElements);

    // Reading elements of the array
    for(ll i = 0; i < numElements; i++) {
        cin >> elements[i];
    }

    // Vector to store indices for each bit position
    vector<ll> bitIndices[MAX_BIT];
    for(ll i = 0; i < numElements; i++) {
        for(ll bit = 0; bit < MAX_BIT; bit++) {
            if(elements[i] & (1 << bit)) 
                bitIndices[bit].push_back(i + 1);
        }
    }

    ll numQueries; 
    cin >> numQueries;
    while(numQueries--) {
        ll minIndex = MAX_INDEX, lowerBound = INVALID, upperBound = MAX_INDEX;
        ll queryIndex, queryValue; 
        cin >> queryIndex >> queryValue;

        for(ll bit = MAX_BIT - 1; bit >= 0; bit--) {
            if (bitIndices[bit].empty()) continue;
            
            auto it = lower_bound(bitIndices[bit].begin(), bitIndices[bit].end(), queryIndex);

            if (queryValue < (1 << bit) && lowerBound == INVALID) {
                if (it != bitIndices[bit].end()) {
                    minIndex = min(minIndex, *it);
                }
            }
            else if (queryValue < (1 << bit)) {
                if (it != bitIndices[bit].end()) {
                    if (upperBound == MAX_INDEX) {
                        upperBound = min(upperBound, *it);
                        upperBound = max(lowerBound, upperBound);
                    }
                    else {
                        ll newMinIndex = min(upperBound, *it);
                        newMinIndex = max(lowerBound, newMinIndex);
                        upperBound = min(upperBound, newMinIndex);
                    }
                }
            }
            else {
                if (it != bitIndices[bit].end()) {
                    lowerBound = max(lowerBound, *it);
                    queryValue -= (1 << bit);
                }
            }
        }

        if (queryValue > 0) lowerBound = INVALID;

        if (lowerBound > 0) {
            cout << min({minIndex, lowerBound, upperBound}) << " ";
        }
        else if (min(minIndex, upperBound) == MAX_INDEX) {
            cout << -1 << " ";
        }
        else {
            cout << min(minIndex, upperBound) << " ";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    ll test = 1;
    // Uncomment the next line to read number of test cases
    // cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}
