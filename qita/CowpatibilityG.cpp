#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const int N=50003;
int subsets[N*31][5];
int cnt[N*20];
int ent;
int t1[N*31],t2[N*31];
bool check(int a){
    int j,an=0;
    for(j=0;j<=4;j++){
        if(subsets[a][j]!=0){
            an++;
        }
    }
    return an&1;
}
bool bijiao(int a,int b){
    int j;
    for(j=0;j<=4;j++){
        if(subsets[a][j]!=subsets[b][j]){
            return true;
        }
    }
    return false;
}
int main(){
    int a[5],i,j,k,b;
    int *x=t1,*y=t2;
    ll ans,num,n;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        for(j=0;j<=4;j++){
            scanf("%d",&a[j]);
        }
        sort(a,a+5);
        for(k=1;k<=31;k++){
            b=0;
            j=0;
            while(b<=4){
                if(k&(1<<b)){
                    subsets[ent][j]=a[b];
                    j++;
                }
                b++;
            }
            ent++;
        }
    }
    for(i=0;i<ent;i++){
        x[i]=i;
    }
    for(j=0;j<5;j++){
        memset(cnt,0,sizeof(cnt));
        for(i=0;i<ent;i++){
            cnt[subsets[i][j]]++;
        }
        for(i=0;i<=1e6;i++){
            cnt[i]=cnt[i]+cnt[i-1];
        }
        for(i=ent-1;i>=0;i--){
            cnt[subsets[x[i]][j]]--;
            y[cnt[subsets[x[i]][j]]]=x[i];
        }
        swap(x,y);
    }
    ans=n*(n-1)/2;
    num=0;
    for(i=0;i<ent;i++){
        num++;
        if(bijiao(x[i],x[i+1])){
            if(check(x[i])){
                ans-=num*(num-1)/2;
            }
            else{
                ans+=num*(num-1)/2;
            }
            num=0;
        }
    }
    printf("%lld",ans);
    return 0;
}
