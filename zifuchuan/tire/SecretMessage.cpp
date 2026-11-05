#include<iostream>
#include<cstdio>
using namespace std;
const int N=500003;
struct {
    int son[2];
    int end;
    int pre;
}t[N];
int ent;
int s[10003];
void insert(int * p,int plen){
    int i,now=0;
    for(i=0;i<plen;i++){
        t[now].pre++;
        if(!t[now].son[p[i]]){
            t[now].son[p[i]]=++ent;
        }
        now=t[now].son[p[i]];
    }
    t[now].pre++;
    t[now].end++;
}
int chaxun(int * p,int plen){
    int i,now=0,ans=0;
    for(i=0;i<plen;i++){
        ans+=t[now].end;
        if(!t[now].son[p[i]]){
            return ans;
        }
        now =t[now].son[p[i]];
    }
    ans+=t[now].pre;
    return ans;
}
int main(){
    int n,m,i,l;
    scanf("%d %d",&n,&m);
    while(n--){
        scanf("%d",&l);
        for(i=0;i<l;i++){
            scanf("%d",&s[i]);
        }
        insert(s,l);
    }
    while(m--){
        scanf("%d",&l);
        for(i=0;i<l;i++){
            scanf("%d",&s[i]);
        }
        printf("%d\n",chaxun(s,l));
    }
    return 0;
}