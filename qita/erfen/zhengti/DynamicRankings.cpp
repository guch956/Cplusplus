#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200003;
int num;
int tree[N];
inline int lowbit(int x){return x&(-x);}
int chaxun(int x){
    int ans=0;
    while(x){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}
void update(int x,int d){
    while(x<=num){
        tree[x]+=d;
        x+=lowbit(x);
    }
}
struct node{
    int id;
    int val;
}p[N<<2];
bool bijiao(node & n1,node & n2){
    return n1.val<n2.val;
}
struct {
    bool type;
    int x;
    int y;
    int k;
    int id;
}qu[N<<2],q1[N<<2],q2[N<<2];
int ent,entp;
int A[N];
void addp(int x,int i){
    entp++;
    p[entp].id=i;
    p[entp].val=x;
}
void add(int ty,int x,int y,int k,int i){
    ent++;
    qu[ent].type=ty;
    qu[ent].x=x;
    qu[ent].y=y;
    qu[ent].k=k;
    qu[ent].id=i;
    if(ty==0){addp(y,ent);}
}
int ans[N];
void solve(int l,int r,int L,int R){
    if(L>R){return ;}
    if(l>r){return ;}
    int i;
    if(l==r){
        for(i=L;i<=R;i++){
            if(qu[i].type==1){ans[qu[i].id]=l;}
        }
        return ;
    }
    int mid=(l+r)>>1,ent1=0,ent2=0,t;
    for(i=L;i<=R;i++){
        if(qu[i].type==1){
            t = qu[i].k-chaxun(qu[i].y)+chaxun(qu[i].x-1);
            if(t<=0){q1[++ent1]=qu[i];}
            else{
                qu[i].k=t;
                q2[++ent2]=qu[i];
            }
        }
        else{
            if(qu[i].y<=mid){
                update(qu[i].x,qu[i].k);
                q1[++ent1]=qu[i];
            }
            else{q2[++ent2]=qu[i];}
        }
    }
    for(i=1;i<=ent1;i++){
        qu[L+i-1]=q1[i];
        if(q1[i].type==0){update(q1[i].x,-q1[i].k);}
    }
    for(i=1;i<=ent2;i++){
        qu[L+ent1+i-1]=q2[i];
    }
    solve(l,mid,L,L+ent1-1);
    solve(mid+1,r,L+ent1,R);
}
int main(){
    int n,q,i,j,a,b,d,m=0;
    char c;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
        add(0,i,A[i],1,0);
    }
    for(i=1;i<=q;i++){
        c = getchar();
        j = i+n;
        while(c!='C' && c!='Q'){
            c = getchar();
        }
        if(c=='C'){
            scanf("%d %d",&a,&b);
            add(0,a,A[a],-1,0);
            add(0,a,b,1,0);
            A[a]=b;
        }
        else{
            scanf("%d %d %d",&a,&b,&d);
            add(1,a,b,d,++m);
        }
    }
    sort(p+1,p+entp+1,bijiao);
    p[0].val=-1;
    for(i=1;i<=entp;i++){
        if(p[i].val!=p[i-1].val){
            num++;
            p[num].val=p[i].val;
        }
        qu[p[i].id].y=num;
    }
    solve(1,num,1,ent);
    for(i=1;i<=m;i++){
        printf("%d\n",p[ans[i]].val);
    }
    return 0;
}