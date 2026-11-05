#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=200003;
ll sum[N];
int main(){
	int n,i,l,r,q;
	int pingyi=0;
	ll ans,s;
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++){
		scanf("%lld",&s);
		sum[i] = sum[i-1]+s;
	}
	while(q--){
		scanf("%d",&i);
		if(i==1){
			scanf("%d",&r);
			pingyi = (pingyi+r-1)%n+1; 
		}
		else{
			scanf("%d %d",&l,&r);
			l = (l+pingyi-1)%n+1;
			r = (r+pingyi-1)%n+1;
			ans = sum[r]-sum[l-1];
			if(l>r){ans = sum[n]+ans;}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
