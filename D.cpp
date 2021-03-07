#include<bits/stdc++.h>
#define int long long int
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
#define mod 1000000007
#define MAXN 200001  
vector<int> spf(MAXN);
ll mul(ll a,ll b){
	return ((a%mod)*(b%mod))%mod;
}
ll add(ll a,ll b){
	return ((a%mod)+(b%mod))%mod;
}
ll power(ll a,ll b){
	if(b==0) return 1;
	if(b==1) return a;
	ll res=power(a,b/2);
	res=mul(res,res);
	if(b%2) res=mul(res,a);
	return res;
}
void sieve() 
{ 
	spf[1] = 1; 
	for (int i=2; i<MAXN; i++)  spf[i] = i; 

	for (int i=4; i<MAXN; i+=2)  spf[i] = 2; 

	for (int i=3; i*i<MAXN; i++){  
		if (spf[i] == i){  
			for (int j=i*i; j<MAXN; j+=i) 
				if (spf[j]==j) 
					spf[j] = i; 
		} 
	} 
} 

map<int,int> getFactorization(int x) { 
	map<int,int> ret; 
	while (x != 1) { 	
		ret[spf[x]]++;
		x = x / spf[x]; 
	} 
	return ret; 
}
void solve(){
	int n,q; cin>>n>>q; int arr[n+1];
	map<int,int> mp[n+1];
	set<pii> prime[MAXN]; vector<int> cnt(MAXN,n);
	for(int i=1;i<=n;i++) {
		cin>>arr[i];
		map<int,int> p=getFactorization(arr[i]);
		for(auto x:p){
			cnt[x.F]--; prime[x.F].insert({x.S,i});
			mp[i][x.F]=x.S;
		}
	}
	///cout <<"---";
	ll g=1; int res[MAXN]={0};
	for(ll i=1;i<MAXN;i++){
		if(cnt[i]) continue;
		auto curr=prime[i].begin();
		g=mul(g,power(i,(curr->F))); 
		res[i]=(curr->F);
	}
	while(q--){
		int i,x; cin>>i>>x;
		map<int,int> p=getFactorization(x);
		for(auto x:p){
			int prev=mp[i][x.F];
			if(mp[i][x.F]==0){
				cnt[x.F]--; mp[i][x.F]=x.S;
				prime[x.F].insert({x.S,i});
			}else{
				 mp[i][x.F]+=x.S;
				prime[x.F].erase({prev,i}); prime[x.F].insert({prev+x.S,i});
			}
			if(cnt[x.F]) continue;
			auto curr=prime[x.F].begin();
			g=mul(g,power(x.F,(*curr).F-res[x.F])); 
			res[x.F]=(curr->F);
		}
		cout <<g<<endl;
	}
	
}
signed main() { 
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	sieve();
	////cout <<"--"<<endl;
	int t=1; ///cin>>t;
	while(t--){
		solve();
	}
	return 0; 
} 
