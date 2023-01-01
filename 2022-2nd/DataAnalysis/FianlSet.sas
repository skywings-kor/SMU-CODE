data work.baseball23;
	set SASHELP.BASEBALL;
	keep nAtBat Salary League;
	where League="American";
run;

