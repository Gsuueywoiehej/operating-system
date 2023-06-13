#include<stdio.h>
int main()
{
	int claim[4][3]={{3,2,2},{6,1,3},{3,1,4},{4,2,2}};
	int allocation[4][3]={{1,0,},{6,1,2},{2,1,1},{0,0,2}};
	int avilable[3]={9,3,6};
	int finish[4]={0};
	int work[3]={0};
	for(int i=0;i<3;i++){
		work[i]=avilable[i];
	}
	int need[4][3];
	for(int i=0;i<4;i++){
		for (int j=0;j<3;j++){
			need[i][j]=claim[i][j]-allocation[i][j];
		}
	}
	int safe=0;
	int sequence[4];
	int count=0;
	while(count<4){
		int found=0;
		for(int i=0;i<4;i++){
			if(!finish[i]){
				int j;
				for(j=0;j<3;j++){
					if(need[i][j]>work[j]){
						break;
					}
				}
				if(j==3){
					for(int k=0;k<3;k++){
						work[k]+=allocation[i][k];
					}
					finish[i]=1;
					sequence[count]=i;
					count++;
					found=1;
					
				}
			}
		}
		if(!found){
			break;
		}
	}
	if(count==4){
		printf("the system is in safe state with the sequence of :");
		for(int i=0;i<4;i++){
			printf("%d",sequence[i]);
		}
		printf("\n");
		safe=1;
	}
	else{
		printf("the system is in unsafe state\n");
	}
	return safe;
}
