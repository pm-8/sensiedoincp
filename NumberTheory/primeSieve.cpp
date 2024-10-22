#include<bits/stdc++.h>
using namespace std;
#define N 5000000
bool arr[N+1];

void sieveArr(vector<int>& v){
    for(int i = 2; i <= N; i++){
        arr[i] = true;
    }
    
    for(int i = 2; i * i <= N; i++){
        if(arr[i]){
            for(int j = i * i; j <= N; j += i){
                arr[j] = false;
            }
        }
    }
    for(int i = 2; i <= N; i++){
        if(arr[i]) v.push_back(i);
    }
}

int countPrimes(int n){
    vector<int> primeSieve;
    sieveArr(primeSieve);
    int c = 0;
    
    for(int i : primeSieve){
        if(i < n){
            c++;
        }
        else break;
    }
    
    return c;
}
