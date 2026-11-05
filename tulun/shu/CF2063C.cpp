#include<iostream>
#include<cstdio>
using namespace std;
const int N=200003;
int edge[N][2];
int du[N];
int lian[N];
int main(){
    int n,T,i,m1,m2,m3,ans;
    scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        m1 = m2 = m3 = ans = 0;
        for(i=1;i<n;i++){
            scanf("%d %d",&edge[i][0],&edge[i][1]);
            du[edge[i][0]]++;
            du[edge[i][1]]++;
        }
        if(n==2){
            printf("0\n");
            du[1]=du[2]=0;
            continue;
        }
        for(i=1;i<=n;i++){
            if(du[i]>du[m1]){
                m3 = m2;
                m2 = m1;
                m1 = i;
            }
            else if(du[i]>du[m2]){
                m3 = m2;
                m2 = i;
            }
            else if(du[i]>du[m3]){
                m3 = i;
            }
        }
        for(i=1;i<n;i++){
            if(edge[i][0]==m1){lian[edge[i][1]]=1;}
            if(edge[i][1]==m1){lian[edge[i][0]]=1;}
        }
        if(lian[m2]==0){ans=du[m1]+du[m2]-1;}
        else{
            if(lian[m3]==0){
                ans = max(du[m1]+du[m2]-2,du[m1]+du[m3]-1);
            }
            else{
                ans = max(du[m1]+du[m2]-2,du[m2]+du[m3]-1);
                for(i=1;i<=n;i++){
                    if(i!=m1 && i!=m2 && i!=m3 && lian[i]==0){ans = max(ans,du[m1]+du[i]-1);}
                }
            }
        }
        printf("%d\n",ans);
        for(i=1;i<=n;i++){du[i]=lian[i]=0;}
    }
    return 0;
}