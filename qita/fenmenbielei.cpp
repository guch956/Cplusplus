#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
    int geshu;
    int zhi;
};
bool bijiao(node & n1,node & n2){
    return n1.geshu<n2.geshu;
}
int A[1003];
node num[1003];
int huafen[1003];
int fenge[1003];
int main(){
    int T,n,i,sum,m,ma,ent,ans,j;
    scanf("%d",&T);
    A[0]=-1;
    while(T--){
        scanf("%d",&n);
        sum = n;m = 0;ma = 0;ent = 0,ans = 0;
        for(i=1;i<=n;i++){
            scanf("%d",&A[i]);
        }
        sort(A+1,A+n+1);
        for(i=1;i<=n;i++){
            if(A[i]!=A[i-1]){m++;num[m].zhi=A[i];num[m].geshu=0;}
            num[m].geshu++;
        }
        for(i=1;i<=m;i++){
            ma = max(ma,num[i].geshu);
        }
        if(2*ma>sum || (sum&1)){printf("-1\n");continue;}
        while(sum){
            ans++;
            sort(num+1,num+m+1,bijiao);
            ma=num[m].geshu-1;
            for(i=m;i>1;i-=2){
                if((!num[i].geshu) || (!num[i-1].geshu)){break;}
                if(2*ma<=sum-2){
                    sum-=2;
                    huafen[++ent]=num[i].zhi;
                    huafen[++ent]=num[i-1].zhi;
                    num[i].geshu--;
                    num[i-1].geshu--;
                }
            }
            fenge[ans]=ent;
        }
        printf("%d\n",ans);
        for(i=1;i<=ans;i++){
            printf("%d",fenge[i]-fenge[i-1]);
            for(j=fenge[i-1]+1;j<=fenge[i];j++){
                printf(" %d",huafen[j]);
            }
            printf("\n");
        }
    }
    return 0;
}