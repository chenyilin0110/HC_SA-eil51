#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double countDistance(int array[51][3],int number,double distance);
void tempData(int array[51][3],int randon1,int randon2);

int main()
{
	FILE *fptr;
	char num[2]={},x[2]={},y[2]={},empty[] = "EOF";
	int read[51][3] = {0};
	int count = 0,i,chose = 1,co = 1;
	double startDistance = 0;
		
	fptr = fopen("countDistance-data.txt","r");	
	while(fscanf(fptr,"%s %s %s",&num,&x,&y) != EOF)
	{				
		if(strcmp(num,empty) != 0)
		{	
			read[count][0] = atoi(num);
			read[count][1] = atoi(x);
			read[count][2] = atoi(y);
			count++;
		}
		else
			break;
	}
	fclose(fptr);
	startDistance = countDistance(read,count,startDistance);
	printf("Distance = %f\n",startDistance);
}

double countDistance(int array[51][3],int number,double distance)
{	
	int j;
	double toCountDistance = distance;		
	for(j=0;j<number;j++)
	{
		int temp;
		if(j!=(number-1))
		{
			temp = j + 1;		
			toCountDistance += sqrt(pow((array[j][1]-array[temp][1]),2)+pow((array[j][2]-array[temp][2]),2));
		}
		else
		{
			temp = 0;
			toCountDistance += sqrt(pow((array[j][1]-array[temp][1]),2)+pow((array[j][2]-array[temp][2]),2));
		}
	}
	return toCountDistance;
}
