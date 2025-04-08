#include<bits/stdc++.h>
using namespace std;

void solve(vector < int > person, int k, int index, int & ans) { 
if (person.size() == 1) { //base case 
ans = person[0]; //if last element is left 
return; 
} 
index =(index + k) % person.size(); //finding the person to be killed 
person.erase(person.begin() + index); //to erase that person 
solve(person, k, index, ans); //recursive call
return; 
} 
int main() { 
int n = 7 , k = 3 ; 
vector < int > person; //to store the person numbering 
for (int i = 1; i <= n; i++) { 
person.push_back(i); 
} 
int ans = -1; //to store the safest place 
solve(person, k - 1, 0, ans); 
cout<<"The safe position is: "<<ans<<endl; 
} 