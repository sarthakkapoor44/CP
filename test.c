#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to calculate prefix sums
void calculatePrefixSum(int *arr, int n, int *prefixSum) {
    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
}

// Function to find the lower bound using binary search
int lowerBound(int *arr, int n, int target) {
    int low = 0, high = n;
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] <= target) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

// Function to find the maximum number of rides
int maxRides(int *leftPrices, int l, int *rightPrices, int r, int M) {
    int *prefixLeft = (int *)malloc(l * sizeof(int));
    int *prefixRight = (int *)malloc(r * sizeof(int));

    // Calculate prefix sums for both arrays
    calculatePrefixSum(leftPrices, l, prefixLeft);
    calculatePrefixSum(rightPrices, r, prefixRight);

    int maxRides = 0;

    // Iterate over the left prefix sums and use binary search on the right prefix sums
    for (int i = 0; i < l; i++) {
        if (prefixLeft[i] > M) break; // If the prefix sum itself exceeds M, stop
        int remaining = M - prefixLeft[i];
        int ridesOnRight = lowerBound(prefixRight, r, remaining);
        maxRides = (i + 1) + ridesOnRight > maxRides ? (i + 1) + ridesOnRight : maxRides;
    }

    // Also consider the case when only rides from the right side are taken
    for (int j = 0; j < r; j++) {
        if (prefixRight[j] > M) break; // If the prefix sum itself exceeds M, stop
        int remaining = M - prefixRight[j];
        int ridesOnLeft = lowerBound(prefixLeft, l, remaining);
        maxRides = (j + 1) + ridesOnLeft > maxRides ? (j + 1) + ridesOnLeft : maxRides;
    }

    free(prefixLeft);
    free(prefixRight);
    return maxRides;
}

int main() {
    int T; // Number of test cases
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        int L, R, M;
        scanf("%d", &L);
        
        int *leftPrices = (int *)malloc(L * sizeof(int));
        for (int i = 0; i < L; i++) {
            scanf("%d", &leftPrices[i]);
        }

        scanf("%d", &R);
        int *rightPrices = (int *)malloc(R * sizeof(int));
        for (int i = 0; i < R; i++) {
            scanf("%d", &rightPrices[i]);
        }

        scanf("%d", &M);

        int result = maxRides(leftPrices, L, rightPrices, R, M);
        printf("%d\n", result);

        free(leftPrices);
        free(rightPrices);
    }

    return 0;
}
