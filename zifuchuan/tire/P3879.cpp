#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=5000003;
struct {
    int nex;
    int id;
}list[N];
int top;
struct {
    int son[26];
    int head;
}t[N];
char p[N];
int ent;
void print(int x){
    if(x==0)return ;
    print(list[x].nex);
    printf("%d ",list[x].id);
}
int add2(int a,int b){
    if(list[a].id==b)return a;
    top++;
    list[top].nex=a;
    list[top].id=b;
    return top;
}
void add(int num){
    int i,now=0,n=strlen(p),ch;
    for(i=0;i<n;i++){
        ch = p[i]-'a';
        if(t[now].son[ch]==0)t[now].son[ch] = ++ent;
        now = t[now].son[ch];
    }
    t[now].head = add2(t[now].head,num);
}
void chaxun(){
    int i,now=0,n=strlen(p),ch;
    for(i=0;i<n;i++){
        ch = p[i]-'a';
        if(t[now].son[ch]==0){
            printf("\n");return ;
        }
        now = t[now].son[ch];
    }
    print(t[now].head);
    printf("\n");
}
int main(){
    int m,n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&k);
        for(j=1;j<=k;j++){
            scanf("%s",p);
            add(i);
        }
    }
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        scanf("%s",p);
        chaxun();
    }
    return 0;
}