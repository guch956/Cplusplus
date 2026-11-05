#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=300003;
int sum[N<<6],num[N<<6],ls1[N<<6],rs1[N<<6],val[N<<6],pri1[N<<6],ent1;
int tree[N];
inline int lowbit(int x){return x&(-x);}
int n;
struct {
    int ls;
    int rs;
    int le;
    int ri;
    int pri;
    int ti;
}t[N*3];
int ent2;
int zhuangtai[N];
void update1(int u){sum[u]=num[u]+sum[ls1[u]]+sum[rs1[u]];}
void fenlie1(int u,int k,int & L,int & R){
    if(u==0){L=R=0;return;}
    if(val[u]<=k){
        L = u;
        fenlie1(rs1[u],k,rs1[L],R);
    }
    else{
        R = u;
        fenlie1(ls1[u],k,L,ls1[R]);
    }
    update1(u);
}
int hebing1(int L,int R){
    if(L==0 || R==0){return L|R;}
    if(pri1[L]>pri1[R]){
        rs1[L]=hebing1(rs1[L],R);
        update1(L);
        return L;
    }
    else{
        ls1[R]=hebing1(L,ls1[R]);
        update1(R);
        return R;
    }
}
void add(int x,int r,int d){
    int L,R,T;
    while(x<=n){
        fenlie1(tree[x],r,L,R);
        fenlie1(L,r-1,L,T);
        if(!T){T=++ent1;pri1[T]=rand();val[T]=r;}
        num[T]+=d;
        sum[T]=num[T];
        tree[x]=hebing1(hebing1(L,T),R);
        x+=lowbit(x);
    }
}
int chaxun(int x,int r){
    int L,R,ans=0;
    while(x){
        fenlie1(tree[x],r-1,L,R);
        ans+=sum[R];
        tree[x]=hebing1(L,R);
        x-=lowbit(x);
    }
    return ans;
}
void fenlie(int u,int k,int & L,int & R){
    if(u==0){L=R=0;return ;}
    if(t[u].le<=k){
        L = u;
        fenlie(t[u].rs,k,t[L].rs,R);
    }
    else{
        R = u;
        fenlie(t[u].ls,k,L,t[R].ls);
    }
}
int hebing(int L,int R){
    if(L==0 || R==0){return L|R;}
    if(t[L].pri>t[R].pri){
        t[L].rs=hebing(t[L].rs,R);
        return L;
    }
    else{
        t[R].ls=hebing(L,t[R].ls);
        return R;
    }
}
int newnode(int l,int r,int tt){
    ent2++;
    t[ent2].le=l;
    t[ent2].ri=r;
    t[ent2].pri=rand();
    t[ent2].ti=tt;
    return ent2;
}
int main(){
    int q,i,l=0,r,L,R,root=0,a,b,ans;
    char c;
    char cc[8];
    scanf("%d %d\n",&n,&q);
    for(i=1;i<=n;i++){
        c = getchar();
        if(c=='0'){
            zhuangtai[i]=1;
            if(l){
                root=hebing(root,newnode(l,i-1,0));
                l = 0;
            }
        }
        else{
            zhuangtai[i]=2;
            if(!l){l = i;}
        }
    }
    if(l){root=hebing(root,newnode(l,n,0));}
    for(i=1;i<=q;i++){
        scanf("%s",cc);
        if(cc[0]=='q'){
            scanf("%d %d",&a,&b);
            ans=0;b--;
            fenlie(root,a,L,R);
            l = L;
            while(t[l].rs){l = t[l].rs;}
            if(t[l].le<=a && t[l].ri>=b){ans+=i-t[l].ti;}
            root=hebing(L,R);
            ans+=chaxun(a,b);
            printf("%d\n",ans);
        }
        else{
            scanf("%d",&a);
            fenlie(root,a,L,R);
            if(zhuangtai[a]==1){
                if(zhuangtai[a-1]<=1 && zhuangtai[a+1]<=1){
                    root=hebing(hebing(L,newnode(a,a,i)),R);
                }
                else if(zhuangtai[a-1]==2 && zhuangtai[a+1]==2){
                    fenlie(R,a+1,r,R);
                    add(t[r].le,t[r].ri,i-t[r].ti);
                    l = L;
                    while(t[l].rs){l = t[l].rs;}
                    add(t[l].le,t[l].ri,i-t[l].ti);
                    t[l].ri=t[r].ri;
                    t[l].ti=i;
                    root=hebing(L,R);
                }
                else if(zhuangtai[a-1]==2){
                    l = L;
                    while(t[l].rs){l = t[l].rs;}
                    add(t[l].le,t[l].ri,i-t[l].ti);
                    t[l].ri=a;
                    t[l].ti=i;
                    root=hebing(L,R);
                }
                else{
                    r = R;
                    while(t[r].ls){r = t[r].ls;}
                    add(t[r].le,t[r].ri,i-t[r].ti);
                    t[r].le=a;
                    t[r].ti=i;
                    root=hebing(L,R);
                }
                zhuangtai[a]=2;
            }
            else{
                if(zhuangtai[a-1]<=1 && zhuangtai[a+1]<=1){
                    fenlie(L,a-1,L,l);
                    add(t[l].le,t[l].ri,i-t[l].ti);
                    root=hebing(L,R);
                }
                else if(zhuangtai[a-1]==2 && zhuangtai[a+1]==2){
                    l = L;
                    while(t[l].rs){l = t[l].rs;}
                    add(t[l].le,t[l].ri,i-t[l].ti);
                    R = hebing(newnode(a+1,t[l].ri,i),R);
                    t[l].ri=a-1;
                    t[l].ti=i;
                    root=hebing(L,R);
                }
                else{
                    l = L;
                    while(t[l].rs){l = t[l].rs;}
                    add(t[l].le,t[l].ri,i-t[l].ti);
                    if(zhuangtai[a-1]==2){t[l].ri=a-1;}
                    else{t[l].le=a+1;}
                    t[l].ti=i;
                    root=hebing(L,R);
                }
                zhuangtai[a]=1;
            }
        }
    }
    return 0;
}