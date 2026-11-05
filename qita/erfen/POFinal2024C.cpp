#include<iostream>
#include<cstdio>
using namespace std;
const int N=300003;
int row[N];
int line[N];
int erfen(int s,int * t,int n){
    int l=0,r=n+1,mid,i,now;
    while(l<r){
        mid = (l+r)>>1;
        now = 0;
        for(i=1;i<=n;i++){
            now = now+t[i];
            now = max(now,0);
            now = min(now,mid);
        }
        if(now>=s){r = mid;}
        else{l = mid+1;}
    }
    if(l==n+1){return -2;}
    return l;
}
int main(){
    int k,nr=0,nl=0,r,l,n,m;
    char c;
    scanf("%d\n",&k);
    for(r=1;r<=k;r++){
        c = getchar();
        switch(c){
            case '^':
                row[++nr]=-1;
                break;
            case '>':
                line[++nl]=1;
                break;
            case '<':
                line[++nl]=-1;
                break;
            case 'v':
                row[++nr]=1;
                break;
        }
    }
    scanf("%d %d",&r,&l);
    n = erfen(r,row,nr);
    m = erfen(l,line,nl);
    n++;m++;
    if(n<0 || m<0){printf("-1");}
    else{printf("%lld",(long long)n*(long long)m);}
    return 0;
}