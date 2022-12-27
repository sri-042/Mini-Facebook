#include <stdio.h>
#include<conio.h>
#include <malloc.h>
#include<conio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30
#define MALLOC(p,s,t) \
		p = (t) malloc(s); \
	if (p == NULL ) \
	 { \
		fprintf(stderr, "Insufficient Memory\n"); \
		exit(EXIT_FAILURE); \
	  }
struct List
{
	char Name[MAX];
	char Email_id[MAX];
	char Current_City[MAX];
	char Workplace[MAX];
	char School[MAX];
	char Hometown[MAX];
	char Gender[MAX];
	char Birthday[MAX];
	char  PhNo[MAX];
	struct List *link;
};
typedef struct List *NODE;
NODE Create   (NODE);
NODE InsFront (NODE);
NODE InsRear  (NODE);
NODE DelFront (NODE);
NODE DelRear  (NODE);
void Display  (NODE);
void ReadData();
char Name[MAX];
	char Email_id[MAX];
	char Current_City[MAX];
	char Workplace[MAX];
	char School[MAX];
	char Hometown[MAX];
	char Gender[MAX];
	char Birthday[MAX];
	char  PhNo[MAX];
int main()
{
	int choice, done,n;
	NODE fi;			/* FIRST node */
	fi= NULL;
	done = 0;
    printf("---------------WELCOME TO MINI FACEBOOK--------------------\n");
	while (!done)
	{
		printf("\n1.Create a new account\t2.Add Account\t3.Delete First Account\n4.Delete Last Account\t5.Display your account details\t6.Exit\n");
		printf("Enter Choice: ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:	 fi = Create(fi);
					  break;

			case 2:   ReadData();
				      fi= InsRear(fi);
					  break;
			case 3:	  fi = DelFront(fi);
                        Display(fi);
				      break;
			case 4:	  fi = DelRear(fi);
                        Display(fi);
					  break;
			case 5:	  Display(fi);
					  break;
			case 6:	  done=1;
					  break;
			default:  printf("Illegal Entry\n\n");
				      break;
}
	}
	return 0;
}
void ReadData()
{

	printf("Enter Name: ");
	scanf("%s", Name);

	printf("Enter Email ID: ");
	scanf("%s", Email_id);

	printf("Enter Current city you are living in: ");
	scanf("%s", Current_City);

	printf("Enter your Workplace: ");
	scanf("%s", Workplace);

	printf("Enter the school you studied in: ");
	scanf("%s", School);

	printf("Enter your hometown: ");
	scanf("%s", Hometown);

	printf("Enter your Gender: ");
	scanf("%s", Gender);

	printf("Enter your birthday: ");
	scanf("%s", Birthday);


	printf("Enter your Phone number: ");
	scanf("%s", PhNo);

}
NODE Create(NODE first)
{

	if (first == NULL)
	{
		{
			printf("Enter Your information \n");
			ReadData();
			first = InsFront(first);
		}
		return first;
	}
	else printf("Your account already exist\n");
	return 0;
}
/* To build the linked list of jobs */
NODE InsFront (NODE first)
{
NODE q;
	MALLOC(q, sizeof(struct List), NODE);

	strcpy (q->Name, Name);
	strcpy(q->Email_id, Email_id);
	strcpy(q->Current_City, Current_City);
	strcpy(q->Workplace, Workplace);
	strcpy(q->School, School);
	strcpy(q->Hometown,Hometown);
	strcpy(q->Gender, Gender);
	strcpy(q->Birthday, Birthday);
	strcpy(q->PhNo, PhNo);
	q->link = first;
	first = q;
	return first;
}
NODE InsRear (NODE first)
{
	NODE q, t = first;
	MALLOC(q, sizeof(struct List), NODE);
	strcpy (q->Name, Name);
	strcpy(q->Email_id, Email_id);
	strcpy(q->Current_City, Current_City);
	strcpy(q->Workplace, Workplace);
	strcpy(q->School, School);
	strcpy(q->Hometown,Hometown);
	strcpy(q->Gender, Gender);
	strcpy(q->Birthday, Birthday);
	strcpy(q->PhNo, PhNo);
	q->link = NULL;
	if (!first) first = q;
	else
	{
		while (t->link)
		    t = t->link;
		t->link = q;		/* goto last node */
	}
	return first;
}
NODE DelFront (NODE first)
{
	NODE te;
	if(first == NULL)
		printf("Can't delete, there is no account\n");
	else
    		te = first;
		first= first->link;
		free(te);
	return first;
}
NODE DelRear (NODE first)
{
	NODE cur, pred;
	if(first == NULL)
	{
		printf("Can't delete, there is no account\n");
		return first;
	}
	if(first->link == NULL)
		return first=NULL;
	// more than one node */
	cur = first;
	while (cur->link != NULL)
	{
		pred = cur;
		cur = cur->link;
	}
	free(cur);
	pred->link = NULL;
	return first;
}
/* Displays the contents of the list */
void Display (NODE first)
{
  int count =0;
  NODE disp_first;
  disp_first = first;
  if(first == NULL)
		printf("No account to display\n");
	while (disp_first)
	{
	printf("Name:%s\t\tMail ID: %s\nCurrent City:%s\t\tWorkplace:%s\nSchool:%s\t\tHometown:%s\nGender:%s\t\tPhone Number:%s\n\n\n", disp_first->Name, disp_first->Email_id, disp_first->Current_City, disp_first->Workplace, disp_first->School, disp_first->Hometown, disp_first->Gender, disp_first->Birthday, disp_first->PhNo);
		disp_first = disp_first->link;
		count++;
    }
}
