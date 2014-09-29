/*ID: yuysyu1
LANG: C++
TASK: namenum
*/

#include <stdio.h>
#include <string.h>

int transChartoNum(char c);
int main()
{
	FILE *fp;
	char test[10000][20];
	int dictTransNum[10000][20]; //just same as test but trans the string to num
	int dicColumnNum[10000];  
	int dict[26];
	int i,j,k;
	int length;
	int inputLength;
	char input[20];
	fp = fopen("dict.txt","r");
	i=0;
	while(fgets(test[i],20,fp))
	{
		for(j=0;test[i][j]!='\0';j++)
		{
			dictTransNum[i][j] = '0' + transChartoNum(test[i][j]);
		}
			dicColumnNum[i] = j-1;
			dictTransNum[i][j] = '\0';
		i++;
	}
	length = i;
//	printf("%d",length);
	fflush(fp);
	fclose(fp);
	freopen("namenum.in","r",stdin);
	freopen("namenum.out","w",stdout);
	scanf("%s",input);
	for(i=0;input[i]!='\0';i++)
		;
	//printf("%c",input[0]);
	inputLength = i;
	i=0;
	k=0;
//	printf("input length : %d\n", inputLength);
	while(i!=length)
	{
		j=0;
		if(inputLength != dicColumnNum[i])
		{
			i++;
			continue;

		}
		while(dictTransNum[i][j]==input[j])
		{
			j++;
			if(j==inputLength)
			{
				k++;
				printf("%s",test[i]);
				break;
			}
		}
		i++;
	}
	if(k==0)
		printf("NONE\n");
	return 0;
}

int transChartoNum(char c)
{
	if(c=='A'||c=='B'||c=='C')
		return 2;
	else if(c=='D'||c=='E'||c=='F')
		return 3;
	else if(c=='G'||c=='H'||c=='I')
		return 4;
	else if(c=='J'||c=='K'||c=='L')
		return 5;
	else if(c=='M'||c=='N'||c=='O')
		return 6;
	else if(c=='P'||c=='R'||c=='S')
		return 7;
	else if(c=='T'||c=='U'||c=='V')
		return 8;
	else if(c=='W'||c=='X'||c=='Y')
		return 9;
	else
		return 0;
}
