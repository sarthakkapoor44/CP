#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to count occurrences of "1543" in the traversal string considering it circular
int countOccurrencesCircular(const string &str, const string &target) {
    int count = 0;
    int n = str.length();
    if (n < target.length()) return 0;

    string str_circular = str + str.substr(0, target.length() - 1); // Extend the string to handle wrapping
    for (int i = 0; i < n; ++i) {
        bool match = true;
        for (int j = 0; j < target.length(); ++j) {
            if (str_circular[i + j] != target[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            count++;
        }
    }
    return count;
}

void getLayerTraversal(int layer, int n, int m, vector<string>& grid, string& traversal) {
    int top = layer;
    int bottom = n - layer -1;
    int left = layer;
    int right = m - layer -1;

    // Check for invalid layer
    if (top > bottom || left > right) return;

    // Traverse top row from left to right
    for (int j = left; j <= right; ++j) {
        traversal += grid[top][j];
    }

    // Traverse right column from top+1 to bottom
    for (int i = top + 1; i <= bottom; ++i) {
        traversal += grid[i][right];
    }

    // Traverse bottom row from right-1 to left (if top != bottom)
    if (bottom != top) {
        for (int j = right - 1; j >= left; --j) {
            traversal += grid[bottom][j];
        }
    }

    // Traverse left column from bottom-1 to top+1 (if left != right)
    if (left != right) {
        for (int i = bottom - 1; i > top; --i) {
            traversal += grid[i][left];
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<string> carpet(n);
        for (int i = 0; i < n; ++i) {
            cin >> carpet[i];
        }

        int total_count = 0;
        int layers = min(n, m) / 2;

        for (int layer = 0; layer < layers; ++layer) {
            string traversal;
            getLayerTraversal(layer, n, m, carpet, traversal);

            total_count += countOccurrencesCircular(traversal, "1543");
        }

        cout << total_count << endl;
    }

    return 0;
}
