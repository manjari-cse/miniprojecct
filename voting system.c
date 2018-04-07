#include<stdio.h>
#include<string.h>
 FILE *fp;
int i,j=0,candidates,n,max,min=0,population,count,k,re[10],max1,pop,m;
char reename[20][30];
float cal;
struct candidate//candidate willing to join
{
	char name[300];
	int age;
}ob[200];
struct sele_cand//selected candidates
{
	char name1[300];
	int votes;
}cd[200];
void help()
{   printf("                                                  HELP");
    printf("\n                                              ***********");
	printf("\n//steps done in the voting program are ");
	printf("\n1.candidates willing to apppear on the on election ar listed");
	printf("\n2.elligible candidates are selected");
	printf("\n3.voting for each candidate is received");
	printf("\n4.Winner name is printed");
    printf("\n5.All the details are stored in the file");
}
void print()
{ 
    fp=fopen("voter_list.txt","w");
    fprintf(fp,"                                             VOTING SYSTEM             ");
	for(i=0;i<candidates;i++)
	{
		fprintf(fp,"\n%d.%s %d",i+1,ob[i].name,ob[i].age);
	}
	fclose(fp);
}
void candidate_selection()
{
	printf("\n=================================================================================================================");
    printf("\n                                               VOTING SYSTEM                                           ");
    printf("\n===================================================================================================================");
    printf("\n                                           CANDIDATE SELECTION  ");
    printf("\n                                        **************************");
    printf("\nENTER THE NUMBER OF CANDIDATES WILlING TO PARTICIPATE : ");
	scanf("%d",&candidates);
	printf("\nENTER THE CANDIDATES NAME AND AGE: \n");
    for(i=0;i<candidates;i++)
    scanf("%s %d",ob[i].name,&ob[i].age);
    for(i=0;i<candidates;i++)
    {
    	if(ob[i].age>21)
    	{
          strcpy(cd[j].name1,ob[i].name);
          j++;
       }
    }
    printf("\nTHE SELECTED CANDIDATES : ");
    fp=fopen("voter_list.txt","a");
    fprintf(fp,"\nTHE SELECTED CANDIDATES : ");
 	for(i=0;i<j;i++)
 	{
      printf("\n%d.%s",i+1,cd[i].name1);
      fprintf(fp,"\n%d.%s",i+1,cd[i].name1);
    }
 
}
void election()
{
	printf("\nENTER THE TOTAL POPULATION OF THAT AREA: ");
	scanf("%d",&population);
	pop=population;
	printf("\n--------------------------------------------------------------------------------------------------------------");
	printf("\n                                              CHOOSE UR LEADER                             ");
	printf("\n                                           **********************");
	printf("\n-------------------------------------------------------------------------------------------------------------");

	while(population!=0)
	{	
	    printf("\nSELECT ONE PERSON FROM THE OPTION: \n");
		for(i=0;i<j;i++)
        printf("%d.%s\n",i+1,cd[i].name1);
		scanf("%d",&n);
	 	cd[n-1].votes++;
	 	population--;
	}
	fprintf(fp,"\nCANDIDATES AND THEIR VOTES:");
	for(i=0;i<j;i++)
	fprintf(fp,"\n%s %d",cd[i].name1,cd[i].votes);
	max=0;
	for(i=0;i<j;i++)
	{
	 if(cd[i].votes>max)
	 max=cd[i].votes;
	}
	for(i=0;i<j;i++)
	{
			if(cd[i].votes==max)
			{
				count++;
			}
	}

}
void re_election()
{
		printf("\n%d CANDIDATES HAVE RECEIVED SAME NUMBER OF VOTES",count);
		fprintf(fp,"\n%d CANDIDATES HAVE RECEIVED SAME NUMBER OF VOTES",count);
		printf("\n                                              RE ELECTION         ");
		fprintf(fp,"\n                                              RE ELECTION         ");
		printf("\n                                           ****************");
		for(i=0;i<j;i++)
		{
			if(cd[i].votes==max)
			{
				strcpy(reename[k],cd[i].name1);
				k++;
			}
		}
		while(pop!=0)
		{	
			printf("\nSELECT ONE PERSON FROM THE OPTION: \n");
			for(i=0;i<j;i++)
      			printf("%d.%s\n",i+1,cd[i].name1);
			scanf("%d",&m);
			re[m-1]++;
			pop--;
	 	}

	for(i=0;i<k;i++)
	{
		if(max1<re[i])
		max1=re[i];
	}
		for(i=0;i<k;i++)
		{
			printf("\n%d.%s %d",i+1,reename[i],re[i]);
			fprintf(fp,"\n%d.%s %d",i+1,reename[i],re[i]);
		}
		for(i=0;i<k;i++)
	    {
			if(re[i]==max1)
			{
				printf("\nTHE WINNER IS %s",reename[i]);
				fprintf(fp,"\nTHE WINNER IS %s",reename[i]);
				break;
			}
	   }
}
void result()
{
			for(i=0;i<j;i++)
		{
			if(cd[i].votes==max)
			{
				printf("\n**************************THE WINNER IS %s**************************************",cd[i].name1);
				fprintf(fp,"\n THE REPRESENTATIVE FOR THIS AREA IS: %s",cd[i].name1);
				break;
			}
}

}
void main()
{
    help();//calling the instruction function
    candidate_selection();//for selecting the candidates
    print();//printing the selected candidates
    election();//conducting the election
   
	if(count>1)
	{
      re_election(); //re election for candidates who got same votings 
    }
	else
	{
      result();//printing the results
    }
}   
