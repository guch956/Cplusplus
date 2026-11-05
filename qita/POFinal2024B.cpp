#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
int qujian[N][2];
int main(){
    int n,S,T,i,j=0,ans=0,sum=0;
    scanf("%d %d %d",&n,&S,&T);
    for(i=1;i<=n;i++){
        scanf("%d %d",&qujian[i][0],&qujian[i][1]);
    }
    for(i=1;i<=n;i++){
        sum+=qujian[i][1]-qujian[i][0];
        while(qujian[j][1]<=qujian[i][1]-T){j++;sum-=qujian[j][1]-qujian[j][0];}
        ans = max(ans,sum+qujian[j][1]-max(qujian[j][0],qujian[i][1]-T));
    }
    ans = T-ans;
    printf("%d",ans);
    return 0;
}