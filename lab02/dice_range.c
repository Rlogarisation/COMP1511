//z5206267@cse.unsw.edu.au
/*
reads the number of sides on a set of dice and how many of them are being rolled.
It then outputs the range of possible totals
that these dice can produce as well as the average value.
e.g
Enter the number of sides on your dice: 6
Enter the number of dice being rolled: 2
Your dice range is 2 to 12. 
The average value is 7.000000
or
./dice_range
Enter the number of sides on your dice: -5
Enter the number of dice being rolled: 4
These dice will not produce a range.
./dice_range
Enter the number of sides on your dice: 6
Enter the number of dice being rolled: 0
These dice will not produce a range.
*/

#include <stdio.h>

int main(void) {
	int sides;
	int dice;
	printf("Enter the number of sides on your dice: ");
	scanf("%d", &sides);
	printf("Enter the number of dice being rolled: ");
	scanf("%d", &dice);
	if (sides <= 0 || dice <= 0)
	{
		printf("These dice will not produce a range.\n");
	}
	else
	{
		int max = dice * sides;
		int min = dice;
		printf("Your dice range is %d to %d.\n", min, max);
		double average = (dice + dice * sides);
		printf("The average value is %lf\n", average/2);
	}
	return 0;
}
