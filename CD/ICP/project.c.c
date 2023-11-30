#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>


void mainmenu(); 			// show the option for entry
void login();         		// to enter in the system	
void signup();        		// to make you id in the system
void enter_donation();		// to enter the donation 
void view_donation();		// view doantion that is available in the system
void update_donation();		// to update the donation	
void search_donation();		// to search the donation 	 
void add_donation();		// to add donation	
void distribution();		// for distributing donation	
void delete_donation();		// delete donation from the list	
void display_distribution();// to show distribute items using bubble short
void displaylist();			// for dislaying the list of distribution
void bubblesort();			// for using bubble short


void main()   		   		// this a login and signup function
{
	int choice;
	
	system ("cls");
   
	printf("\n\t\t\t*************************\n\t\t\t **WELCOME TO C-19 DMS**\n\t\t\t*************************");
    
    printf("\n\n\tWhich operator do you want to perform?\n\t");
	a:
    printf("\n\t1. login");
    printf("\n\t2. signup");
    printf("\n\t3. Exit");
    
    printf("\n\n\tplease enter a valid number to perform task!!\n\t:",choice);

	scanf("%d",&choice); fflush(stdin);
	
	switch(choice)
	{
		case 1: login(); 		// getway to inter into login
				break;
			
		case 2: signup();		//  this option is for new user
				break;
			
		case 3: system("cls");
				printf("\n\tThankyou for using!!\n\n\tPress any key to exit!\n");
				return;
		default: system("cls");
		printf("\n\n\tInvalid choice, Please Enter from [1-3]\n\n\t");
		goto a;
		getch();
	}
	mainmenu();
}


void signup()    			// the signup function
{
	system("cls");
	printf("\n\t\t\tSIGNUP PAGE");
	printf("\n\t\t------------------------\n\t");
	int age;
	char f_name[10], l_name[10], username[10], password[10], c_password[10];
	
	FILE*L;
	
	L=fopen("Login.txt","a"); 	// file that store information of user 
	
	if(L==NULL)
	{
		printf("\n\nFile couldnot be opened!"); getch(); return;
	}
	
	printf("\n\tEnter your information:\n\n");
	printf("\n\tAge:");  scanf("%d", &age); fflush(stdin);
	printf("\n\tFirst Name:"); gets(f_name); fflush(stdin);
	printf("\n\tlast Name:"); gets(l_name); fflush(stdin);
	
	printf("\n\tset your username and password which will be use for login!!\n");
	printf("\n\tUsername:"); gets(username); fflush(stdin);
	B:
	printf("\n\tPassword:"); gets(password); fflush(stdin);
	printf("\n\tConfirm Password:"); gets(c_password); fflush(stdin);
	if(strcmp(password,c_password)==0)
	{
	fprintf(L,"%d %s %s %s %s\n",age,f_name, l_name, username, password);
	printf("\n\n\tAccount registered!!!\n");
	
	fclose(L);
	login();
	}
	else
	{
		system("cls");
		printf("\tPlease Renter the Password!!\n\t");
		goto B;
	}
	
}
void login()		// function to enter the username and password
{
	
	system("cls");
	printf("\n\t\t\tLOGIN PAGE");
	printf("\n\t\t------------------------\n\t");
	int age;
	char f_name[10], l_name[10], username[10], password[10];
	char  un[20], pd[20];
	FILE*L;
	
	L=fopen("Login.txt","r"); 	//  reading the data from file
	
	if(L==NULL)
	{
		printf("\n\nFile couldnot be opened!"); getch(); return;
	}
	

	printf("\n\tEnter username:");
	gets(un);
	
	printf("\n\tEnter password:");
	gets(pd);
	
	while(fscanf(L,"%d %s %s %s %s",&age, f_name, l_name, username, password)==5)
	{
		if((strcmp(username,un)==0)&&(strcmp(password,pd)==0))
		{
			fclose(L);
			printf("\n\tlogin successfull");
			printf("\n\n\tEnter any key to go in home page of donation management systen!!!");
			getch();
			return ;
		}
	
	}
	printf("\n\tInvalid username or password!! Try again"); getch(); login();
	
}

