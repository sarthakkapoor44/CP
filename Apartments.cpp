#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class SegmentTree {
private:
    vector<long long> tree;
    int n;

public:
    SegmentTree(const vector<long long>& data) {
        n = data.size();
        tree.resize(2 * n);
        for (int i = 0; i < n; ++i) {
            tree[n + i] = data[i];
        }
        for (int i = n - 1; i > 0; --i) {
            tree[i] = min(tree[2 * i], tree[2 * i + 1]);
        }
    }

    void update(int pos, long long value) {
        pos += n;
        tree[pos] = value;
        while (pos > 1) {
            pos /= 2;
            tree[pos] = min(tree[2 * pos], tree[2 * pos + 1]);
        }
    }

    long long query(int l, int r) { // inclusive l, exclusive r
        long long res = numeric_limits<long long>::max();
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) res = min(res, tree[l++]);
            if (r & 1) res = min(res, tree[--r]);
        }
        return res;
    }
};

long long getMinimumCost(const vector<int>& cost, int k) {
    int n = cost.size();
    vector<long long> dp(n + 1, numeric_limits<long long>::max());
    dp[0] = 0;
    SegmentTree st(dp);

    for (int i = 1; i <= n; ++i) {
        int left = max(0, i - k);
        int right = i - 1;
        long long min_cost = st.query(left, right + 1);
        dp[i] = min_cost + cost[i - 1];
        st.update(i, dp[i]);
    }

    return dp[n];
}

int main() {
    vector<int> cost = {4, 3, 9, 3,1};
    int k = 2;
    cout << "Minimum Cost to Reach End: " << getMinimumCost(cost, k) << endl;
    return 0;
}
