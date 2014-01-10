/*D: yuysyu1
LANG: C++
TASK: milk2
*/

#include <stdio.h>
#include <string.h>

int main()
{
	int i,j,k;
	int N=0;
	unsigned int timearr[5005][2];
	int timemonitor[1000000];
	int max=0,min=1000000;	
	int idle=0,cont=0;	
	int temp1,temp2;
	
	freopen("milk2.in","r",stdin);
	freopen("milk2.out","w",stdout);
	
	scanf("%d\n",&N);
	memset(timemonitor,0,1000000*sizeof(int));
	for(i=0;i<N;i++)
	{
		scanf("%d %d\n",&timearr[i][0],&timearr[i][1]);	
		if(timearr[i][0]<min)
			min = timearr[i][0];

		if(timearr[i][1]>max)
			max = timearr[i][1];

	}
	for(i=0;i<N;i++)
	{
		for(j=timearr[i][0];j<timearr[i][1];j++)
		{
			timemonitor[j]= 1;	
		}
	}
	temp1 =1;
	for(i=min;i<=max;i++)
	{
		if(i==min)
		{
			
			//temp1++;
			continue;
		}
		if(timemonitor[i]==timemonitor[i-1])
		{
			temp1++;
		}
		else
		{
			//continues full
			if(timemonitor[i-1]==1)
			{
				if(temp1>cont)
					cont=temp1;
			}
			//idel time
			if(timemonitor[i-1]==0)
			{
				if(temp1>idle)
					idle=temp1;
			}
			temp1=1;
		}
		if(i==max)
		{
			if(temp1>cont)
				cont = temp1;
		}
	}
	printf("%d %d\n",cont,idle);

	

}
