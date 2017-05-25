#include<stdio.h>

#define FARE 1.0
struct Passenger
{
	double kms;
	double money;
	int yes;
};

void Print(struct Passenger Cab[])
{
	int i;
	printf("No	Kms		Money		Yes\n");
	for(i=0;i<6;i++)
		printf("%d:	%f	%f	%d\n",i,Cab[i].kms,Cab[i].money,Cab[i].yes);
}
int NoOfPassengers(struct Passenger Cab[])
{
	int n=0,i;
	for(i=0;i<6;i++)
	{
		if(Cab[i].yes==1)
			n++;
	}
	return n;
}
void Dist(struct Passenger Cab[],int dist,int n)
{
	int i;
	for(i=0;i<n;i++)
	{

		Cab[i].money+=FARE*dist/n;
		Cab[i].kms+=dist;
	}
}
void Delete(struct Passenger Cab[],int i)
{
	Cab[i].yes=0;
	Cab[i].kms=0;
	Cab[i].money=0;
}
void GetOn(struct Passenger Cab[])
{
	int m,i,n=NoOfPassengers(Cab);
	printf("How many will get on?");
	scanf("%d",&m);
	if(m+n>6)
		printf("not possible");
	for(i=n;i<m+n;i++)
		Cab[i].yes=1;
	Print(Cab);
}
void GetOff(struct Passenger Cab[])
{
	int n,i,j,l,k;
	Print(Cab);
	printf("How many will get off?");
	scanf("%d",&n);
	int arr[6];
	printf("Who will get out??");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<n;i++)
		Delete(Cab,arr[i]);
	n=NoOfPassengers(Cab);
	for(j=5;j>=0;j--)
		if(Cab[k].yes==1)
			break;


	if(n!=j)
	{
		for(l=0;l<=j;l++)
		{
			for(i=0;i<=j;i++)
			{
				if(Cab[i].yes==0)
				{
					Cab[i]=Cab[i+1];
					Delete(Cab,i+1);
				}
			}
		}
	}

}
int Stop(struct Passenger Cab[])
{
	printf("Distance to next stop:");
	int dist,n;
	scanf("%d",&dist);
	n=NoOfPassengers(Cab);
	Dist(Cab,dist,n);
	GetOff(Cab);
	GetOn(Cab);
	printf("End trip?(If no return 0,or else anything else)");
	scanf("%d",&n);
	return n;
}


int main()
{
	struct 	Passenger Cab[6]={0.0,0.0,0};
	printf("Enter Initial Passengers:");
	int n,x,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		Cab[i].yes=1;
	Print(Cab);
	do
	{
		x=Stop(Cab);
	}while(x==0);
}
