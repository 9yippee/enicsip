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
}

int main (void)
{
    int square[4][4] = {0, };
    int check[4][4] = {0, };
    int rule[LT] = {4, 3, 2, 1, 1, 2, 2, 2, 4, 3, 2, 1, 1, 2, 2, 2};
    //int rule[LT] = {2, 1, 2, 4, 2, 3, 3, 1, 2, 3, 1, 2, 3, 2, 2, 1};
    //int rule[LT] = {2, 2, 3, 1, 3, 2, 1, 2, 3, 1, 2, 2, 1, 3, 2, 2};
    int col = 0, row = 0, counter = 0, target = 0, flag = 0;

    while(row != 4)
    {
        col = 0;
        while(col != 4)
        {
            // If MIN OUT MAX
            if(rule[TOP_RULE_LT + col] == 1)
            {
                square[col][0] = 4;
                check[col][0] = 1;
            }
            else if(rule[BOT_RULE_LT + col] == 1)
            {
                square[col][3] = 4;
                check[col][3] = 1;
            }
            else if(rule[LEF_RULE_LT + row] == 1)
            {
                square[0][row] = 4;
                check[0][row] = 1;
            }
            else if(rule[RIG_RULE_LT + row] == 1)
            {
                square[3][row] = 4;
                check[3][row] = 1;
            }

            // MIN MAX TOP & BOT
            if(rule[TOP_RULE_LT + col] == 4 && rule[BOT_RULE_LT + col] == 1)
            {
                square[col][row] = row + 1;
                check[col][row] = 1;
            }
            else if(rule[TOP_RULE_LT + col] == 1 && rule[BOT_RULE_LT + col] == 4)
            {
                square[col][row] = reverse_input(row+1);
                check[col][row] = 1;
            }
            // MIN MAX LEF
            if(rule[LEF_RULE_LT + row] == 4 && rule[RIG_RULE_LT + row] == 1)
            {
                square[col][row] = col + 1;
                check[col][row] = 1;
            }
            else if(rule[LEF_RULE_LT + row] == 1 && rule[RIG_RULE_LT + row] == 4)
            {
                square[col][row] = reverse_input(col+1);
                check[col][row] = 1;
            }
            
            // TOP or BOT 1 & 2
            if(rule[TOP_RULE_LT + col] == 1 && rule[BOT_RULE_LT + col] == 2)
            {
                square[col][3] = 3;
                check[col][3] = 1;
            }
            if(rule[TOP_RULE_LT + col] == 2 && rule[BOT_RULE_LT + col] == 1)
            {
                square[col][0] = 3;
                check[col][0] = 1;
            }
            // LEF or RIG 1 & 2
            if(rule[LEF_RULE_LT + row] == 1 && rule[RIG_RULE_LT + row] == 2)
            {
                square[3][row] = 3;
                check[3][row] = 1;
            }
            if(rule[LEF_RULE_LT + row] == 2 && rule[RIG_RULE_LT + row] == 1)
            {
                square[0][row] = 3;
                check[0][row] = 1;
            }

            // TOP or BOT 2 & 2
            if(rule[TOP_RULE_LT + col] == 2 && rule[BOT_RULE_LT + col] == 2)
            {
                if(square[col][0] == 2 && square[col][3] == 3)
                {
                    square[col][1] = 1;
                    square[col][2] = 4;
                    check[col][1] = 1;
                    check[col][2] = 1;
                }
                else if(square[col][0] == 3 && square[col][3] == 2)
                {
                    square[col][1] = 4;
                    square[col][2] = 1;
                    check[col][1] = 1;
                    check[col][2] = 1;
                }
                if(square[col][0] == 3 && square[col][1] == 4)
                {
                    square[col][2] = 1;
                    square[col][3] = 2;
                    check[col][2] = 1;
                    check[col][3] = 1;
                }
                else if(square[col][3] == 3 && square[col][2] == 4)
                {
                    square[col][0] = 2;
                    square[col][1] = 1;
                    check[col][0] = 1;
                    check[col][1] = 1;
                }
            }
            // LEF or RIG 2 & 2
            if(rule[LEF_RULE_LT + row] == 2 && rule[RIG_RULE_LT +row] == 2)
            {
                if(square[0][row] == 2 && square[3][row] == 3)
                {
                    square[1][row] = 1;
                    square[2][row] = 4;
                    check[1][row] = 1;
                    check[2][row] = 1;
                }
                else if(square[0][row] == 3 && square[3][row] == 2)
                {
                    square[1][row] = 4;
                    square[2][row] = 1;
                    check[1][row] = 1;
                    check[2][row] = 1;
                }
                if(square[0][row] == 3 && square[1][row] == 4)
                {
                    square[2][row] = 1;
                    square[3][row] = 2;
                    check[2][row] = 1;
                    check[3][row] = 1;
                }
                else if(square[3][row] == 3 && square[2][row] == 4)
                {
                    square[0][row] = 2;
                    square[1][row] = 1;
                    check[0][row] = 1;
                    check[1][row] = 1;
                }
            }

            // TOP or BOT 2 & 3
            if(rule[TOP_RULE_LT + col] == 2 && rule[BOT_RULE_LT + col] == 3)
            {
                square[col][1] = 4;
                check[col][1] = 1;
            }
            else if(rule[TOP_RULE_LT + col] == 3 && rule[BOT_RULE_LT + col] == 2)
            {
                square[col][2] = 4;
                check[col][2] = 1;
            }
            // LEF or RIG 2 & 3
            if(rule[LEF_RULE_LT + row] == 2 && rule[RIG_RULE_LT + row] == 3)
            {
                square[1][row] = 4;
                check[1][row] = 1;
            }
            if(rule[LEF_RULE_LT + row] == 3 && rule[RIG_RULE_LT + row] == 2)
            {
                square[2][row] = 4;
                check[2][row] = 1;
            }
            col++;
        }
        row++;
    }
    
        // COL checker
        col = 0;
        row = 0;
        while(row != 4)
        {
            if(square[0][row] + square[1][row] + square[2][row] + square[3][row] != 10)
            {
                col = 0;
                counter = 0;
                while(col != 4)
                {
                    if(square[col][row] == 0)
                    {
                        target = col;
                        counter++;
                    }
                    col++;
                }
                if(counter == 1)
                {
                    square[target][row] = 10 - (square[0][row] + square[1][row] + square[2][row] + square[3][row]);
                    check[target][row] = 1;
                }
            }
            row++;
        }
        // ROW checker
        col = 0;
        row = 0;
        while(col != 4)
        {
            if(square[col][0] + square[col][1] + square[col][2] + square[col][3] != 10)
            {
                row = 0;
                counter = 0;
                while(row != 4)
                {
                    if(square[col][row] == 0)
                    {
                        target = row;
                        counter++;
                    }
                    row++;
                }
                if(counter == 1)
                {
                    square[col][target] = 10 - (square[col][0] + square[col][1] + square[col][2] + square[col][3]);
                    check[col][target] = 1;
                }
            }
            col++;
        }
    
    // PRINT
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
    // CHECK
    printf("----------\n");
    col = 0;
    row = 0;
    while(row != 4)
    {
        col = 0;
        while(col != 4)
        {
            printf("%d ",check[col][row]);
            col++;
        }
        printf("\n");
        row++;
    }
    return (0);
}