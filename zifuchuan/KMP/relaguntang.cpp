#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=100003;
int n,m;
char s1[N],s2[N],s1r[N],s2r[N];
int Next1[N],Next2[N];
int pipei[N];
void get_next(int l,char * p,int * nex){
    int i,j;
    nex[0]=nex[1]=0;
    for(i=1;i<l;i++){
        j = nex[i];
        while(j && p[i]!=p[j]){j = nex[j];}
        if(p[i]==p[j]){nex[i+1]=j+1;}
        else{nex[i+1]=0;}
    }
}
void solve(){
    int i,j=0;
    get_next(n,s1,Next1);
    get_next(n,s1r,Next2);
    for(i=0;i<m;i++){
        while(j && s2r[i]!=s1r[j]){j = Next2[j];}
        if(s2r[i]==s1r[j]){j++;}
        pipei[i]=j;
    }
    j = 0;
    if(pipei[n-1]==n){printf("Yes\n");return ;}
    for(i=0;i<m;i++){
        while(j && s2[i]!=s1[j]){j = Next1[j];}
        if(s2[i]==s1[j]){j++;}
        if(j==i+1 && pipei[n-2-i]==n-1-i){
            printf("Yes\n");
            return ;
        }
    }
    printf("No\n");
    return ;
}
int main(){
    int T,i;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&m);
        scanf("%s",s1);
        scanf("%s",s2);
        for(i=0;i<n;i++){s1r[i]=s1[n-i-1];}
        for(i=0;i<m;i++){s2r[i]=s2[m-i-1];}
        solve();
    }
    return 0;
}