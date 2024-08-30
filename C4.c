/*
Do NOT forget to encode your name, section and date of submission.
LASTNAME1, FIRSTNAME1: SECTION:
LASTNAME2, FIRSTNAME2: SECTION:
DATE SUBMITTED :December 16, 2021
Make sure that you do the following:
1. COMPILE your C source code with -Wall directive.
Example: CCPROG2> gcc -Wall 02-C4.c -o 02-C4.exe
where 02 is an example group number and C4 is the Challenge number.
You must replace 02 with your own group number!
2. RUN the program's exe file in the command line with input and output (I/O)
redirection.
Example: CCPROG2> 02-C4 < AMZN.txt > 02-C4-OUTPUT.txt
The text file 02-C4-OUTPUT.txt will contain the actual output of your
program.
3. COMPARE your program's output your program with the accompanying C4-
EXPECTED.txt file using bbtest.c.
In case you do not have bbtest.exe, produce it first by compiling
bbtest.c as shown below:
Example: CCPROG2> gcc -Wall bbtest.c -o bbtest.exe
Thereafter, run bbtest.exe with I/O redirection as shown below:
Example: CCPROG2> bbtest C4-EXPECTED.txt 02-C4-OUTPUT.TXT > 02-
C4-BBTEST.txt
The output file 02-C4-BBTEST.txt contains the results of the
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
are not expected output files provided for other companies. You'll have
to figure out how to verify the
correctness of your program's output on your own.
*/
#include <stdio.h>
#include <string.h>
#include "C4.h" // read and understand the contents of this file
/* Do NOT include other files. */
/*
HARD REQUIREMENTS: NON-COMPLIANCE WILL MAKE YOUR SOLUTION INCORRECT or CAUSE
POINT DEDUCTIONS!
1. Similar to Challenge #2, you must apply arrays and strings in solving
Challenge #4.
2. Do NOT use struct data type yet for this particular challenge.
3. Segregate your program's logic into multiple functions. Non-compliance
will result to a
5 point deduction for this Challenge.
4. Document your codes with SENSIBLE comments.
5. You are NOT allowed to use library functions that were NOT discussed in
our subject.
*/
/* Do NOT change the name of MAX defined in the next line. Also do NOT define a
macro with the same name as MAX. */
#define MAX 1000
/*
You may #define any constants that you need below this comment.
*/
#define COLUMN 5
#define ROW 966
#define SIZE 21
/*
You may declare any typedef that you need below this comment.
*/
// StrDate alias is to be used with a string that represents a date
typedef char StrDate[11]; // char [51]
typedef char string50[51]; // char [51]
typedef char str[11]; // char [11]
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
//* FUNCTION FOR INPUTTING DATA AND RETURNING DATA SIZE */
int InputDataFunction(str name, StrDate DATE[], double OHLC[][COLUMN], double
VOLUME[]){
// DECLARE VARIABLES
int row, ctr = 0; // counter for the number of data + intialize
double Open, High, Low, Close;
double Volume;
char NewDate[11];
// input of company name and rows
scanf("%s %d", name, &row);
// initialize the contents via scanf()
for (ctr = 0; ctr < row; ctr++){
scanf("%s %lf %lf %lf %lf %lf", NewDate, &Open, &High, &Low, &Close, &Volume);
strcpy(DATE[ctr], NewDate);
OHLC[ctr][0] = Open;
OHLC[ctr][1] = High;
OHLC[ctr][2] = Low;
OHLC[ctr][3] = Close;
VOLUME[ctr] = Volume;
}
return row;
}
/* FUNCTION FOR SMA AVERAGE */
double AverageSMA(int m, StrDate DateSMA[], double SMA[], StrDate DATE[], double
OHLC[][COLUMN],int n){
int i, j=0, k;
//int num=m-1;
double sum = 0;
for(i = n-m; i >= 0; i--){ // iterates for all the elements included
strcpy(DateSMA[j], DATE[i]); // changes the order when copied
k=m-1;
while(k>=0)
{ // loops from m to current index
sum += OHLC[i+k][3];
//gets the sum of current ave and ohlc
k--;
}
;
SMA[j]=sum/m; // the SMA is total sum of m closing prices/
sum=0; // re-initialize average back to 0 before iterating
j++;
}
return j;
}
/*
TO DO: Complete the body of the main() function.
*/
int
main()
{
/* TO DO: Declare your own local variables AFTER this comment. You MUST
declare and use variables
for the following:
1. a string for storing company symbol, example "AMZN"
2. an integer for storing the number of rows of stock historical data
(in the case
of AMZN.txt this value will store 629)
variable
3. 1D array of string for storing the dates (assume that the date
values in the text file are
are already formatted as "MM/DD/YYYY")
4. 2D array of double values for storing the OHLC values
5. 1D array of double for storing the volume
*/
str name;
int data;
StrDate DATE[ROW];
double OHLC[ROW][COLUMN];
double VOLUME[ROW];
/* Do NOT change the next four lines of variable declarations. */
int i, j, m;
int count;
StrDate DateSMA[MAX]; // 1D array of dates with corresponding SMA values
double SMA[MAX]; // 1D array of SMA values
/* Do NOT change the next line of array definition. View the C4.h header file
to see the values of the macros. */
int test_cases[3] = { TEST_NDAYS1, TEST_NDAYS2, TEST_NDAYS3 };
/*
TO DO: Fill in the blank by CALLing the function that you defined above
for reading the stock historical data.
*/
data = InputDataFunction(name, DATE, OHLC, VOLUME);
/* NOTE: The statements below should produce the required output. You are
allowed to change or edit
ONLY those lines with blanks by filling-up the missing information.
Refer to the accompanying C4-EXPECTED.txt to see the expected results
using AMZN.txt as input file. */
/* TO DO: Fill in the blank to print the company symbol. */
printf("%s\n", name);
/* The following lines are used to test the function you defined for computing
the m-day SMA.
Three test values for m are used which correspond to the macros
TEST_NDAYS1, TEST_NDAYS2, and TEST_NDAYS3.
*/
for (i = 0; i < 3; i++) { // for each test case
m = test_cases[i]; // m is the number of prices that are averaged
printf("\n**TEST-%d-day-SMA**\n", m);
/* TO DO: Fill in the blank by calling the function that computes the
m-day SMA. The function should return
an integer value to be stored in count. It must also accept
as 1st parameter the value of m,
DateSMA as 2nd parameter, and SMA as 3rd parameter. Supply
the function name
and the other parameters that you think you'll need to
accomplish the requirement. */
count = AverageSMA(m, DateSMA, SMA, DATE, OHLC, data) ;
/* The following will print the count value, the dates and SMA values.
Again, refer to the accompanying C4-EXPECTED.txt to see the expected
results using AMZN.txt as input file. */
printf("count = %d\n", count);
for (j = 0; j < count; j++)
printf("%3d %s %.2lf\n", j + 1, DateSMA[j], SMA[j]);
printf("\n");
}
return 0;
}