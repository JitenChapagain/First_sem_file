#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void login();  // for login

void mainn();  // main interface
void signup();   //for signup
void inventory();  // add item in inventory
void display();  // display inventory
void delete();   // to delete inventory
void distribution (); // to distribute from inventory
void update(); //add additional quantity
void search(); // to search specific items
void bubblesort(); //to arrange in order
void viewdistribution(); // to display distribution
void displaydistribution();



struct items{
	char name_of_the_supply[30],supply_code[30],donator[30];
	int shipments;
	float quantity_recieved;
};

void main()
{	
int choice;
system ("cls");
printf("\n Press '1' for login");
printf("\n\n Press '2' for signup\n\n\n");
scanf("%d",&choice);
 fflush(stdin);
switch(choice)
{
case 1:
 login();
break;
system("cls");
case 2:
 signup();
break;

default:
	printf("\n\n\nEnter valid Number!!!!!!!!!!!!!!!!!!!!!!!!!! ");
	break;
system("cls");
getch();
}
}
void signup()
{
system("cls");
int age, n;
char f_name[10], l_name[10], username[10], password[10], email[20];
FILE*L;
L=fopen("Login.txt","a");
if(L==NULL)
{
printf("\n\nFile couldnot be opened!");
 getch();
  return;
}
printf("\nEnter your information:\n\n");
printf("\nAge:"); 
scanf("%d", &age);
 fflush(stdin);
printf("\nFirst Name:");
 gets(f_name);
  fflush(stdin);
printf("\nlast Name:");
 gets(l_name);
  fflush(stdin);
  printf("\n phone_number:");
  scanf("%d", &n);
  fflush(stdin);
printf("\nEmail:");
 gets(email);
  fflush(stdin);

printf("\nUsername:");
 gets(username);
  fflush(stdin);
printf("\nPassword:");
 gets(password);
  fflush(stdin);

fprintf(L,"%d %s %s %s %s\n",age,f_name, l_name, username, password);
printf("\n\n Account registered!!!\n");

fclose(L);
system ("cls");
login();
}
void login()
{	
int age;
char f_name[10], l_name[10], username[20], password[20];
char un[20], pd[20];
FILE*L;
L=fopen("Login.txt","r");
if(L==NULL)
{
printf("\n\nFile couldnot be opened!");
 getch();
  return;
}
printf("\nEnter username:");
gets(un);
printf("\nEnter password:");
gets(pd);
while(fscanf(L,"%d %s %s %s %s",&age, f_name, l_name, username, password)==5)
{
if((strcmp(username,un)==0)&&(strcmp(password,pd)==0))
{
fclose(L);
printf("login successfull");
printf("\n\n Press any key to move to the further system!!!");
getch();
mainn();
}
}
printf("\nInvalid username or password..\nRe-enter......");
 getch(); 
}
void mainn()
{
system("cls");
system("color a ");	
int num, i;
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xBWelcome to Covid Donation Management System\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB\n");
printf("[1]= Add items in inventory\n"); 
printf("[2]= Display donators\n");
printf("[3]= Update donation\n");
printf("[4]= Distribute donation\n");
printf("[5]= Search donation\n");
printf("[6]= Show distribited donation\n");
printf("[7]= Delete donation\n\n");
printf("Enter your choice:  ");
scanf("%d", &num);
switch (num)
{
	case 1:
	    inventory();
       	break;
    case 2:
	    display();
	    break;
	case 3:
		update ();
	    break;	   	
	case 4:
		distribution ();
		break;
	case 5:
		search();
		break;
	case 6:
		displaydistribution();
		break;
	case 7:
	    delete();
		break;	
		
}
		getch();
    while(num !=7);
    system("CLS");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    printf("Thank You For Using This System\n");
   
    getch();
    
}
// INVENTORY CREATION*****************
void inventory()
{
	int choice;
	char material[50], code[10],donator[50];
	int shipments;
	float quantity;
	FILE * iv;
	iv=fopen("donation.txt","a");
	if(iv==NULL)
	{
		printf("file could not be opened");
		getch();
		return;
	}
	for(;;)
	{
	system("cls");
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Enter donation records\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("Name of the material:");
	 scanf("%s", &material);
	 fflush(stdin);
	printf("supply code:");
	scanf("%s", &code);
	fflush(stdin);
	printf("donator:");
	 scanf("%s", &donator);
	 fflush(stdin);
	printf("shipments count:");
	scanf("%d", &shipments);
	fflush(stdin);
	printf("Quantity(in millions):");
	scanf("%f", &quantity);
	fflush(stdin);
	fprintf(iv,"%s %s %s %d %f\n", material,code,donator,shipments,quantity);
	printf("donation record written successfully to file!\n\n!");
	printf("Do you want to continue the process?? 0[yes],1[no]");
	 scanf("%d", &choice);
	if(choice==0)
	{
		continue;	
	}
	else
	break;
	}
	fclose(iv);
	
	getch();
	mainn();
}
//DISPLAY INVENTORY************************
void display()
{
	
	char material[30],donator[30],code[10];
	int shipment;
	float quantity; 
	FILE *iv;
	iv=fopen("donation.txt","r");
	if(iv==NULL)
	{
		printf("file could not be read");
		getch();
		return;
	}
	printf("|-------------------------|-------------|---------------|-----------|----------|\n");
	printf("|     name of supply      | supply code |    donator    | shipments | quantity |\n");
	printf("|-------------------------|-------------|---------------|-----------|----------|\n");
	while(fscanf(iv,"%s %s %s %d %f\n",material, code,donator,&shipment,&quantity)==5)
	{
		
	printf("|%25s|%13s|%15s|%11d|%7.3f   |\n",material,code,donator,shipment,quantity);
	printf("|-------------------------|-------------|---------------|-----------|----------|\n");
	}
	fclose(iv);
	printf("\n\n\npress any key to goto menu");
	getch();
	mainn();	
}

