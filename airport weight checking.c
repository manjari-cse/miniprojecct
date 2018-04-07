#include <stdio.h>

int main(void) {
	int option;
	void function1();
	void function2();
	 printf("choose the option\n1.single passenger\n2.mulipassenger");
	 scanf("%d",&option);
	 switch(option)
	 {
	 	case 1:
	 	{
	 	function1();
	 	break;
	 	}
	 	case 2:
	 	{
	 	function2();
	 	break;
	 	}
	 }
	 return 0;
}
	 void function1(){
	 	int weight;
	 	printf("\nenter the weight");
	 	scanf("%d",&weight);
	 	weight=weight-15;
	 	if(weight>0)
	 	printf("%dRs amount u have to pay in extra",weight*200);
	 	else
	 	printf("no need to pay extra amount");
	 }
void function2()
{
	int weight[100],num,sum=0,i;
	printf("enter number of persons");
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		printf("enter %d persons weight",i+1);
	scanf("%d",&weight[i]);
	sum=sum+weight[i];
	}
	if(sum>num*15){
	sum=sum-num*15;	
	printf("%drs amount you have to pay in extra",sum*200);
	}
	else
	printf("no extra amount needed");
}
