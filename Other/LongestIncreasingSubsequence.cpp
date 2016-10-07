/**
Longest Increasing Subsequence using Dynamic Programming
The longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order.

L[0] = {arr[O]}
L[i] = {Max(L[j])} + arr[i] 
where j < i and arr[j] < arr[i] and if there is no such j then L[i] = arr[i]
*/

#include <iostream>
#include <vector>
using namespace std;

// Utility function to print LIS
void printLIS(vector<int>& arr) {
    for (int x : arr) { cout << x << " "; }
    cout << endl;
}

void constructPrintLIS(int arr[], int n) {
    vector<vector<int> > L(n);

    L[0].push_back(arr[0]);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {

            /* L[i] = {Max(L[j])} + arr[i] where j < i and arr[j] < arr[i] */
            if ((arr[i] > arr[j]) && (L[i].size() < L[j].size() + 1)) {
                L[i] = L[j];
            }
        }

        L[i].push_back(arr[i]);
    }

    // L[i] now stores increasing sub-sequence of
    // arr[0..i] that ends with arr[i]
    vector<int> max = L[0];

    for (vector<int> x : L)
        if (x.size() > max.size())
            max = x;

    printLIS(max);

}

int main() {
    int arr[] = { 1, 3, 2, 6 ,7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // construct and print LIS of arr
    constructPrintLIS(arr, n);

    return 0;
}
