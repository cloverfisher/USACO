/*ID: yuysyu1
LANG: C++
TASK: palsquare
*/

#include <stdio.h>
int palsquare(int B, int N);
int main()
{
	int B,N;
	int i,j,k;
	freopen("palsquare.in","r",stdin);
	freopen("palsquare.out","w",stdout);
	scanf("%d",&B);

	for(i=1;i<300;i++)
	{
		palsquare(B,i);
	}

}

int palsquare(int B,int a)
{
	int N = a * a;
	int inum[20];
	int temp;
	char ctemp;
	char cnum[20];
	char inputnum[20];
	int i ,j,k;
	int length;
	for(i=0;N!=0;i++)
	{
		temp = N%B;
		inum[i]=temp;
		N = N /B;	
	}
	length = i;
	cnum[length] = '\0';
	for(i=0;a!=0;i++)
	{
		temp = a%B;
		if(temp>=10)
			inputnum[i]=temp-10+'A';
		else
			inputnum[i]=temp+'0';
		a = a /B;	
	}
	inputnum[i] = '\0'; 
	for(j=i-1,i=0;i<j;i++,j--)
	{
		ctemp = inputnum[i];
		inputnum[i] = inputnum[j];
		inputnum[j] = ctemp;
	}
	for(i=0,j=length-1;i<j;i++,j--)
	{
		if(inum[i]==inum[j])
		{
			if(inum[i]>=10)
				cnum[i] = cnum[j] = inum[i]-10+'A';
			else
				cnum[i] = cnum[j] = inum[i]+'0';
		}
		else
			break;
	}
	if(i==j)
	{
		if(inum[i]>=10)
			cnum[i] = inum[i]-10+'A';
		else
			cnum[i] = inum[i]+'0';
		printf("%s %s\n",inputnum,cnum);
	}
	if(i>j)
	{
		printf("%s %s\n",inputnum,cnum);
	}
return 0;
}