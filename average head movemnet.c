#include<stdio.h>
#include<stdlib.h>
void sortTracks(int *Tracks,int numTracks){
	int i,j,temp;
	for(i=0;i<numTracks-1;j++){
		for(j=0;j<numTracks;j++){
			if(Tracks[j]>Tracks[j+1]){
				temp=Tracks[j];
				Tracks[j]=Tracks[j+1];
				Tracks[j+1]=temp;
			}
		}
	}
}
int findClosestTrack(int *Tracks,int numTracks,int headPos,int direction){
	int ClosestTrack=-1;
	if(direction==1){
		for(int i=0;i<numTracks;i++){
			if(Tracks[i]>=headPos){
				ClosestTrack=i;
				break;	
			}
		}
	}
		else
		{
			for(int i=numTracks-1;i>=0;i--){
				if(Tracks[i]<=headPos){
					ClosestTrack=i;
					break;
				}
			}
		}
		return ClosestTrack;
	}
int main(){
	int numTracks=9;
	int Tracks={55,58,60,70,18,19,150,160,184};
	int headPos=50;
	int direction=1;
	int totalheadmovement=0;
	int numRequests=numTracks;
	sortTracks(Tracks,numTracks);
	int ClosestTrack=findClosestTrack(Tracks,numTracks,headPos,direction);
	while (numRequests>0){
		headPos = Tracks[ClosestTrack];
		printf("head moved to track%d\n",headPos);
		totalheadmovement+=abs(headPos-Tracks[ClosestTrack]);
		for(int i=ClosestTrack;i<numTracks-1;i++){
			Tracks[i]=Tracks[i+1];
		}
		numTracks--;
		numRequests--;
		if (num Tracks==0){
			break;
		}
		if(headPos==tracks[0]){
			direction=1;
		}else if(headPos==Tracks[numTracks-1]){
			direction=0;
		}
		ClosestTrack=findClosestTrack(Tracks,num Tracks,headPos,direction);
	}
	float averageheadmovement=(float)totalheadmovement/numRequest;
	printf("averageheadmovement:%.2f\n",averageheadmovement);
	return 0;
}