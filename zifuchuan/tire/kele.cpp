#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000003;
const int LEN=20;
struct {
    int son[2];
    int siz;
}t[N*LEN];
int ent;
int p[40];
void getp(int x){
    for(int i=LEN-1;i>=0;i--){
        p[i]=x&1;
        x=x>>1;
    }
}
void insert(int *s){
    int i,now=0;
    for(i=0;i<LEN;i++){
        if(!t[now].son[s[i]]){
            t[now].son[s[i]]=++ent;
        }
        now = t[now].son[s[i]];
        t[now].siz++;
    }
}
int dfs(int now,int *s,int pos){
    if(pos==LEN-1){return t[now].siz;}
    if(s[pos]){
        if(t[now].son[0]==0 || t[now].son[1]==0){
            return t[t[now].son[0]+t[now].son[1]].siz;
        }
        else{
            return max(t[t[now].son[0]].siz+dfs(t[now].son[1],s,pos+1),
            t[t[now].son[1]].siz+dfs(t[now].son[0],s,pos+1));
        }
    }
    else{
        int ans=0;
        if(t[now].son[0]){
            ans=max(ans,dfs(t[now].son[0],s,pos+1));
        }
        if(t[now].son[1]){
            ans=max(ans,dfs(t[now].son[1],s,pos+1));
        }
        return ans;
    }
}
int main(){
    int n,k,a,i;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        getp(a);
        insert(p);
    }
    getp(k);
    printf("%d",dfs(0,p,0));
    return 0;
}