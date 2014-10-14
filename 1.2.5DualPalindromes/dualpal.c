/*ID: yuysyu1
LANG: C++
TASK: dualpal
*/

#include <stdio.h>
#include <string.h>
int dualpal( int S);
int main()
{
	int N,S;
	int i,j,k;
	freopen("dualpal.in","r",stdin);
	freopen("dualpal.out","w",stdout);
	scanf("%d %d",&N,&S); //1<=N<=15; 0<S<=10000
	for(i=1;N>0;i++)
	{
		if(dualpal(S+i))
			N--;
	}


}

int dualpal(int S)
{
	int i,j,k;
	int B;
	int flag = 0;
	int chnum[20];
	int N1=S;
	int length;
	//1024 = 2^10; 10000< 2^14
	for(B=2;B<=10;B++)
	{
		N1 = S;
		memset(chnum,0,20 * sizeof(int));
		for(i=0;;i++)
		{
			chnum[i] = N1%B;
			N1/=B;
			if(N1 == 0)
				break;
		}
		length = i;
		for(i=0,j=length;chnum[i]==chnum[j];i++,j--)
		{
			if(i>=j)
			{
				flag++;
				break;
			}
		}
		if(flag==2)
		{

			printf("%d\n",S);
			return 1;
			break;
		}
	}
	return 0;
}