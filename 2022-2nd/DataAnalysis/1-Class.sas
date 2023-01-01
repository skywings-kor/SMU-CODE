/*library Creation(라이브러리 창조)*/
/*libname mydata '/folders/myfolders/';*/

/*sas file creation by cards*/

data park;		/*mydata 없이 할 경우 라이브러리-work(임시 폴더)에 저장됨*/
input nico;		/*변수 창조할 때 쓰는 거*/
cards;
20
08
23
20
22
19
18
24
17
04
;



/*sas file creation with 2 variables */


data ciga;
input x y;
cards;
77 82
50 53
;
run;		/*없어도되고 있어도됨 직접 누르기 때문*/


/*trans txt to SAS(TXT파일을 SAS로 변환)*/
proc import out=mydata.ex1
datafile="/home//ex1.txt"
DBMS=tab REPLACE;
getnames=yes;
run;

/*trans excel to SAS (엑셀파일을 sas로 변환)*/
proc import out=Univbank
datafile="/home/u62258246/universal_bank.xlsx"
DBMS=xlsx REPLACE;
SHEET='sheet1';
getnames=yes;
run;