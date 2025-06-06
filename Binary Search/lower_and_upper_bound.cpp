// For lower_bound(): 
// Initialise the startIndex as 0 and endIndex as N - 1.
// Compare K with the middle element(say arr[mid]) of the array.
// If the middle element is greater equals to K then update the endIndex as a middle index(mid).
// Else Update startIndex as mid + 1.
// Repeat the above steps until startIndex is less than endIndex.
// After all the above steps the startIndex is the lower_bound of K in the given array.

// For upper_bound(): 
// Initialise the startIndex as 0 and endIndex as N - 1.
// Compare K with the middle element(say arr[mid]) of the array.
// If the middle element is less than equals to K then update the startIndex as middle index + 1(mid + 1).
// Else Update endIndex as mid.
// Repeat the above steps until startIndex is less than endIndex.
// After all the above steps the startIndex is the upper_bound of K in the given array.

// C program for iterative implementation
// of the above approach

#include <stdio.h>

// Function to implement lower_bound
int lower_bound(int arr[], int N, int X)
{
    int mid;

    // Initialise starting index and
    // ending index
    int low = 0;
    int high = N;

    // Till low is less than high
    while (low < high) {
        mid = low + (high - low) / 2;

        // If X is less than or equal
        // to arr[mid], then find in
        // left subarray
        if (X <= arr[mid]) {
            high = mid;
        }

        // If X is greater arr[mid]
        // then find in right subarray
        else {
            low = mid + 1;
        }
    }
  
    // if X is greater than arr[n-1]
    if(low < N && arr[low] < X) {
       low++;
    }
      
    // Return the lower_bound index
    return low;
}

// Function to implement upper_bound
int upper_bound(int arr[], int N, int X)
{
    int mid;

    // Initialise starting index and
    // ending index
    int low = 0;
    int high = N;

    // Till low is less than high
    while (low < high) {
        // Find the middle index
        mid = low + (high - low) / 2;

        // If X is greater than or equal
        // to arr[mid] then find
        // in right subarray
        if (X >= arr[mid]) {
            low = mid + 1;
        }

        // If X is less than arr[mid]
        // then find in left subarray
        else {
            high = mid;
        }
    }
  
    // if X is greater than arr[n-1]
    if(low < N && arr[low] <= X) {
       low++;
    }

    // Return the upper_bound index
    return low;
}

// Function to implement lower_bound
// and upper_bound of X
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

int main()
{
    int arr[] = { 4, 6, 10, 12, 18, 20 };
    int N = sizeof(arr) / sizeof(arr[0]);

    // upper bound to 
    int X = 6;
    printBound(arr, N, X);
    return 0;
}