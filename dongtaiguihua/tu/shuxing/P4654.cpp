#include<cstdio>
#include<iostream>
using namespace std;
const int N=1000003;
int to[N<<1];
int nex[N<<1];
int head[N];
int ent;
int dp[N];
int fa[N];
int du[N];
bool yes[N];
int val[N];
int num[N];
int m,total;
void adde(int a,int b){
    ent++;
    to[ent] = b;
    nex[ent] = head[a];
    head[a] = ent;
} 
void dfs0(int s,int f){
    int i;
    fa[s] = f;
    if(s==m){yes[s] = 1;}
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f)continue;
        du[s]++;
        dfs0(to[i],s);
        if(yes[to[i]]){
            yes[s]=1;
            du[s]--;
        }
    }
    if(yes[s]){total+=du[s];}
}
void dfs1(int s){
    int i,ma1=0,ma2=0;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==fa[s])continue;
        dfs1(to[i]);
        if(dp[to[i]]>ma1){
            ma2 = ma1;
            ma1 = dp[to[i]];
        }
        else if(dp[to[i]]>ma2){
            ma2 = dp[to[i]];
        }
    }
    dp[s] = ma2+du[s];
}
int main(){
    int n,i,a,b,t,l,r,mid,c;
    bool ok;
    scanf("%d %d %d",&n,&t,&m);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dfs0(t,0);
    a = 1;ent = 0;total-=du[t];b = 0;
    while(1){
        if(m==t)break;
        for(i=head[m];i;i=nex[i]){
            if(to[i]==fa[m] || yes[to[i]])continue;
            dfs1(to[i]);
            ent++;
            val[ent] = dp[to[i]]+total-du[b];
        }
        num[a] = ent;
        du[fa[m]]+=du[m];
        b = m;
        m = fa[m];
        a++;
    }
    l = 0;r = n;
    while(l<r){
        mid = (l+r)>>1;
        i = 1;ok = 1;t = mid;
        for(c=1;c<a;c++){
            b=0;
            for(i=num[c-1]+1;i<=num[c];i++){
                if(val[i]>t)b++;
            }
            if(b+mid-t>c){ok = 0;break;}
            t = t-b;
            if(t<0){ok = 0;break;}
        }
        if(ok){r = mid;}
        else{l = mid+1;}
    }
    printf("%d",l);
    return 0;
}