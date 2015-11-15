/*************************************************************************
  * Copyright (C) Rohini Sanjay Sable rohinisable1997@gmail.com
  *
  * This program(hospital management) is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>
**************************************************************************/
#include<stdio.h>
struct patient{
	char name[40];
        char fname[40];
        int age;
	char yn;
        char bg[3];
        char gender[6];
	int regn;
        char ph[12];
        char dis[60];
        char doc_name[40];
        char history[200];
        char date[40];
        char treat[40];
        char med[40];
	int hno;
        char street[40];
        char city[40];
        char state[40];
};

struct staff{
        char nme[40];
        char fnme[40];
        int age;
        char bg[10];
        char gen[10];
        int eid;
	char ph[12];
        char desig[40];
	char sal[10];
	int ehno;
        char estreet[40];
        char ecity[40];
        char estate[40];
};

struct inventory{
        int sno;
        char name[30];
        char dop[20];
        int qnty;
       	float price;
        float amount;
};
void emp(void);
void menu(void);
void pat(void);
void inv(void);
