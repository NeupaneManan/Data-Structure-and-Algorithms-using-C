#include<stdio.h>
#include<conio.h>
void shellsort(int arr[],int n)
{
	int gap,i,j,temp;
	for(gap=n/2;gap>0;gap/=2)//repeatdly apply insertion sort with varying no.
	{
		for(i=gap;i<n;i++){
			temp=arr[i];
			for(j=i-gap;j>=0&& arr[j]>temp;j=j-gap)
			{
				arr[j+gap]=arr[j];			}
		}
		arr[j+gap]=temp;
	}
}
int main(){
	
	int arr[]={7,4,8,1,10,9,6,2,5,3};
	int i;
	printf("Before Sorting....\n");
	for(i=0;i<10;i++)
	printf("%d",arr[i]);
	shellsort(arr,10);
	printf("\nAfter Sorting....\n");
	for(i=0;i<10;i++)
	printf("\n%d",arr[i]);
	
	}

