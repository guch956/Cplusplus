#include<iostream>
#include<cstdio>
using namespace std;
class sport{
private:
    int A[303][303];
    int zhizhen[303];
    int shan[303];
    int num[303];
    int m,n;
public:
    sport();
    int check();
};
sport::sport(){
    int i,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&A[i][j]);
        }
        A[i][m+1]=0;
    }
    shan[0]=0;
}
int sport::check(){
    int i,ma,j,ans=n+1,num_s=0;
    bool ok=false;
    for(i=1;i<=n;i++){
        zhizhen[i]=1;
    }
    for(i=1;i<=m;i++){
        shan[i]=0;
    }
    while(1){
        for(i=1;i<=m;i++){
            num[i]=0;
        }
        for(i=1;i<=n;i++){
            num[A[i][zhizhen[i]]]++;
        }
        ma = -1;
        for(i=1;i<=m;i++){
            if(num[i]>ma){
                ma = num[i];
                j = i;
            }
        }
        ans = min(ans,ma);
        shan[j]=1;
        num_s++;
        if(num_s==m)break;
        for(i=1;i<=n;i++){
            while(shan[A[i][zhizhen[i]]]){
                zhizhen[i]++;
            }
        }
    }
    return ans;
}
int main(){
    sport * a = new sport;
    printf("%d",a->check());
    return 0;
}