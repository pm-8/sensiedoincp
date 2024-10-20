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
            //otherwise we need to fine the nearest starting point
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
                cout << i << endl;
            }
        }
        cout << endl;
    }
    return 0;
}