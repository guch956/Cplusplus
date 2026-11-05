#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000003;
int nex[N],head[N],to[N],ent;
int black[N];
int weizhi[N];
int you[N];
int vis[N];
int dao[N];
int zhan[N];
int len;
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
int dfs(int s){
    int i,an=0;
    vis[s]=1;
    if(you[weizhi[s]]==0 && black[s]){an++;you[weizhi[s]]=1;}
    for(i=head[s];i;i=nex[i]){
        if(vis[to[i]]==0){
            weizhi[to[i]]=(weizhi[s]+len-1)%len;
            an+=dfs(to[i]);
        }
    }
    return an;
}
int main(){
    int T,i,m,n,j,a,ans1,ans2,top,beg;
    char c;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&m);
        ans1=ans2=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                c = getchar();
                while(c!='0' && c!='1'){c = getchar();}
                if(c=='0'){black[(i-1)*m+j]=1;}
                else{black[(i-1)*m+j]=0;}
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                c = getchar();
                while(c!='U' && c!='R' && c!='D' && c!='L'){c = getchar();}
                a = (i-1)*m+j;
                switch(c){
                    case 'U':
                        adde(a-m,a);
                        dao[a]=a-m;
                        break;
                    case 'R':
                        adde(a+1,a);
                        dao[a]=a+1;
                        break;
                    case 'D':
                        adde(a+m,a);
                        dao[a]=a+m;
                        break;
                    case 'L':
                        adde(a-1,a);
                        dao[a]=a-1;
                        break;
                }   
            }
        }
        n = n*m;
        for(i=1;i<=n;i++){
            if(vis[i]==0){
                a = i;
                top=0;
                while(vis[a]==0){
                    vis[a]=1;
                    zhan[++top]=a;
                    a = dao[a];
                }
                for(j=1;j<=top;j++){
                    if(zhan[j]!=a){vis[zhan[j]]=0;}
                    else{beg=j;break;}
                }
                len = top-beg+1;
                ans1+=len;
                for(j=0;j<len;j++){
                    weizhi[zhan[j+beg]]=j;
                    ans2+=dfs(zhan[j+beg]);
                }
                for(j=0;j<len;j++){
                    you[j]=0;
                }
            }
        }
        for(i=1;i<=n;i++){vis[i]=0;head[i]=0;}
        ent=0;
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}