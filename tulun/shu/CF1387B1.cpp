#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=100003;
int inque[N];
int head[N],to[N<<1],nex[N<<1],finish[N],ent;
int du[N];
int zhan[N];
int weizhi[N];
void adde(int u,int v){
    ent++;
    nex[ent]=head[u];
    to[ent]=v;
    head[u]=ent;
}
int main(){
    int n,i,a,b,m,ans=0;
    queue<int> q;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
        du[a]++;
        du[b]++;
    }
    for(i=1;i<=n;i++){
        if(du[i]==1){q.push(i);inque[i]=1;}
    }
    while(q.size()){
        b = q.front();
        q.pop();
        if(finish[b]){continue;}
        m = 0;
        for(i=head[b];i;i=nex[i]){
            if(!finish[to[i]]){a = to[i];}
        }
        finish[a]=1;
        inque[a]=0;
        for(i=head[a];i;i=nex[i]){
            if(inque[to[i]] && !finish[to[i]]){
                zhan[++m]=to[i];
                finish[to[i]]=1;
                inque[to[i]]=0;
            }
            else if(!inque[to[i]]){
                du[to[i]]--;
                if(du[to[i]]==1){
                    q.push(to[i]);
                    inque[to[i]]=1;
                }
            }
        }
        ans+=2*m;
        if(m&1){
            weizhi[a]=zhan[1];
            weizhi[zhan[1]]=a;
            for(i=2;i<m;i+=2){
                weizhi[zhan[i]]=weizhi[zhan[i+1]];
                weizhi[zhan[i+1]]=weizhi[zhan[i]];
            }
        }
        else{
            weizhi[a]=zhan[1];
            weizhi[zhan[1]]=zhan[2];
            weizhi[zhan[2]]=a;
        }
        for(i=3-(m&1);i<m;i+=2){
            weizhi[zhan[i]]=zhan[i+1];
            weizhi[zhan[i+1]]=zhan[i];
        }
    }
    printf("%d\n",ans);
    for(i=1;i<=n;i++){
        printf("%d ",weizhi[i]);
    }
    return 0;
}
