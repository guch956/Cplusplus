#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200003;
const int INF=0x3f3f3f3f;
struct qj{
    int l;
    int r;
}q[N];
bool bijiao(qj & q1,qj & q2){
    return q1.l<q2.l;
}
int st[N][18];
int LOG2[N];
int sum[N];
int zuida(int l,int r){
    return max(st[l][LOG2[r-l+1]],st[r+1-(1<<LOG2[r-l+1])][LOG2[r-l+1]]);
}
int main(){
    int n,T,su=0,j,l1,r1,l,r,mid,k,i;
    scanf("%d %d",&n,&T);
    LOG2[0]=-1;
    q[0].r=-1;
    for(i=1;i<=n;i++){
        scanf("%d %d",&q[i].l,&q[i].r);
        LOG2[i]=LOG2[i>>1]+1;
    }
    sort(q+1,q+n+1,bijiao);
    for(i=1;i<=n;i++){
        st[i][0]=q[i].l-su;
        su+=q[i].r-q[i].l;
        sum[i]=su;
    }
    st[n+1][0]=INF;
    for(i=1;i<18;i++){
        su = 1<<(i-1);
        for(j=1;j<=n+1-su;j++){
            st[j][i]=max(st[j][i-1],st[j+su][i-1]);
        }
    }
    while(T--){
        scanf("%d %d",&l1,&r1);
        l=0;r=n;
        while(l<r){
            mid=(l+r+1)>>1;
            if(q[mid].r<=l1){
                l=mid;
            }
            else{
                r=mid-1;
            }
        }
        su=r1-sum[l];
        k = l+1;
        l=k;r=n+1;
        while(l<r){
            mid=(l+r)>>1;
            i = zuida(l,mid);
            if(zuida(l,mid)>=su){
                r = mid;
            }
            else{
                l=mid+1;
            }
        }
        printf("%d\n",l-k);
    }
    return 0;
}