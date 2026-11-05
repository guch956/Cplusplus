#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
char s[N];
int fa[23];
int find(int x){
    if(fa[x]!=x)fa[x]=find(fa[x]);
    return fa[x];
}
int main(){
    int T,i,n,a,b,ans;
    char c;
    bool xing;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        xing = 1;ans = 0;
        scanf("%s\n",s);
        for(i=1;i<=23;i++){fa[i]=i;}
        for(i=0;i<n;i++){
            c = getchar();
            if(c<s[i]){xing=0;}
            a = find(s[i]-'a'+1);
            b = find(c-'a'+1);
            if(a!=b){
                ans++;
                fa[b]=a;
            }
        }
        if(xing){printf("%d\n",ans);}
        else{printf("-1\n");}
    }
    return 0;
}