void mainmenu()		// this function will display the menu 
{   

	int choose;	
	system ("cls");
	H:
	
	printf("\n\t\t\t*****************************************\n\t\t\t **Donation Management System Home Page**\n\t\t\t*****************************************");
	printf("\n\t1. Enter doantion \n");
	printf("\n\t2. View donation \n");
	printf("\n\t3. Update donation \n");
	printf("\n\t4. Search donation \n");
	printf("\n\t5. Delete donation \n");
	printf("\n\t6. Display_distributed_donation \n");
	printf("\n\t7. Exit \n");
	
	
	printf("\n\tWhich option do you want to choose?\n\t Number :");
	scanf("%d",&choose);
	fflush(stdin);
	switch(choose)
	{
		case 1: enter_donation(); 
			break;
		case 2: view_donation();
			break;
		case 3: update_donation();
			break;
		case 4:search_donation();
			break;
		case 5: delete_donation();
			break;
		case 6: display_distribution();
			break;
		case 7: system ("cls");
			printf("\n\n\t\t Bye\n\t\t Have a nice Day!!!!\n\n");
			return;
		default :system ("cls");
			printf("\n\n\tInvalid choice, Please Enter from [1-7]\n\n\t");
			goto H;
			getch();
	}
}
 void enter_donation() // function to enter the donation
	{
		system ("cls");
		char s_name[40],s_code[40],donator[40];
		int no_of_shipment;
		float quantity_received;
	
	FILE *L2;
	int choice;
	
	L2=fopen("donation.txt","a");
	
	if(L2==NULL)
	{
		printf("\n\nFile could not be opened!\n"); getch(); return;
	}
	
	for(;;)
	{
		printf("\n\t\t\tEnter Donation record:");
		printf("\n\t\t\t----------------------\n\t");
		printf("\n  \n\n");
		printf("\n	Supply Name: "); 
		scanf("%s",&s_name); fflush(stdin);
		printf("\n	Supply Code: "); 
		gets(s_code); fflush(stdin);
		printf("\n	Donator: ");
		gets(donator); fflush(stdin);
		printf("\n	Shipment Count: ");
		scanf("%d",&no_of_shipment); fflush(stdin);
		printf("\n	Received Quantity(M): ");
		scanf("%f",&quantity_received); fflush(stdin);
	
	
		fprintf(L2,"%s %s %s %d %f\n",s_name,s_code,donator,no_of_shipment,quantity_received);
		
		if(fprintf!=0)
		{
			printf("\n\n Data written successfully to file!\n");
		}	
		else 
		{
			printf("\n\nSomething went wrong..\nTry again..");	
		}
		printf("Do you want to Re Enter donation?[1=yes,0=no ]:");
		scanf("%d",&choice); fflush(stdin);
		if(choice==1) continue; 
		else 
		break;
	}
	fclose(L2);
	mainmenu();
	}
	
	
void view_donation() 		// this a function for viewing donation
{
	char s_name[40],s_code[40],donator[40];
	int no_of_shipment;
	float quantity_received;
	int choice;
	system("cls");

	FILE *L2;
	L2=fopen("donation.txt","r");
	
	if(L2==NULL)
	{
		printf("\nNo data to display...\n");
	}
	printf("\n\n\t\t\tView Donation record:");
		printf("\n\t\t\t----------------------\n\t");
	printf("\n\t\t Following donation record read from file!!\n");
	printf("\t\t____________________________________________\n");

	printf("\t\tSupply Name\t\t\tSupply code\t\tDonator\t\tShipment Count\t\tQuantity Received\n");
	
	printf("\t\t-----------\t\t\t-----------\t\t--------\t-------------\t\t---------------\n");
	while(fscanf(L2,"%s %s %s %d %f",s_name,s_code,donator,&no_of_shipment,&quantity_received)==5)
{
	printf("\n\t\t%s\t\t\t\t\t%s\t\t%s\t\t\t%d\t\t%f\n\n",s_name,s_code,donator,no_of_shipment,quantity_received);
}

	fclose(L2);
	
	printf("\n\n\t\t\tDo you want to goto mainmenu?[1=yes,0=no]?:");
	scanf("%d",&choice); fflush(stdin);
	
	if(choice==1)
	{
	
		 mainmenu(); 
	}
	else
	{
	 
		system ("cls");
		printf("\t\t\n\n\t\t\tEnter any key to close!!!!!!\t\t\n\n\n\n\t");
		return;
	}
	
}	


