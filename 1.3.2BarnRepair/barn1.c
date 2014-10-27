/*ID: yuysyu1
LANG: C++
TASK: barn1
*/

#include <stdio.h>
#include <stdlib.h>


int compare (const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}
int main()
{
	/* 	M: maxinum number of boards that can be purchased: 1<=M<=50 
		S: total number of stall: 1<=S<=200
		C: the number of cow in stall: 1<=C<=S*/
	int M,S,C;
	int cows[205];
	int i,j,k;
	int distance[205];
	int output = 0;
	int temp1,temp2;
	freopen("barn1.in","r",stdin);
	freopen("barn1.out","w",stdout);
	scanf("%d %d %d\n",&M,&S,&C);


	for(i=0;i<C;i++)
	{
		scanf("%d",&cows[i]);
	}

	if(M>=C)
	{
		printf("%d\n",C);
		return 0;
	}


	


	qsort(cows, C,sizeof(int),compare );

	for(i=0;i<C-1;i++)
	{
		distance[i] = cows[i+1]- cows[i]; 
	}

	for(i=0;i<C-M;i++)
	{	
		temp1 = distance[0];
		temp2 = 0;
		for(j=1;j<C-1;j++)
		{
		  if(distance[j]<=temp1)
			{
				temp2 = j;
				temp1 = distance[j];
			}
		}
//		printf("%d --> %d",cows[temp2],cows[temp2+1]);
		output+= temp1;
		distance[temp2] = S;

	}
	printf("%d\n",output+M);
	return 0;

}
