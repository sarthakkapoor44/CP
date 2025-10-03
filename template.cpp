#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> findOverlappingTimes(vector<vector<int>> intervals) {
    if (intervals.empty()) return {};

    sort(intervals.begin(), intervals.end(),
         [](const vector<int>& a, const vector<int>& b){
             if (a[0] == b[0]) return a[1] < b[1];
             return a[0] < b[0];
         });

    vector<vector<int>> merged;
    merged.push_back(intervals[0]);

    for (size_t i = 1; i < intervals.size(); ++i) {
        // Overlap if next.start <= last.end (touching endpoints merge too)
        if (intervals[i][0] <= merged.back()[1]) {
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        } else {
            merged.push_back(intervals[i]);
        }
    }
    return merged;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    // In the custom tester, the next line is always "2" (size of each interval).
    // Read and ignore it if present.
    int sz;
    if (cin >> sz) {
        if (sz != 2) { /* optional: handle unexpected */ }
    }

    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; ++i) cin >> intervals[i][0] >> intervals[i][1];

    auto ans = findOverlappingTimes(intervals);
    for (auto &iv : ans) cout << iv[0] << ' ' << iv[1] << '\n';
    return 0;
}