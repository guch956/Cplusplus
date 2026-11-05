#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=500003;
struct {
    bool repeat;
    bool isend;
    int son[26];
}t[N];
int ent=1;
void insert(char * s){
    int now=0,ch;
    for(int i=0;s[i];i++){
        ch = s[i]-'a';
        if(t[now].son[ch]==0){
            t[now].son[ch]=ent;
            ent++;
        }
        now = t[now].son[ch];
        if(i==strlen(s)-1){
            t[now].isend=1;
        }
    }
}
int find(char * s){
    int now=0,ch;
    for(int i=0;s[i];i++){
        ch = s[i]-'a';
        if(t[now].son[ch]==0){
            return 3;
        }
        now = t[now].son[ch];
    }
    if(t[now].isend==0){return 3;}
    if(t[now].repeat==0){
        t[now].repeat=1;
        return 1;
    }
    return 2;
}
int main(){
    int n,m;
    char a[51];
    scanf("%d",&n);
    while(n--){
        scanf("%s",a);
        insert(a);
    }
    scanf("%d",&m);
    while(m--){
        scanf("%s",a);
        n = find(a);
        switch (n){
            case 1:
                printf("OK\n");
                break;
            case 2:
                printf("REPEAT\n");
                break;
            case 3:
                printf("WRONG\n");
                break;
        }
    }
    return 0;
}