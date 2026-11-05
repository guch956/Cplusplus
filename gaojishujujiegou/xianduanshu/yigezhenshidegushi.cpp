#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=50003;
int treel[N<<2][31][2];
int treer[N<<2][31][2];
int treem[N<<2];
int chuxian[31];
int n,k;
int A[N];
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
void fuzhi(int p,int pl,int d){
    treel[p][1][0]=treer[p][1][0]=d;
    treel[p][1][1]=treer[p][1][1]=pl;
    for(int i=2;i<=d;i++){
        treel[p][i][0]=treer[p][i][0]=i-1;
        treel[p][i][1]=INF;
        treer[p][i][1]=-INF;
    }
    for(int i=d+1;i<=k;i++){
        treel[p][i][0]=treer[p][i][0]=i;
        treel[p][i][1]=INF;
        treer[p][i][1]=-INF;
    }
    treem[p]= k==1?1:INF;
}
void push_up(int p){
    int i,j,t;
    memset(chuxian,0,sizeof(chuxian));
    for(i=1;i<=k;i++){
        if(treel[ls(p)][i][1]<=n){
            treel[p][i][1]=treel[ls(p)][i][1];
            treel[p][i][0]=treel[ls(p)][i][0];
            chuxian[treel[p][i][0]]=1;
        }
        else{
            t = 1;
            for(j=1;j<=k;j++){
                if(!chuxian[treel[rs(p)][j][0]]){
                    treel[p][i+t-1][1]=treel[rs(p)][j][1];
                    treel[p][i+t-1][0]=treel[rs(p)][j][0];
                    t++;
                }
            }
            break;
        }
    }
    memset(chuxian,0,sizeof(chuxian));
    for(i=1;i<=k;i++){
        if(treer[rs(p)][i][1]>0){
            treer[p][i][1]=treer[rs(p)][i][1];
            treer[p][i][0]=treer[rs(p)][i][0];
            chuxian[treer[p][i][0]]=1;
        }
        else{
            t = 1;
            for(j=1;j<=k;j++){
                if(!chuxian[treer[ls(p)][j][0]]){
                    treer[p][i+t-1][1]=treer[ls(p)][j][1];
                    treer[p][i+t-1][0]=treer[ls(p)][j][0];
                    t++;
                }
            }
            break;
        }
    }
    treem[p]=min(treem[ls(p)],treem[rs(p)]);
    for(i=1;i<=k;i++){
        chuxian[i]=1;
    }
    j=1;chuxian[treel[rs(p)][j][0]]++;
    for(i=k;i>=1;i--){
        treem[p]=min(treem[p],treel[rs(p)][j][1]-treer[ls(p)][i][1]+1);
        chuxian[treer[ls(p)][i][0]]--;
        if(chuxian[treer[ls(p)][i][0]]==0){
            while(1){
                j++;
                chuxian[treel[rs(p)][j][0]]++;
                if(treer[ls(p)][i][0]==treel[rs(p)][j][0]){
                    break;
                }
            }
        }
    }
}
void build(int p,int pl,int pr){
    if(pl==pr){
        fuzhi(p,pl,A[pl]);
        return ;
    }
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}
void update(int p,int pl,int pr,int x,int d){
    if(pl==pr){
        fuzhi(p,pl,d);
        return ;
    }
    int mid=(pl+pr)>>1;
    if(x<=mid){update(ls(p),pl,mid,x,d);}
    if(x>mid){update(rs(p),mid+1,pr,x,d);}
    push_up(p);
}
int main(){
    int i,T,a,b;
    scanf("%d %d %d",&n,&k,&T);
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
    }
    build(1,1,n);
    while(T--){
        scanf("%d",&i);
        if(i==1){
            scanf("%d %d",&a,&b);
            update(1,1,n,a,b);
        }
        else{
            if(treem[1]>n){
                printf("-1\n");
            }
            else{
                printf("%d\n",treem[1]);
            }
        }
    }
    return 0;
}
