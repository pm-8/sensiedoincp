// Segmented Sieve
// The idea of a segmented sieve is to divide the range [0..n-1] in different segments and compute primes in all segments one by one. This algorithm first uses Simple Sieve to find primes smaller than or equal to ?(n). Below are steps used in Segmented Sieve.

// Use Simple Sieve to find all primes up to the square root of ‘n’ and store these primes in an array “prime[]”. Store the found primes in an array ‘prime[]’.
// We need all primes in the range [0..n-1]. We divide this range into different segments such that the size of every segment is at-most ?n
// Do following for every segment [low..high] 
// Create an array mark[high-low+1]. Here we need only O(x) space where x is a number of elements in a given range.
// Iterate through all primes found in step 1. For every prime, mark its multiples in the given range [low..high].
// In Simple Sieve, we needed O(n) space which may not be feasible for large n. Here we need O(?n) space and we process smaller ranges at a time (locality of reference)
#include<iostream>
#include <vector>
using namespace std;

#define N 100000
int sieveArr[N+1] = {0};
vector<int> primes;
void sieve(){
    for(long long i = 2; i <= N; i++){
        if(sieveArr[i] == 0){
            primes.push_back(i);
            for(long long j = i*i; j <= N; j++){
                sieveArr[j] = 1;
            }
        }
    }
}
int main()
{
    sieve();
    int t;
    cin >> t;
    while(t--){
        int m, n;
        cin >> m >> n;
        vector<int> segment(n-m+1,0);
        for(auto p : primes){
            //stop when p^2 > n
            if(p*p > n){
                break;
            }
            //otherwise we need to find the nearest starting point
            int start = (m/p)*p;
            //special case
            if(p>=m && p <= n){
                start = 2 * p;
            }

            for(int j = start; j <= n; j += p){
                if(j < m) continue;
                //marked it as non primes
                segment[j-m] = 1;
            }
        }
        for(int i = m; i <= n; i++){
            if(segment[i - m] == 0 && i!=1){
                cout << i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}