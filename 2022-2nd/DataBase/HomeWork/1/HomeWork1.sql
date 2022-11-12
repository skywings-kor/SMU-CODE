USE master
CREATE DATABASE EduManager
GO

use EduManager

CREATE TABLE COURSE(
	COU_ID INT NOT NULL,
	COU_NAME VARCHAR(20) NULL,
	TEA_NAME VARCHAR(20) NULL,
	PRIMARY KEY(COU_ID)
)
GO

CREATE TABLE STUDENT(
	STU_ID INTEGER NOT NULL,
	STU_NAME VARCHAR(20) NULL,
	AGE INTEGER NULL,
	STU_EMAIL VARCHAR(20) NULL,
	COU_ID INTEGER NULL,
	PRIMARY KEY(STU_ID),		--학생 번호가 기본키가 되는 구분
	
	--과정번호가 외래키로 됨
	FOREIGN KEY(COU_ID) REFERENCES COURSE(COU_ID)
)
GO

ALTER TABLE STUDENT
	ADD SEX VARCHAR DEFAULT 'M';
GO

--DROP TABLE 하나만 삭제하는 경우에는 외부키 참조라서 안됨 그래서 둘 다 하게 됨
DROP TABLE STUDENT;
DROP TABLE COURSE;
GO


--not null 제약 조건을 위한 member 테이블 생성
Create table member(
	id varchar(20) null,
	pwd varchar(20) null,
	name varchar(20) null,
	email varchar(20) not null,
	hp varchar(20) null
)
GO


--not null 제약 조건
insert into member
values (null, null, null, 'moon@nate.com','01012341234')

select * from member



--notnull 제약조건 설정하여 테이블 생성 ppt45 page
drop table member
go


--ppt 40p
create table member(
	id varchar(20),
	pwd varchar(20),
	name varchar(20),
	email varchar(20),
	hp varchar(20)
)
GO

select *from member

insert into member
values(null,null,null,'moon@nate.com','1063385361')
select *from member


--ppt 47p 안되는거 보여주기용
create table nomember(
	id varchar(20) not null,
	pwd varchar(20) not null,
	name varchar(20) not null,
	email varchar(20) null,
	hp varchar(20) null
)
GO

--not null로 만든 공간에 null을 넣어서 오류가 생깁니다!
insert into nomember
values(null,null,null,'moon@nate.com','01063385361')

--그러면 이렇게 하면 정상적으로 됩니다
insert into nomember
values('moon','y','문종헌','moon@nate.com','01063385361')
select *from nomember


create table member2(
	--중복된 값 허용하지 않는다는 제약 조건이 생김 유니크 , 특별!
	id varchar(20) unique,
	pwd varchar(20) not null,
	name varchar(20) not null,
	email varchar(20) null,
	hp varchar(20) null
)
GO

insert into member2
values('park','m','박규민','test@nate.com','01012341234')
select *from member2

--여기서 이제 또 똑같은 park를 넣을경우 오류가 발생!
insert into member2
values('park','s','박규란','test2@nate.com','01028485212')


create table member3(
	id varchar(20) constraint PK_id primary key,
	pwd varchar(20) constraint NN_pwd not null,
	name varchar(20) constraint NN_name not null,
	email varchar(20) null,
	hp varchar(20) null
)
GO

--기본키는 중복 안됨!
insert into member3
values('moon','y','박규민','park@nate.com','01012341234')

insert into member3
values('moon','m','테스터','test@nate.com','01028374212')

insert into member3
values(null,'y','테스터','test2@nate.com','01023241234')

--ppt69페이지부터 하면됨
--제약조건 체험해보기
create table course2(
	COU_ID int not null,
	COU_Name varchar(20) null,
	TEA_NAME varchar(20) null,
	PRIMARY KEY(COU_ID)
)
GO

create table student2 (
	STU_ID INTEGER NOT NULL,
	STU_NAME VARCHAR(20) NULL,
	AGE INTEGER NULL CHECK(AGE<30),
	STU_EMAIL VARCHAR(20) NULL,
	COU_ID INTEGER NULL,
	SEX varchar null default'M',
	PRIMARY KEY(STU_ID),
	FOREIGN KEY(COU_ID) REFERENCES course2(COU_ID)

)
GO

--시스템 뷰 생성을 체험하기 위해 제작한 것
create table student3(
	STU_ID INTEGER NOT NULL,
	STU_NAME VARCHAR(20) NULL,
	AGE INTEGER NULL,
	STU_EMAIL VARCHAR(20) NULL,
	COU_ID INTEGER NULL,
	SEX varchar null default'M',
	PRIMARY KEY(STU_ID),
	FOREIGN KEY(COU_ID) REFERENCES course2(COU_ID)
)
GO
--course 더미값
insert into course2 values(10,'모바일','성윤정')
insert into course2 values(20,'자바','김혜경')
insert into course2 values(30,'윈도우','황연주')
insert into course2 values(40,'웹표준','전혜영')


--student3 더미값
insert into student3 values(101,'박규민',23,'test@nate.com',10,'M')
insert into student3 values(102,'김개1',23,'test@nate.com',30,'M')
insert into student3 values(103,'김민2',23,'test@nate.com',20,'M')
insert into student3 values(104,'김민3',23,'test@nate.com',40,'M')
insert into student3 values(105,'김민4',23,'test@nate.com',20,'M')
insert into student3 values(106,'김민5',23,'test@nate.com',30,'M')
insert into student3 values(107,'김민6',23,'test@nate.com',20,'M')
insert into student3 values(108,'김민7',23,'test@nate.com',10,'M')




--시스템 뷰 생성
select * into STU_COPY
from student3

CREATE VIEW STU_VIEW30
as
select STU_ID, STU_Name, COU_ID
from STU_COPY
where COU_ID=30

--뷰 불러오기
select* from STU_VIEW30


--뷰 데이터 추가
insert into STU_VIEW30
values(200,'전수빈',30)
select* from STU_VIEW30

--뷰로 기본 테이블에 데이터 추가
select *from STU_COPY


--뷰 제거법?
drop view STU_VIEW30
select *from STU_VIEW30


--저장 프로시저 생성
create procedure usp_STUDENT
as
select STU_ID, STU_NAME, AGE, STU_EMAIL, COU_ID from student3
where STU_EMAIL IS NOT NULL
ORDER BY STU_NAME

--저장 프로시저 실행
exec usp_STUDENT


--프로시저 삭제법?
drop procedure usp_STUDENT
exec usp_STUDENT



--데이터 백업 테이블 저장!
create table EMP(
	EMPNO int identity PRIMARY KEY,
	ENAME VARCHAR(20),
	JOB varchar(20)
);

create trigger TRG_INSERT
on EMP
AFTER INSERT
as
select '신입사원이 입사했습니다.', *from
inserted

--테이블에 데이터 insert
insert into EMP VALUES('전원지','화가')


--트리거 delete
create trigger TRG_DELETE
ON EMP
AFTER DELETE
as
select Deleted.ENAME,'사원이 퇴사했습니다.',*from deleted


--테이블에서 데이터를 삭제
DELETE EMP WHERE ENAME='전원지'



--업데이트 트리거 작성
create trigger TRG_UPDATE
ON EMP
for UPDATE
as
select 'Deleted->',*from deleted -- old data
select 'Inserted->',*from inserted -- new data


--업데이트 써보자
insert into EMP VALUES('전원지','화가')
update EMP set JOB='선생님' where ENAME='전원지'


--트리거 삭제
drop trigger TRG_UPDATE

UPDATE EMP SET JOB='교수' WHERE ENAME='전원지'