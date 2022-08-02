#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,m,x;
	    cin>>n>>m>>x;
	    // create a pair for arr elements and its corresponding index. 
	    vector<pair<int,int>> p;
	    int distance;
	    for(int i=0; i<n;i++){
	        cin>>distance;
	        p.push_back(make_pair(distance, i+1));
	    }
	    // sort the vector elements 
	    sort(p.rbegin(), p.rend());
	    vector<int> ans;
	    for(int i=0;i<n;i++){
	        if(p[i].first >= m || ans.size() < x)
	            ans.push_back(p[i].second);
	    }
	    sort(ans.begin(), ans.end());
	    cout<<ans.size()<<" ";
	    for(int i=0; i<ans.size();i++)
	        cout<<ans[i]<<" ";
	    cout<<"\n";
	}
	return 0;
}

