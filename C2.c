/*
Do not forget to encode your name, section and date of submission.
LASTNAME1, FIRSTNAME1:JAVIER, AARON JORDAN A.
SECTION:S13
LASTNAME2, FIRSTNAME2:MARTINEZ, MICHELLE ANDREA
SECTION:S13
DATE SUBMITTED :Dec 15,2021
CCPROG2 MP Solution for: Challenge #2
Make sure to compile your C source code with a -Wall directive. Use -o
directive to specify the exe file.
Example: CCPROG2> gcc -Wall 02-C2.c -o 02-C2.exe
Run the program's exe file in the command line with input and output (I/O)
redirection.
Example: CCPROG2> 02-C2 < AMZNorig.txt > AMZN.txt
*/
#include <stdio.h>
#include <string.h>
#define ROW 970
#define COLUMN 4
/* Do NOT include other header files. */
/*
HARD REQUIREMENTS: NON-COMPLIANCE WILL MAKE YOUR SOLUTION INCORRECT or CAUSE
POINT DEDUCTIONS!
1. You must apply arrays and strings in solving Challenge #2.
2. Do NOT use the following yet for this particular challenge:
a. struct data type
b. file processing functions such as fopen(), fclose(), etc.
3. Segregate your program's logic into functions. Non-compliance will result
to a 5 point
deduction for this Challenge.
4. Document your codes with SENSIBLE comments.
5. You are NOT allowed to use library functions that were NOT discussed in
our online class.
*/
/*
You may declare any typedef that you need below this comment.
*/
typedef char string50[51]; // char [51]
typedef char strdate[11]; // char [11]
typedef char str[11]; // char [11]
/*
Define any function that you need below this comment.
*/
/* DECLARING FUNCTION FOR FORMATTING DATE */
void DateFormatFunction(char NewDate[]); // mm/dd/yyyy
/* FUNCTION FOR INPUTTING DATA AND RETURNING DATA SIZE */
int InputDataFunction(str name, strdate DATE[], double OHLC[][COLUMN], double
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
DateFormatFunction(NewDate); // call function for fixing format so no need to call later
strcpy(DATE[ctr], NewDate);
OHLC[ctr][0] = Open;
OHLC[ctr][1] = High;
OHLC[ctr][2] = Low;
OHLC[ctr][3] = Close;
VOLUME[ctr] = Volume;
}
return row;
}
/* ACTUAL FUNCTION FOR FORMATTING DATE */
void DateFormatFunction(char NewDate[]){ // mm/dd/yyyy
int len;
len = strlen(NewDate);
while(len != 10){
if(NewDate[2] != '/'){ // month guarantee has only 1 digit
if (NewDate[4] == '/'){ // one digit for month, but two digits for day
NewDate[9] = NewDate[8];
NewDate[8] = NewDate[7];
NewDate[7] = NewDate[6];
NewDate[6] = NewDate[5];
NewDate[5] = NewDate[4];
NewDate[4] = NewDate[3];
NewDate[3] = NewDate[2];
NewDate[2] = NewDate[1];
NewDate[1] = NewDate[0];
NewDate[0] = '0';
len = strlen(NewDate);
}
else{ // one digit for both month and day
NewDate[9] = NewDate[8];
NewDate[8] = NewDate[7];
NewDate[7] = NewDate[6];
NewDate[6] = NewDate[5];
NewDate[5] = NewDate[4];
NewDate[4] = NewDate[3];
NewDate[3] = NewDate[2];
NewDate[2] = '0';
NewDate[2] = NewDate[1];
NewDate[1] = NewDate[0];
NewDate[0] = '0';
len = strlen(NewDate);
}
}
if((NewDate[2] == '/') && (NewDate[5] != '/')){ // one digit guarantee for day
NewDate[9] = NewDate[8];
NewDate[8] = NewDate[7];
NewDate[7] = NewDate[6];
NewDate[6] = NewDate[5];
NewDate[5] = NewDate[4];
NewDate[4] = NewDate[3];
NewDate[3] = '0';
NewDate[2] = NewDate[2];
NewDate[1] = NewDate[1];
NewDate[0] = NewDate[0];
len = strlen(NewDate);
}
if(NewDate[9] == '\0'){ // year is not 4 digits
NewDate[9] = NewDate[8];
NewDate[8] = NewDate[7];
NewDate[7] = '0';
NewDate[6] = '2';
NewDate[5] = NewDate[5];
NewDate[4] = NewDate[4];
NewDate[3] = NewDate[3];
NewDate[2] = NewDate[2];
NewDate[1] = NewDate[1];
NewDate[0] = NewDate[0];
len = strlen(NewDate);
}
}
}
/* FUNCTION FOR PRINTING DATA */
void OutputDateFunction(str name, strdate DATE[], double OHLC[][COLUMN], double
VOLUME[], int n){
int i;
printf("%s %-6d\n\n", name, n);
for (i = 0; i < n; i++) {
printf("%s %-6.2lf %-6.2lf %-6.2lf %-6.2lf %-6.2lf\n", DATE[i], OHLC[i][0],
OHLC[i][1], OHLC[i][2], OHLC[i][3], VOLUME[i]);
}
}
int main(){
str name;
int data;
strdate DATE[ROW];
double OHLC[ROW][COLUMN];
double VOLUME[ROW];
/* FUNCTION CALL FOR INPUTTING DATA */
data = InputDataFunction(name, DATE, OHLC, VOLUME);
/* FUNCTION CALL FOR PRINTING OF DATA */
OutputDateFunction(name, DATE, OHLC, VOLUME, data);
return 0;
}