#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=10003;
int head[N],to[N*20],nex[N*20];
int ent;
int zhuangtai[N];
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
int main(){
    int n,m,i,a,b,ans=0,n2,n3;
    bool xing=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    for(i=1;i<=n;i++){
        if(zhuangtai[i]==0){
            n2=n3=0;
            queue<int> q;
            q.push(i);
            zhuangtai[i]=2;
            while(q.size()){
                a = q.front();
                q.pop();
                if(zhuangtai[a]==2){n2++;}
                else{n3++;}
                for(b=head[a];b;b=nex[b]){
                    if(zhuangtai[to[b]]==0){
                        zhuangtai[to[b]]=zhuangtai[a]^1;
                        q.push(to[b]);
                    }
                    else{
                        if(zhuangtai[to[b]]!=(zhuangtai[a]^1)){xing=1;break;}
                    }
                }
                if(xing){break;}
            }
            if(xing){break;}
            ans+=min(n2,n3);
        }
    }
    if(xing){printf("Impossible");}
    else{printf("%d",ans);}
    return 0;
}