//UPDATE INVENTORY
void update()
{
	system("cls");
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Enter the Supply code you want to add \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  ");
		char material_name[30];
		char code[30], check_code[30];
		char donator[30];
		int shipments;
		float quantity,updated_donation;

		FILE *L2= fopen("donation.txt","r");
		FILE *L3=fopen("tmp.txt","a");



		if(L2==NULL || L3==NULL)
		{
			printf("\n File can't be opened!'");
			 getch();
			  return;
		}
		printf("\n Code:\n "); 
		scanf("%s",check_code);
		 fflush(stdin);
		printf("\n Quantity (in million):\n");
		 scanf("%f",&updated_donation);
		  fflush(stdin);

		while(fscanf(L2,"%s %s %s %d %f\n",material_name,code,donator,&shipments,&quantity)==5)
		{
			if(strcmp(code,check_code)==0)
		{
		quantity= quantity + updated_donation;
		fprintf(L3,"%s %s %s %d %f\n",material_name,code,donator,shipments,quantity);
		continue;
		}
			fprintf(L3,"%s %s %s %d %f\n",material_name,code,donator,shipments,quantity);
		}
		fclose(L2);
		fclose(L3);
		remove("donation.txt");
		rename("tmp.txt","donation.txt");
		printf("\n\n\npress any key to goto menu");
		getch();
		mainn();
		system ("cls");
}

