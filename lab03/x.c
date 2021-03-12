//z5206267@cse.unsw.edu.au
//Written 24/May/2020
/*
reads an integer n from standard input, 
and prints an nxn pattern of asterisks and dashes in the shape of an "X".
You can assume n is odd and >= 5.
e.g.
Enter size: 5
*---* (This is column 1)
-*-*-
--*--
-*-*-
*---*
(row 1)
*/

#include<stdio.h>

int main(void)
{
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    //int variables for range
    int column = 1;
    
    //Considering for each row
    while (column <= size)
    {
        //row can reset automatically each round if we set it here
        int row = 1;
        //considering for each column
        while (row <= size)
        {
            //since the column starts from 1 rather than 0, so + 1
            if (column == row || row == size + 1 - column)
            {
                printf("*");
            }
            else
            {
                printf("-");
            }
            row++;
        }
        printf("\n");
        

        column++;
    }




    return 0;
}