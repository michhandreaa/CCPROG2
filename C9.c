/*
CHALLENGE #9: Read From an Input Text File, Write to an Output Text File
Do NOT forget to encode your name, section and date of submission.
LASTNAME1, FIRSTNAME1: MARTINEZ, MICHELLE ANDREA SECTION: s1313
DATE SUBMITTED : Februaru 7, 2021
Make sure that you do the following:
1. COMPILE your C source code with -Wall directive.
Example: CCPROG2> gcc -Wall 02-C9.c -o 02-C9.exe
where 02 is an example group number and C9 is the Challenge number.
You must replace 02 with your own group number!
2. RUN the program's exe file in the command line. Unlike the previous
challenges you should NOT use
I/O redirection.
Example: CCPROG2> 02-C9
The input data should be read from the text files in the accompanying
folder named as SHD.
The output file should NOT be created inside the accompanying SHD folder;
it should be
in the same folder where you have your C source file.
For the 1st test function call in main(), a new output text file named as
02-AMZN.txt will be
produced after the program execution.
For the 2nd test function call, an error message "XYZ data file not
found." will be
displayed on the standard error device (i.e., display screen) via
fprintf(stderr, _____).
Lastly, the 3rd test function call will perform the required task based on
a symbol input by the user.
3. COMPARE your program's output text file with the accompanying C9-AMZN-
EXPECTED.txt file using bbtest.c.
In case you do not have bbtest.exe, produce it first by compiling
bbtest.c as shown below:
Example: CCPROG2> gcc -Wall bbtest.c -o bbtest.exe
Thereafter, run bbtest.exe with I/O redirection as shown below:
Example: CCPROG2> bbtest C9-AMZN-EXPECTED.txt 02-AMZN.txt > 02-
C9-BBTEST.txt
The output redirected file 02-C9-BBTEST.txt contains the results of the
comparison. If you see
Differences = 0 towards the end of the file, then it means that your
program's output matches the
expected output. Otherwise, if you see a Differences value higher than
0, then there's a strong
probability that you either have a logical error in your program, or
you did NOT follow the
MP specifications (including the directions in this file).
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
#include <stdlib.h>
/*
For C9: you have the option to use or not to use the structure data type you
declared in your
C6 header file. If you decide to use it, then uncomment Line 71, and
replace
GROUPNUMBER in the #include with your own group number. For
example if you are group 2,
you should have #include "02-C6.h". Group numbers from 1 to 9
should have a leading zero in
the filename.
*/
#include "44-C6.h"
// Do NOT edit/delete the next #include directive
#include "numeric_date.c" // read and understand the contents of this file
/* Do NOT include other files. */
/*
Helper function -- the use of this function is optional, i.e., you may or may
not use this function.
This function will return the numeric year given a string that stores a date
value in "MM/DD/YYYY" format.
For example, GetYear("12/17/2021") returns the value 2021.
*/
int
GetYear(char *date)
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
GetMonth(char *date)
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
GetDay(char *date)
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
1. You are required to use TEXT FILE PROCESSING commands fopen(), fclose(),
fscanf() and fprintf()
on top of previous topics in solving Challenge #9.
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
void New_Format(MultipleRowType *stock, int Year[], StrDate Month[], int Day[]);
void Print_Data(char symbol[], MultipleRowType *stock, char new[], int Year[],
StrDate Month[], int Day[]);
void Read_Store_Files(char symbol[]){
int i=0; // array index; it'll also be used as a counter
MultipleRowType stock;
int Year[ROW]={};
StrDate Month[ROW]={};
int Day[ROW]={};
// STEP 1: declare a file pointer variable
FILE *read_fp;
char new[25]= "./SHD/";
char txt[5] = ".txt"; // to add extension
strcat(new, symbol); // adds stock symbol to char new array
strcat(new, txt); // adds .txt extension to read stock symbol
// step 2: open the file in read mode
read_fp = fopen(new, "r");
//checking if file exists
if (read_fp != NULL){ // file exists
fscanf(read_fp, "%s %d", stock.Symbol, &stock.RowNumber);
// step 3: read data via fscanf()
for(i = 0; i<stock.RowNumber; i++){
fscanf(read_fp, "%s %lf %lf %lf %lf %lf", stock.Data[i].NewDate,
&stock.Data[i].Open, &stock.Data[i].High, &stock.Data[i].Low, &stock.Data[i].Close,
&stock.Data[i].Volume);
}
New_Format(&stock, Year, Month, Day);
// step 4: don't forget to close the file
fclose(read_fp);
Print_Data(symbol, &stock, new, Year, Month, Day);
}
else // file does not exist
fprintf(stderr, "%s data file not found.\n", symbol);
}
void New_Format(MultipleRowType *stock, int Year[], StrDate Month[], int Day[]){
int i; // i is used in for functions, j is used for months
char AlphMonth[12][12]={"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL",
"AUG", "SEP", "OCT", "NOV", "DEC"};
for(i=0; i <stock->RowNumber; i++){
Year[i] = GetYear(stock->Data[i].NewDate); // year
// month
if(GetMonth(stock->Data[i].NewDate) == 1)
strcpy(Month[i], AlphMonth[0]);
else if(GetMonth(stock->Data[i].NewDate) == 2)
strcpy(Month[i], AlphMonth[1]);
else if(GetMonth(stock->Data[i].NewDate) == 3)
strcpy(Month[i], AlphMonth[2]);
else if(GetMonth(stock->Data[i].NewDate) == 4)
strcpy(Month[i], AlphMonth[3]);
else if(GetMonth(stock->Data[i].NewDate) == 5)
strcpy(Month[i], AlphMonth[4]);
else if(GetMonth(stock->Data[i].NewDate) == 6)
strcpy(Month[i], AlphMonth[5]);
else if(GetMonth(stock->Data[i].NewDate) == 7)
strcpy(Month[i], AlphMonth[6]);
else if(GetMonth(stock->Data[i].NewDate) == 8)
strcpy(Month[i], AlphMonth[7]);
else if(GetMonth(stock->Data[i].NewDate) == 9)
strcpy(Month[i], AlphMonth[8]);
else if(GetMonth(stock->Data[i].NewDate) == 10)
strcpy(Month[i], AlphMonth[9]);
else if(GetMonth(stock->Data[i].NewDate) == 11)
strcpy(Month[i], AlphMonth[10]);
else if(GetMonth(stock->Data[i].NewDate) == 12)
strcpy(Month[i], AlphMonth[11]);
Day[i] = GetDay(stock->Data[i].NewDate); // day
}
}
void Print_Data(char symbol[], MultipleRowType *stock, char new[], int Year[],
StrDate Month[], int Day[]){
FILE *print_fp;
int i;
char group[20] ="44-"; // for fixing file name
char txt[5] = ".txt"; // to add extension
strcat(group, symbol); // add group number to entered portfolio_filename
strcat(group, txt);
print_fp = fopen(group, "w");
fprintf(print_fp, "%s %d\n", stock->Symbol, stock->RowNumber);
for(i = 0; i < stock->RowNumber; i++){
fprintf(print_fp, "%d-%s-%.2d %-6.2lf %-6.2lf %-6.2lf %-6.2lf
%-6.2lf\n", Year[i], Month[i], Day[i], stock->Data[i].Open, stock->Data[i].High,
stock->Data[i].Low, stock->Data[i].Close, stock->Data[i].Volume);
}
fclose(print_fp);
}
/*
main() function for testing student's solution.
*/
int
main()
{
// Fill in the blank by supplying the missing name of the function that will:
// a. read the contents of the input text file containing the stock
historical data for the company
// corresponding to the symbol specified as actual parameter
// b. write the contents of the output text file which contains the same set
of values as the input
// text file but with the date entries formatted as "YYYY-AA-DD", for
example, "2021-OCT-27".
//
// The name of output text file should be GROUPNUMBER-SYMBOL.txt where SYMBOL
is the stock's symbol. For
// example, if your group number is 2, and the stock symbol is AMZN, then the
output file should be named
// as 02-AMZN.txt.
char symbol[8];
// do NOT declare other local variables
Read_Store_Files("AMZN"); // Test #1: AMZN -- test the solution for an
existing stock symbol;
// expected output text file is GROUPNUMBER-
AMZN.txt located in the same
// folder as your C source file
Read_Store_Files("XYZ"); // Test #2: XYZ -- test the solution for a NON-
existent stock symbol.
// Since there's no company with XYZ as stock
symbol, your solution should
// display an error message on the
standard error device. The expected
// error message is:
// "XYZ data file not found." (don't forget
the period)
// NOTE: You must use fprintf(stderr, ____) to
display the error message.
// test with a symbol input by the user
printf("Input the stock symbol: ");
scanf("%s", symbol); // symbol may or may not exist
Read_Store_Files(symbol); // Test #3: -- test using a symbol input by the
user
return 0;
}