/*
Do NOT forget to encode your name, section and date of submission.
LASTNAME1, FIRSTNAME1:JAVIER, AARON JORDAN A.
SECTION:S13
LASTNAME2, FIRSTNAME2:MARTINEZ,MICHELLE ANDREA
SECTION:S13
DATE SUBMITTED :
Make sure that you do the following:
1. COMPILE your C source code with -Wall directive.
Example: CCPROG2> gcc -Wall 02-C3.c -o 02-C3.exe
where 02 is an example group number and C3 is the Challenge number.
You must replace 02 with your own group number!
2. RUN the program's exe file in the command line with input and output (I/O)
redirection.
Example: CCPROG2> 02-C3 < AMZN.txt > 02-C3-OUTPUT.txt
The text file 02-C3-OUTPUT.txt will contain the actual output of your
program.
3. COMPARE your program's output your program with the accompanying C3-
EXPECTED.txt file using bbtest.c.
In case you do not have bbtest.exe, produce it first by compiling
bbtest.c as shown below:
Example: CCPROG2> gcc -Wall bbtest.c -o bbtest.exe
Thereafter, run bbtest.exe with I/O redirection as shown below:
Example: CCPROG2> bbtest C3-EXPECTED.txt 02-C3-OUTPUT.TXT > 02-
C3-BBTEST.txt
The output file 02-C3-BBTEST.txt contains the results of the
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
your solution is 100% logically
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
/* Do NOT include other files. */
/*
HARD REQUIREMENTS: NON-COMPLIANCE WILL MAKE YOUR SOLUTION INCORRECT or CAUSE
POINT DEDUCTIONS!
1. Similar to Challenge #2, you must apply arrays and strings in solving
Challenge #3.
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
It is suggest that you use #define to define a maximum array size.
*/
#define ROW 970
#define COLUMN 4
/*
You may declare any typedef that you need below this comment.
*/
typedef char string50[51]; // char [51]
typedef char str[11]; // char [11]
// StrDate alias is to be used with a string that represents a date
typedef char StrDate[11];
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
/* USER-DEFINED FUNCTIONS */
/* FUNCTION FOR INPUTTING DATA AND RETURNING DATA SIZE */
int InputDataFunction(str name, StrDate DATE[], double OHLC[][COLUMN], double
VOLUME[]){
// DECLARE VARIABLES
int row, ctr = 0; // counter for the number of data + intialize
double Open, High, Low, Close;
double Volume;
char NewDate[10];
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
/* FUNCTION FOR GETTING THE MINIMUM STOCK PRICE */
int MinimumStockPrice(double OHLC[][COLUMN], int n) {
int i; // indexing variable
int min = 0; // min contains the index of the smallest element
for (i = 1; i < n; i++){
if (OHLC[min][2] > OHLC[i][2])
min = i; // update the min index
}
return min; // returns the index of minimum
}
/* FUNCTION FOR GETTING THE MAXIMUM STOCK PRICE */
int MaximumStockPrice(double OHLC[][COLUMN], int n) {
int i; // indexing variable
int max = 0; // min contains the index of the smallest element
for (i = 1; i < n; i++){
if (OHLC[max][1] < OHLC[i][1])
max = i; // update the min index
}
return max; // returns the index of minimum
}
/*
TO DO: Complete the body of the main() function.
*/
/* MAIN FUNCTION */
int main() {
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
/* Do NOT change the next two variable declarations. Use min_index to store the
index
of the array with the lowest (minimum) stock price. Similarly, use
max_index
to store index of the the array with the highest (maximum) stock price. */
int min_index;
int max_index;
/* FUNCTION CALL FOR INPUTTING DATA */
data = InputDataFunction(name, DATE, OHLC, VOLUME);
min_index = MinimumStockPrice(OHLC, data);
max_index = MaximumStockPrice(OHLC, data);
/* TO DO: Fill in the blank to print the company symbol. */
printf("%s\n", name);
/* TO DO: Fill in the blanks to print array index corresponding to the
(a) index of the most recent lowest price, (b) the date associated with
that index
and (c) the lowest price value. */
printf("%d %s %.2f\n", min_index, DATE[min_index], OHLC[min_index][2]);
/* TO DO: Fill in the blanks to to print the array index corresponding to the
(a) index of the most recent highest price, (b) the date associated
with that index
(c) and the highest price value. */
printf("%d %s %.2f\n", max_index, DATE[max_index], OHLC[max_index][1]);
return 0;
}