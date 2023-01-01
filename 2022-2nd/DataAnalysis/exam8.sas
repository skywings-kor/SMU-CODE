proc sql;
create table cars14 as select make,model, type, horsepower, weight, length from sashelp.cars where make in("BMW","Audi");
run;

proc sgplot data=cars14;
hbar weight;
by make;
run;

proc sgpanel data=cars14;
panelby make;
vbox horsepower / category=type;
run;