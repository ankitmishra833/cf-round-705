#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define F first
#define S second
#define mod 1000000007
using namespace std;

void solve(){
	int n,k; cin>>n>>k; 
	vector<int> ans;
	for(int i=1;i<=n;i++){
		if(i>k){
			ans.push_back(i); continue;
		}
		if(k%2){
			if(i%2==0) ans.push_back(i);
		}else{
			if(i>=k/2 && i!=k) ans.push_back(i);
		}
	}
	cout << ans.size() <<endl;
	for(auto x:ans) cout <<x<<" ";
	cout <<endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;   cin>>t;
    for(int it=1;it<=t;it++){
    	solve();
	}
}



