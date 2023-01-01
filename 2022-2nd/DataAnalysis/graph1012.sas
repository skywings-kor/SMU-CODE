/*Creating New Sample Data . Cars78*/
proc sql;
create table cars78 as select make, model, type, length, weight
from mydata.cars
where make in ('Audi','BMW');
run;

/*creating Bar chart */
proc sgplot data=cars78;
hbar length;
by make;
run;
quit;

/* Creating bar-line-chart*/
proc sgplot data=sashelp.stocks(where=(date>="01jan2000"d and date<="01jan2001"d and stock ="IBM"));
vbar date/ response=volume;
vline date / response=close y2axis;
run;

/*creating new sample file*/
proc sql;
create table cars2 as
select make, model,type, horsepower, length, weight
	from sashelp.cars
	where make in ('Audi','BMW');
run;

/*basic boxplot*/
proc sgplot data=cars2;
	vbox horsepower / category = type;
		title 'Horsepower of cars by types';
run;


/**/
proc sgpanel data=cars2;
panelby make;
*panelby make / columns =1 novarname;
vbox horsepower /category =type;
run;



