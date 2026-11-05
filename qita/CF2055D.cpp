#include<iostream>
#include<cstdio>
using namespace std;
const int N=200003;
int weizhi[N];
int tim[N];
int dao[N];
int main(){
    int T,i,n,k,l,ans,t;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d",&n,&k,&l);
        k = k<<1;l = l<<1;
        for(i=1;i<=n;i++){
            scanf("%d",&weizhi[i]);
            weizhi[i]=weizhi[i]<<1;
        }
        dao[1]=k;
        tim[1]=weizhi[1];
        ans = tim[1]+max(0,l-dao[1]);
        for(i=2;i<=n;i++){
            if(weizhi[i]+tim[i-1]<dao[i-1]){
                dao[i]=weizhi[i]+tim[i-1]+k;
                tim[i]=tim[i-1];
            }
            else if(dao[i-1]+tim[i-1]<weizhi[i]){
                t = (weizhi[i]-tim[i-1]-dao[i-1])/2;
                dao[i]=dao[i-1]+t+k;
                tim[i]=tim[i-1]+t;
            }
            else{
                tim[i]=tim[i-1];
                dao[i]=dao[i-1]+k;
            }
            ans = min(ans,tim[i]+max(0,l-dao[i]));
        }
        printf("%d\n",ans);
    }
    return 0;
}