#include<iostream>
#include<cstdio>
using namespace std;
const int N=5002;
int dmin[N];
int dmax[N];
int fa[N];
void build(int l,int r,int sum){
    int i,a;
    sum-=r-l;
    fa[l+1]=l;
    if(sum==0){
        if(r>l+1){fa[r]=l;}
        return ;
    }
    for(i=0;i<=r-l;i++){
	    a = sum-dmin[r-l-i];
	    if(dmin[i]<=a && a<=dmax[i]){
            build(l+1,r-i,dmin[r-l-i]);
	        if(i){
                fa[r-i+1]=l;
		        build(r-i+1,r,a);
	        }
	        break;
	    }
	    a = sum-dmax[r-l-i];
	    if(dmin[i]<=a && a<=dmax[i]){
            build(l+1,r-i,dmax[r-l-i]);
            if(i){
                fa[r-i+1]=l;
                build(r-i+1,r,a);
            }
	        break;
        }
    }
}
int main(){
    int T,n,d=1,i,t=0;
    dmin[1]=dmax[1]=0;
    for(i=2;i<N;i++){
        if(i==d*2){
            d = d*2;
	        t++;
	    }
	    dmin[i]=dmin[i-1]+t;
	    dmax[i]=i*(i-1)/2;
    }
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&d);
	    if(d<dmin[n] || d>dmax[n]){
	        printf("NO\n");
	    }
	    else{
	        build(1,n,d);
	        printf("YES\n");
	        for(i=2;i<=n;i++){
                printf("%d ",fa[i]);
	        }
	        printf("\n");
	    }
    }
    return 0;
}
