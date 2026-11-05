#include<iostream>
#include<cstdio>
using namespace std;
const int N=600003;
const int LEN=24;
struct {
    int son[2];
    int siz;
}t[N*LEN];
int ent;
int root[N];
int sum[N];
int p[40];
void getp(int x){
    for(int i=LEN-1;i>=0;i--){
        p[i]=x&1;
        x=x>>1;
    }
}
int newnode(int si){
    ent++;
    t[ent].siz=si;
    return ent;
}
void insert(int *s,int k){
    int i,now=root[k-1],r=root[k];
    for(i=0;i<LEN;i++){
        t[r].son[s[i]]=newnode(t[t[now].son[s[i]]].siz+1);
        t[r].son[s[i]^1]=t[now].son[s[i]^1];
        now=t[now].son[s[i]];
        r=t[r].son[s[i]];
    }
}
int chaxun(int l,int r,int *s){
    int now1,now2=root[r-1],i,a1,a2;
    if(l==1){now1=0;}
    else{now1=root[l-2];}
    int ans=0;
    for(i=0;i<LEN;i++){
        a1=t[now1].son[s[i]^1];
        a2=t[now2].son[s[i]^1];
        if(t[a1].siz<t[a2].siz){
            ans+=1<<(LEN-i-1);
            now1=a1;
            now2=a2;
        }
        else{
            now1=t[now1].son[s[i]];
            now2=t[now2].son[s[i]];
        }
    }
    return ans;
}
int main(){
    int n,m,a,i,l,r;
    char c;
    root[0]=newnode(1);
    n = root[0];
    for(i=0;i<LEN;i++){
        t[n].son[0]=newnode(1);
        n = t[n].son[0];
    }
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        sum[i]=sum[i-1]^a;
        getp(sum[i]);
        root[i]=newnode(t[root[i-1]].siz+1);
        insert(p,i);
    }
    while(m--){
        cin>>c;
        if(c=='A'){
            scanf("%d",&a);
            n++;
            sum[n]=sum[n-1]^a;
            getp(sum[n]);
            root[n]=newnode(t[root[n-1]].siz+1);
            insert(p,n);
        }
        else{
            scanf("%d %d %d",&l,&r,&a);
            getp(sum[n]^a);
            printf("%d\n",chaxun(l,r,p));
        }
    }
    return 0;
}
