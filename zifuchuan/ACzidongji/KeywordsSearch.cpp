#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int N=500003;
struct {
    int son[26];
    int fail;
    int end;
}t[N];
int ent;
char s[N<<1];
int newnode(){
    ent++;
    memset(t[ent].son,0,sizeof(t[ent].son));
    t[ent].fail=t[ent].end=0;
    return ent;
}
void insert(char * s,int slen){
    int i,now=0,ch;
    for(i=0;i<slen;i++){
        ch = s[i]-'a';
        if(!t[now].son[ch]){
            t[now].son[ch]=newnode();
        }
        now = t[now].son[ch];
    }
    t[now].end++;
}
void getfail(){
    int i,ch,now;
    queue<int> q;
    for(i=0;i<26;i++){
        if(t[0].son[i]){q.push(t[0].son[i]);}
    }
    while(q.size()){
        now = q.front();
        q.pop();
        for(i=0;i<26;i++){
            if(t[now].son[i]){
                q.push(t[now].son[i]);
                t[t[now].son[i]].fail=t[t[now].fail].son[i];
            }
            else{
                t[now].son[i]=t[t[now].fail].son[i];
            }
        }
    }
}
int query(char * s,int slen){
    int i,now=0,tmp,ans=0;
    for(i=0;i<slen;i++){
        now=t[now].son[s[i]-'a'];
        tmp=now;
        while(tmp && t[tmp].end!=-1){
            ans+=t[tmp].end;
            t[tmp].end=-1;
            tmp = t[tmp].fail;
        }
    }
    return ans;
}
int main(){
    int T,n;
    scanf("%d",&T);
    while(T--){
        ent=-1;
        ent = newnode();
        scanf("%d",&n);
        while(n--){
            scanf("%s",s);
            insert(s,strlen(s));
        }
        getfail();
        scanf("%s",s);
        printf("%d\n",query(s,strlen(s)));
    }
    return 0;
}
