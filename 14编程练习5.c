#include <stdio.h>
#define CSIZE 4
struct name {
	char first_name[20];
	char last_name[20];
};
struct student {
	struct name names;
	float grade[3];
	float average;
};
int main(void)
{
	struct student students[CSIZE];
	int i = 0;


	while (i < 4)
	{
		printf("Enter one student's first name:");
		scanf("%s", students[i].names.first_name);
		printf("Enter one student's last name:");
		scanf("%s", students[i].names.last_name);
		printf("Enter his or her math grade:");
		scanf("%f", &students[i].grade[0]);
		printf("Enter his or her IT grade:");
		scanf("%f", &students[i].grade[1]);
		printf("Enter his or her English grade:");
		scanf("%f", &students[i].grade[2]);
		i++;
	}
	
	i = 0;
	while(i < 4)
	{
		students[i].average = (students[i].grade[0] + students[i].grade[1] + students[i].grade[2]) / 3;
		printf("The average of %s %s grades is %.1f.\n", students[i].names.first_name, students[i].names.last_name, students[i].average);
		i++;
	}

	return 0;
}



	

