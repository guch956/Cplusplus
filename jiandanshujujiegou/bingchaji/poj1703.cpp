#include<iostream>
#include<cstdio>
using namespace std;
const int N=200003;
int fa[N];
int find(int x){
    if(fa[x]!=x){
        fa[x]=find(fa[x]);
    }
    return fa[x];
}
void hebing(int x,int y){
    int a=find(x),b=find(y);
    if(a!=b){
        fa[a]=b;
    }
}
int main(){
    int t,n,m,i,a,b;
    char c;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(i=1;i<=2*n;i++){fa[i]=i;}
        while(m--){
            c = getchar();
            while(c!='A' && c!='D'){c = getchar();}
            scanf("%d %d",&a,&b);
            if(c=='A'){
                if(find(a)==find(b)){printf("In the same gang.\n");}
                else if(find(a)==find(b+n)){printf("In different gangs.\n");}
                else{printf("Not sure yet.\n");}
            }
            else{
                hebing(a,b+n);
                hebing(a+n,b);
            }
        }
    }
    return 0;
}