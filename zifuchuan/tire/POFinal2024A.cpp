#include<iostream>
#include<cstdio>
const int N=100003;
int t[N*20][26];
int is[N*20];
int weifan[N*20];
char s[N*20],top;
void dfs(int p){
    int i;
    if(weifan[p]){
        for(i=0;i<top;i++){
            printf("%c",s[i]);
        }
        printf(" ");
    }
    for(i=0;i<26;i++){
        if(t[p][i]){
            s[top++]=i+'a';
            dfs(t[p][i]);
            top--;
        }
    }
}
int main(){
    int i,num=0,n,m,len,now=0,ent=0,ch;
    scanf("%d %d",&n,&m);
    for(int j=0;j<n;j++){
        scanf("%s",s);
        now = 0;
        for(i=0;s[i];i++){
            ch = s[i]-'a';
            if(!t[now][ch]){t[now][ch]=++ent;}
            now = t[now][ch];
        }
        if(j==0){
            is[now]=1;
        }
    }
    num = 0;
    while(m--){
        scanf("%s",s);
        now = 0;
        for(i=0;s[i];i++){
            now = t[now][s[i]-'a'];
        }
        if(is[now]==0 && weifan[now]==0){
            weifan[now]=1;
            num++;
        }
        is[now]=0;
        now = 0;
        scanf("%s",s);
        scanf("%s",s);
        for(i=0;s[i];i++){
            now = t[now][s[i]-'a'];
        }
        is[now]=1;
    }
    printf("%d\n",num);
    dfs(0);
    return 0;
}