//DISTRIBUTE INVENTORY***************
void distribution()
{
	system("cls");
	char material[50],code[10],donator[50],check_supply[30];
	int shipment;
	double quantity,d_quantity;

	FILE *L2=fopen("donation.txt","r");
	FILE *L3=fopen("dist.txt","a");
	FILE *temp=fopen("temp.txt","a");
	

	if(L2==NULL || L3==NULL)
	{
		printf("\nFile Could Not be opened.\n");
		 getch();
		  return;
	}
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Enter the following \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
	printf("\nSupply code: ");
	 scanf("%s",&check_supply);
	  fflush(stdin);
	printf("\nDistribution Quantity: ");
	 scanf("%lf",&d_quantity);
	  fflush(stdin);
	while(fscanf(L2,"%s %s %s %d %lf\n",material,code,donator,&shipment,&quantity)==5)
	{
		if(strcmp(check_supply,code)==0)
	{
		quantity=quantity-d_quantity;
		fprintf(temp,"%s %s %s %d %lf\n",material,code,donator,shipment,quantity);
		fprintf(L3,"%s %f\n",code,d_quantity);
		continue;
	}
		fprintf(temp,"%s %s %s %d %lf\n",material,code,donator,shipment,quantity);
	}
	printf("\n	Data written successfully in dist.txt");
	 getch();
	fclose(L2);
	fclose(L3);
	fclose(temp);
	remove("donation.txt");
	rename("temp.txt","donation.txt");
	printf("\n\npress any key to goto menu");
	getch(); 
	mainn();
	
}
//SEARCH ITEMS IN INVENTORY**************
void search()
{
	
char searchId[40];
char supply_name[40],supply_code[40],donator[40];
int no_of_shipment;
float quantity_received;

FILE *L2;
L2=fopen("donation.txt","r");
system("cls");
printf("\nSearch Donations...\n");
printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  \n");
printf("\nDontion ID: ");
 scanf("%s",&searchId);

while(fscanf(L2,"%s %s %s %d %f",supply_name,supply_code,donator,&no_of_shipment,&quantity_received)==5)
{
if(strcmp(searchId,supply_code)==0)
{

printf("\nResults for %s:..\n",searchId);
printf("\n Supply Name: %s\n",supply_name);
printf("\n Supply Code: %s\n",supply_code);
printf("\n Donator: %s\n",donator);
printf("\n Shipment Count: %d\n",no_of_shipment);
printf("\n Quantity Received(M): %f",quantity_received);
printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
}



}
fclose(L2);
getch();
return;
mainn();
}

//DELETE ITEMS FROM INVENTORY***********
void delete()
{
system("cls");
FILE *iv=fopen("donation.txt","r");
FILE *iv1=fopen("tmp.txt","a");

 char name_of_the_supply[30],donator[30],supply_code[30],sc[30];
 int no_of_shipments;
 float quantity_recieved;


  printf("\n Enter supply code to delete:");
  
  scanf("%s",&sc); 
  fflush(stdin);

   while(fscanf(iv,"%s %s %s %d %f\n",name_of_the_supply,supply_code,donator,&no_of_shipments,&quantity_recieved)==5)
   {

    	if(strcmp(sc,supply_code)==0)
    	{
        	continue;
    	}
        fprintf(iv1,"%s %s %s %d %f\n",name_of_the_supply,supply_code,donator,no_of_shipments,quantity_recieved);
	}
    fclose(iv);
	fclose(iv1);
	remove("donation.txt");
    rename("tmp.txt","donation.txt");
    printf("\n\npress any key to goto menu");
    getch();
	mainn();
          

 }
 
 void bubblesort(struct items P[], int n)
{
	int i,j;
	struct items teemp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(P[j].quantity_recieved<P[j+1].quantity_recieved)
			{
				teemp=P[j];
				P[j]=P[j+1];
				P[j+1]=teemp;
			}
		}
	}
	return;
}

void viewdistribution(struct items P[], int n)
{
	
	int i;
	for(i=0;i<n;i++)
	{
		printf("\n %s\t\t%f",P[i].supply_code,P[i].quantity_recieved);
	}
	
	getch();
	mainn();
	
}


//DISPLAY DISTRIBUTED ITEMS

void displaydistribution()
{
	system("cls");
    int i=0;
    struct items A[40];
    struct items teemp;

    char supply_code[30],supply_name[30],donator[30];
    float quantity_recieved;
    int shipment;

    FILE *iv=fopen("dist.txt","r");
    if(iv==NULL)
    {
        printf("\n    No files found :|\n");
    }
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n    Distribution List \n");
     printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\nSupply Code    Distributed Quantity(In millions)");
    printf("\n---------------------------------------------");
    while(fscanf(iv,"%s\n %f\n\n",supply_code,&quantity_recieved)==2)
    {
        teemp.quantity_recieved=quantity_recieved;
        strcpy(teemp.supply_code,supply_code);
        A[i]=teemp;
        i++;
    }
    fclose(iv);
    bubblesort(A,i);
    viewdistribution(A,i);
    printf("press any key to goto menu");
    getch();
    mainn();

}

 
 
 
 
 
 
 


