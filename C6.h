/*
Challenge #6 header file.
This file will be included in your source codes for Challenges #7 and #8.
Do NOT forget to encode your name, section and date of submission.
LASTNAME1, FIRSTNAME1: JAVIER, AARON JORDAN SECTION: S13
LASTNAME2, FIRSTNAME2: MARTINEZ, MICHELLE ANDREA SECTION: S13
DATE SUBMITTED :
*/
/*
Do NOT change the lines that contain #ifndef, #define and #endif processor
directives.
*/
#ifndef C6_DEFINED
#define C6_DEFINED (1)
/*
You may #define any number of constants that you need below this comment.
*/
#define COLUMN 4
#define ROW 966
#define SIZE 21
/*
You may declare any typedef that you need below this comment.
*/
typedef char Str20[21];
/*
Do NOT change the next two typedef declarations.
You should use StrDate alias for a string that represents date.
You should use StrStock alias for a string that represents the stock code,
for example: "AMZN".
*/
typedef char StrDate[11];
typedef char StrStock[6];
/*
TO DO: Declare your struct data type for representing & storing ONE row of
stock historical data (SHD),
i.e., date, OHLC and volume. Again, it is for just one row (or one line of
text), NOT for all
rows of stock data.
Use sensible tag names and member names.
You are REQUIRED to write sensible inline comments to describe the purose/use
purpose of each member.
*/
struct OneRow {
StrDate NewDate;
double Open;
double High;
double Low;
double Close;
double Volume;
};
/*
TO DO: Declare a typedef alias for the struct data type you declared above.
*/
typedef struct OneRow OneRowType;
/*
TO DO: Declare your struct data type for representing and storing ALL values
present in a text
file which contains the stock data.
This data structure will be used for storing:
a. stock symbol
b. actual number of rows of data
c. date, OHLC and Volume values for each row of data -- you are REQUIRED
to use the
struct data type or alias you declared above.
Use sensible tag names and member names.
You are REQUIRED to write sensible inline comments to describe the
purpose/use purpose of each member.
*/
struct MultipleRow {
StrStock Symbol;
int RowNumber;
OneRowType Data[ROW];
};
/*
TO DO: Declare a typedef alias for the struct data type you declared above.
*/
typedef struct MultipleRow MultipleRowType;
#endif