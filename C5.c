/*
Do NOT forget to encode your name, section and date of submission.
LASTNAME1, FIRSTNAME1:JAVIER, AARON JORDAN A.
SECTION:S13
LASTNAME2, FIRSTNAME2:MARTINEZ,MICHELLE ANDREA
SECTION:S13
DATE SUBMITTED :December 16, 2021
Make sure that you do the following:
1. COMPILE your C source code with -Wall directive.
Example: CCPROG2> gcc -Wall 02-C5.c -o 02-C5.exe
where 02 is an example group number and C5 is the Challenge number.
You must replace 02 with your own group number!
2. RUN the program's exe file in the command line with input and output (I/O)
redirection.
Example: CCPROG2> 02-C5 < AMZN.txt > 02-C5-OUTPUT.txt
The text file 02-C5-OUTPUT.txt will contain the actual output of your
program.
3. COMPARE your program's output your program with the accompanying C5-
EXPECTED.txt file using bbtest.c.
In case you do not have bbtest.exe, produce it first by compiling
bbtest.c as shown below:
Example: CCPROG2> gcc -Wall bbtest.c -o bbtest.exe
Thereafter, run bbtest.exe with I/O redirection as shown below:
Example: CCPROG2> bbtest C5-EXPECTED.txt 02-C5-OUTPUT.TXT > 02-
C5-BBTEST.txt
The output file 02-C5-BBTEST.txt contains the results of the
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
#include "C5.h" // read and understand the contents of this file
#include "numeric_date.c" // read and understand the contents of this file
/* Do NOT include other files. */
/*
HARD REQUIREMENTS: NON-COMPLIANCE WILL MAKE YOUR SOLUTION INCORRECT or CAUSE
POINT DEDUCTIONS!
1. Similar to Challenge #2, you must apply arrays and strings in solving
Challenge #5.
2. Do NOT use struct data type yet for this particular challenge.
3. Segregate your program's logic into multiple functions. Non-compliance
will result to a
5 point deduction for this Challenge.
4. Document your codes with SENSIBLE comments.
5. You are NOT allowed to use library functions that were NOT discussed in
our subject.
*/
/*
You may #define any constants that you need below this comment.
*/
#define COLUMN 4
#define ROW 966
#define SIZE 21
/*
You may declare any typedef that you need below this comment.
*/
// StrDate alias is to be used with a string that represents a date
typedef char StrDate[11];
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
/* FUNCTION FOR INPUTTING DATA AND RETURNING DATA SIZE */
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
/* FUNCTION FOR SEARCHING DATE */
int DateLinearSearch(StrDate key, StrDate DATE[], int n) {
int i;
for (i = 0; i < n; i++){
if (numeric_date(key) == numeric_date(DATE[i]))
return i;
}
return -1;
}
int BinarySearch(StrDate key, StrDate DATE[], int n) {
int low = n - 1, high = 0, mid;
int found = 0; // 0 means that the key is NOT yet found, 1 means found
while (!found && low >= high) { // not found and there are still elements to
check
mid = low+(high-low)/2;
if (numeric_date(key) == numeric_date(DATE[mid]))
found = 1;
else if (numeric_date(key) < numeric_date(DATE[mid]))
high = mid+1;
else
low = mid-1;
}
if (found)
return mid;
else
return -1;
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
/* Do NOT change the next three lines of variable declarations. */
int i;
int index;
StrDate key;
/* Do NOT change the next line of array definition. View the C5.h header file
to see the values of the macros. */
StrDate test_cases[7] = { TEST_DATE1, TEST_DATE2, TEST_DATE3, TEST_DATE4,
TEST_DATE5, TEST_DATE6, TEST_DATE7 };
/*
TO DO: Fill in the blank by CALLing the function that you defined above
for reading the stock historical data.
*/
data = InputDataFunction(name, DATE, OHLC, VOLUME);
/* NOTE: The statements below should produce the required output. You are
allowed to change or edit
ONLY those lines with blanks by filling-up the missing information.
Refer to the accompanying C5-EXPECTED.txt to see the expected results
using AMZN.txt as input file. */
/* TO DO: Fill in the blank to print the company symbol. */
printf("%s\n", name);
/* The following lines are used to test your Linear Search algorithm
implementation.
Seven test values for the search key are used which correspond to macros
TEST_DATE1 to TEST_DATE7.
*/
printf("** TEST-01-LINEAR-SEARCH**\n");
for (i = 0; i < 7; i++) {
strcpy(key, test_cases[i]);
/* TO DO: Fill in the blank by calling the Linear Search function. The
function should return an integer value to be stored in index. It the search key is
found, it should correspond to the array index where the search key was found;
otherwise, the value is -1. It must accept the search key as the 1st parameter.
Supply the function name and the other parameters that you think you'll need to
accomplish the requirement.
*/
index = DateLinearSearch(key, DATE, data);
printf("%d %12s %3d ", i + 1, key, index);
if (index != -1) { // found
/* TO DO: Fill in the blank to print the closing price
corresponding to the array index. */
printf(" %8.2f", OHLC[index][3]);
}
printf("\n");
}
printf("\n");
/* The following lines are used to test your Binary Search algorithm
implementation.
*/
printf("** TEST-02-BINARY-SEARCH**\n");
for (i = 0; i < 7; i++) {
strcpy(key, test_cases[i]);
/* TO DO: Fill in the blank by calling the Binary Search function.
The function should return an integer
value to be stored in index. It the search key is found, it
should correspond to the
array index where the search key was found; otherwise,
the value is -1.
It must accept the search key as the 1st parameter.
Supply the function name
and the other parameters that you think you'll need to
accomplish the requirement.
*/
index = BinarySearch(key, DATE, data);
printf("%d %12s %3d ", i + 1, key, index);
if (index != -1) { // key was found
/* TO DO: Fill in the blank to print the closing price
corresponding to the array index. */
printf(" %8.2f", OHLC[index][3]);
}
printf("\n");
}
return 0;
}