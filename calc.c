#include <stdio.h>
#include <string.h>


void main() {

    char inputstring[100];
    char firstDigit[100];
    char secondDigit[100];

    char operation;

    int operator_position;
    int stringlength;
    int firstDigitNum;
    int secondDigitNum;
    int k;
    int m = 0;
    int operatorFound = 0;

    scanf("%s", &inputstring);

    for (int i = 0; inputstring[i] != '\0'; i++)
    {
        if ((inputstring[i] == '+' || inputstring[i] == '-' || inputstring[i] == '*' || inputstring[i] == '/') && operatorFound == 0 && i != 0)
        {
            operator_position = i;
            operation = inputstring[i];
            operatorFound = 1;
        }
        stringlength = i + 1;
    }

    for (int j = 0; j <= operator_position; j++)
    {
        firstDigit[j] = inputstring[j];
        if (j == operator_position)
        {
            firstDigit[j] = '\0';
            firstDigitNum = atoi(firstDigit);
        }
    }

    for (k = operator_position + 1; inputstring[k] != '\0'; k++) {
        secondDigit[m] = inputstring[k];
        m++;
    }
    secondDigit[k + 1] = '\0';
    secondDigitNum = atoi(secondDigit);

    printf("%d\n", firstDigitNum);
    printf("%d\n", secondDigitNum);


    switch (operation)
    {
    case '+': printf("%d\n", firstDigitNum + secondDigitNum);
        break;
    case '-': printf("%d\n", firstDigitNum - secondDigitNum);
        break;
    case '*': printf("%d\n", firstDigitNum * secondDigitNum);
        break;
    case '/': printf("%d\n", firstDigitNum / secondDigitNum);
        break;
    }


    return;
}