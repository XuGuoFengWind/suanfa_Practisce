#include <stdio.h>
#include <stdlib.h>
void disp(int n,int a[]){
	int i;
	for(i=0;i<n;i++)
    {
    	printf("%d ",a[i]);
	}
	printf("\n");
}
int Partion(int a[],int s,int t){
	int temp;
	temp=a[s];
	int i,j;
	i=s;
	j=t;
	while(i!=j)
	{
		while(j>i && a[j]>=temp)  //找到小于temp的,放到前面去
		j--;
		a[i]=a[j];
		while(i<j && a[i]<=temp)   //找到大于temp的,放到后面去
		i++;
		a[j]=a[i];
	}
	a[i]=temp;
	return i;
}
void Quicksort(int a[],int s,int t)
{
	if(s<t)        //序列内至少存在两个元素的情况
	{
		int i=Partion(a,s,t);
		Quicksort(a,s,i-1);    //对左子序列递归排序
		Quicksort(a,i+1,t);    //对右子序列递归排序
	}
}
int main(int argc, char *argv[]) {
	int n=10;
	int a[]={2,5,8,3,6,4,7,1,9,10};
	printf("Before sort:\n");
	disp(n,a);
	Quicksort(a,0,n-1);
	printf("After sort:\n");
	disp(n,a);
	return 0;
}
