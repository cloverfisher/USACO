/*ID: yuysyu1
LANG: C++
TASK: milk
*/

#include <stdio.h>
#include <string.h>

int main()
{
	int M,N;
	int P[5005],A[5005];
	int i,j,k;
	int price = 0;
	int temp1,temp2;

	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);
	scanf("%d %d",&N,&M);

	for(i=0;i<M;i++)
	{
		/*
			P is price per unit, A is unit sum;
		*/
		scanf("%d %d\n",&P[i],&A[i]);	
	}



	for(i=0;i<M;i++)
	{
		for(j=1+i;j<M;j++)
		{
			if(P[i]>P[j])
			{
				temp1 = P[i];
				temp2 = A[i];
				P[i] =  P[j];
				A[i] = A[j];
				P[j] = temp1;
				A[j] = temp2;
			}
		}
	}
	// for(i=0;i<M;i++)
	// {
	// 	printf("%d %d\n",P[i],A[i]);
	// }
	i=0;
	while(N-A[i]>0)
	{
		price = price + P[i]*A[i];
		N = N-A[i];
		i++;
	}
	price = price + P[i]*N;

	printf("%d\n",price);
	
	return 0;
}

