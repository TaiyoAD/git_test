#include<stdio.h>
int sum(int);
int main(){
    int n,s;
    scanf("%d",&n);
    s=sum(n);
    printf("%d\n",s);
    return 0;
}
int sum(int n){
    if(n==0)
        return 0;
    else
        return n%10+(n/10);
}