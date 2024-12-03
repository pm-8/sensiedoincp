#include<iostream>
using namespace std;
long long recursive_power(long long A, long long B){
    if(B==0){
        return 1;
    }
    long long res = recursive_power(A,B/2);
    if(B%2)
    return res * res * A;
    else 
    return res * res;
}
long long iterative_power(long long a, long long b){
    long long res = 1;
    while(b){
    if(b&1)
    res *= a;
    a*=a;
    b>>=1;
    }
    return res;
}
long long fast_multiplication(long long a, long long b, long long c){
    long long res = 0;
    while(b--){
        if(b&1)
        res+=a;
        res%=c;
        a=a%c;
        a = 2*a;
        b >>=1;
    }
    return res;
}
int main()
{
    int b =8;
    while(b){
        cout << b << endl;
        b >>= 1;
    }
    return 0;
}