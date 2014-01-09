/*
ID: yuysyu1
LANG: C++
TASK: gift1
*/

#include <stdio.h>
#include <string.h>

int NP;
char groupmember[11][100];
int groupmoney[11] = {0};
int main()
{
	int i,j,k,l;
	char tempString[100];
	int tempmoney;
	freopen("gift1.in","r",stdin);
	freopen("gift1.out","w",stdout);
	scanf("%d",&NP);

//	memset(groupmember,0,sizeof(groupmember));
	for(i=0;i<NP;i++)
	{
	 	//gets(groupmember[i]);
		scanf("%s",groupmember[i]);
	}
	for(i=0;i<NP;i++)
	{
//		printf("%s",groupmember[i]);
//		printf("\n");
		scanf("%s",tempString);
		for(j=0;j<NP;j++)
		{
			if(strcmp(tempString,groupmember[j])==0)
			{
		//		printf("%s\n",groupmember[j]);
				scanf("%d %d",&tempmoney,&k);
				if(k!=0)
				tempmoney = tempmoney/k;
		//		printf("%d",tempmoney);	
		//		groupmoney = 0;
				for(;k>0;k--)
				{
					scanf("%s",tempString);
			//		printf("%s\n",tempString);
					for(l=0;l<NP;l++)
					{
						if(strcmp(tempString,groupmember[l])==0)
						{
							groupmoney[l]+=tempmoney;
							groupmoney[j]-=tempmoney;
							break;
						}
					}
				}
				break;
			}
		}
	}
	for(i=0;i<NP;i++)
	{
		printf("%s %d\n",groupmember[i],groupmoney[i]);
	}

return 0;
}
