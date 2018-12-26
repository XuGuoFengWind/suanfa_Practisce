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
		while(j>i && a[j]>=temp)  //�ҵ�С��temp��,�ŵ�ǰ��ȥ
		j--;
		a[i]=a[j];
		while(i<j && a[i]<=temp)   //�ҵ�����temp��,�ŵ�����ȥ
		i++;
		a[j]=a[i];
	}
	a[i]=temp;
	return i;
}
void Quicksort(int a[],int s,int t)
{
	if(s<t)        //���������ٴ�������Ԫ�ص����
	{
		int i=Partion(a,s,t);
		Quicksort(a,s,i-1);    //���������еݹ�����
		Quicksort(a,i+1,t);    //���������еݹ�����
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
