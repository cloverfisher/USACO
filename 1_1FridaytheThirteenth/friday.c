/*
ID: yuysyu1
LANG: C++
TASK: friday
*/

#include <stdio.h>



int main()
{
	int i,j,k;
	int N;
	int week[7] = {0};
	int days = 3;
	freopen("friday.in","r",stdin);
	freopen("friday.out","w",stdout);
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		for(j=1;j<13;j++)
		{
			if(j==1||j==2||j==4||j==6||j==8||j==9||j==11)
			{
				days = days+31;
				days = days%7;
				week[days]++;
			}
			else if(j==5||j==7||j==10||j==12)
			{
				days = days +30;
				days = days%7;
				week[days]++;
			}			
			else
			{
				if(i%4==0&&i!=0&&i!=200&&i!=300&&i!=400)
				{
					days = days + 29;
					days = days%7;
					week[days]++;
				}
				else
				{
					days = days + 28;
					days = days%7;
					week[days]++;
				}
			}



		}
	}
	
	printf("%d ",week[6]);
	for(i=0;i<5;i++)
		printf("%d ",week[i]);
	printf("%d",week[5]);
	printf("\n");
	return 0;
}
