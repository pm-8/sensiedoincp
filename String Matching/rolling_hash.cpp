#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
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
long long fast_hashing(string const& s, int i, int j){
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for(int k = i; k <= j; k++){
        hash_value = (hash_value + (s[k] - 'a' + 1)*p_pow)%m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

int count_unique_substrings(string const&s){
    int n = s.size();
    const int p = 31;
    const int m = 1e9 + 9;
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for(int i = 1; i < n; i++){
        p_pow[i] = (p_pow[i-1] * p) % m;
    }
    vector<long long> h(n+1,0);
    for(int i = 0; i < n; i++){
        h[i+1] = (h[i] + (s[i] - 'a' + 1)*p_pow[i])%m; 
    }
    int cnt = 0;
    for(int l = 1; l <= n; l++){
        unordered_set<long long> hs;
        for(int i = 0; i <= n-l; i++){
            long long cur_h = (h[i+l] + m - h[i])%m;
            cur_h = (cur_h * p_pow[n-i-1])%m;
            hs.insert(cur_h);
        }
        cnt+=hs.size();
    }
    return cnt;
}
vector<int> rabin_karp(string const& s, string const& t){
    const int p = 31;
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();
    vector<long long> p_pow(max(S,T));
    p_pow[0] = 1;
    for(int i = 1; i < (int)p_pow.size(); i++){
        p_pow[i] = (p_pow[i-1]*p)%m;
    }
    vector<long long> h(T + 1, 0);
    for(int i = 0; i < T; i++){
        h[i+1] = (h[i] + (t[i] - 'a' + 1)*p_pow[i])%m;
    }
    long long h_s = 0;
    for(int i = 0; i < S; i++){
        h_s = (h_s + (s[i] - 'a' + 1)*p_pow[i])%m;
    }
    vector<int> occurrences;
    for(int i = 0; i + S - 1 < T; i++){
        long long cur_h = (h[i+S] + m - h[i])%m;
        if(cur_h == h_s * p_pow[i]%m){
            occurrences.push_back(i);
        }
    }
    return occurrences;
}
int main()
{
    // vector<string> s = {"abc", "bca", "bca", "xyz", "abc", "def", "xyz"};
    // vector<vector<int>> groups = group_identical_strings(s);
    // for(auto& group : groups){
    //     cout << "Group: ";
    //     for(int index : group){
    //         cout << s[index] << " ";
    //     }
    //     cout << endl;
    // }
    // string s = "abcde";
    // int i = 0, j = 2; // Hashing substring s[i..j]
    // long long hash_value = fast_hashing(s, i, j);
    // cout << "Hash of substring s[" << i << ".." << j << "] = " << hash_value << endl;
    // // Hashing substring s[i..j] using compute_hash function
    // long long hash_value2 = compute_hash(s.substr(i, j-i+1));
    // cout << "Hash of substring s[" << i << ".." << j << "] using compute_hash = " << hash_value2 << endl;
    // cout << "Number of unique substrings in " << s << " = " << count_unique_substrings(s) << endl;
    // string s = "abcabc";
    // cout << "Number of unique substrings in " << s << " = " << count_unique_substrings(s) << endl;
    string s = "abcde";
    string t = "abcdecabcabcde";
    vector<int> occurrences = rabin_karp(s, t);
    cout << "Occurrences of " << s << " in " << t << ": ";
    for(int index : occurrences){
        cout << index << " ";
    }
    cout << endl;
    return 0;   
}