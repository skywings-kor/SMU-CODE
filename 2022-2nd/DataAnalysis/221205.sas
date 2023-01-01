data mydata.life;
input race gender belief $ count @@;
cards;
1 1 Y 371 1 1 M 49 1 1 N 74
1 0 Y 250 1 0 M 45 1 0 N 71
0 1 Y 64 0 1 M 9 0 1 N 15
0 0 Y 25 0 0 M 5 0 0 N 13
;
run;


data mydata.coffee;
input first second symm count @@;
cards;
1 1 1 93 1 2 2 17 1 3 3 44 1 4 4 7 1 5 5 10
2 1 2 9 2 2 6 46 2 3 7 11 2 4 8 0 2 5 9 9
3 1 3 17 3 2 7 11 3 3 10 155 3 4 11 9 3 5 12 12
4 1 4 6 4 2 8 4 4 3 11 9 4 4 13 15 4 5 14 2
5 1 5 10 5 2 9 4 5 3 12 12 5 4 14 2 5 5 15 27
;
run;

/*젭모드 코드가 없음*/

