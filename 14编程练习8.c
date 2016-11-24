#include <stdio.h>
#define NUM 12
struct plane {
	int ID;
	int status;
	char first_name[15];
	char last_name[15];
};
void print(void);
int a(struct plane *pr);
void b(struct plane *pr);
void c(struct plane *pr);
void d(struct plane *pr);

int main(void)
{
	struct plane planes[NUM];
	char choice;
	int i = 0;
	
	while (i++ < NUM)
	{
		planes[i].ID = i;
		planes[i].status = 0;
	}
	
	do
	{
		print();
		scanf("%s", &choice);
		switch (choice)
		{
			case 'a' :
				a(planes);
				break;
			case 'b' :
				b(planes);
				break;
			case 'c' :
				c(planes);
				break;
			case 'd' :
				d(planes);
				break;
			case 'e' :
				break;
			default :
				printf("Please enter a letter form a to e:\n");
			}
	}
	while (choice != 'e');
	printf("Goodbye!\n");


	return 0;
}
void print(void)
{
	printf("To choose a function, enter its letter label:\n");
	printf("a) Show number of empty seats\n");
	printf("b) Show list of empty seats\n");
	printf("c) Assign a customer to a seat assignment\n");
	printf("d) Delete a seat assignment\n");
	printf("e) Quit\n");
}

int a(struct plane *pr)
{
	int count = 0;
	int i = 0;

	while (i < NUM)
	{
		if (pr->status == 0)
			count++;
		i++;
		pr++;
		}
	printf("There are %d seats is empty now.\n", count);

	return count;
}

void b(struct plane *pr)
{
	int i = 0;

	while (i < NUM)
	{
		if (pr->status == 0)
			printf("%d is empty now.\n", pr->ID);
		i++;
		pr++;
	}
}

void c(struct plane *pr)
{
	if (a(pr) != 0)
	{
		b(pr);
		int assign;
		printf("Enter a number you want to assgin:");
		scanf("%d", &assign);
		(pr + assign)->status = 1;
		printf("OK, can I know your first name? Enter it:\n");
		scanf("%s", (pr + assign)->first_name);
		printf("Now, your last name:");
		scanf("%s", (pr + assign)->last_name);
		printf("Your assginment is aceppted. Thank you for your choice!\n");
	}
	else
		printf("Sorry, there is no empty seats!\n");
}

void d(struct plane *pr)
{
	int de;
	printf("Enter an ID you want to delete:");
	scanf("%d", &de);
	(pr + de)->status = 0;
	printf("Your assignment is deleted!\n");
}
