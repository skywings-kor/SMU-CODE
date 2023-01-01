proc univariate data=mydata2.totalscores;
var total;
by Type;
run;


proc boxplot data=mydata2.totalscores;
plot total*Type / boxstyle=schematic;
run;


proc stdize data=mydata2.totalscores method=std out=totalscores01;
var total;
by Type;
run;


proc stdize data=totalscores01 method=std pstat;
title 'method hehehehe';
var total;
by Type;
run;


