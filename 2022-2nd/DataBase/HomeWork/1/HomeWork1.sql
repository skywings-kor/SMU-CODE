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
	PRIMARY KEY(STU_ID),		--�л� ��ȣ�� �⺻Ű�� �Ǵ� ����
	
	--������ȣ�� �ܷ�Ű�� ��
	FOREIGN KEY(COU_ID) REFERENCES COURSE(COU_ID)
)
GO

ALTER TABLE STUDENT
	ADD SEX VARCHAR DEFAULT 'M';
GO

--DROP TABLE �ϳ��� �����ϴ� ��쿡�� �ܺ�Ű ������ �ȵ� �׷��� �� �� �ϰ� ��
DROP TABLE STUDENT;
DROP TABLE COURSE;
GO


--not null ���� ������ ���� member ���̺� ����
Create table member(
	id varchar(20) null,
	pwd varchar(20) null,
	name varchar(20) null,
	email varchar(20) not null,
	hp varchar(20) null
)
GO


--not null ���� ����
insert into member
values (null, null, null, 'moon@nate.com','01012341234')

select * from member



--notnull �������� �����Ͽ� ���̺� ���� ppt45 page
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


--ppt 47p �ȵǴ°� �����ֱ��
create table nomember(
	id varchar(20) not null,
	pwd varchar(20) not null,
	name varchar(20) not null,
	email varchar(20) null,
	hp varchar(20) null
)
GO

--not null�� ���� ������ null�� �־ ������ ����ϴ�!
insert into nomember
values(null,null,null,'moon@nate.com','01063385361')

--�׷��� �̷��� �ϸ� ���������� �˴ϴ�
insert into nomember
values('moon','y','������','moon@nate.com','01063385361')
select *from nomember


create table member2(
	--�ߺ��� �� ������� �ʴ´ٴ� ���� ������ ���� ����ũ , Ư��!
	id varchar(20) unique,
	pwd varchar(20) not null,
	name varchar(20) not null,
	email varchar(20) null,
	hp varchar(20) null
)
GO

insert into member2
values('park','m','�ڱԹ�','test@nate.com','01012341234')
select *from member2

--���⼭ ���� �� �Ȱ��� park�� ������� ������ �߻�!
insert into member2
values('park','s','�ڱԶ�','test2@nate.com','01028485212')


create table member3(
	id varchar(20) constraint PK_id primary key,
	pwd varchar(20) constraint NN_pwd not null,
	name varchar(20) constraint NN_name not null,
	email varchar(20) null,
	hp varchar(20) null
)
GO

--�⺻Ű�� �ߺ� �ȵ�!
insert into member3
values('moon','y','�ڱԹ�','park@nate.com','01012341234')

insert into member3
values('moon','m','�׽���','test@nate.com','01028374212')

insert into member3
values(null,'y','�׽���','test2@nate.com','01023241234')

--ppt69���������� �ϸ��
--�������� ü���غ���
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

--�ý��� �� ������ ü���ϱ� ���� ������ ��
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
--course ���̰�
insert into course2 values(10,'�����','������')
insert into course2 values(20,'�ڹ�','������')
insert into course2 values(30,'������','Ȳ����')
insert into course2 values(40,'��ǥ��','������')


--student3 ���̰�
insert into student3 values(101,'�ڱԹ�',23,'test@nate.com',10,'M')
insert into student3 values(102,'�谳1',23,'test@nate.com',30,'M')
insert into student3 values(103,'���2',23,'test@nate.com',20,'M')
insert into student3 values(104,'���3',23,'test@nate.com',40,'M')
insert into student3 values(105,'���4',23,'test@nate.com',20,'M')
insert into student3 values(106,'���5',23,'test@nate.com',30,'M')
insert into student3 values(107,'���6',23,'test@nate.com',20,'M')
insert into student3 values(108,'���7',23,'test@nate.com',10,'M')




--�ý��� �� ����
select * into STU_COPY
from student3

CREATE VIEW STU_VIEW30
as
select STU_ID, STU_Name, COU_ID
from STU_COPY
where COU_ID=30

--�� �ҷ�����
select* from STU_VIEW30


--�� ������ �߰�
insert into STU_VIEW30
values(200,'������',30)
select* from STU_VIEW30

--��� �⺻ ���̺� ������ �߰�
select *from STU_COPY


--�� ���Ź�?
drop view STU_VIEW30
select *from STU_VIEW30


--���� ���ν��� ����
create procedure usp_STUDENT
as
select STU_ID, STU_NAME, AGE, STU_EMAIL, COU_ID from student3
where STU_EMAIL IS NOT NULL
ORDER BY STU_NAME

--���� ���ν��� ����
exec usp_STUDENT


--���ν��� ������?
drop procedure usp_STUDENT
exec usp_STUDENT



--������ ��� ���̺� ����!
create table EMP(
	EMPNO int identity PRIMARY KEY,
	ENAME VARCHAR(20),
	JOB varchar(20)
);

create trigger TRG_INSERT
on EMP
AFTER INSERT
as
select '���Ի���� �Ի��߽��ϴ�.', *from
inserted

--���̺� ������ insert
insert into EMP VALUES('������','ȭ��')


--Ʈ���� delete
create trigger TRG_DELETE
ON EMP
AFTER DELETE
as
select Deleted.ENAME,'����� ����߽��ϴ�.',*from deleted


--���̺��� �����͸� ����
DELETE EMP WHERE ENAME='������'



--������Ʈ Ʈ���� �ۼ�
create trigger TRG_UPDATE
ON EMP
for UPDATE
as
select 'Deleted->',*from deleted -- old data
select 'Inserted->',*from inserted -- new data


--������Ʈ �Ẹ��
insert into EMP VALUES('������','ȭ��')
update EMP set JOB='������' where ENAME='������'


--Ʈ���� ����
drop trigger TRG_UPDATE

UPDATE EMP SET JOB='����' WHERE ENAME='������'