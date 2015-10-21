#include <stdio.h>
#include <string.h>

int exec_calculator(const char *inputStr)
{
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

    for (int i = 0; inputStr[i] != '\0'; i++)
    {
        if ((inputStr[i] == '+' || inputStr[i] == '-' || inputStr[i] == '*' || inputStr[i] == '/') && operatorFound == 0 && i != 0)
        {
            operator_position = i;
            operation = inputStr[i];
            operatorFound = 1;
        }
        stringlength = i + 1;
    }

    for (int j = 0; j <= operator_position; j++)
    {
        firstDigit[j] = inputStr[j];
        if (j == operator_position)
        {
            firstDigit[j] = '\0';
            firstDigitNum = atoi(firstDigit);
        }
    }

    for (k = operator_position + 1; inputStr[k] != '\0'; k++) {
        secondDigit[m] = inputStr[k];
        m++;
    }
    secondDigit[k + 1] = '\0';
    secondDigitNum = atoi(secondDigit);

    printf("%d\n", firstDigitNum);
    printf("%d\n", secondDigitNum);


    switch (operation)
    {
    case '+': return firstDigitNum + secondDigitNum;
    case '-': return firstDigitNum - secondDigitNum;
    case '*': return firstDigitNum * secondDigitNum;
    case '/': return firstDigitNum / secondDigitNum;
    default: return 0;
    }

    return 0;
}

struct test_case_t
{
    const char *expr;
    int expected_result;
};

#define NELEMENTS(a) (sizeof(a) / sizeof(a[0]))

int main(int argc, char **argv)
{
    int i;

    /*
     * We can run in two ways:
     *
     * 1 - accept a doubled-quote-string argument, like:
     *      .\our-program.exe "1 + 1"
     *
     * 2 - accept no arguments and run the hard-coded test-cases, like:
     *      .\our-program.exe
     */

    if (argc == 2)
    {
        printf("calculating \"%s\"\n", argv[1]);
        printf("%d\n", exec_calculator(argv[1]));
    }

    struct test_case_t testCases[] =
    {
        /* ez stuff */
        { "1 + 0", 1 },
        { "1 * 0", 0 },
        { "3 * 3", 9 },
        { "0 - 100", -100 },
        { "1-0", 1 },
        { "0 -1", -1 },
        { "-1 - 0", -1 },
        { "-1 * 7", -7 },
        /* time to break it */
        { "1 / 2", 1 },     /* integer math w/ rounding or floating-point? */
        { "1 / 0", 0 },     /* uh oh */
        { "1", 1 }          /* this is reasonable */
    };

    for (i = 0; i < NELEMENTS(testCases); ++i)
    {
        const struct test_case_t *t = &testCases[i];

        int result = exec_calculator(t->expr);

        printf("TEST CASE \"%s = %d\": %s\n",
            t->expr,
            t->expected_result,
            (t->expected_result == result) ? "PASS" : "FAIL");
    }

    return 0;
}