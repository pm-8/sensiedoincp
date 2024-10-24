#include <iostream>
#include <vector>
using namespace std;
int gcd(int a,int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}
//{x,y}
vector<int> extendedGCD(int a, int b){
    if(b == 0){
        //return the values of x and y
        return {1,0,a};
    }
    vector<int> result = extendedGCD(b, a%b);
    //Bottom Up way of building the solution
    int smallX = result[0];
    int smallY = result[1];
    int gcd = result[2];
    int x = smallY;
    int y = smallX - (a/b)*smallY;
    
    return {x,y,gcd};
}
int main(){
    int a, b;
    cin >> a >> b;
    vector<int> v = extendedGCD(a,b);
    cout << v[0] << " " <<  v[1] << endl;
    cout << a*v[0] + b*v[1] << endl;
    cout << gcd << endl;
    return 0;
}