proc means data=SASHELP.CLASSFIT chartype mean std min max n var vardef=df 
		skewness kurtosis;
	var Height Weight;
	class Sex;
run;


proc sql;
create table MYDATA.Fish1 as select Species, Weight, Length1, Height, Width from sashelp.fish
where Species in ("Roach","Pike","Smelt");
run;

proc sgpanel data=WORK.FISH2;
	panelby Species;
	bubble x=Length1 y=Weight size=Width;
run;
