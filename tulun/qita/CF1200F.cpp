#include<iostream>
#include<cstdio>
using namespace std;
const int N=1003;
const int M=2520;
int du[N];
int zhi[N];
int go[N*3000];
int to[N][12];
int vis[N*3000];
int siz[N*3000];
int chuxian[N];
int zhan[N*3000],top;
int main(){
	int n,i,j,k,a,s,q;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&zhi[i]);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&du[i]);
		zhi[i]=((zhi[i]%M)+M)%M;
		for(j=0;j<du[i];j++){
			scanf("%d",&to[i][j]);
		}
	}
	for(i=1;i<=n;i++){
		for(j=0;j<M;j++){
			k = (j+zhi[i])%M;
			go[j*n+i]=k*n+to[i][k%du[i]];
		}
	}
	for(i=1;i<=n;i++){
		for(j=0;j<M;j++){
			k = j*n+i;
			if(!vis[k]){
				a = k;
				while(1){
					if(vis[a]){break;}
					zhan[++top]=a;
					vis[a]=1;
					a = go[a];
				}
				if(vis[a]==1){
					for(k=1;k<=top;k++){
						if(zhan[k]==a){break;}
					}
					s = 0;
					for(;k<=top;k++){
						a = (zhan[k]-1)%n+1;
						if(chuxian[a]==0){
							s++;
							chuxian[a]=1;
						}
					}
					for(k=1;k<=top;k++){
						a = (zhan[k]-1)%n+1;
						chuxian[a]=0;
					}
				}
				else{s=siz[a];}
				for(k=1;k<=top;k++){
					vis[zhan[k]]=2;
					siz[zhan[k]]=s;
				}
				top=0;
			}
		}
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&i,&j);
		k = (j%M+M)%M*n+i;
		printf("%d\n",siz[k]);
	}
	return 0;
}