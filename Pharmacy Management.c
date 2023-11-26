#include<stdio.h>
#include<string.h>

#define RESIDUAL_STOCK 2 // Macro that defines the residual stock the pharmacy must maintain
// Define the Pharmacy structure with the product name and its quantity
struct Pharma
{
	char Name[20];
	int Quan;
};

// Function definitions 
void display(FILE* fp2); 
void fill_stock(struct Pharma p_t[3],FILE *fp,int n);
int alter(struct Pharma *p,FILE*fp3);
void write_file(struct Pharma *p,FILE*fp3,int n);
int append_accord(struct Pharma *p,FILE*fp4,int n);


int main()
{
	int n,num;
	struct Pharma p_t[100]; // array of structures 
	struct Pharma s_t[100];
	printf("Welcome to Module\n");
	printf("Enter suitably to carry out the desired action\n");
	printf("1:Fill the empty stock \n 2. Display stock \n 3.Alter the stock \n 4.Delete from stock  5.Quit \n");
	scanf("%d",&num);  // user enters the desired choice
	while(num>0 && num<=4)
	{
		switch(num)
		{
		
			case 1: printf("\nEnter the number of items you want to fill into\n");
				scanf("%d",&n);	
				fflush(stdin);
				FILE* fp=fopen("data1.txt","w");
				fprintf(fp,"Item\tQuantity\n"); // store the quantity and item details inside a stock file "data1.txt"
				fill_stock(p_t,fp,n);
				fclose(fp);
				break;

			case 2: printf("\nFile contents\n");
				FILE* fp2=fopen("data1.txt","r");
				display(fp2); // read the stock contents from the stock file
				fclose(fp2);
				break;

			case 3: printf("\nEnter as follows\n");
				FILE* fp3=fopen("data1.txt","r");
				n=alter(s_t,fp3); // alter the stock contents
				fclose(fp3);
				FILE* fp4=fopen("data1.txt","w");
				write_file(s_t,fp4,n); // rewrite the updates back into the stock file 
				fclose(fp4);
				break;

			case 4: printf("Deletion underway\n");
				FILE* fp5=fopen("data1.txt","r");
				n=append_accord(s_t,fp5,n);  // fetch the record you wish to delete
				fclose(fp5);
				FILE* fp6=fopen("data1.txt","w");
				write_file(s_t,fp6,n); // rewrite the stock file with the updated records
				fclose(fp6);
				break;
		}
		printf("\nEnter choice again\n");
		scanf("%d",&num);
	}
	return 0;
}

// function handles new items that are introduced 
void fill_stock(struct Pharma p_t[100],FILE *fp,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("Enter %d Medicine name\n",i+1);
		scanf("%[^\n]s",&(p_t[i].Name));

		// function writes the medicine name into the stock file
		fprintf(fp,"%s\t",p_t[i].Name);
		printf("Enter %d Quantity\n",i+1);
		scanf("%d",&(p_t[i].Quan));

		//function writes the quantity of the stock/,edicine into the stock file
		fprintf(fp,"%d\n",p_t[i].Quan);
		fflush(stdin);
	}
}

// function displays the contents of the stock file		
void display(FILE* fp2)
{
	char len[200];
	// function reads the file and displays all the strings stored in it
	while(fgets(len,200,fp2)!=NULL)
		printf("%s",len);
	
}

// function writes contents into the stock file
void write_file(struct Pharma *p,FILE*fp3,int n)
{
	fprintf(fp3,"Item\tQuantity\n");
	for(int i=0;i<n;i++)
	{
		fprintf(fp3,"%s\t",p[i].Name);
		fprintf(fp3,"%d\n",p[i].Quan);
	}
}



int alter(struct Pharma *p,FILE*fp3)
{
	int i=0; int n1;
	char len[200];
	fgets(len,200,fp3);
	while(fscanf(fp3,"%s",&(p[i].Name))!=EOF)
	{
		fscanf(fp3,"%d",&(p[i].Quan));
		i++;
	}
	// function adds new stock or deducts stock when customer buys medicine or refills the stock with new supplies 

	printf("1.Add new medicines to the stock \n2.Customer intends to buy medicine\n4.Refill the stock with supplies\n");
	scanf("%d",&n1); // user enters the choice on altering the stock file
	fflush(stdin);
	char search[20]; // stock item for which stock alteration is needed
	int new,check,add;
	switch(n1)
	{
		case 1: 	
			printf("How many additional records do you wish to add?\n");
			scanf("%d",&add);
			for(int k=i;k<(add+i);k++)
			{
				fflush(stdin);
				printf("Enter %d Medicine name\n",k+1);
				scanf("%[^\n]s",&(p[k].Name));
				printf("Enter %d Quantity\n",k+1);
				scanf("%d",&(p[k].Quan));
			}
			i=add+i;
			fflush(stdin);
			printf("Stock successfully filled\n");
			break;

		case 2:	
			printf("Enter search element\n");
			scanf("%[^\n]s",search);
			for(int j=0;j<i;j++)
			{
				if(strcmp(search,(p[j].Name))==0) // search for the item in the stock list
				{
					printf("Old quantity is %d \n",p[j].Quan);
					printf("Enter quantity required\n");
					scanf("%d",&new);
					check=(p[j].Quan)-new;
					if(check<RESIDUAL_STOCK) // Request cannot cause the stock to fall below a certain quantity
						printf("Stock is low.Cannot process request! Please refill your supplies \n");
					else
					{
						p[j].Quan=check;
						printf("Stock succesfully altered\n");
					}	
				}
			}
			
			break;

		case 3: 
			printf("Enter search element\n");
			scanf("%[^\n]s",search);
			for(int j=0;j<i;j++)
			{
				if(strcmp(search,(p[j].Name))==0) // check for stock item in the stock list
				{
					printf("Old quantity is %d \n",p[j].Quan);
					printf("Enter refill quantity\n");
					scanf("%d",&new);
					check=(p[j].Quan)+new; // new stock is added to existing stock quantity 
					p[j].Quan=check;	
				}
			}
			printf("Stock successfully refilled\n");
			break;		
	}
	return i;
}

// function deletes stock records from the stock file 
int append_accord(struct Pharma *p,FILE*fp4,int n)
{
	char search[20]; char temp[20]; 
	int count=n;
	printf("Enter the name of the medicine you want to remove from the stock\n");
	fflush(stdin);
	scanf("%[^\n]s",search);
	for(int i=0;i<n;i++)
	{
		if(!strcmp(search,fscanf(fp4,"%s",temp))) // iterative check for stock record
		{
			strcpy(p[i].Name,temp);	// copy all those stock records back into the stock file that do not match the item to delete
			fscanf(fp4,"%d",&(p[i].Quan));	
		}
		else
			count=n-1; 
	}
	printf("Stock succesfully deleted\n");
	return count;
}
	
					
			



