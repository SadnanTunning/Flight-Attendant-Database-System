//header files
#include<stdio.h> //standard I/O operation
#include<windows.h> //Windows-specific header files
#include<conio.h> //for gets()
#include<ctype.h> //for toupper() tolower()
#include<string.h> //for strcmp(),strcpy(),strlen()
#include<stdlib.h> //standard library

char ans=0; //to determine if want to do an operation more than once
int ok; //used for gender verification
int b, valid=0; // alphabetical validity checking and making lower case alphabets converted to uppercase

//function declaration
void WelcomeScreen(void);// Function declaration of Welcome Screen
void Title(void);//Title
void MainMenu(void);//MainMenu
void LoginScreen(void);//Login Screen
void Add_rec(void);//Add record
void func_list();//list
void Search_rec(void);//Search
void Edit_rec(void);//Edit
void Dlt_rec(void);//Delete
void ex_it(void);//exit

void gotoxy(short x, short y) {
COORD pos = {x, y};//sets co-ordinates in (x,y)
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

struct Attendant//global variable list
{
	int age;
	char Gender;
	char First_Name[20];
	char Last_Name[20];
	char Contact_No[15];
	char Address[30];
	char Email[30];
	char Airlines[20];
	char Type[20];
};

struct Attendant p,temp_c;



main(void)
{

    WelcomeScreen();//call WelcomeScreen function
	Title();//call Title function
	LoginScreen();//call Menu function




}
//************************************************** Welcome Screen***************************************************
void WelcomeScreen(void)
{

	printf("\n\n\n\n\n\n\n\t\t\t\t#########################################");
	printf("\n\t\t\t\t#\t\t WELCOME TO\t\t#");
	printf("\n\t\t\t\t#    FLIGHT ATTENDANT DATABASE SYSTEM   #");
	printf("\n\t\t\t\t#########################################");
	printf("\n\n\n\n\n Press any key to continue......\n");
	getch();//holds screen
	system("cls");//clears screen

}
//************************************************** Title Screen *********************************************
void Title(void)
{
	printf("\n\n\t\t----------------------------------------------------------------------------------");
	printf("\n\t\t\t\t       Aviation Operators Association of Bangladesh (AOAB)       ");
	printf("\n\t\t----------------------------------------------------------------------------------");
}
//************************************************* Menu *******************************************************
void MainMenu(void)//function declare
{
	system("cls");
	int choose;
	Title();//Title function calling
	printf("\n\n\n\n\n\t\t\t\t1. Add Flight Attendants Record\n");
	printf("\n\t\t\t\t2. List of Flight Attendants\n");
	printf("\n\t\t\t\t3. Search Flight Attendants Record\n");
	printf("\n\t\t\t\t4. Edit Flight Attendants Record\n");
	printf("\n\t\t\t\t5. Delete Flight Attendants Record\n");
	printf("\n\t\t\t\t6. Exit\n");
	printf("\n\n\n \n\t\t\t\tChoose from 1 to 6:");
	scanf("%i", &choose);

	switch(choose) //switch statement
	{

	case 1:
	Add_rec();//Add record
    	break;
    case 2:
    	func_list(); //View record
    	break;
	case 3:
	Search_rec();//Search record
    	break;
	case 4:
		Edit_rec();//Edit record
		break;
	case 5:
		Dlt_rec();//Delete record
		break;
	case 6:
		ex_it();//exit
    	break;

	default:
		printf("\n\n\n \n\t\t\t\tInvalid entry.");
		getch();
	}//switch ends


}
//************************************************** Exit Screen *********************************************
void ex_it(void)//function
{
	system("cls");
	Title();// title function calling
	printf("\n\n\n\n\n\t\t\tTHANK YOU FOR VISITING");
	getch();

}
//************************************************* Log in Screen *********************************************
void LoginScreen(void)//log in screen function
{
//list of variables
int e=0	; //counter
char Username[15];
char Password[15];
char original_Username[25]="aviation123";
char original_Password[15]="tourism";

do
{
	printf("\n\n\n\n\t\t\t\tEnter Username and Password");
	printf("\n\n\n\t\t\t\t\tUSERNAME:");
	scanf("%s",&Username);

	printf("\n\n\t\t\t\t\tPASSWORD:");
	scanf("%s",&Password);

	if (strcmp(Username,original_Username)==0 && strcmp(Password,original_Password)==0) //compares original & given password
	{
		printf("\n\n\n\t\t\t\t\t...Login Successfull...");


		getch();
		MainMenu();//Main Menu function calling
		break;
	}
	else
	{
		printf("\n\n\n\t\t\t\t\tUsername or Password is incorrect.Try Again.\n");
		e++; //counting how many time attempted
		getch();
	}

}
while(e<=2);
	if(e>2)
	{
	printf("\n\n\n\t\t\t\t\tYou have crossed the limit. You cannot login.");
	getch();
    ex_it();
	}

system("cls");
}


//**************************************Add Record*******************************************

void Add_rec(void)
{
	system("cls");
	Title();//Title function calling

	char ans;
	FILE*ek;//file pointer
	ek=fopen("Record2.dat","a");//opens the binary text file in append mode
	printf("\n\n\t\t\t************** Add Flight Attendants Record **************\n");

	//***************************First Name***********************************

	A:
	printf("\n\t\t\tFirst Name: ");
	scanf("%s",p.First_Name);
	p.First_Name[0]=toupper(p.First_Name[0]);
	if(strlen(p.First_Name)>20||strlen(p.First_Name)<2)
	{
		printf("\n\t Invalid. \t The max range for first name is 20 and min range is 2");
		goto A;
	}
	else
	{
		for (b=0;b<strlen(p.First_Name);b++)
		{
			if (isalpha(p.First_Name[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t First name contain Invalid character. Enter again");
			goto A; //lebel
		}
	}

	//********************************************** Last name ************************************************
	B:
	printf("\n\t\t\tLast Name: ");
    scanf("%s",p.Last_Name);
    p.Last_Name[0]=toupper(p.Last_Name[0]);
    if(strlen(p.Last_Name)>20||strlen(p.Last_Name)<2)
	{
		printf("\n\t Invalid. \t The max range for last name is 20 and min range is 2 ");
		goto B;
	}
	else
	{
		for (b=0;b<strlen(p.Last_Name);b++)
		{
			if (isalpha(p.Last_Name[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Last name contain Invalid character.Enter again ");
			goto B;
		}
	}
//******************************************* Gender **************************************************************
	do
	{
	    printf("\n\t\t\tGender[M/F]: ");
		scanf(" %c",&p.Gender);
		if(toupper(p.Gender)=='M'|| toupper(p.Gender)=='F')
		{
			ok =1;
		}
		else
		{
		ok =0;
		}
        if(!ok)
	    {
	    	printf("\n\t\t Gender contains Invalid character. Enter either M or F ");
    	}
	 }	while(!ok);
//***************************************** Age **********************************************************************
    printf("\n\t\t\tAge:");
    scanf(" %i",&p.age);
//**************************************** Address *******************************************************************
    do
    {
    C:
    printf("\n\t\t\tAddress: ");
    scanf("%s",p.Address);
    p.Address[0]=toupper(p.Address[0]);
    if(strlen(p.Address)>20||strlen(p.Address)<4)
	{
		printf("\n\t Invalid. \t The max range for address is 20 and min range is 4");
		goto C;
	}

}while(!valid);
//******************************************* Contact no.*****************************************
do
{
	D:
    printf("\n\t\t\tContact no: ");
    scanf("%s",p.Contact_No);
    if(strlen(p.Contact_No)>11||strlen(p.Contact_No)!=11)
	{
		printf("\n\t Invalid. Contact No. must contain 11 numbers.");
		goto D;
	}
	else
	{
		for (b=0;b<strlen(p.Contact_No);b++)
		{
			if (!isalpha(p.Contact_No[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Contact No. contain Invalid character.");
			goto D;
		}
	}
}while(!valid);
//************************************************** Email********************************************
do
{
    printf("\n\t\t\tEmail: ");
    scanf("%s",p.Email);
    if (strlen(p.Email)>30||strlen(p.Email)<8)
    {
       printf("\n\t Invalid  \t The max range for email is 30 and min range is 8 ");
	}
}while(strlen(p.Email)>30||strlen(p.Email)<8);
//********************************************************* Airlines ***********************************************
    E:
    printf("\n\t\t\tAirlines: ");
    scanf("%s",p.Airlines);
    p.Airlines[0]=toupper(p.Airlines[0]);
    if(strlen(p.Airlines)>15||strlen(p.Airlines)<3)
	{
		printf("\n\t Invalid  \t The max range for Airline's name is 30 and min range is 3 ");
		goto E;
	}
	else
	{
		for (b=0;b<strlen(p.Airlines);b++)
		{
			if (isalpha(p.Airlines[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\tAirlines name contains Invalid character");
			goto E;
		}
	}
//**********************************************Type ****************************************************
	F:
    printf("\n\t\t\tType:");
    scanf("%s",p.Type);
    p.Type[0]=toupper(p.Type[0]);
    if(strlen(p.Type)>30||strlen(p.Type)<3)
	{
		printf("\n\t Invalid \t The max range for airlines type is 30 and min range is 3 ");
		goto F;
	}
	else
	{
		for (b=0;b<strlen(p.Type);b++)
		{
			if (isalpha(p.Type[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\tAirlines type contains Invalid character");
			goto F;
		}
	}

    fprintf(ek," %s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_No, p.Email, p.Airlines, p.Type);
    printf("\n\n\t\t\t.... Information Record Successful ...");
    fclose(ek);//ek file closed
    sd:
    getch();
    printf("\n\n\t\t\tDo you want to add more[Y/N]?? ");
    scanf(" %c",&ans);
    if (toupper(ans)=='Y')
	{
    	Add_rec();
	}
    else if(toupper(ans)=='N')
	{
		printf("\n\t\tThank you");
    	getch();
    	MainMenu();
	}
    else
    {
        printf("\n\t\tInvalid Input\n");
        goto sd;
    }
}
//**************************************View Record*******************************************
void func_list()
{
	int row;
	system("cls");
	Title();
	FILE *ek;
	ek=fopen("Record2.dat","r"); //reading mode
	printf("\n\n\t\t\t************** List of Flight Attendants **************\n");
	gotoxy(1,15);
		printf("Full Name");
		gotoxy(20,15);
		printf("Gender");
		gotoxy(32,15);
		printf("Age");
		gotoxy(37,15);
		printf("Address");
		gotoxy(49,15);
		printf("Contact No.");
		gotoxy(64,15);
		printf("Email");
		gotoxy(88,15);
		printf("Airlines");
		gotoxy(98,15);
		printf("Type\n");
		printf("=================================================================================================================");
		row=17;
		while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name,
					&p.Gender, &p.age, p.Address, p.Contact_No, p.Email, p.Airlines, p.Type)!=EOF)
		{
			gotoxy(1,row);
			printf("%s %s",p.First_Name, p.Last_Name);
			gotoxy(20,row);
			printf("%c",p.Gender);
			gotoxy(32,row);
			printf("%i",p.age);
			gotoxy(37,row);
			printf("%s",p.Address);
			gotoxy(49,row);
			printf("%s",p.Contact_No);
			gotoxy(64,row);
			printf("%s",p.Email);
			gotoxy(88,row);
			printf("%s",p.Airlines);
			gotoxy(98,row);
			printf("%s",p.Type);
			row++;
		}
		fclose(ek);
		getch();
		MainMenu();
}
//**************************************************Search Record*******************************************
void Search_rec(void)
{
	char name[20];
	system("cls");
	Title();//Title function calling
	FILE *ek;
	ek=fopen("Record2.dat","r");
	printf("\n\n\t\t\t************** Search Flight Attendants Record **************\n");
	gotoxy(12,8);
	printf("\n Enter Attendants Name to be viewed:");
	scanf("%s",name);
	fflush(stdin); //cleans input buffer
	name[0]=toupper(name[0]);
	while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_No, p.Email, p.Airlines, p.Type)!=EOF)
	{
		if(strcmp(p.First_Name,name)==0)
		{
			gotoxy(1,15);
			printf("Full Name");
			gotoxy(25,15);
			printf("Gender");
			gotoxy(32,15);
			printf("Age");
			gotoxy(37,15);
			printf("Address");
			gotoxy(52,15);
			printf("Contact No.");
			gotoxy(64,15);
			printf("Email");
			gotoxy(80,15);
			printf("Airlines");
			gotoxy(95,15);
			printf("Type\n");
			printf("=================================================================================================================");
			gotoxy(1,18);
			printf("%s %s",p.First_Name, p.Last_Name);
			gotoxy(25,18);
			printf("%c",p.Gender);
			gotoxy(32,18);
			printf("%i",p.age);
			gotoxy(37,18);
			printf("%s",p.Address);
			gotoxy(52,18);
			printf("%s",p.Contact_No);
			gotoxy(64,18);
			printf("%s",p.Email);
			gotoxy(80,18);
			printf("%s",p.Airlines);
			gotoxy(95,18);
			printf("%s",p.Type);
			printf("\n");
			break;
		}
	   }
	   if(strcmp(p.First_Name,name)!=0) //if name not matches
	   {
		gotoxy(5,10);
		printf("Record not found!");
		getch();
	   }
	fclose(ek);
	L:
	getch();
	printf("\n\n\t\t\tDo you want to view more[Y/N]??");
    scanf("%c",&ans);
    if (toupper(ans)=='Y')
    {
        Search_rec();
    }
	else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you");
    	getch();
		MainMenu();
    }
	else
    {
    	printf("\n\tInvalid Input.\n");
    	goto L;
    }
}
//****************************************************Edit Record*************************************************
void Edit_rec(void)
{
	FILE *ek, *ft; //ft is temp file for editing
  int i,b, valid=0;
  char ch;
  char name[20];

  system("cls");
  	Title();// Title calling
 		ft=fopen("temp2.dat","w+"); //write+read
	   ek=fopen("Record2.dat","r");
	   if(ek==NULL) //no value exists
	   {
		printf("\n\t Cant open file");
		getch();
		MainMenu();
	   }
       	printf("\n\n\t\t\t************** Edit Flight Attendants Record **************\n");
	   	gotoxy(12,13);
	   	printf("Enter the First Name of the Flight Attendant : ");
	   	scanf(" %s",name);
	   	fflush(stdin);
	   	name[0]=toupper(name[0]);
		gotoxy(12,15);

		if(ft==NULL)
		{
			printf("\n Cant open file");
			getch();
			MainMenu();
		}
		while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_No, p.Email, p.Airlines, p.Type)!=EOF) //EOF=END OF FILE
		{
			if(strcmp(p.First_Name, name)==0)
			{
				valid=1;
				gotoxy(25,17);
				printf("*** Existing Record ***");
				gotoxy(10,19);
				printf("%s \t%s \t%c \t%i \t%s \t%s \t%s \t%s \t%s\n",p.First_Name,p.Last_Name,p.Gender, p.age,p.Address,p.Contact_No,p.Email,p.Airlines,p.Type);
				gotoxy(12,22);
				printf("Enter New First Name: ");
				scanf("%s",p.First_Name);
				gotoxy(12,24);
				printf("Enter Last Name: ");
				scanf("%s",p.Last_Name);
				gotoxy(12,26);
				printf("Enter Gender: ");
				scanf(" %c",&p.Gender);
				p.Gender=toupper(p.Gender);
				gotoxy(12,28);
				printf("Enter age: ");
				scanf(" %i",&p.age);
				gotoxy(12,30);
				printf("Enter Address: ");
				scanf("%s",p.Address);
				p.Address[0]=toupper(p.Address[0]);
				gotoxy(12,32);
				printf("Enter Contact No: ");
				scanf("%s",p.Contact_No);
				gotoxy(12,34);
				printf("Enter New email: ");
				scanf("%s",p.Email);
			    gotoxy(12,36);
				printf("Enter Airlines Name: ");
				scanf("%s",p.Airlines);
				p.Airlines[0]=toupper(p.Airlines[0]);
			    gotoxy(12,38);
				printf("Enter Type: ");
			    scanf("%s",p.Type);
			    p.Type[0]=toupper(p.Type[0]);
			    printf("\nPress U character for the Updating operation : ");
				ch=getche(); //waits for keyboard input
				if(ch=='u' || ch=='U')
				{
				fprintf(ft,"%s %s %c %i %s %s %s %s %s\n",p.First_Name,p.Last_Name,p.Gender, p.age,p.Address,p.Contact_No,p.Email,p.Airlines,p.Type);
				printf("\n\n\t\t\tAttendant record updated successfully...");
				}
			}
			else
			{
			fprintf(ft,"%s %s %c %i %s %s %s %s %s\n",p.First_Name,p.Last_Name,p.Gender, p.age,p.Address,p.Contact_No,p.Email,p.Airlines,p.Type);
			} //update terminates
		 }
		 if(!valid) printf("\n\t\tNO RECORDS FOUND...");
	   fclose(ft);
	   fclose(ek);
	   remove("Record2.dat");
   	   rename("temp2.dat","Record2.dat"); //transforms temp file to record2 file
		getch();
		MainMenu();
}
//***********************************************Delete record*******************************************
void Dlt_rec()
{
	char name[20];
	int found=0;
	system("cls");
	Title();// Title function calling
	FILE *ek, *ft;
	ft=fopen("temp_file2.dat","w+");
	ek=fopen("Record2.dat","r");
	printf("\n\n\t\t\t************** Delete Flight Attendants Record **************\n");
	gotoxy(12,8);
	printf("\n Enter Attendant Name to delete: ");
	fflush(stdin); //used to flush the output buffer of the stream
	gets(name);
	name[0]=toupper(name[0]);

	while (fscanf(ek,"%s %s %c %i %s %s %s %s %s", p.First_Name, p.Last_Name, &p.Gender,
			 &p.age, p.Address, p.Contact_No, p.Email, p.Airlines, p.Type)!=EOF)
	{
		if (strcmp(p.First_Name,name)!=0) //compares original name with searched name
		fprintf(ft,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_No, p.Email, p.Airlines, p.Type);
		else
		{
			printf("%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_No, p.Email, p.Airlines, p.Type);
			found=1;
		}
	}//loop ends
	if(found==0)
	{
		printf("\n\n\t\t\t Record not found....");
		getch();
		MainMenu();
	}
	else
	{
		fclose(ek);
		fclose(ft);
		remove("Record2.dat");
		rename("temp_file2.dat","Record2.dat");
		printf("\n\n\t\t\t Record deleted successfully");
		getch();
		MainMenu();
	}
}
