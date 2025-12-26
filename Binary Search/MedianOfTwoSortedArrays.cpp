// class Solution {
//   public:
//     double medianOf2(vector<int>& a, vector<int>& b) {
//         // code here
//         int n1 = a.size();
//         int n2 = b.size();
//         if(n1 > n2) return medianOf2(b,a);
//         int l = 0, r = n1;
//         int left = (n1 + n2 + 1) >> 1;
//         int n = n1 + n2;
//         while(l <= r){
//             int m1 = (l + r) >> 1;
//             int m2 = left - m1;
//             int l1 = INT_MIN, l2 = INT_MIN;
//             int r1 = INT_MAX, r2 = INT_MAX;
//             if(m1 < n1) r1 = a[m1];
//             if(m2 < n2) r2 = b[m2];
//             if(m1-1 >= 0) l1 = a[m1-1];
//             if(m2-1 >= 0) l2 = b[m2-1];
//             if(l1 <= r2 && l2 <= r1){
//                 if(n % 2 == 1){
//                     return max(l1,l2);
//                 }
//                 else{
//                     return (double)(max(l1,l2) + min(r1,r2))/2;
//                 }
//             }
//             else if(l1 > r2){
//                 r = m1 - 1;
//             }
//             else {
//                 l = m1 + 1;
//             }
//         }
//         return 0.0;
//     }
// // };