#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=200003;
int A[N];
int fa[N];
int find_set(int x){
    if(fa[x]!=x){
        fa[x]=find_set(fa[x]);
    }
    return fa[x];
}
void hebing(int x,int y){
    int a=find_set(x),b=find_set(y);
    fa[b]=a;
}
int main(){
    char s[53];
    int n,i,k,l,j,ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%s",s);
        fa[i]=i;
        l = strlen(s);
        for(j=0;j<l;j++){
            k = 1<<(s[j]-'a');
            A[i]=A[i]|k;
        }
    }
    for(j=0;j<26;j++){
        k = 1<<j;
        for(i=1;i<=n;i++){
            if(A[i]&k){l = i;break;}
        }
        for(i++;i<=n;i++){
            if(A[i]&k){hebing(l,i);}
        }
    }
    for(i=1;i<=n;i++){
        if(find_set(i)==i){ans++;}
    }
    printf("%d",ans);
    return 0;
}