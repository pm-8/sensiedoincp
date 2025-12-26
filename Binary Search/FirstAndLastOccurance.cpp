#include <bits/stdc++.h>
using namespace std;

//Function for finding last occurrence of x
int findLast(vector<int> arr, int x) {
    int n = arr.size();

    // Initialize low and high index
    // to find the last occurrence
    int low = 0, high = n - 1;

    // Initialize last occurrence
    int last = -1;

    // Find last occurrence of x
    while(low <= high) {

        // Find the mid index
        int mid = (low + high) / 2;

        // If x is equal to arr[mid]
        if (x == arr[mid]) {
            last = mid;
            low = mid + 1;
        }

        // If x is less than arr[mid], 
        // then search in the left subarray
        else if (x < arr[mid])
            high = mid - 1;

        // If x is greater than arr[mid], 
        // then search in the right subarray
        else
            low = mid + 1;
    }

    return last;
}

// Function for finding first occurrence of x
int findFirst(vector<int> arr, int x) {
    int n = arr.size();

    // Initialize low and high index
    // to find the first occurrence
    int low = 0, high = n - 1;

    // Initialize first occurrence
    int first = -1;

    // Find first occurrence of x
    while(low <= high) {

        // Find the mid index
        int mid = (low + high) / 2;

        // If x is equal to arr[mid]
        if (x == arr[mid]) {
            first = mid;
            high = mid - 1;
        }

        // If x is less than arr[mid], 
        // then search in the left subarray
        else if (x < arr[mid])
            high = mid - 1;

        // If x is greater than arr[mid], 
        // then search in the right subarray
        else
            low = mid + 1;
    }

    return first;
}

// Function for finding first and last occurrence of x
vector<int> find(vector<int> arr, int x) {
    int n = arr.size();

    // Find first and last index
    int first = findFirst(arr, x);
    int last = findLast(arr, x);

    vector<int> res = {first, last};
    return res;
}

int main() {
    vector<int> arr = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int x = 5;
    vector<int> res = find(arr, x);
    cout << res[0] << " " << res[1];
    return 0;
}