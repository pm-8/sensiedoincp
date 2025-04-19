#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long compute_hash(string const& s){
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for(char c : s){
        hash_value = (hash_value + (c - 'a' + 1)*p_pow)%m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}
vector<vector<int>> group_identical_strings(vector<string> const& s){
    int n = s.size();
    vector<pair<long long, int>> hashes(n);
    for(int i = 0; i < n; i++){
        hashes[i] = {compute_hash(s[i]), i};
        cout << "Hash of " << s[i] << ": " << hashes[i].first << endl;
    }
    sort(hashes.begin(), hashes.end());
    vector<vector<int>> groups;
    for(int i = 0; i < n; i++){
        if(i == 0 || hashes[i].first != hashes[i-1].first){
            groups.push_back({hashes[i].second});
        }else{
            groups.back().push_back(hashes[i].second);
        }
    }
    return groups;
}
int main()
{
    vector<string> s = {"abc", "bca", "bca", "xyz", "abc", "def", "xyz"};
    vector<vector<int>> groups = group_identical_strings(s);
    for(auto& group : groups){
        cout << "Group: ";
        for(int index : group){
            cout << s[index] << " ";
        }
        cout << endl;
    }
    return 0;
}