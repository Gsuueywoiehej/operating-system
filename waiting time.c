#include<stdio.h> 
int main()
{

	int n=4;
	int bt[]={6,8,7,3};
	int wt[n],tat[n],avwt=0,avtat=0;
	for(int i=0;i<n-1;i++){
		int min_idx=1;
		for(int j=i+1;j<n;j++){
			if(bt[j]<bt[min_idx]){
				min_idx=j;
			}
		}
		int temp=bt[min_idx];
		bt[min_idx]=bt[i];
		bt[i]=temp;
	}
	for(int i=0;i<n;i++){
		wt[i]=0;
		for(int j=0;j<i;j++){
			wt[i]+=bt[j];
		}
		tat[i]=wt[i]+bt[i];
		avwt+=wt[i];
		avtat+=tat[i];
	}
	for(int i=0;i<n;i++){
		printf("P%d\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
	}
	avwt/=n;
	avtat/=n;
	printf("\n Average waiting time:%d\n",avwt);
	printf("\n average turnaround time:%d\n",avtat);
	return 0;	
}