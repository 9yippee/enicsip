#include <stdio.h>
#define TOP_RULE_LT 0
#define BOT_RULE_LT 4
#define LEF_RULE_LT 8
#define RIG_RULE_LT 12
#define LT 16

int reverse_input(int n)
{
    int counter = 0;

    if(n == 1)
        return 4;
    else if(n == 2)
        return 3;
    else if(n == 3)
        return 2;
    else if(n == 4)
        return 1;
    else
        return 0;
}

int main (void)
{
    int square[4][4] = {0, };
    int square_check[4][4] = {0, };
    int rule[LT] = {4, 3, 2, 1, 1, 2, 2, 2, 4, 3, 2, 1, 1, 2, 2, 2};
    //int rule[LT] = {2, 1, 2, 4, 2, 3, 3, 1, 2, 3, 1, 2, 3, 2, 2, 1};
    int col = 0, row = 0;

    while(row != 4)
    {
        col = 0;
        while(col != 4)
        {
            // MIN MAX TOP
            if(rule[TOP_RULE_LT + col] == 4)
            {
                square[col][row] = row + 1;
                square_check[col][row] = 1;
            }
            else if(rule[TOP_RULE_LT + col] == 1)
            {
                square[col][row] = reverse_input(row+1);
                square_check[col][row] = 1;
            }
            // MIN MAX BOT
            if(rule[BOT_RULE_LT + col] == 4)
            {
                square[col][row] = reverse_input(row+1);
                square_check[col][row] = 1;
            }
            else if(rule[BOT_RULE_LT + col] == 1)
            {
                square[col][row] = row+1;
                square_check[col][row] = 1;
            }
            // MIN MAX LEF
            if(rule[LEF_RULE_LT + row] == 4)
            {
                square[col][row] = col + 1;
                square_check[col][row] = 1;
            }
            else if(rule[LEF_RULE_LT + row] == 1)
            {
                square[col][row] = reverse_input(col+1);
                square_check[col][row] = 1;
            }
            // MIN MAX RIG
            if(rule[RIG_RULE_LT + row] == 4)
            {
                square[col][row] = reverse_input(col+1);
                square_check[col][row] = 1;
            }
            else if(rule[RIG_RULE_LT + row] == 1)
            {
                square[col][row] = col+1;
                square_check[col][row] = 1;
            }
            // TOP or BOT 1 & 2
            if(rule[TOP_RULE_LT + col] == 1 && rule[BOT_RULE_LT + col] == 2)
            {
                square[col][3] = 3;
                square_check[col][3] = 1;
            }
            if(rule[TOP_RULE_LT + col] == 2 && rule[BOT_RULE_LT + col] == 1)
            {
                square[col][0] = 3;
                square_check[col][0] = 1;
            }
            // LEF or RIG 1 & 2
            if(rule[LEF_RULE_LT + row] == 1 && rule[RIG_RULE_LT + row] == 2)
            {
                square[3][row] = 3;
                square_check[3][row] = 1;
            }
            if(rule[LEF_RULE_LT + row] == 2 && rule[RIG_RULE_LT + row] == 1)
            {
                square[0][row] = 3;
                square_check[0][row] = 1;
            }


            col++;
        }
        row++;
    }
    col = 0;
    row = 0;
    while(row != 4)
    {
        col = 0;
        while(col != 4)
        {
            printf("%d ",square[col][row]);
            col++;
        }
        printf("\n");
        row++;
    }

    printf("\n\n\n\n");

    row = 0;
    while(row != 4)
    {
        col = 0;
        while(col != 4)
        {
            printf("%d ",square_check[col][row]);
            col++;
        }
        printf("\n");
        row++;
    }
    return (0);
}