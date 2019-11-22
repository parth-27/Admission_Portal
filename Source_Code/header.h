#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
#define P printf
#define S scanf
FILE *f1, *f2;
int sel, ser, res;
char cmp[40];
char dummy;
int cont=0;
int EXIT(int n);
void user();

struct fdbk
{
	char name[20],content[5000];
}feed;

void validity()
{
	system("color 4E");
 	P("\a\a\a");
	P("Please enter Valid Characters : ");
}
void type();
struct student
{
  char user_name[25],user_password[25],name[20],address[150],gen,mname[20],med[15],lname[20],fname[20],city[20],state[20],password[20];
  int seatnumber,phy,maths,chem;
};
struct student stdu;
struct info
{
  char name[40];
  char sur[40];
}rec;
void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if(!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h,c);
}
void line(int j)
{
	int i;
	for(i=0;i<=83;i++)
	{
		gotoxy(i,j);
			P("%c",196);
		gotoxy(166-i,j);
			P("%c",196);
		Sleep(10);
	}
	P("\n\n");
}
void center(char str[150])
{
	int j=1;
	while(j<(83-(strlen(str)/2)))
	{
		P(" ");
		j++;
	}
	puts(str);
}
void box(int x, int y)
{
	int j;
	for(j=0;j<=y;++j)
	{
		gotoxy(j,12);
			P("%c",223);
		gotoxy(j,12+x);
			P("%c",223);
	}
	for(j=0;j<x;++j)
	{
		gotoxy(0,12+j);
			P("%c",219);
		gotoxy(y,12+j);
			P("%c",219);
	}
	gotoxy(2,14);
}
void center_box(char ch[100])
{
	int i,j,k=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<=83+strlen(ch)/2;j++)
		{
			if((i==2 || i==0) && (j<=80+strlen(ch)/2 && j>=76-strlen(ch)/2) || (i==1 && (j==77-strlen(ch)/2 || j==76-strlen(ch)/2 || j==79+strlen(ch)/2 || j==80+strlen(ch)/2)))
				P("%c",176);
			else if(i==1 && (j<=78+strlen(ch)/2 && j>=78-strlen(ch)/2))
			{
				P("%c",ch[k]);
				k++;
			}
			else
				P(" ");
		}P("\n");
	}
}
void header()
{
	line(1);
	center(">>>>>ADMISSION PORTAL<<<<<\n");
	line(5);
}
int execute()
{
	FILE *fp;
	int x;
	char str;
	fp=fopen("portal.txt","r");
	system("cls");
	header();
	if(fp==NULL)
	{
		box(5,165);
		center("The file could not be  opened...");
		gotoxy(61,27);
		exit(1);
	}
	else
	{
		center_box(" WELCOME TO THE XYZ COLLEGE ADMISSION PORTAL ");
		box(13,60);
		do
		{
			fflush(stdin);
			str=fgetc(fp);
			P("%c",str);
			Sleep(10);
			if(str=='\n')
				P("%c",219);
		}while(str!=EOF);
		S("%d",&x);
		fclose(fp);
		gotoxy(61,23);
	}
	return x;
}
void add(int flag)
{
	int i,j,m=0,n=0;
  char ch;
  FILE *fp;
  //P("Write name: ");
  //fgets(rec.name, sizeof(rec.name), stdin);
  //P("Write surname: ");
  //fgets(rec.sur, sizeof(rec.sur), stdin);
	system("cls");
	header();
	center_box(" Welcome to Details Addititon Section ");
	gotoxy(2,14);
Naam :
	system("color 07");
	P("%c \tEnter Your First Name:",219);
	gets(stdu.name);
	for(j=0;j<strlen(stdu.name);j++)
	{
		if(isalpha(stdu.name[j])==0)
		{
			validity();
			goto Naam;
		}
	}
		fflush(stdin);
Bapu :
	system("color 07");
	P("\n%c \tEnter Your Middle Name : ",219);
	gets(stdu.mname);
	for(j=0;j<strlen(stdu.mname);j++)
	{
		if(isalpha(stdu.mname[j])==0)
		{
			validity();
			goto Bapu;
		}
	}
	fflush(stdin);
Surname :
	system("color 07");
	P("\n%c \tEnter Your Last Name : ",219);
	gets(stdu.lname);
	for(j=0;j<strlen(stdu.lname);j++)
	{
		if(isalpha(stdu.lname[j])==0)
		{
			validity();
			goto Surname;
		}
	}
	int mdm;
	fprintf(fp,"%s\n",stdu.lname);
	P("\n%c\n%c Enter Your Medium of Education:\n",219,219);
	P("%c\t 1.) English\n",219);
	P("%c\t 2.) Gujarati\n",219);
	P("%c\t 3.) Other\n%c ",219);
Madhiyam :
	system("color 07");
	S("%d",&mdm);
	fflush(stdin);
	if(mdm==3)
	{
		P("\n\nPlease Specify : ");
		S("%s",stdu.med);
	}
	else if(mdm==2)
		strcpy(stdu.med,"Gujarati");
	else if(mdm==1)
		strcpy(stdu.med,"English");
	else
	{
		validity();
		goto Madhiyam;
	}
	fflush(stdin);
	P("\n%c\n%c Choose Your Gender:\n%c\n",219,219,219);
	P("%c M.) Male\n",219);
	P("%c F.) Female\n%c ",219,219);
Jati :
	system("color 07");
	fflush(stdin);
	fflush(stdin);
	stdu.gen=getchar();
	if(stdu.gen!='M' && stdu.gen!='m' && stdu.gen!='F' && stdu.gen!='f')
	{
			validity();
			goto Jati;
	}
	P("\n%c\n%c Enter Your Board Seat Number : ",219,219);
	S("%d",&stdu.seatnumber);
	fflush(stdin);
	P("\n%c\n%c Please Enter Your Address : ",219,219);
	gets(stdu.address);
	fflush(stdin);
	P("\n%c\n%cEnter Your City : ",219,219);
	gets(stdu.city);
	P("\n%c\n%c Enter Your State : ",219,219);
	gets(stdu.state);
marks :
	P("\n%c\n%c Enter Your Physics Marks (out of 100) : ",219,219);
	S("%d",&stdu.phy);
	if(isdigit(stdu.phy)!=0 && (stdu.phy<101 && stdu.phy>=0))
	{
		validity();
		goto marks;
	}
	P("\n%c\n%c Enter Your Chemistry Marks (out of 100) : ",219,219);
	S("%d",&stdu.chem);
	if(isdigit(stdu.chem)!=0 && (stdu.chem<101 && stdu.chem>=0))
	{
		validity();
		goto marks;
	}
	P("\n%c\n%c Enter Your Maths Marks (out of 100) : ",219,219);
	S("%d",&stdu.maths);
	if(isdigit(stdu.maths)!=0 && (stdu.phy<101 && stdu.phy>=0))
	{
		validity();
		goto marks;
	}
	fwrite(&stdu,sizeof(stdu),1,fp);
	fclose(fp);

	if(flag==0)
	{
	   f1=fopen("information.txt","a+"); //<- open file for writing
	}
  else if(flag==1)
  {
  	f1=fopen("information.txt","w"); //<- open file for writing
  }
  fputs(rec.name,f1);
  fputs(rec.sur,f1);
  fprintf(f1,"\n");
  fclose(f1); // close the file. this will flush the buffer.
}
int search(int flag)
{
	static int con=0;
  fgets(cmp, sizeof(cmp), stdin);
  f1=fopen("information.txt","r"); //<- open the file for reading
  while(!feof(f1))
  {
    fgets(rec.name,sizeof(rec.name),f1); //<- read both the data. this will update the file pointer.
    fgets(rec.sur,sizeof(rec.sur),f1);
  	fscanf(f1,"%c",&dummy); //<- this handles the additional newline
    if(strcmp(cmp,rec.name)==0)
    {
      P("RECORD FOUND::\nName:%sSurname:%s\n\n",rec.name,rec.sur);
      if(flag==1)
      	add(1);
      break; //<- break if record is found
    }
  }
  fclose(f1); //<- close the file after you are done.
  return 0;
}
int details()
{
	int i,j,m=0,n=0;
  char ch;
  FILE *fp;
  fp=fopen("information.txt","w+");
  P("1.) Already have an account\n",219);
  P("%c 2.) Create a new account\n%c\n%c\n",219,219,219);
	P("%c Enter Your choice : ",219);
	S("%d",&i);
	fflush(stdin);
	if(i==1)
	{
		system("cls");
		header();
		center_box(" Welcome to Details Addititon Section ");
		gotoxy(2,14);
Naam :
		system("color 07");
  	P("%c \tEnter Your First Name:",219);
 		gets(stdu.name);
 		for(j=0;j<strlen(stdu.name);j++)
 		{
	 		if(isalpha(stdu.name[j])==0)
	 		{
	 			validity();
				goto Naam;
			}
		}
  		fflush(stdin);
Bapu :
		system("color 07");
		P("\n%c \tEnter Your Middle Name : ",219);
  	gets(stdu.mname);
 		for(j=0;j<strlen(stdu.mname);j++)
 		{
		 	if(isalpha(stdu.mname[j])==0)
 			{
 				validity();
 				goto Bapu;
 			}
 		}
  	fflush(stdin);
Surname :
		system("color 07");
	  P("\n%c \tEnter Your Last Name : ",219);
  	gets(stdu.lname);
 		for(j=0;j<strlen(stdu.lname);j++)
 		{
 			if(isalpha(stdu.lname[j])==0)
 			{
				validity();
 				goto Surname;
 			}
 		}
 		int mdm;
  	fprintf(fp,"%s\n",stdu.lname);
		P("\n%c\n%c Enter Your Medium of Education:\n",219,219);
  	P("%c\t 1.) English\n",219);
  	P("%c\t 2.) Gujarati\n",219);
  	P("%c\t 3.) Other\n%c ",219);
Madhiyam :
		system("color 07");
		S("%d",&mdm);
 		fflush(stdin);
 		if(mdm==3)
 		{
			P("\n\nPlease Specify : ");
			S("%s",stdu.med);
		}
 		else if(mdm==2)
 			strcpy(stdu.med,"Gujarati");
 		else if(mdm==1)
			strcpy(stdu.med,"English");
 		else
 		{
			validity();
			goto Madhiyam;
		}
		fflush(stdin);
  	P("\n%c\n%c Choose Your Gender:\n%c\n",219,219,219);
  	P("%c M.) Male\n",219);
  	P("%c F.) Female\n%c ",219,219);
Jati :
		system("color 07");
		fflush(stdin);
		fflush(stdin);
  	stdu.gen=getchar();
		if(stdu.gen!='M' && stdu.gen!='m' && stdu.gen!='F' && stdu.gen!='f')
  	{
 				validity();
  			goto Jati;
  	}
  	P("\n%c\n%c Enter Your Board Seat Number : ",219,219);
    S("%d",&stdu.seatnumber);
    fflush(stdin);
    P("\n%c\n%c Please Enter Your Address : ",219,219);
    gets(stdu.address);
    fflush(stdin);
    P("\n%c\n%cEnter Your City : ",219,219);
    gets(stdu.city);
    P("\n%c\n%c Enter Your State : ",219,219);
    gets(stdu.state);
marks :
    P("\n%c\n%c Enter Your Physics Marks (out of 100) : ",219,219);
    S("%d",&stdu.phy);
    if(isdigit(stdu.phy)!=0 && (stdu.phy<101 && stdu.phy>=0))
    {
    	validity();
    	goto marks;
		}
    P("\n%c\n%c Enter Your Chemistry Marks (out of 100) : ",219,219);
    S("%d",&stdu.chem);
    if(isdigit(stdu.chem)!=0 && (stdu.chem<101 && stdu.chem>=0))
    {
    	validity();
    	goto marks;
		}
    P("\n%c\n%c Enter Your Maths Marks (out of 100) : ",219,219);
    S("%d",&stdu.maths);
		if(isdigit(stdu.maths)!=0 && (stdu.phy<101 && stdu.phy>=0))
    {
    	validity();
    	goto marks;
		}
    fwrite(&stdu,sizeof(stdu),1,fp);
		fclose(fp);
		return 0;
  }
  else if(i==2)
  {
  	system("cls");
		header();
		center_box(" Welcome to Account Creaton Section ");
		box(25,90);
  	type();
	}
}
void feedback()
{
	FILE *fp;
	fp = fopen("feedback.txt","a");
	gotoxy(0,7);
	center_box(" WELCOME TO FEEDBACK PART ");
	box(20,93);
	printf("Please enter the name : ");
	S("%s",feed.name);
	//fprintf(fp,"%s",feed.name);
	P("### Please enter '$' to exit entering the content ###\n\tPlease Enter the feedback : ");
	scanf("%[^\t]s",feed.content);
	fwrite(&feed,sizeof(feed),1,fp);
	fclose(fp);
	EXIT(1);
}
void type()
{
	int i=0,ct=0;
	FILE *p;
	p=fopen("user_details.txt","w+");
	char s[50],s1[50];
	do{
		fscanf(p,"%c",s[i]);
		i++;
	}while(s[i]!=EOF);
	fprintf(p,"\n");
carry :
	system("color 07");
	P("Pls Enter USERNAME(WITHOUT entering SPACES and from 5-20 letters) : ");
	S("%s",stdu.user_name);
	fflush(stdin);
	P("%c",223);
	if(strlen(s1)<5 || strlen(s1)>20)
	{
		validity();
		goto carry;
	}
	fprintf(p,"%s\n",stdu.user_name);
	strcpy(s1,stdu.user_name);
	for(i=0;i<strlen(stdu.user_name);i++)
	{
		if(s1[i]==32 || s1[i]==9 && ct==0)
		{
			validity();
			ct++;
			goto carry;
		}
	}
	P(" Pls Enter Your name : ");
	gets(s);
	fprintf(p,"%s\n",s);
	fflush(stdin);
	P("%c Create your PASSWORD (UPTO 15 letters only): ",219);
	S("%s",s);
	P("%c Re-Enter your PASSWORD : ",219);
	S("%s",s1);
	P("%c",219);
	if(strcmp(s,s1)==0)
	{
		P("\n%c\n%c\n%c",219,219,219);
		system("color 71");
		P("ACCOUNT SUCCESSFULLY CREATED.. : )");
		strcpy(stdu.user_password,s);
		fprintf(p,"%s\n",stdu.user_password);
		system("cls");
		header();
		center_box(" Welcome to Details Addititon Section ");
		box(15,100);
		details();
	}
	else
	{
		system("color 4E");
		P("\a\a\a");
		P("The Passwords doesn't match...");
	}
	getch();
	system("color 07");
	fclose(p);
}
void cases(int x);
void password()
{
	int i;
	FILE *f;
	int x,q;
	char user_c[20],c[15],m[20];
	fflush(stdin);
	f=fopen("user_details.txt","rb");
	gets(user_c);
	P("Pls enter username : ");
	fscanf(f,"%s",m);
	if(strcmp(user_c,m)==0)
	{
		fflush(stdin);
		P("%c",219);
		P("Pls enter your password : ");
		repeat:{
			c[q]=getch();
			if(c[q]!=13)
			{
				P("%c",178);
				m[q]=c[q];
				q++;
				goto repeat;
			}
			else if(c[q]==8)
			{
				system("cls");
				header();
				gotoxy(106,40);
				P("//Welcome Page //Student User //Main Menu //Edit Details");
				gotoxy(0,7);
				P("%c Pls enter username : ",219);
				P("\n%c\n%c Pls enter your password (25 words limit) : ",219,219);
				q--;
				for(i=0;i<q;i++)
					P("%c",178);
				goto repeat;
			}
		}
		fscanf(f,"%s",c);
		if(strcmp(c,m)==0)
		{
			system("color 57");
			center("\n\n\nWelcome to Your Account...");
		}
		else
		{
			system("color 4E");
			P("\a\a\a");
			center("\n\nInvalid Passsword entered...!!!");
		}
		getch();
		system("color 07");
	}
	else
	{
		P("User with the entered name doesn't exist..");
		Sleep(1);
		P("Forwarding to the main page");
	}
	getch();
	fclose(f);
	EXIT(1);
}
int q=0,count=0;
char c[25],m,pwd[]="AHDUNI";
void branch()
{
	FILE *fp;
	P("\n\n");
	center(" BRANCH WISE DISTRIBUTION ");
	P("\n\n");
	getch();
	fopen("information.txt","r");
	getch();
	while(fread(&stdu,sizeof(struct student),1,fp))
		printf("%10d %20s %20s %20s %20s %20d %20d %20d",stdu.seatnumber,stdu.fname,stdu.mname,stdu.lname,stdu.gen,stdu.maths,stdu.phy,stdu.chem);
	getch();
	EXIT(0);
}
void password_user()
{
	FILE* fp;
	int i,count=0;
	P("\n\nPls enter your password (25 words limit) : ");
	repeat : {
		fflush(stdin);
		m=getch();
		if(m!=13 && q<25 && (m<127 && m>31))
		{
			c[q]=m;
			P("%c",178);
			q++;
			goto repeat;
		}
		else if(m==8)
		{
			system("cls");
			header();
			center_box(" WELCOME TO XYZ COLLEGE ADMISSION REGISTRATION PART ");
			box(20,91);
			P("\t\t\t\tSecurity Purpose");
			P("\n\nPls enter your password (25 words limit) : ");
			q--;
			for(i=0;i<q;i++)
				P("%c",178);
			goto repeat;
		}
		else
			c[q]='\0';
		if(strcmp(c,pwd)==0)
		{
			system("cls");
			system("color 71");
			P("\n\n\n\t\t\tWelcome to portal...");
			system("color 07");
		}
		else
		{
			system("color 4E");
			P("\a\a\a");
			P("\nPls enter Proper password....");
			count++;
			if(count<4)
			{
				Sleep(1);
				system("color 4E");
				for(q=120;q>=0;q--)
				{
					Sleep(1);
					system("cls");
					P("Number of times left to enter valid password : %d\n",3-count);
					if(q==120 || q==60)
						P("%d min. left",q/60);
					else
						P("%d sec. left",q);
				}
				P("\nPls Re-enter the password : ");
				q=0;
				goto repeat;
			}
			else
			{
				system("color 4E");
				P("\a\a\a");
				P("\t\t\t\t...Tried Maximum number of times...");
				P("\n\n");
				exit(1);
			}
			system("color 07");
		}
	}
}
int i;
void cases(int x)
{
	system("cls");
	switch(x)
	{
		case 1 :
		{
			header();
			gotoxy(106,40);
			P("//Welcome Page //Student User //Main Menu //New Admission\n\n\n");
			gotoxy(0,7);
			center_box(" WELCOME TO XYZ COLLEGE ADMISSION REGISTRATION PART ");
			box(20,91);
			details();
			gotoxy(63,0);
			EXIT(1);
			break;
		}
		case 2 :
		{
			header();
			gotoxy(106,40);
			P("//Welcome Page //Student User //Main Menu //Edit Details");
			gotoxy(0,7);
			box(20,90);
			password();
			search(1);
			gotoxy(63,0);
			EXIT(1);
			break;
		}
		case 3 :
		{
			header();
			gotoxy(106,40);
			P("//Welcome Page //Student User //Main Menu //");
			gotoxy(0,7);
			box(20,90);
			password();
			gotoxy(63,0);
			EXIT(1);
			break;
		}
		case 4 :
		{
			char c[50];
			int i=(-1);
			FILE *f;
			f=fopen("notify.txt","w+b");
			header();
			gotoxy(106,40);
			P("\\Welcome Page \\Student User \\Main Menu \\Notification Penal");
			gotoxy(0,7);
			center_box(" WELCOME TO XYZ COLLEGE NOTICE REGISTRATION PART ");
			box(20,101);
			P("\n%c\n%c\n%c To Register to the further notices of the XYZ College : ",219,219,219);
			P("\n%c Pls. enter Your e-mail address : ",219);
		valid :
			do
			{
				i++;
				fflush(stdin);
				c[i]=getchar();
				if((c[i]<=57 && c[i]>=48) || (c[i]==64) || (c[i]>=97 && c[i]<=122) || (c[i]==64))
				{
					fprintf(f,"%c",c[i]);
				}
				else
				{
					P("\nPls enter valid characters only...\nRe-enter the e-mail address\n");
					i=(-1);
					goto valid;
				}
			}while(c[i]!='\n' && i<5);
			P("%c From which media did you hear about this college",219);
			gets(c);
			fputs(c,f);
			fclose(f);
			EXIT(1);
			break;
		}
		case 5 :
		{
			header();
			gotoxy(106,40);
			P("//Welcome Page //Student User //Main Menu //Feedback/n/n/n");
			feedback();
			P("... Thanks for Giving feedback ...");
			break;
		}
		default :
		{
			header();
			center("\nInvalid Value Entered...");
			EXIT(1);
			break;
		}
	}
}
int EXIT(int n)
{
	system("cls");
	int m,x;
	center("\n\nTo go to main page --- Enter 1 ---If Entered random value, the programme will end....\n");
	S("%d",&m);
	if(m==1)
	{
		if(n==1)
		{
			system("cls");
			x=execute();
			cases(x);
		}
		else if(n==0)
		{
			system("cls");
			user();
		}
	}
	else
	{
		system("cls");
		header();
		gotoxy(0,20);
		center("Programme exited...");
		center("Thank you for visiting");
		getch();
		exit(1);
	}
	return x;
}
void user()
{
	int x;
	gotoxy(75,15);
	P("Hello User....");
	Sleep(500);
	system("cls");
	Sleep(10);
	center_box(" >>> WELCOME TO THE ADMISSSION PORTAL <<< ");
	Sleep(10);
	P("\n\n Who are you ? \n\n\n");
	P("1.>		Institute Faculty Member..\n2.>		Student..\n3.>		Visitor..");
	P("\n\n\t\t\t\t\tPls Enter respective number..  :  ");
	S("%d",&x);
	if(x==1)
	{
		system("cls");
		gotoxy(0,20);
		center("Security Purpose");
		password_user();
		system("cls");
		P("\n\nThe List is shown as per Catagory : \n\n");
		center_box(" >.>.> Branch Wise <.<.<");
		system("delay");
		system("cls");
		branch();
	}
	else if(x==2)
	{
		int i,j,y;
		for(i=0;i<48;i++)
		{
			system("cls");
			gotoxy(0,20);
			for(j=1;j<=50+i;j++)
				P(" ");
			P("...HELLO STUDENT...");
			Sleep(1);
		}system("cls");
		y=execute();
		cases(y);
	}
	else if(x==3)
	{
		int i,j,choice;
		char name[50];
		for(i=0;i<48;i++)
		{
			system("cls");
			gotoxy(0,20);
			for(j=1;j<=50+i;j++)
				P(" ");
			P("Hello Visitor...");
			Sleep(1);
		}system("cls");
		header();
		center_box(" Welcome to the Visitor Section ");
		box(20,90);
		P("1.> Register for Further Notifications\n");
		P("%c 2.> About Us & Feedback\n",223);
		P("%c\n%c",223,223);
		P("Please enter any Number : ");
		S("%d",&choice);
		if(choice==1)
		{
			int j,i=(-1);
			char c[50];
			FILE *f;
			system("cls");
			header();
			f=fopen("notify.txt","w");
			gotoxy(106,40);
			P("\\Welcome Page \\Visitor User \\Main Menu \\Notification Penal");
			gotoxy(0,7);
			center_box(" Welcome to Registration Part ");
			box(20,90);
			P("%c Please  enter your name : ",223);
NAAM:
			system("color 07");
			fflush(stdin);
			gets(name);
			for(j=0;j<strlen(name);j++)
 			{
	 			if(isalpha(name[j])==0)
	 			{
	 				system("color 4E");
	 				P("%c Please enter Valid Name... : ",223);
	 				goto NAAM;
				}
			}
			P("%c Please enter the Email Address : ",223);
valid:
			system("color 07");
			do
			{
				i++;
				fflush(stdin);
				c[i]=getchar();
				if((c[i]<=57 && c[i]>=48) || (c[i]==64) || (c[i]>=97 && c[i]<=122))
				{
					fprintf(f,"%c",c[i]);
				}
				else
				{
					system("co1or 4E");
					P("\nPls enter valid characters only...\nRe-enter the e-mail address\n");
					i=(-1);
					goto valid;
				}
			}while(c[i]!='\n' && i<5);
			P("From which media did you hear about this college");
			gets(c);
			fputs(c,f);
			fclose(f);
			EXIT(0);
		}
		else if(choice==2)
		{
			system("cls");
			header();
			gotoxy(106,40);
			P("//Welcome Page //Visitor User //Main Menu //Feedback/n/n/n");
			feedback();
			P("... Thanks for Giving feedback ...");
		}
	}
	else
		EXIT(0);
}
