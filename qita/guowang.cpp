#include<iostream>
long long A[500],B[500],d,dp[500][100][100];
void jisuan(int n){
	int i,x,y;
	for(i=0;i<(1<<n);i++){
		x = 0;
		if((i&(i<<1)) == 0){
			y = i;
			A[d]=i;
			while(y>0){
				x += y&1;
				y = y>>1;
			}
			B[d]=x;
			d++;
		}
	}
}
int main(){
	using namespace std;
	int n,k,m,i,j,h;
    long long ans=0;
	cin>>n>>k;
	jisuan(n);
	for(i=0;i<d;i++){
		if(B[i]<=k){
			dp[A[i]][B[i]][0]=1;
		}
	}
	for(j=1;j<n;j++){
		for(i=0;i<d;i++){
			for(m=B[i];m<=k;m++){
				for(h=0;h<d;h++){
					if ( ((A[i]&A[h])==0) && ((A[i]&(A[h]<<1))==0) && (((A[i]<<1)&A[h])==0)){
						dp[A[i]][m][j] = dp[A[i]][m][j]+dp[A[h]][m-B[i]][j-1];
					}
				}
			}
		}
	}
	for(i=0;i<d;i++){
		ans  = ans+dp[A[i]][k][j-1];
	}
	cout<<ans;
	return 0;
}