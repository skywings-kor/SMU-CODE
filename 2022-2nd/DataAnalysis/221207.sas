proc glm data=mydata.grade;
class Way;
model grade=Way;
means way / hovtest=levene;
lsmeans Way / adjust=tukey pdiff;
run;
