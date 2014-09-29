/*D: yuysyu1
LANG: C++
TASK: transform
*/



#include <stdio.h>
#include <string.h>

int main()
{
	char origin[11][11];
	char after[11][11];
	int i,j,k;
	int N;
	int tag[7];
	int tag2[3];
	freopen("transform.in","r",stdin);
	freopen("transform.out","w",stdout);
	memset(tag,0,7*sizeof(int));
	memset(tag2,0,3*sizeof(int));
	scanf("%d\n",&N);
	for(i=0;i<N;i++)
	{
		scanf("%s",origin[i]);
	}
	for(i=0;i<N;i++)
	{
		scanf("%s",after[i]);
	}
	
	// for(i=0;i<N;i++)
	// {
	// 	printf("%s\n",origin[i]);
	// 	printf("%s\n",after[i]);

	// }
//	printf("%c",after[1][0]);
	//scanf("%s",)
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(origin[i][j] != after[j][N-1-i])
			{
		//		printf("%d%d\n",i,j);
		//		printf("%c%c\n",origin[i][j],after[i][N-1-j]);
				tag[0] = 1;
			}
			if(origin[i][j] != after[N-1-i][N-1-j])
				tag[1] = 1;
			if(origin[i][j] != after[N-1-j][i])
				tag[2] = 1;
			if(origin[i][j] != after[i][N-1-j])
				tag[3] = 1;
			if(origin[i][j]!= after[i][j])
				tag[5] = 1;
			// if((origin[i][j]==after[N-1-j][N-1-i])||(origin[i][j]==after[N-1-i][j])||origin[i][j]==after[j][i])
			// 	continue;
			// else
			// 	tag[4] = 1;
		}
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(origin[i][j]==after[N-1-j][N-1-i])
				continue;
			else
				tag2[0] = 1;
		}
		for(j=0;j<N;j++)
		{
			if(origin[i][j]==after[N-1-i][j])
				continue;
			else
				tag2[1] = 1;
		}
		for(j=0;j<N;j++)
		{
			if(origin[i][j]==after[j][i])
				continue;
			else
				tag2[2] = 1;
		}
	}
	if((tag2[0]==1)&&(tag2[1]==1)&&(tag2[2]==1))
		tag[4]=1;
	else
		tag[4]=0;
//	tag[6] = 1;
	for(i=0;i<7;i++)
	{
		if(tag[i]==0)
		{
			printf("%d\n",i+1);
			break;
		}
	}
}
