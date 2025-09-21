#include<iostream>
#include<vector>
using namespace std;
int largestSubsquare(vector<vector<char>>& mat){
    // int n = mat.size();
    // int maxSize = 0;
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         for(int size = 1; size <= n-max(i,j); size++){
    //             bool valid = true;
    //             for(int k = 0; k < size; k++){
    //                 if(mat[i][j + k] != 'X' || mat[i+k][j] != 'X'){
    //                     valid = false;
    //                     break;
    //                 }
    //             }
    //             for(int k = 0; k < size; k++){
    //                 if(mat[i + size - 1][j+k] != 'X'
    //                 || mat[i+k][j+size-1] != 'X'){
    //                     valid = false;
    //                     break;
    //                 } 
    //             }
    //             if(valid){
    //                 maxSize = max(maxSize,size);
    //             }
    //         }
    //     }
    // }
    // return maxSize;



    // DP Approach
    int n = mat.size();
    vector<vector<int>> right(n,vector<int>(n,0));
    vector<vector<int>> down(n,vector<int>(n,0));
    for(int i = n-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            if(mat[i][j] == 'X'){
                right[i][j] = (j == n-1)?1:right[i][j+1]+1;
                down[i][j] = (i == n-1)?1:down[i+1][j]+1;  
            }
        }
    }
    int maxSize = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int maxSide = min(right[i][j],down[i][j]);
            for(int side = maxSide; side > 0; side--){
                if(right[i + side - 1][j] >= side &&
                down[i][j + side - 1] >= side){
                    maxSize = max(maxSize,side);
                    break;
                }
            }
        }
    }
    return maxSize;
}
int main() {
  
    vector<vector<char>> mat =
              {{'X','X','X','O'},
               {'X','O','X','X'},
               {'X','X','X','O'},
               {'X','O','X','X'}};
    cout << largestSubsquare(mat);
}