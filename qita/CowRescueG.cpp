#include<iostream>
#include<cstdio>
int main(){
    int n,m,x,y,x1,y1,ax,ay,a,ans=0x3f3f3f3f;
    scanf("%d %d",&n,&m);
    scanf("%d %d",&x1,&y1);
    while(m--){
        scanf("%d %d",&x,&y);
        if(x>=x1){
            a = x-x1+abs(y1-x1-y+x);
            if(a<ans){
                ans = a;
                ax = x;
                ay = y;
            }
            else if(a==ans){
                if(x<ax){ax = x;ay = y;}
                else if(x==ax && y<ay){ax = x;ay = y;}
            }
        }
    }
    ans++;
    std::cout<<ax<<' '<<ay<<std::endl;
    std::cout<<ans;
    return 0;
}