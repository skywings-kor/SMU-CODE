proc sql;
create table cars12 as select make, model, type, horsepower, weight, length from mydata.cars
where make in ("Audi", "BMW");
run;

proc sgplot data=cars12;
hbar length;
by make;
run;

proc sgplot data=sashelp.stocks(where=(date>="01jan2000"d and date<="01jan2001"d and stock="IBM"));
vbar date/response=volume;
vline date /response=close y2axis;
run;

proc sql;
create table cars13 as select make, model, type, horsepower, length, weight from sashelp.cars
where make in ("Audi","BMW");
run;

proc sgplot data=cars13;
vbox horsepower / category= type;
title "i want to go home";
run;

proc sgpanel data=cars13;
panelby make;
vbox horsepower / category=type;
title "Test";
run;









proc sql;
create table cars11 as select make, model, type, length, weight from mydata.cars
where make in('BMW','Audi');
run;

proc sgplot data=cars11;
hbar length;
by make;
run;

proc sgplot data=sashelp.stocks(where=(date>="01jan2000"d and date<="01jan2001"d and stock="IBM"));
vbar date / response=volume;
vline date / response=close y2axis;
run;


proc sgplot data-