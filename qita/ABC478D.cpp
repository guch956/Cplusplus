#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=200003;
int head[N];
int nex[N];
int lef[N],rig[N];
int ans[N];
int ent;
void add(int u,int l,int r){
    ent++;
    nex[ent] = head[u];
    lef[ent] = l;
    rig[ent] = r;
    head[u] = ent;
}
struct qujian{
    int l;
    int r;
    bool operator < (const qujian & q1){
        return l<q1.l;
    }
}p[N];
int main(){
    int n,q,i,l,r,x,j;
    scanf("%d %d",&n,&q);
    for(i=1;i<=q;i++){
        scanf("%d %d %d",&l,&r,&x);
        add(x,l,r);
    }
    for(i=1;i<=q;i++){
        x = 0;
        for(j=head[i];j;j=nex[j]){
            p[x].l = lef[j];
            p[x++].r = rig[j];
        }
        sort(p,p+x);
        p[x].l = n+1;
        r = 0;l = p[0].l;
        for(j=0;j<x;j++){
            r = max(r,p[j].r);
            if(r<p[j+1].l){
                ans[l]++;
                ans[r+1]--;
                l = p[j+1].l;
                r = 0;
            }
        }
    }
    for(i=1;i<=n;i++){
        ans[i] = ans[i-1]+ans[i];
        printf("%d ",ans[i]);
    }
    return 0;
}