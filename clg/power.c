#include<stdio.h>
int power(int, int);
int main(){
    int r,y,z;
    printf("Enter base and exponent: ");
    scanf("%d %d",&y,&z);
    r=power(y,z);
    printf("%d\n",r);
    return 0;
}
int power(int y, int z){
    if(z==0)
        return 1;
    else
        return y*power(y, z-1);
}