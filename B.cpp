#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define F first
#define S second
#define mod 1000000007
using namespace std;

bool valid(int h1,int m1,int h,int m,int check[]){
	vector<int> hh; vector<int> mm;
	while(h1){
		if(check[h1%10]==-1) return false;
		hh.push_back(check[h1%10]); h1=h1/10;
	}
	while(hh.size()<2) hh.push_back(0);
	while(m1){
		if(check[m1%10]==-1) return false;
		mm.push_back(check[m1%10]); m1=m1/10;
	}
	while(mm.size()<2) mm.push_back(0);
	int mini=hh[0]*10+hh[1];
	int hour=mm[0]*10+mm[1];
	if(hour<h && mini<m){
		cout <<check[hh[1]]<<check[hh[0]]<<":"<<check[mm[1]]<<check[mm[0]]<<endl;
		return true;
	}
	return false;
}
void solve(){
	int check[]={0,1,5,-1,-1,2,-1,-1,8,-1};
	int h,m; cin>>h>>m;
	int h1; cin>>h1; char x; cin>>x;
	int m1; cin>>m1;
	while(true){
		if(valid(h1,m1,h,m,check)){
			return ;
		}
		m1=(m1+1)%m;
		if(m1==0) h1=(h1+1)%h;
		///cout <<h1<<" "<<m1<<endl;
	}
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;   cin>>t;
    for(int it=1;it<=t;it++){
    	solve();
	}
}



