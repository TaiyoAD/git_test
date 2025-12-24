#include <stdio.h>
int main ()
{
    int n;
    printf("enter the size of array ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        printf("enter element : ");
        scanf("%d",&arr[i]);
    }
    int min=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]<min)
        {
            min=arr[i]; 
        }

    }
    printf("minimum element is %d",min);
    int max=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i]; 
        }

    }
    int s=max-min;
    printf("\nmaximum element is %d",max);
    printf("\ndifference between maximum and minimum is %d",s);
    return 0;
}