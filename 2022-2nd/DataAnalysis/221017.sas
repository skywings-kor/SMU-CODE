/*버블 도표*/
proc sgplot data=sashelp.class;
	bubble x=height y=weight size=age;	
run;

/*creating bubble chart by man,female*/
proc sgpanel data=sashelp.class;
	panelby sex;
	bubble x=height y=weight size=age;
run;




/*열지도*/
proc sql;
create table heart1 as select status, sex, weight, cholesterol ,smoking_status from sashelp.heart;
run;

/*creating heatmap*/
proc sgplot data=heart1;
	heatmap x=weight y=cholesterol;
run;


/*Creating heatmap by sex*/
proc sgpanel data=heart1;
	panelby sex;
	heatmap x=weight y=cholesterol;
run;

/*Creating heatmap by status*/
proc sgpanel data=heart1;
 panelby smoking_status;
 heatmap x=weight y=cholesterol;
run;


/*선그래프*/
proc sgplot data=sashelp.class;
	where(sex="F");
	series x=name y=height;
	/*refline은 평균임*/
	refline 60.8;
run;

