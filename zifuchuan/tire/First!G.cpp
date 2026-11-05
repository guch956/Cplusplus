#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=30003;
char s[N*11];
bool ans[N];
int g[26][26];
int len[N];
int vis[26];
struct {
    int son[26];
    bool isend;
}t[N*10];
int ent;
bool huan;
void insert(char * s,int slen){
    int i,now=0,ch;
    for(i=0;i<slen;i++){
        ch = s[i]-'a';
        if(!t[now].son[ch]){t[now].son[ch]=++ent;}
        now = t[now].son[ch];
    }
    t[now].isend=1;
}
void dfs(int s){
    int i;
    vis[s]=1;
    for(i=0;i<26;i++){
        if(g[s][i]){
            if(!vis[i]){
                dfs(i);
            }
            else if(vis[i]==1){
                huan = 1;
            }
        }
    }
    vis[s]=2;
}
bool check(char * s,int slen){
    memset(g,0,sizeof(g));
    memset(vis,0,sizeof(vis));
    huan =0;
    int i,now=0,ch,j;
    for(i=0;i<slen;i++){
        ch = s[i]-'a';
        for(j=0;j<26;j++){
            if(j!=ch && t[now].son[j]){
                g[ch][j]=1;
            }
        }
        if(t[now].isend){return 1;}
        now = t[now].son[ch];
    }
    for(j=0;j<26;j++){
        if(!vis[j]){
            dfs(j);
        }
    }
    return huan;
}
int main(){
    int n,l=0,i,num=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",s+l);
        len[i] = strlen(s+l);
        insert(s+l,len[i]);
        l += len[i]+1;
    }
    l = 0;
    for(i=0;i<n;i++){
        if(!check(s+l,len[i])){
            num++;
            ans[i]=1;
        }
        l += len[i]+1;
    }
    printf("%d\n",num);
    l = 0;
    for(i=0;i<n;i++){
        if(ans[i]){
            printf("%s\n",s+l);
        }
        l += len[i]+1;
    }
    return 0;
}