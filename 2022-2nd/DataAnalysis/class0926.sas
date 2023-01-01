/*Dataset Overlook*/

proc univariate data=mydata2.TotalScores;
var total;
by Type;
run;

/*Finding Outlier*/
proc boxplot data=mydata2.TotalScores;
plot total*Type /boxstyle=schematic;
run;

/*standardization by std*/
proc stdize data=mydata2.TotalScores method=std out=test01;
var total;
by type;
run;

/*std Result of new dataset*/
proc stdize data=test01 method=std pstat;
title 'Method=std';
var total;
by Type;
run;

/*std Result of original dataset totalscores*/
proc stdize data=mydata2.totalscores method=std pstat;
title "Method=differnece";
var total;
by Type;
run;
