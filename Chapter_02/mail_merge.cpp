#include <stdio.h>
#include <string.h>
#include <time.h>

void readLine(char *text, int size)
{
	fgets(text, size, stdin);
	text[strcspn(text, "\n")] = '\0';
}

const char *ordinalSuffix(int day)
{
	if (day % 100 >= 11 && day % 100 <= 13)
		return "th";

	switch (day % 10)
	{
		case 1: return "st";
		case 2: return "nd";
		case 3: return "rd";
		default: return "th";
	}
}

int main(void)
{
	char firstName[100];
	char lastName[100];
	char studyProgram[200];
	char academicYear[50];
	const char *months[] = {
		"January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December"
	};
	time_t currentTime;
	struct tm *currentDate;

	printf("Enter your first name: ");
	readLine(firstName, sizeof(firstName));
	printf("Enter your last name: ");
	readLine(lastName, sizeof(lastName));
	printf("Enter your study program: ");
	readLine(studyProgram, sizeof(studyProgram));
	printf("Enter the academic year: ");
	readLine(academicYear, sizeof(academicYear));

	time(&currentTime);
	currentDate = localtime(&currentTime);

	printf("\nDate: %d%s %s %d\n\n", currentDate->tm_mday,
		   ordinalSuffix(currentDate->tm_mday),
		   months[currentDate->tm_mon], currentDate->tm_year + 1900);
	printf("To: %s %s,\n\n", firstName, lastName);
	printf("Dear %s,\n\n", firstName);
	printf("CONGRATULATIONS! I am pleased to inform you that the Makerere University\n");
	printf("Admissions Board has approved your application for admission to the\n");
	printf("%s academic year.\n\n", academicYear);
	printf("You have been offered a place for the following course:\n");
	printf("PROGRAM: %s\n\n", studyProgram);
	printf("As a student of Makerere University, you will be part of a historic\n");
	printf("institution dedicated to academic excellence and innovation. Please ensure\n");
	printf("that you report to the Academic Registrar's office with your original\n");
	printf("academic documents for verification during the orientation week.\n\n");
	printf("We look forward to welcoming you to Makerere University.\n\n");
	printf("Yours sincerely,\n\n\n");
	printf("John Doe\n");
	printf("Registrar\n");

	return 0;
}