proc sgplot data=sashelp.class;
bubble x=height y=weight size=age;
run;

proc sgpanel data=sashelp.class;
panelby sex;
bubble x=height y=weight size=age;
run;

proc sql;
create table heart2 as select status, sex, weight, cholesterol ,smoking_status from sashelp.heart;
run;

proc sgplot data=heart2;
heatmap x=weight y=cholesterol;
run;


proc sgpanel data=heart2;
panelby sex;
heatmap x=weight y=cholesterol;
run; 






proc sgpanel data=heart2;
panelby smoking_status;
heatmap x=weight y=cholesterol;
run;


proc sgplot data=sashelp.class;
where (sex="F");
series x=name y=height;
refline 60.3;
run;




