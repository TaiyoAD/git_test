#include<stdio.h>
int prime (int );
int main(){
    int p,n;
    printf("Enter a number: ");
    scanf("%d",&n);
    while(n>1){
        n=prime(n);
    }
    printf("%d",n);
    return 0;
}
int prime(int n){
    int i,flag=1;
    for(i=2;i<=n/2;i++){
        if(n%i==0){
            flag=0;
            break;
        }
    }
    if(flag==1)
        printf("%d \n",n);
    return n-1;
}
