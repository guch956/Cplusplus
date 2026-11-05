#include<iostream>
#include<cstdio>
#include<cmath>
#define ll long long
const int N=2e6;
struct {
    int ls;
    int rs;
    ll begin;
    ll len;
    ll siz;
    int pri;
}t[N];
int ent;
int root[N],root0;
void update(int x){t[x].siz=t[t[x].ls].siz+t[t[x].rs].siz+t[x].len;}
int newnode(ll b,ll l){
    ent++;
    t[ent].begin=b;
    t[ent].len=l;
    t[ent].siz=l;
    t[ent].pri=rand();
    return ent;
}
int fenlie(int u,ll k,int & L,int & R){
    if(u==0){L=R=0;return 0;}
    if(k>t[t[u].ls].siz){
        L = u;
        int v=fenlie(t[u].rs,k-t[t[u].ls].siz-t[u].len,t[L].rs,R);
        update(u);
        if(v){return v;}
        return L;
    }
    else{
        R = u;
        int v=fenlie(t[u].ls,k,L,t[R].ls);
        update(u);
        return v;
    }
}
int hebing(int L,int R){
    if(L==0 || R==0){return L+R;}
    if(t[L].pri>t[R].pri){
        t[L].rs=hebing(t[L].rs,R);
        update(L);
        return L;
    }
    else{
        t[R].ls=hebing(L,t[R].ls);
        update(R);
        return R;
    }
}
int get(int u,ll k){
    int x=u;
    while(1){
        if(k<=t[t[x].ls].siz){x=t[x].ls;}
        else if(k>t[t[x].ls].siz+t[x].len){
            x = t[x].rs;
            k-=t[t[x].ls].siz+t[x].len;
        }
        else{break;}
    }
    return x;
}
int main(){
    ll n,m,i,b,a,d,f;
    int q,L,R,c,p,r,L0,R0;
    scanf("%lld %lld %d",&n,&m,&q);
    for(i=1;i<=n;i++){
        root[i]=newnode(1+m*(i-1),m-1);
        root0=hebing(root0,newnode(i*m,1));
    }
    while(q--){
        scanf("%lld %lld",&a,&b);
        if(b<m){
            c = fenlie(root[a],b,L,R);
            d = t[c].begin+b+t[c].len-t[L].siz-1;
            printf("%lld\n",d);
            p = fenlie(L,t[L].siz-t[c].len,L,c);
            if(d==t[c].begin){
                t[c].begin++;
                t[c].len--;
                t[c].siz--;
                if(!t[c].len){c = 0;}
            }
            else if(d==t[c].begin+t[c].len-1){
                t[c].len--;
                t[c].siz--;
                if(!t[c].len){c = 0;}
            }
            else{
                f = t[c].begin+t[c].len-1-d;
                t[c].len=d-t[c].begin;
                t[c].siz=t[c].len;
                c = hebing(c,newnode(d+1,f));
            }
            p = fenlie(root0,a,L0,R0);
            r = fenlie(L0,a-1,L0,p);
            root[a]=hebing(L,hebing(c,hebing(R,p)));
            root0=hebing(L0,hebing(R0,newnode(d,1)));
        }
        else{
            p = fenlie(root0,a,L0,R0);
            r = fenlie(L0,a-1,L0,p);
            t[p].pri=rand();
            printf("%lld\n",t[p].begin);
            root0=hebing(L0,hebing(R0,p));
        }
    }
    return 0;
}