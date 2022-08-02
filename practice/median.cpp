#include <bits/stdc++.h>
#include<vector>
using namespace std;

void median(vector<int>&arr, int n){
	// to store median
	vector<float>m;
	// If n is odd
	if(n & 1){
		m.push_back(arr[n/2] * 1.0);
	}
	// If n is even
	else{
		m.push_back((arr[n/2] + arr[(n-1)/2])/2.0);
	}
	for(auto& x : arr){
		auto it = find(arr.begin(),arr.end(),x);
		
		n--;

        if(n & 1){
		    m.push_back(arr[n/2] * 1.0);
	    }
	// If n is even
	    else{
        	m.push_back((arr[n/2] + arr[(n-1)/2])/2.0);
	    }
	}
	for(int i=0;i<m.size();i++){
		cout<<m[i] <<' ';
	}
}

int main() {
	// your code goes here
	int n,element;
	cin>>n;
	vector<int>arr;
	for(int i=0;i<n;i++){
		cin>>element;
		arr.push_back(element);
	}
	// function call
	median(arr,n);
	return 0;
}