void search_donation()		// function to search donation
{
	int choice;
	char searchId[40];
	char s_name[40],s_code[40],donator[40];
	int no_of_shipment;
	float quantity_received;
	system("cls");
	FILE *L2;
	L2=fopen("donation.txt","r");
		if(L2==NULL)
	{
		printf("\nNo data to display...\n");
	}
	M:
	printf("\n\t\t\tSearch Donation record:");
	printf("\n\t\t\t----------------------\n\t");
	
	
	printf("\n\tEnter a ID which you want to search!!: "); scanf("%s",&searchId);

	
	while(fscanf(L2,"%s %s %s %d %f",s_name,s_code,donator,&no_of_shipment,& quantity_received)==5)
	{
		if(strcmp(searchId,s_code)==0) 
		{
	
			printf("\n\n\nSupply Name\t\t\t\tSupply code\t\t\tDonator\t\tShipment Count\t\tQuantity Received\n");
	
			printf("-----------\t\t\t\t-----------\t\t\t--------\t-------------\t\t-----------------\n");

			printf("%s\t\t\t\t\t%s\t\t\t%s\t\t\t%d\t\t%f\n\n",s_name,s_code,donator,no_of_shipment,quantity_received);
			fclose(L2);
		}
	}
	if(strcmp(searchId,s_code)!=0) 
	{
		printf("\n\n\tCode not found");
	}
	
	printf("\n\n\t\t\tDo you want to goto mainmenu?[1=yes,0=no]?:");
	scanf("%d",&choice); fflush(stdin);
	
	if(choice==1)
	{
	
		 mainmenu(); 
	}
	else
	{
	 
		system ("cls");
		printf("\t\t\n\n\t\t\tEnter any key to close!!!!!!\t\t\n\n\n\n\t");
		return;
	}	
	
}


void update_donation() // funciton to update like add and distribute donation
{
	int choice;
	system ("cls");
	D:
	printf("\n\t\t\tUpdate Donation record:");
	printf("\n\t\t\t----------------------\n\t");
	printf("which number you are looking for?");
	printf("\n	1.Add Donation: ");
	printf("\n	2.Distribute Donation: ");
	printf("\n	3.Goto mainmenu: ");
	printf("\n\n\n Enter Your Choice From[1-2]: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			add_donation(); break;
		case 2:
			distribution(); break;
		case 3:
			mainmenu(); break;
		default:system ("cls");
			printf("\n\tInvalid Input\n");
			goto D;
	}
	getch();
}


void add_donation()		//  function to add donation 
{
	char s_name[40],s_code[40],donator[40],check_s_code[40];
	int no_of_shipment;
	float quantity_received, added_quantity;
	
	FILE *L2= fopen("donation.txt","r");
	FILE *fp=fopen("tmp.txt","a");

	if(L2==NULL || fp==NULL)
	{
		printf("\n File can't be opened!'"); getch(); return;
	}
	printf("\n Supply Code: "); scanf("%s",&check_s_code); fflush(stdin);
	printf("\n Received Quantity: "); scanf("%f",&added_quantity); fflush(stdin);
	
	while(fscanf(L2,"%s %s %s %d %f",s_name,s_code,donator,&no_of_shipment,&quantity_received)==5)
	{
		if(strcmp(check_s_code,s_code)==0)
		{
			quantity_received= quantity_received + added_quantity;
			fprintf(fp,"%s %s %s %d %.2f\n",s_name,s_code,donator,no_of_shipment,quantity_received);
			continue;
		}
		fprintf(fp,"%s %s %s %d %.2f\n",s_name,s_code,donator,no_of_shipment,quantity_received);
	}
	fclose(L2);
	fclose(fp);
	remove("donation.txt");
	rename("tmp.txt","donation.txt");
	mainmenu();
	
}


