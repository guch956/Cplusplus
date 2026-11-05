#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=1000003;
ll A[N];
int B[N];
int main(){
	int T,n,i;
	ll m,sum,d,num,now,leave;
	scanf("%d",&T);
	while(T--){
		scanf("%d %lld %lld",&n,&d,&m);
		for(i=1;i<=n;i++)scanf("%d",&B[i]);
		sum = 0;num = 0;now = 0;
		for(i=1;i<=n;i++){
			if(B[i]==1){
				if(num)now+=d;
				num=0;
				A[i]=now;
			}
			else{
				num++;
				A[i]=now+1;
			}
			sum+=A[i];
		}
		if(sum>m){
			printf("No\n");
			continue;
		}
		leave = m-sum;
		A[n]+=leave/d*d;
		leave = leave%d;
		for(i=n;i>=1;i--){
			if(B[i]==0){
				if(leave<d-1){
					A[i]+=leave;
					leave=0;
				}
				else{
					A[i]+=d-2;
					leave=1;
				}
			}
		}
		if(leave>0)printf("No\n");
		else{
			for(i=1;i<=n;i++)printf("%lld ",A[i]);
			printf("\n");
		}
	}
	return 0;
}
