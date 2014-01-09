/*
ID: yuysyu1
LANG: C
TASK: beads
*/


#include <stdio.h>
#include <string.h>

int main()
{
	int i,j,k;
	char necklace[355];
	char beads[710];
	int N=0;
	int tag=0;
	int step=0;
	int beadsnum=0;
	int maxbeadsnum=0;
	int left,right;
	char thisbead=0;

	freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);
	scanf("%d\n",&N);
	scanf("%s",necklace);
	
	strcat(beads,necklace);
	strcat(beads,necklace);

	for(i=1;i<2*N-1;i+=step)
	{
		left =0;
		right = 0;
		tag = 0;
		for(j=1;i-j>=0;j++)
		{
			if(beads[i-j]=='w')
			{
				left++;
				continue;
			}
			else if(tag==0)
			{
				tag=1;
				left++;	
				thisbead = beads[i-j];
			}
			else if(tag==1)
			{
				if(beads[i-j]==thisbead)
				{
					left++;
				}
				else
				{
					break;
				}
			}
		}
	//	left = j;
		step = 0;
		tag=0;
		for(j=0;i+j<=2*N;j++)
		{
			if(beads[i+j]=='w')
			{
				right++;
				continue;
			}
			else if(tag==0)
			{
				tag = 1;
				right++;
				thisbead = beads[i+j];
			}
			else if(tag==1)
			{
				if(beads[i+j]==thisbead)
				{
					right++;
				}
				else
				{
					break;
				}
			}
		}
	//	right = j;
		step = right;
//		printf("%d %d \n",left,right);
		if(maxbeadsnum < right+left)
			maxbeadsnum = right+left;
//		printf("%d ",maxbeadsnum);
	}
	if(maxbeadsnum>N)
		maxbeadsnum = N;
	printf("%d\n",maxbeadsnum);
	//printf("%s\n",beads);
//	printf("%d\n",N);

return 0;
}
