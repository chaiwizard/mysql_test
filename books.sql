#!create a database
create database books;

use books;

#create tables

CREATE TABLE CATEGORY (
    ID INT NOT NULL AUTO_INCREMENT,
	CATEGORY_DESCRIPTION VARCHAR(20) NOT NULL,
	PRIMARY KEY (ID)
	);

CREATE TABLE BOOK(
    ID INT NOT NULL AUTO_INCREMENT,
	CATEGORY_ID INT NOT NULL,
	BOOK_TITLE VARCHAR(60) NOT NULL,
	PUBLISHER VARCHAR(60) NOT NULL,
	PRIMARY KEY (ID),
	CONSTRAINT FK_BOOK_1 FOREIGN KEY (CATEGORY_ID) REFERENCES CATEGORY(ID)
	);

CREATE TABLE AUTHOR (
    ID INT NOT NULL AUTO_INCREMENT,
	BOOK_ID INT NOT NULL,
	FIRST_NAME VARCHAR(20) NOT NULL,
	LAST_NAME VARCHAR(20) NOT NULL,
	PRIMARY KEY (ID),
	CONSTRAINT FK_AUTHOR_1 FOREIGN KEY (BOOK_ID) REFERENCES BOOK (ID)
	);

#find tables 
show tables;

DESC CATEGORY;


insert into CATEGORY (category_description) values('Java');

select * from CATEGORY where category_description = 'Java';

update CATEGORY set category_description = 'Python' where category_description = 'Go';

delete from CATEGORY where category_description = 'Python';


insert into BOOK (CATEGORY_ID,BOOK_TITLE,PUBLISHER) values (1, "Java Programming", "Apress");

insert into AUTHOR (BOOK_ID,FIRST_NAME,LAST_NAME) values (1,"John","Steven");
