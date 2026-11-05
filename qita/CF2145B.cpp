#include<iostream>
#include<cstdio>
using namespace std;
const int N=200003;
char s[N];
int main(){
    int T,n,t,i,k,lef,rig,mid,b;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&k);
        scanf("%s",s);
        lef=rig=mid=0;
        for(i=0;i<k;i++){
            if(s[i]=='0') lef++;
            else if(s[i]=='1') rig++;
            else mid++;
        }
        t = lef+mid;
        b = n-rig-mid;
        for(i=1;i<=lef;i++){printf("-");}
        if(t<=b){
            for(i=lef+1;i<=t;i++){printf("?");}
            for(i=t+1;i<=b;i++){printf("+");}
            for(i=b+1;i<=n-rig;i++){printf("?");}
        }
        else{
            if(k==n){for(i=lef+1;i<=n-rig;i++)printf("-");}
            else{for(i=lef+1;i<=n-rig;i++)printf("?");}
        }
        for(i=n-rig+1;i<=n;i++){printf("-");}
        printf("\n");
    }
    return 0;
}