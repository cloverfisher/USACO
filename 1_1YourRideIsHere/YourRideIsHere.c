/*
ID: yuysyu1
LANG: C++
TASK: ride
*/
#include <stdio.h>
#include <stdlib.h>

int mod47(char a[])
{
	int i; int mo;
	printf("%s\n",a);
	for(i=0;a[i];i++)
	{
		if(i==0)
			mo = a[i] - 'A' + 1;
		else
			mo = (a[i]-'A'+1)*mo%47;
		printf("%d,",mo);
	}
	printf("%d ",mo);
	return mo;
}




int main()
{
	FILE *fin,*fout;
	int i;
	char a[7],b[7];
	freopen("ride.in","r",stdin);
	scanf("%s ",a);
	scanf("%s ", b);

//	fin = fopen("ride.in","r");
	fout = fopen("ride.out","w");	
//	fscanf(fin,"%s %s",a,b);	
	printf("%s",a);
	for(i=0;a[i];i++)
	{
		printf("%d ",a[i]-'A' + 1);
	}	
	if(mod47(a) == mod47(b))
	{
		printf("GO\n");
		fprintf(fout,"GO\n");
	}	
	else
	{
		printf("STAY\n");
		fprintf(fout, "STAY\n");
	}

	return 0;

}
