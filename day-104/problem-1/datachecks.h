/*
 *	datachecks.h
 *
 */

#define Size 40

int
GetAnInt();

int
IsValidInt(char val[]);

int
GetAnInt()
{
	bool isInt = false;
	char value[Size] = { 0 };
	do
	{
		gets(value);
		if (IsValidInt(value) == false)
		{
			printf("Invalid integer - Please re-enter: ");
			continue;
		}
		isInt = true;
	} while (isInt == false);
	return (atoi(value));
}

int
IsValidInt(char val[])
{
	int start = 0;
	int i;
	int valid = true;
	int sign = false;

	if (val[0] == '\0')
	{
		valid = false;
	}

	if (val[0] == '-' || val[0] == '+')
	{
		sign = true;
		start = 1;
	}

	if (sign == true && val[1] == '\0')
	{
		valid = false;
	}

	i = start;
	while (valid == true && val[i] != '\0')
	{
		if (val[i] < '0' || val[i] > '9')
		{
			valid = false;
		}
		++i;
	}

	return valid;
}

