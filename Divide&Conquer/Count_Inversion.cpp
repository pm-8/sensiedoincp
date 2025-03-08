#include<iostream>
#include <vector>
using namespace std;

//helper method
int c = 0;
int merge(vector<int> &array,int s,int e){
	int i = s;
	int m = (s+e)/2;
	int j = m + 1;

	vector<int> temp;

    int cnt = 0;

	while(i<=m and j<=e){
		if(array[i] < array[j]){
			temp.push_back(array[i]);
			i++;
		}
		else{
            cnt += (m - i + 1);
			temp.push_back(array[j]);
			j++;
		}
	}

	//copy rem elements from first array
	while(i<=m){
		temp.push_back(array[i++]);
	}

	// or copy rem elements from second array
	while(j<=e){
		temp.push_back(array[j++]);
	}

	//copy back the eleemtns from temp to original array
	int k = 0 ;
	for(int idx = s; idx <=e ;idx++){
		array[idx] = temp[k++];
	}
	return cnt;
}

//sorting method
int mergesort(vector<int> &arr,int s,int e){
	//base case
	if(s>=e){
		return 0;
	}
	//rec case
	int mid = (s+e)/2;
	int c1 = mergesort(arr,s,mid);
	int c2 = mergesort(arr,mid+1,e);
	int ci = merge(arr,s,e);
    return c1 + c2 + ci;
}

int main(){
  	
  	vector<int> arr{0,5,2,3,1};

	int s = 0;
	int e = arr.size()-1;
    int m = mergesort(arr,s,e);
	cout << m << endl;
	return 0;
}




