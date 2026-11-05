#include<iostream>
struct tree{
    int huanlue;
    int zishuhe;
    int sum_child;
    int num_child;
    tree* child;
}
int jisuan(tree t[],tree* gen){
    if(gen->num_child==0){
        gen->sum_child = 0;
        gen->num_child = 0>gen->huanlue?0:gen->huanlue;
    }
    else{
        int i,s1=0,s2=0;
        for(i=0;i<num_child){
            jisuan(t,(gen->child)+i);
        }
        for(i=0;i<num_child){
            s1+=((gen->child)+i)->sum_child;
            s2+=((gen->child)+i)->zishuhe;
        }
        gen->sum_child=s2
        if(gen->huanlue<0){
            gen->zishuhe=s2;
        }
        else{
            s1+=gen->huanlue;
            gen->zishuhe = s1>s2?s1:s2;
        }
    }
}
int main(){
    using namespace std;
    int n,*p,*q,d;
    tree *t;

}