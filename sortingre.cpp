
#include<stdio.h>
#include<conio.h>
 void bubblesort(int arr[], int n)
 {
  int i,j,temp,flag,count=0;
  for(i=0;i<n-1-i ;i++)//number of pass //normally n-1, to increase performance n-1-i
  {
   flag=1;
   for(j=0;j<n-1;j++)//number of comparison in each pass
   {
    count++;
    if(arr[j]>arr[j+1])//not in order case
    {
     temp=arr[j];
     arr[j]=arr[j+1];
     arr[j+1]=temp;
     flag=0;
    }
  }
  if(flag==1)break;//if flag is not reset list is sorted so leave remaining passes.
 }
 printf("Number of comparison: %d",count);
 }
 int getSmallestIndex(int arr[],int i,int n)
 {
  int smallest=i;
  int j;
  for(j=i+1;j<=n;j++)
  {
   if(arr[j]<arr[smallest])
   {
    smallest=j;
   }
   return smallest;
  }
 }
 void selectionsort(int arr[], int n)//selection short logic
 {
  int i,j,temp;
  for(i=0;i<n-1;i++)
  {
   j=getSmallestIndex(arr,i,n-1);
   temp=arr[i];
   arr[i]=arr[j];
   arr[j]=temp;
  }
 }
 void insertionsort(int arr[],int n)
 {
 	int i,j,key;
 	for(i=1;i<n;i++)
 	{
 		key=arr[i];
 		for(j=i-1;j>=0&&arr[j]>key;j--)
 		{
 			arr[j+1]=arr[j];// Move one position right so that there will be room for insertion
		 }
		 arr[j+1]=key;//put the key item in the vacant space.
	 }
 }
 void quicksort(int arr[],int left, int right)//partation exchange sort
 {
 	int pivot=left;
 	int down=left,up=right;
 	int temp;
 	if(left<right)
 	{
 	repeat:
 	while(arr[down]<=arr[pivot]&& down<=right)
 	{
 		down++;
	 }
	while(arr[up]>arr[pivot])
	{
		up--;
	}
	if(down<up)//exchange down with up and repeat again
	{
		temp=arr[down];
		arr[down]=arr[up];
		arr[up]=temp;
		goto repeat;
	}
	else{//exchange pivot with up and partition the last
		temp=arr[pivot];
		arr[pivot]=arr[up];
		arr[up]=temp;
		quicksort(arr,left,up-1);//apply quicksort to left sublist
		quicksort(arr,up+1,right);//apply quicksort to right sublist
	}
	  }
 }
 
 void detach(int arr[],int p, int r){
 	int q;
 	if(p<r){
 		q=floor(p+r)/2);
 		detach(arr,p,q);
 		detach(arr,q+1,r);
 		merge(arr,p,q,r);
	 }
 }
 
 void merge(int arr[], inr p, int q, int r){
 	  int b[10];
 	  int i,j,k;
 	  k=0;
 	  i=p;
 	  j=q+1;
 	  while(q>=i&& r>=j){
 	  	if(a[i]<a[j]){
 	  		b[k++]=a[j++];
		   }
		   else{
		   	b[k++]=a[j++];
		   }
	   }
	   while(i<=q){
	   	b[k++]=a[i++];
	   }
	   while(j<=r){
	   	b[k++]=a[j++];
	   }
	   for(i=r;i>=p;i++){
	   	a[i]=b[--k];
	   }
 }
 int main()
 {
  int i;
  int arr[]={7,4,8,3,9,11,2,8,5,6};
  printf("Before sorting...\n");
  for(i=0;i<10;i++)
   printf("%d ",arr[i]);
  //bubblesort(arr,10);
  //selectionsort(arr,10);//calls selection sort function
  //insertionsort(arr,10);
  //quicksort(arr,0,9);
  
  detach(arr,10);
  printf("\nAfter sorting....\n");//
  for(i=0;i<10;i++)
   printf("%d ",arr[i]);//print the data after  selection sort
  getch();
 }
