#include<iostream>
int A[100],B[100],d,dp[100][100][120],map[120];
void jisuan(int n){
	int i,x,y;
	for(i=0;i<(1<<n);i++){
		y = i;
		x = 0;
		if ( (i&(i<<1))==0 && (i&(i<<2))==0){
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
	int n,m,i,j,k,ans=0,l;
	char c;
	cin>>n>>m;
	jisuan(m);
	for(i=0;i<n;i++){
		k = 0;
		for(j=0;j<m;j++){
			cin>>c;
			k = k<<1;
			if(c=='H'){
				k++;
			}
		}
		map[i]=k;
	}
	if(n==1){
		for(i=0;i<d;i++){
			if((A[i]&map[0])==0)
				ans = max(ans,B[i]);
		}
		cout<<ans;
	}
	else{
		for(i=0;i<d;i++){
			if((A[i]&map[1])==0){
				for(j=0;j<d;j++){
					if((A[i]&A[j])==0 && (A[j]&map[0])==0){
						dp[i][j][1] = max(dp[i][j][1],B[i]+B[j]);
					}
				}
			}
		}
		for(k=2;k<n;k++){
			for(i=0;i<d;i++){
				if((A[i]&map[k])==0){
					for(j=0;j<d;j++){
						if((A[j]&map[k-1])==0){
							for(l=0;l<d;l++){
								if((A[i]&A[j])==0 && (A[i]&A[l])==0 && (A[j]&A[l])==0 && (A[l]&map[k-2])==0){
									dp[i][j][k] = max(dp[i][j][k],B[i]+dp[j][l][k-1]);
								}
							} 
					    }
					}
				}
			}
		}/*
		for(i=0;i<d;i++){
			for(j=0;j<d;j++){
				cout<<A[i]<<' '<<A[j]<<' '<<dp[A[i]][A[j]][1]<<endl;
			}
		}*/
		for(i=0;i<d;i++){
			for(j=0;j<d;j++){
				ans = max(ans,dp[i][j][n-1]);
			}
		}
		cout<<ans;
	}	
	
	return 0;
}