#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1000003;
char s1[N];
int t1[N<<1],t2[N<<1],cnt[N],sa[N];
void getsa(char * s){
    int n=strlen(s),m=128,i,k,*x=t1,*y=t2,p;
    for(i=0;i<n;i++){
        x[i]=s[i];
        cnt[x[i]]++;
    }
    for(i=1;i<=m;i++){cnt[i]+=cnt[i-1];}
    for(i=n-1;i>=0;i--){
        sa[--cnt[x[i]]]=i;
    }
    for(k=1;k<=n;k=k*2){
        p = 0;
        for(i=0;i<=m;i++){cnt[i]=0;}
        for(i=n-k;i<n;i++){y[p++]=i;}
        for(i=0;i<n;i++){if(sa[i]>=k){y[p++]=sa[i]-k;}}
        for(i=0;i<n;i++){cnt[x[y[i]]]++;}
        for(i=1;i<=m;i++){cnt[i]+=cnt[i-1];}
        for(i=n-1;i>=0;i--){
            sa[--cnt[x[y[i]]]]=y[i];
        }
        swap(x,y);
        p = 1;x[sa[0]]=0;
        for(i=1;i<n;i++){
            x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++;
        }
        if(p>=n){break;}
        m = p;
    }
}
int main(){
    int n;
    scanf("%s",s1);
    getsa(s1);
    n = strlen(s1);
    for(int i=0;i<n;i++){
        printf("%d ",sa[i]+1);
    }
    return 0;
}
