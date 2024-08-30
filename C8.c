/*
CHALLENGE #8: Dollar Cost Averaging (DCA)
Do NOT forget to encode your name, section and date of submission.
LASTNAME1, FIRSTNAME1: JAVIER, AARON JORDAN SECTION: S13
LASTNAME2, FIRSTNAME2: MARTINEZ, MICHELLE ANDREA SECTION: S13
DATE SUBMITTED : JAN 31, 2022
Make sure that you do the following:
1. COMPILE your C source code with -Wall directive.
Example: CCPROG2> gcc -Wall 02-C8.c -o 02-C8.exe
where 02 is an example group number and C8 is the Challenge number.
You must replace 02 with your own group number!
2. RUN the program's exe file in the command line with input and output (I/O)
redirection.
Example: CCPROG2> 02-C8 < AMZN.txt > 02-C8-OUTPUT.txt
The text file 02-C8-OUTPUT.txt will contain the actual output of your
program.
3. COMPARE your program's output your program with the accompanying C8-AMZN-
EXPECTED.txt file using bbtest.c.
In case you do not have bbtest.exe, produce it first by compiling
bbtest.c as shown below:
Example: CCPROG2> gcc -Wall bbtest.c -o bbtest.exe
Thereafter, run bbtest.exe with I/O redirection as shown below:
Example: CCPROG2> bbtest C8-AMZN-EXPECTED.txt 02-C7-OUTPUT.TXT >
02-C8-BBTEST.txt
The output file 02-C8-BBTEST.txt contains the results of the
comparison. If you see Differences = 0
towards the end of the file, then it means that your program's output
matches the expected output.
Otherwise, if you see a Differences value higher than 0, then there's a
strong probability that you
either have a logical error in your program, or you did NOT follow the
MP specifications (including
the directions in this file).
Debug your C source file, and redo the steps above until you get
Differences = 0.
Take note, however, that Differences = 0 does NOT necessarily mean that
your solutions is 100% logically
correct. The bbtest.exe only tests if two files have the same
contents. It is not meant to test the logic
of your C program.
4. TEST your solution using the stock historical data for other companies
other than AMZN.txt. Note that there
are no expected output files provided for other companies. You'll have to
figure out how to verify the
correctness of your program's output on your own.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
TO DO: replace GROUPNUMBER in the #include below with your own group number.
For example if you are group 2,
you should have #include "02-C6.h". Group numbers from 1 to 9 should have a
leading zero in the filename.
*/
#include "33-C6.h"
// Do NOT edit/delete the next #include directive
#include "numeric_date.c" // read and understand the contents of this file
/* Do NOT include other files. */
/*
Do NOT define any constant in this file.
Do NOT declare any typedef that you need below this comment.
You should encode #define and typedef declarations in your GROUPNUMBER-C6.h
header file.
*/
/*
Helper function -- the use of this function is optional, i.e., you may or may
not use this function.
This function will return the numeric year given a string that stores a date
value in "MM/DD/YYYY" format.
For example, GetYear("12/17/2021") returns the value 2021.
*/
int
GetYear(StrDate date)
{
return atol(date+6); // date + 6 is the start of the portion of the string
that stores the "YYYY".
}
/*
Helper function -- the use of this function is optional, i.e., you may or may
not use this function.
This function will return numeric month given a string that stores a date
value in "MM/DD/YYYY" format.
For example, GetMonth("12/17/2021") returns the value 12.
*/
int
GetMonth(StrDate date)
{
char temp[3] = "";
temp[0] = date[0]; // extract the 1st digit of the month
temp[1] = date[1]; // extract the 2nd digit of the month
return atol(temp);
}
/*
Helper function -- the use of this function is optional, i.e., you may or may
not use this function.
This function will return numeric day given a string that stores a date value
in "MM/DD/YYYY" format.
For example, GetDay("12/17/2021") returns the value 17.
*/
int
GetDay(StrDate date)
{
char temp[3] = "";
temp[0] = date[3]; // extract the 1st digit of the day
temp[1] = date[4]; // extract the 2nd digit of the day
return atol(temp);
}
/
*==================================================================================
================*/
/*
HARD REQUIREMENTS: NON-COMPLIANCE WILL MAKE YOUR SOLUTION INCORRECT or CAUSE
POINT DEDUCTIONS!
1. You are required to use structures, arrays and strings concepts in solving
Challenge #7.
2. Segregate your program's logic into multiple functions. Non-compliance
will result to a
5 point deduction for this Challenge.
3. Document your codes with SENSIBLE comments.
4. You are NOT allowed to use library functions that were NOT discussed in
our subject.
*/
/*
TO DO: Define the functions that you need below this comment. You are the one
responsible in deciding
what should be the function's
a. return data type
b. name
c. formal parameters
d. local variables and statements inside the body.
You SHOULD write a SENSIBLE comment describing briefly what the function is
supposed to accomplish BEFORE
the function definition itself.
*/
/*
1st required function: use scanf() to read and store the contents of the SHD
data file (for example AMZN.txt)
via input redirection. Your function definition must have ONLY ONE formal
parameter.
*/
void Read_Store_SHD(MultipleRowType *stock){
// declare the data structure variable
int i; // counter for the number of students
scanf("%s", stock->Symbol);
scanf("%d", &stock->RowNumber);
// initialize the contents via scanf()
// structure member access operator (dot symbol)
for(i=0; i<stock->RowNumber; i++){
scanf("%s %lf %lf %lf %lf %lf", stock->Data[i].NewDate, &stock-
>Data[i].Open, &stock->Data[i].High, &stock->Data[i].Low, &stock->Data[i].Close,
&stock->Data[i].Volume);
}
}
/*
2nd required function: implement Dollar Cost Averaging as described in the MP
specifications document.
Your function definition must have ONLY TWO FORMAL PARAMETERS, one of them is
the value of the Fixed
Dollar Amount (FDA).
You are required to use the following printf() statements to ensure that your
output will be in the
same format as the EXPECTED output files. Fill in the missing parameters.
a. for printing the counter, date, buy price, number of shares and the
accumulated total number of shares
printf("%2d %s %.2lf %lf %lf\n",
______________________________________);
b. for printing the other results
printf("\n");
printf("Number of buy transactions = %d\n", ______);
printf("Total buy amount = %.2lf\n", ______);
printf("Total number of shares bought = %lf\n", ______);
printf("Average price per share = %lf\n", ______);
printf("\n");
printf("Sell date = %s\n", ______);
printf("Sell price = %.2lf\n", ______);
printf("Sell amount = %lf\n", ______);
printf("P/L = %lf\n", ______);
printf("%%P/L = %lf\n", ______);
*/
void Print_Student_Array(MultipleRowType *stock, double FDA){
int i;
int counter = 0, min=0;
double runningshares = 0;
double RUNNINGSHARES[ROW]={0};
double SHARESBOUGHT[ROW]={0};
double TEMPORARY[ROW]={0};
for(i=stock->RowNumber; i>0; i--){ // starting with earliest date
SHARESBOUGHT[i] = FDA/stock->Data[i-1].Close;
if(GetMonth(stock->Data[i].NewDate) < GetMonth(stock->Data[i-
1].NewDate)){ // ie. Jan (01) < Feb (02)
counter++;
if(GetDay(stock->Data[i].NewDate) < GetDay(stock-
>Data[min].NewDate)){ // checks if it's the earliest day
RUNNINGSHARES[i] = SHARESBOUGHT[i];
min=i;
printf("%2d %s %.2lf %lf %lf\n", counter, stock-
>Data[i-1].NewDate, stock->Data[i-1].Close, SHARESBOUGHT[i], RUNNINGSHARES[i]);
TEMPORARY[counter] = RUNNINGSHARES[i];
runningshares = RUNNINGSHARES[i];
}
else { // not the earliest date
RUNNINGSHARES[i] = TEMPORARY[counter-1] + SHARESBOUGHT[i];
printf("%2d %s %.2lf %lf %lf\n", counter, stock-
>Data[i-1].NewDate, stock->Data[i-1].Close, SHARESBOUGHT[i], RUNNINGSHARES[i]);
TEMPORARY[counter] = RUNNINGSHARES[i];
runningshares = RUNNINGSHARES[i];
}
}
else if(GetMonth(stock->Data[i].NewDate) > GetMonth(stock->Data[i-
1].NewDate)){ // ie. DEC (12) < Jan (01)
RUNNINGSHARES[i] = TEMPORARY[counter] + SHARESBOUGHT[i];
counter++;
printf("%2d %s %.2lf %lf %lf\n", counter, stock->Data[i-
1].NewDate, stock->Data[i-1].Close, SHARESBOUGHT[i], RUNNINGSHARES[i]);
TEMPORARY[counter] = RUNNINGSHARES[i];
runningshares = RUNNINGSHARES[i];
}
}
printf("\n");
printf("Number of buy transactions = %d\n", counter);
printf("Total buy amount = %.2lf\n", (FDA*counter));
printf("Total number of shares bought = %lf\n", runningshares);
printf("Average price per share = %lf\n",
((FDA*counter)/runningshares));
printf("\n");
printf("Sell date = %s\n", (stock->Data[0].NewDate));
printf("Sell price = %.2lf\n", (stock->Data[0].Close));
printf("Sell amount = %lf\n", ((stock->Data[i].Close)*runningshares));
printf("P/L = %lf\n", (((stock->Data[i].Close)*runningshares)-
(FDA*counter)));
printf("%%P/L = %lf\n", (((((stock->Data[i].Close)*runningshares)-
(FDA*counter))/(FDA*counter))*100));
}
/*
TO DO: Complete the body of the main() function.
*/
int
main()
{
/* TO DO: declare a structure variable that will the store the SHD for a
company. The structure
variable will store the
a. stock symbol
b. actual number of rows of data
c. date, OHLC and Volume values for each row of data
The variable's data type should be the one you declared in your C6.h
header file.
*/
MultipleRowType stock; // example: stockType stock;
double fda; // this variable stores the value of the Fixed Dollar Amount
/* You are NOT allowed to declare other local variables. */
/*
Fill in the blank based on the TO DO requirement.
*/
Read_Store_SHD(&stock); // TO DO: call the 1st required function that will
read and store the SHD
// YOU MUST PASS ONLY ONE ACTUAL
PARAMETER
printf("%s\n", stock.Symbol); // TO DO: print the stock symbol
printf("%d\n", stock.RowNumber); // TO DO: print the actual number of
rows of stock historical data
printf("\n");
fda = 100.00; // set Fixed Dollar Amount to 100 dollars
for testing purposes
// note that I may change this when I test
your solution.
printf("FDA = %.2lf\n", fda);
printf("\n");
Print_Student_Array(&stock, fda); // TO DO: call the 2nd required function for
Dollar Cost Averaging
// YOU MUST PASS
ONLY TWO ACTUAL PARAMETERS, one of them
// is the value of
the Fixed Dollar Amount
return 0;
}