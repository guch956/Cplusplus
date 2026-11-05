#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200003;
int head[N];
int tail[N];
int main(){
    int n,m,i,j,ans=0,k;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++)scanf("%d",&head[i]);
    for(i=1;i<=m;i++)scanf("%d",&tail[i]);
    sort(head+1,head+n+1);
    sort(tail+1,tail+m+1);
    i = n;
    for(j=m;j>=1;j--){
        while(head[i]>tail[j]){i--;}
        if(i!=0){
            ans++;
            i--;
        }
    }
    if(ans>=k)cout<<"Yes";
    else cout<<"No";
    return 0;
}