void distribution()		// funciton to distribute donation
{
	char s_name[40],s_code[40],donator[40],check_supply[40];
	int no_of_shipment;
	float quantity_received,dist_quantity;
	
	FILE *L2=fopen("donation.txt","r");
	FILE *L3=fopen("dist.txt","a");
	FILE *tmp=fopen("tmp.txt","a");
	
	if(L2==NULL || tmp==NULL)
	{
		printf("\nFile Could Not be opened.\n"); getch(); return;
	}
	
	printf("\nSupply code: "); scanf("%s",&check_supply); fflush(stdin);
	printf("\nDistribution Quantity: "); scanf("%f",&dist_quantity); fflush(stdin);	
	while(fscanf(L2,"%s %s %s %d %f\n",s_name,s_code,donator,&no_of_shipment,&quantity_received)==5)
	{
		if(strcmp(check_supply,s_code)==0)
		{
		  quantity_received=quantity_received-dist_quantity;
		  fprintf(tmp,"%s %s %s %d %.2f\n",s_name,s_code,donator,no_of_shipment,quantity_received);
		  fprintf(L3,"%s %.2f\n",s_code,dist_quantity );
		  
		  fclose(L3);
		  printf("\n Data written successfully on dist.txt file.\n");
		  continue;
		  
		}
		fprintf(tmp,"%s %s %s %d %.2f\n",s_name,s_code,donator,no_of_shipment,quantity_received);
	}
	fclose(L2);fclose(tmp);
	remove("donation.txt");
	rename("tmp.txt","donation.txt");
	mainmenu();
	
}

void delete_donation()		// function to delete donation from the list
{
	FILE *L2=fopen("donation.txt","r");
	FILE *L3=fopen("tmp.txt","a");
	
	char searchcode[40];
	
		char s_name[40],s_code[40],donator[40];
		int no_of_shipment;
		float quantity_received;
	
	system("cls");
	printf("\nDelete Record.....\n");
	printf("\n-----------------------------\n");
	printf("\nEnter Supply Code to be delete!!: ");
	scanf("%s",&searchcode);
	while(fscanf(L2,"%s %s %s %d %f",s_name,s_code,donator,&no_of_shipment,&quantity_received)==5)
	{
		if(strcmp(searchcode,s_code)==0)
		{
			continue;
		}
		fprintf(L3,"%s %s %s %d %f\n",s_name,s_code,donator,no_of_shipment,quantity_received);
	}
		fclose(L2);
		fclose(L3);
		remove("donation.txt");
		rename("tmp.txt","donation.txt");
		mainmenu();

}

	struct distem
	{
	char s_name[40],s_code[40],donator[40];
	int no_of_shipments;
	float quantity_recieved;
	};
 
 
 
 
 
 
 
 void bubblesort(struct distem P[], int n)		// function for bubbleshort
{
	int i,j;
	struct distem tmp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(P[j].quantity_recieved<P[j+1].quantity_recieved)
			{
				tmp=P[j];
				P[j]=P[j+1];
				P[j+1]=tmp;
			}
		}
	}
	return;
}
 void viewdistribution(struct distem P[], int n) 	//function to viewdistribute 
{
	
	int i;
	for(i=0;i<n;i++)
	{
		printf("\n %s\t\t%f",P[i].s_code,P[i].quantity_recieved);
	}
	printf("\n\npress any key to goto menu");
	getch();
	mainmenu();
	
}
void display_distribution() 		// function to display the distribution after bubbleshort
{
    int i=0;
    struct distem A[40];
    struct distem tmp;

    char s_code[30],s_name[30],donator[30];
    float quantity_recieved;
    int no_of_shipment;

    FILE *rc=fopen("dist.txt","r");
    if(rc==NULL)
    {
        printf("\n    No files found :|\n");
    }
    printf("\n    Distribution List...\n");
    printf("\n    ----------------------------------");
    printf("\n    Supply Code    Dist.Quantity(M)");
    printf("\n    ----------------------------------");
    while(fscanf(rc,"%s %f",s_code,&quantity_recieved)==2)
    {
        tmp.quantity_recieved=quantity_recieved;
        strcpy(tmp.s_code,s_code);
        A[i]=tmp;
        i++;
    }
    fclose(rc);
    bubblesort(A,i);
    viewdistribution(A,i);
    printf("\n\npress any key to go to menu");
    getch();
    mainmenu();

}
