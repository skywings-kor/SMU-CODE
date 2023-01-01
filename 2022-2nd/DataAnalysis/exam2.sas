/*
 *
 * SAS Studio 3.8에서 생성된 작업 코드 
 *
 * 생성일: '22. 10. 22. 오후 11:22' 
 * 생성자: 'u62258246' 
 * 생성 서버: 'ODAWS02-APSE1-2.ODA.SAS.COM' 
 * SAS 플랫폼 'Linux LIN X64 3.10.0-1062.12.1.el7.x86_64'에서 생성됨 
 * SAS 버전 '9.04.01M6P11072018'에서 생성됨 
 * 브라우저 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/106.0.0.0 Safari/537.36'에서 생성됨 
 * 웹 클라이언트 'https://odamid-apse1-2.oda.sas.com/SASStudio/main?locale=ko_KR&zone=GMT%252B09%253A00&ticket=ST-46419-0n0AW7KbzCLEXMiJ7e34-cas'에서 생성됨 
 *
 */

proc sql noprint;
	create table WORK.'sas_univbank'n as select * from MYDATA.UNIV_BANK 
		where(Experience GE 0);
quit;