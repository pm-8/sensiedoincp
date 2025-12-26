// C program for iterative implementation
// of the above approach

#include <stdio.h>

// Function to implement lower_bound
int lower_bound(int arr[], int N, int X)
{
    int mid;
    int low = 0;
    int high = N;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (X <= arr[mid]) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }
    if(low < N && arr[low] < X) {
       low++;
    }
    return low;
}
int upper_bound(int arr[], int N, int X)
{
    int mid;
    int low = 0;
    int high = N;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (X >= arr[mid]) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    if(low < N && arr[low] <= X) {
       low++;
    }
    return low;
}
void printBound(int arr[], int N, int X)
{
    int idx;

    // If lower_bound doesn't exists
    if (lower_bound(arr, N, X) == N) {
        printf("Lower bound doesn't exist");
    }
    else {

        // Find lower_bound
        idx = lower_bound(arr, N, X);
        printf("Lower bound of %d is"
               "% d at index % d\n ",
               X,
               arr[idx], idx);
    }

    // If upper_bound doesn't exists
    if (upper_bound(arr, N, X) == N) {
        printf("Upper bound doesn't exist");
    }
    else {

        // Find upper_bound
        idx = upper_bound(arr, N, X);
        printf("Upper bound of %d is"
               "% d at index % d\n ",
               X,
               arr[idx], idx);
    }
}

// Driver Code
int main()
{
    // Given array
    int arr[] = { 4, 6, 10, 12, 18, 20 };
    int N = sizeof(arr) / sizeof(arr[0]);

    // Element whose lower bound and
    // upper bound to be found
    int X = 6;

    // Function Call
    printBound(arr, N, X);
    return 0;
}