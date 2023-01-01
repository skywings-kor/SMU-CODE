proc univariate data=mydata2.totalscores;
var total;
by type;
run;

proc boxplot data=mydata2.totalscores;
plot total*type / boxstyle=schematic;
run;

proc stdize data=test01 method=std pstat;
title "Mehod=std";
var total;
by Type;
run;

proc stdize data=mydata2.totalscores method=std pstat;
title "Method-difference";
var total;
by type;
run;