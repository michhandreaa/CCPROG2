/*
CHALLENGE #10: Stock Portfolio (Final Challenge)
Do NOT forget to encode your name, section and date of submission.
LASTNAME1, FIRSTNAME1: MARTINEZ, MICHELLE ANDREA SECTION: S13
DATE SUBMITTED : FEBRUARY 08, 2020
Make sure that you do the following:
1. COMPILE your C source code with -Wall directive.
Example: CCPROG2> gcc -Wall 02-C10.c -o 02-C10.exe
where 02 is an example group number and C10 is the Challenge number.
You must replace 02 with your own group number!
2. RUN the program's exe file in the command line. Unlike the previous
challenges you should NOT use
I/O redirection.
Example: CCPROG2> 02-C10
Your program should produce two text files named as:
a. 02-PORTFOLIO.txt
b. 02-MYTEST.txt
based on the two function calls in the main() function. The output files
should NOT be created inside
the accompanying SHD folder; it should be in the same folder where you
have your C source file.
3. COMPARE your program's 02-PORTFOLIO.txt output file with the accompanying
C10-EXPECTED.txt file
using bbtest.c.
In case you do not have bbtest.exe, produce it first by compiling
bbtest.c as shown below:
Example: CCPROG2> gcc -Wall bbtest.c -o bbtest.exe
Thereafter, run bbtest.exe with I/O redirection as shown below:
Example: CCPROG2> bbtest C10-EXPECTED.txt 02-PORTFOLIO.txt > 02-
C10-BBTEST.txt
The output redirected file 02-C10-BBTEST.txt contains the results of
the comparison. If you see
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
your solutions is 100% logically
correct. The bbtest.exe only tests if two files have the same
contents. It is not meant to test the logic
of your C program.
4. TEST your solution using the stock historical data for other companies.
Create your own portfolio
text file and use them for testing. You'll have to figure out how to
verify the correctness of your
program's output using your own portfolio files.
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
#include "44-C6.h"
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
on top of previous topics in solving Challenge #10.
2. You are required to implement and use a binary search algorithm for
searching using buy date
as search key.
3. Segregate your program's logic into multiple functions. Non-compliance
will result to a
5 point deduction for this Challenge.
4. Document your codes with SENSIBLE comments.
5. You are NOT allowed to use library functions that were NOT discussed in
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
int BinarySearch(MultipleRowType *stock, StrDate tempdate);
void Read_Files(char portfolio_filename[], char reference_date[]){
int i, j=0, dateindex=0, referenceindex=0; // array index; it'll also be used
as a counter
double shares=0;
StrStock symbol={};
StrDate date={};
double SHARES[ROW]={};
StrStock SYMBOL[20]={};
StrDate DATE[20]={};
MultipleRowType stock;
// step 1: declare a file pointer variable
FILE *fp; // for reading portfolio.txt
FILE *fp_SHD; // for reading SHD file txt
FILE *fp_Result; // for writing output txt
double pl=0, ppl=0, referenceprice=0;
char group[12] ="44-"; // for fixing file name
strcat(group, portfolio_filename); // add group number to entered
portfolio_filename
fp_Result = fopen(group, "w"); // step 2: open the file in write mode
// step 2: open the file in read mode
fp = fopen(portfolio_filename, "r"); // reading entered portfolio_filename txt
files
// checking if file exists
if (fp != NULL){ // portfolio_filename file exists
i=0;
fprintf(fp_Result,"PORTFOLIO PERFORMANCE AS OF %s\n\n",
reference_date); // write processed stock data to output
while(fscanf(fp, "%s %lf %s", symbol, &shares, date) == 3){ // step 3: read
data via fscanf() from portfolio_filename entered
strcpy(SYMBOL[i], symbol);
SHARES[i] = shares;
strcpy(DATE[i], date);
char new[20] = "./SHD/"; // array for SHD files
char txt[5] = ".txt"; // to add extension
strcat(new, SYMBOL[i]); // adds stock symbol to char new array
strcat(new, txt); // adds .txt extension to read stock symbol
// step 2: open the file in read mode
fp_SHD = fopen(new, "r"); // opens SHD .txt file
// checking if file exists
if(fp_SHD != NULL){ // SHD file exists
fscanf(fp_SHD, "%s %d", stock.Symbol, &stock.RowNumber);
for (j = 0; j < stock.RowNumber; j++){
fscanf(fp_SHD, "%s %lf %lf %lf %lf %lf",
stock.Data[j].NewDate, &stock.Data[j].Open, &stock.Data[j].High,
&stock.Data[j].Low, &stock.Data[j].Close, &stock.Data[j].Volume);
}
dateindex = BinarySearch(&stock, DATE[i]);
referenceindex = BinarySearch(&stock, reference_date);
referenceprice = stock.Data[referenceindex].Close;
pl = referenceprice - stock.Data[dateindex].Close;
ppl = (pl/stock.Data[dateindex].Close)*100;
fprintf(fp_Result, "%s %6.6lf %6s %6.6lf %6.6lf
%6.6lf %6.6lf\n", SYMBOL[i], SHARES[i], DATE[i], stock.Data[dateindex].Close,
referenceprice, pl, ppl);
}
else{ // SHD file does not exist
fprintf(stderr, "error: %s does not exist!\n", new);
}
i++;
}
// step 4: don't forget to close the file
fclose(fp_Result);
fclose(fp_SHD);
fclose(fp);
}
else{ // portfolio_filename file does not exist
fprintf(stderr, "error: %s does not exist!\n", portfolio_filename);
}
}
/*
You are required to implement and use a binary search algorithm for searching
the buy date
as search key. Implement your binary search function after this comment...
*/
int BinarySearch(MultipleRowType *stock, StrDate tempdate){
int i, index=0; // i is used in for function -- index is used for printing
out the correct i in which date_key was equal to date in data
int key=0; // 0 means that the key is not yet found, 1 means found
int low=0;
int high=stock->RowNumber-1;
int mid=0;
mid=low+(high-low)/2;
for(i=0; i<stock->RowNumber; i++){
if(numeric_date(stock->Data[i].NewDate) == numeric_date(tempdate)){ //
search middle
key=1;
index=i;
}
else if(numeric_date(stock->Data[i].NewDate) <
numeric_date(tempdate)) // search high
high=mid+1;
else // search low
low=mid-1;
}
if(key==1) // found
return index;
else // not found
printf("%s NO DATA\n", tempdate);
return 0;
}
/*
TO DO: Complete the body of the main() function.
*/
int
main()
{
char portfolio_filename[100];
char reference_date[11];
// do NOT declare other variables
// Fill in the blank by supplying the name of the function that will process
the contents of the
// portfolio text file based on the specified reference date.
//
// Except for the required function names, you are NOT allowed to add any
other lines of codes.
// Test #1: based on hardcoded actual parameters
Read_Files("PORTFOLIO.txt", "10/29/2021");
// Test #2: based on actual parameters specified via scanf()
printf("Input the name of your test portfolio file: ");
scanf("%s", portfolio_filename); // example: MYTEST.txt or other files that
you may want
// to use for testing
printf("Input a reference date in MM/DD/YYYY format: ");
scanf("%s", reference_date); // example: 10/29/2021 or other dates you may
want to use for testing
Read_Files(portfolio_filename, reference_date);
return 0;
}