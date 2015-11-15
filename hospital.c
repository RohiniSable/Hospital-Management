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
#include<stdlib.h>
#include<string.h>
#include "hospital.h"
void menu(){
        char choice;
        printf("\n");
        printf("\t\t*************************************************\n");
        printf("\t\t  *** WELCOME TO HOSPITAL MANAGEMENT SYSTEM ***\n");
       	printf("\t\t*************************************************");
        
	printf("\n\n\n\n\n\n\n");
       	printf("\t\t1.PATIENT\n");
        printf("\t\t2.STAFF\n");
        printf("\t\t3.INVENTORY\n");
        printf("\t\t0.EXIT\n\n");
        printf("\tEnter your choice: ");
        
	fflush(stdin);
	scanf("%c", &choice);
        
	switch(choice){
	        case '1':
			printf("\n\n");
                	pat();
                        break;
                case '2':
                        emp();
                        break;
                case '3':
                        inv();
                        break;
                case '0':
                        exit(1);
                default:
                       	printf(" Please enter valid choice.....\n");
                        menu();
	}
}
void main(){
	menu();
}
//Patient function
void pat(){
	int i,n,reg_no,ch,delete_line,temp;
	char r,m,another;
	FILE *fp,*ft;
	struct patient p;
	
	printf("\t\t\tPATIENT\n");
        printf("\t\t1.Enter a New Entry\n");
        printf("\t\t2.Modify Existing\n");
        printf("\t\t3.Search an Entry\n");
       	printf("\t\t4.Listing of records\n");
        printf("\t\t5.Delete an Entry\n");
        printf("\t\t6.Main Menu\n\n");
       	printf("\t\tEnter your choice here: ");
	scanf("%d",&ch);
	
	switch(ch){
		case 1:	//Add a new patient
			while(1){
				printf("\n\n\n");
				fp=fopen("pate2.dat","a");
				printf("Enter Registration Number: ");
                                scanf("%d",&p.regn);
				printf("\n");
				printf("Enter the name of the patient: ");
				scanf("%s", p.name);
				printf("\n");
				printf("Enter the age of the patient: ");
                                scanf("%d",&p.age);
				printf("\n");
				printf("Enter the phone number of the patient: ");
                                scanf("%s",p.ph);
				printf("\n");
                                printf("Enter the Blood group of the patient: ");
                                scanf("%s",p.bg);
				printf("\n");
				printf("Enter the gender of the patient(M.male or F.female): ");
                                scanf("%s",p.gender);
				printf("\n");
				printf("Enter the address of the patient:\n\n");
                                printf("\t\tEnter the house number: ");
                                scanf("%d",&p.hno);
				printf("\n");
				                                                                                                                                             					printf("\t\tEnter the street/colony: ");
                                scanf("%s",p.street);
				printf("\n");
                        	                                                    
				printf("\t\tEnter the city: ");
                                scanf("%s",p.city);
				printf("\n");
                                 
                                printf("\t\tEnter the state: ");
                                scanf("%s",p.state);
				printf("\n");
				
				printf("Enter the Disease or problem for which he/she wants treatment: ");
				scanf("%s", p.dis);
				printf("\n"); 

				printf("Enter the date of treatment given(DD-MM-YY)(If you are new patient write '------'):");
                                scanf("%s",p.date);
				printf("\n");

				printf("Enter the detail of treatment given(If you are new patient write '------'):");
                                scanf("%s",p.treat);
				printf("\n");
                                        
				printf("Enter the medicines prescribed(If you are new patient write '------'):");
                                scanf("%s",p.med);
				printf("\n");
				                                                                       
				
				printf("Enter the name of the Doctor to which he/she being referred:"); 			
				scanf("%s", p.doc_name);
				printf("\n");
                                                                               
				printf("Enter the history, if any, related to treatment of the patient(otherwise write UNAVAILABLE): ");
				scanf("%s", p.history);

				fwrite(&p,sizeof(p),1,fp);
				fclose(fp);
				printf("\n------------------------------------------------------------------------------------------------\n");
				pat();
			}	
			break;
		case 2:	//Modify existing record of a patient
                        fp=fopen("pate2.dat","r+");                                                                  
			printf("\nEnter the Registration number of the patient to modify: \n");
                        scanf("%d",&reg_no);
                        rewind(fp);
                        while(fread(&p,sizeof(p),1,fp)==1){
                        	if(p.regn==reg_no){
                                	fflush(stdin);
					printf("Enter the new name of the patient: ");
					scanf("%s", p.name);
					printf("\n");

					printf("Enter the new age of the patient: ");
                                	scanf("%d",&p.age);
					printf("\n");

					printf("Enter the new phone number of the patient: ");
                                	scanf("%s",p.ph);
					printf("\n");

                                	printf("Enter the new Blood group of the patient: ");
                                	scanf("%s",p.bg);
					printf("\n");

					printf("Enter the new gender of the patient(M.male or F.female): ");
                                	scanf("%s",p.gender);
					printf("\n");

					printf("Enter the new address of the patient:\n\n");
                                        printf("\t\tEnter the house number: ");
                                        scanf("%d",&p.hno);
					printf("\n");
                                                                               
                                        printf("\t\tEnter the street/colony: ");
                                        scanf("%s",p.street);
					printf("\n");
                                                         
					printf("\t\tEnter the city: ");
                                      	scanf("%s",p.city);
					printf("\n");
                                                                                
					printf("\t\tEnter the state: ");
                                        scanf("%s",p.state);
					printf("\n");
								
					printf("Enter the Disease or problem for which he/she wants treatment: ");
					scanf("%s",p.dis);
					printf("\n");
                                                                                                               
					printf("Enter the date of treatment given(DD-MM-YY): ");
                                        scanf("%s",p.date);
					printf("\n");

					printf("Enter the detail of treatment given: ");
                                        scanf("%s",p.treat);
					printf("\n");
                                        
					printf("Enter the medicines prescribed: ");
                                      	scanf("%s",p.med);
					printf("\n");

                                        fseek(fp,-sizeof(p),SEEK_CUR);
                                        fwrite(&p,sizeof(p),1,fp);
					break;
				}
			}
			fclose(fp);
			printf("-----------------------------------------------------\n");
			pat();
			break;
		case 3:	//Search a record
			fp=fopen("pate2.dat","r");
			printf("enter reg. no to be search:\n");
			scanf("%d",&reg_no);
			rewind(fp);
			while(fread(&p,sizeof(p),1,fp)){
				if(reg_no==p.regn){				
					printf("Registration Number of the Patient : %d\n",p.regn);
                                        printf("Name of the Patient : %s\n",p.name);
                                        printf("Age : %d\n",p.age);
                                        printf("phone number :%s\n",p.ph);
                                        printf("Blood group: %s\n",p.bg);
					printf("Gender : %s\n",p.gender);
                                        printf("Disease : %s",p.dis);
					printf("Name of the Doctor : %s\n",p.doc_name);
                                        printf("Earlier History : %s\n",p.history);                                        
					printf("Details of treatment given and medicine prescribed:\n");
					printf("DATE\t\t TREATMENT GIVEN\t\t\t MEDICINE PRESCRIBED\n");
                                        printf("%s\t %s\t\t\t %s\n",p.date,p.treat,p.med);
                                        printf("\n--------------------------------------------------------------\n");
				}
				
			}
			fclose(fp);
			pat();
			break;
		case 4:	//Display all records
			fp=fopen("pate2.dat","r");			
			rewind(fp);
			while(fread(&p,sizeof(p),1,fp)){
				printf("Registration Number of the Patient : %d\n",p.regn);                                               
                                printf("Name of the Patient : %s\n",p.name);                                        
                                printf("Age : %d\n",p.age);
                                printf("phone number :%s\n",p.ph);
                                printf("Blood group: %s\n",p.bg);
				printf("Gender : %s\n",p.gender);
				printf("Address  : %d,%s,%s,%s\n",p.hno,p.street,p.city,p.state);
                                printf("Disease : %s\n",p.dis);
				printf("Name of the Doctor : %s\n",p.doc_name);
                                printf("Earlier History : %s\n",p.history);                                                
				printf("Details of treatment given and medicine prescribed:\n");
				printf("DATE\t\tTREATMENT GIVEN\t\t MEDICINE PRESCRIBED\n\n");
				printf("**************************************************************************\n");
                                printf("%s \t%s\t%s\n",p.date,p.treat,p.med);
                                printf("\n-----------------------------------------------------------------\n");
			}
			pat();
			break;
		case 5:	//Delete a record
			fp=fopen("pate2.dat","r+");
			printf("Enter the Registration number of the Patient to be deleted: ");
                        scanf("%d",&reg_no);
			printf("\n");
                        ft=fopen("temp.dat","w+");
                        rewind(fp);
                        while(fread(&p,sizeof(p),1,fp)==1){
                        	if(p.regn!=reg_no)
                                	fwrite(&p,sizeof(p),1,ft);
                                else
					printf("The Record has been Deleted Successfully.\n");
                        }
                        fclose(fp);
                        fclose(ft);
                        remove("pate2.dat");
                        rename("temp.dat","pate2.dat");
                        pat();
                        break;
               case 6:	//Go to main menu
			menu();
			break;
	}
}
//Staff function
void emp(){
	FILE *fs,*fx;
	int id,c;
	struct staff s;
        
	printf("\t\t\tEMPLOYEE\n");
        printf("\t\t1.Add an Entry\n");
        printf("\t\t2.Modify Existing One\n");
        printf("\t\t3.Search an Entry\n");
        printf("\t\t4.Listing of all records\n");
        printf("\t\t5.Delete an Entry\n");
        printf("\t\t6.Main Menu\n\n");
        printf("\t\tEnter your choice here: ");
        fflush(stdin);
	scanf("%d",&c);
	
	switch(c){
		case 1:	//Add a new staff
			while(1){
				fs=fopen("emp.dat","a");
				printf("\n\n\n");
				printf("Enter the UID of the Employee: ");
                                scanf("%d",&s.eid);
				printf("\n");

				printf("Enter the name of the Employee: ");
                                scanf("%s",s.nme);
				printf("\n");
                                
				printf("Enter the name of the Guardian: ");
                                scanf("%s",s.fnme);
				printf("\n");
                                
                                printf("Enter the age of the Employee: ");
                                scanf("%d",&s.age);
				printf("\n");
				
				printf("Enter the phone number of the Employee: ");
                                scanf("%s",s.ph);
				printf("\n");
										
                                printf("Enter the Blood group of the Employee: ");
                                scanf("%s",s.bg);
				printf("\n");
				
				printf("Enter the gender of the patient(M.male or F.female): ");
                                scanf("%s",s.gen);
				printf("\n");
                                                                                
                                printf("Enter the address of the Employee:\n\n");
                                printf("\tEnter the house number: ");
                                scanf("%d",&s.ehno);
				printf("\n");
                                                                             
                                printf("\tEnter the street/colony: ");
                                scanf("%s",s.estreet);
				printf("\n");
                                
                                printf("\tEnter the city: ");
                                scanf("%s",s.ecity);
				printf("\n");
                                
                                printf("\tEnter the state: ");
                                scanf("%s",s.estate);
				printf("\n");
                                                                                                                             
                                printf("Enter the Designation: ");
                                scanf("%s",s.desig);
				printf("\n");
				
				printf("Enter the Salary of the Employee: ");
                                scanf("%s",s.sal);
				printf("\n");

				fwrite(&s,sizeof(s),1,fs);
				fclose(fs);
				printf("-------------------------------------------------------------------------------------------\n");
				emp();
			}
			break;
		case 2:	//Modify existing record of a particular staff
			fs=fopen("emp.dat","r+");
			printf("Enter the UID of the patient to modify: ");
                        scanf("%d",&id);
			printf("\n");
                        rewind(fs);
                        
			while(fread(&s,sizeof(s),1,fs)==1){
                        	if(s.eid==id){
                                	printf("Enter the new name of the Employee: ");
       	                                scanf("%s",s.nme);
					printf("\n");
                                                                                
					printf("Enter the new name of the Guardian: ");
                                        scanf("%s",s.fnme);
					printf("\n");
                                               
	                                printf("Enter the new age of the Employee: ");
                                        scanf("%d",&s.age);
					printf("\n");
						
					printf("Enter the new phone number of the Employee: ");
                                        scanf("%s",s.ph);
					printf("\n");
                                                
		                        printf("Enter the new Blood group of the Employee: ");
                                        scanf("%s",s.bg);
					printf("\n");
						
					printf("Enter the new gender of the patient(M.male or F.female): ");
                                        scanf("%s",s.gen);
					printf("\n");
                                                                                
                                        printf("Enter the new address of the Employee:\n\n");
                                        printf("\tEnter the house number: ");
                                        scanf("%d",&s.ehno);
					printf("\n");
                                        fflush(stdin);
                                                
		                        printf("\tEnter the street/colony: ");
                                        scanf("%s",s.estreet);
					printf("\n");
                                                
					printf("\tEnter the city: ");
                                        scanf("%s",s.ecity);
					printf("\n");
                                                
		                        printf("\tEnter the state: ");
                                        scanf("%s",s.estate);
					printf("\n");
                                                                                
                                        fflush(stdin);
                                        printf("Enter the new Designation: ");
                                       	scanf("%s",s.desig);
					printf("\n");
						
					printf("Enter the new Salary of the Employee: ");
                                        scanf("%s",s.sal);
					printf("\n");
                                                             
					fseek(fs,-sizeof(s),SEEK_CUR);
                                        fwrite(&s,sizeof(s),1,fs);
                                        break;
				}
			}
			fclose(fs);
                        printf("----------------------------------------------------\n");
			emp();
			break;
		case 3:	//Search a record
			fs=fopen("emp.dat","r");
			printf("enter UID to be search:");
			scanf("%d",&id);
			printf("\n");
			rewind(fs);

			while(fread(&s,sizeof(s),1,fs)){	
				if(id==s.eid){			
					printf("UID of the Employee : %d\n",s.eid);
                                        printf("Name of the Employee : %s\n",s.nme);                              
                                        printf("Name of the Guardian : %s\n",s.fnme);
                                      	printf("Age : %d\n",s.age);
					printf("phone number :%s\n",s.ph);
					printf("Blood group: %s\n",s.bg);
					printf("Gender : %s\n",s.gen);
                                	printf("Address:%d,%s,%s,%s\n", s.ehno, s.estreet, s.ecity, s.estate);
                                	printf("Designation : %s\n",s.desig);
					printf("Salary: %s\n",s.sal);
                                        printf("----------------------------------------------------\n");
				}
			}
			fclose(fs);
			emp();
			break;
		case 4:	//Display all records
			fs=fopen("emp.dat","r");			
			rewind(fs);

			while(fread(&s,sizeof(s),1,fs)){
				printf("UID of the Employee : %d\n",s.eid);
                                printf("Name of the Employee : %s\n",s.nme);
                                printf("Name of the Guardian : %s\n",s.fnme);
     				printf("Age : %d\n",s.age);
				printf("phone number :%s\n",s.ph);
				printf("Blood group: %s\n",s.bg);
				printf("Gender : %s\n",s.gen);
                                printf("Address  : %d,%s,%s,%s\n",s.ehno,s.estreet,s.ecity,s.estate);
                                printf("Designation : %s\n",s.desig);
				printf("Salary: %s\n",s.sal);
                                printf("----------------------------------------------------\n");
			}
			emp();
			break;
		case 5:	//Delete a record
			fs=fopen("emp.dat","r+");
			printf("Enter the UID of Employee to be deleted: ");
                        scanf("%d",&id);
			printf("\n");
                        fx=fopen("temp1.dat","w+");
                        rewind(fs);

                        while(fread(&s,sizeof(s),1,fs)==1){
                        	if(s.eid!=id)
                                	fwrite(&s,sizeof(s),1,fx);
                                else
					printf("The Record has been Deleted Successfully.\n");
                        }
                        fclose(fs);
                        fclose(fx);
                        remove("emp.dat");
                        rename("temp1.dat","emp.dat");
                        emp();
                        break;
       		case 6:	//Go to main menu
			menu();
			break;
	}
}
//Inventory function
void inv(){
	FILE *fi,*fy;
	struct inventory v;
	int z,j=1,q=1;
	char i_name[40];
	
	printf("\t\t\tINVENTORY\n");
        printf("\t\t1.Add an Entry for Item\n");
        printf("\t\t2.Modify Existing Entry\n");
        printf("\t\t3.Search an Entry\n");
        printf("\t\t4.Listing of all Entries\n");
        printf("\t\t5.Delete an Entry\n");
        printf("\t\t6.Main Menu\n\n");
        printf("\t\tEnter your choice here: \n");
        fflush(stdin);
        scanf("%d",&z);	
	
	switch(z){
		case 1:	//Add a new item
			while(1){
				fi=fopen("inv.dat","a");
				printf("Enter the Name of the Item: ");
                                scanf("%s",v.name);		
				printf("\n");
				printf("Enter the Date of purchase: ");
                                scanf("%s",v.dop);
				printf("\n");
                                fflush(stdin);
                                                                            
				printf("Enter the Quantity of the Item: ");
                                scanf("%d",&v.qnty);
                                printf("\n");
				printf("Enter the price of One Item: ");
                                scanf("%f",&v.price);
				printf("\n");

                                v.amount=v.qnty*v.price;
				printf("The amount of %d %s is = %.2f\n\n",v.qnty,v.name,v.amount);

                                fwrite(&v,sizeof(v),1,fi);
				fclose(fi);
                                printf("----------------------------------------------------\n");
				inv();				
			}
		case 2:	//Modify existing record of item
			fi=fopen("inv.dat","r+"); 
			printf("Enter the SR.NO of the item to modify: ");
                        scanf("%d",&q);
			printf("\n\n\n");
			rewind(fi);
                        
			while(fread(&v,sizeof(v),1,fi)==1){
				if(j==q){
					printf("Enter the new Name of the Item: ");
                                        scanf("%s",v.name);		
					printf("\n");
					
					printf("Enter the new Date of purchase: ");
                                        scanf("%s",v.dop);
					printf("\n");
                                        fflush(stdin);
                                                                                
					printf("Enter the new Quantity of the Item: ");
                                        scanf("%d",&v.qnty);
					printf("\n");
                                        
                                        printf("Enter the new price of One Item: ");
                                        scanf("%f",&v.price);
					printf("\n");
                                      	v.amount=v.qnty*v.price;
				
					printf("The new amount of %d %s is = %.2f\n",v.qnty,v.name,v.amount);
					fseek(fi,-sizeof(v),SEEK_CUR);
                                        fwrite(&v,sizeof(v),1,fi);
                                        break;
				}
				else
					j++;
			}
			fclose(fi);
                        printf("\n----------------------------------------------------");
			inv();
                        break;
		case 3:	//Search an item 
			fi=fopen("inv.dat","r");
                        printf("Enter name of item to search: ");
                        scanf("%s",i_name);
			printf("\n");
                       	rewind(fi);

                        while(fread(&v,sizeof(v),1,fi)==1){
                        	if(strcmp(v.name,i_name)==0){
                               		printf("The Name of the Item: %s\n",v.name);
                                        printf("The Date of purchase: %s\n",v.dop);
                                      	printf("Quantity of the Item: %d\n",v.qnty);
                                        printf("Price of One Item: %f\n",v.price);
                                       	v.amount=v.qnty*v.price;
					printf("The amount of %d %s is = %.2f\n",v.qnty,v.name,v.amount);
					printf("----------------------------------------------------\n");
				}
			}
                        printf("----------------------------------------------------\n");
                                                                
                        inv();
                        break;
		case 4:	//Display an item
			fi=fopen("inv.dat","r");						
			printf("S.No.     ITEM           DOP            QUANTITY         PRICE          AMOUNT\n");
			printf("--------------------------------------------------------------------------------\n");
                        rewind(fi);

                        while(fread(&v,sizeof(v),1,fi)){
				printf("%d    %s         %s        %d          Rs.%.2f        Rs.%.2f\n",j,v.name,v.dop,v.qnty,v.price,v.amount);
                                j++;                      						          
			}
			printf("--------------------------------------------------------------------------------\n");
			inv();
			break;
		case 5:	//Delete an item	
			fi=fopen("inv.dat","r+");					
                        printf("Enter the name of the Item to be deleted: ");
                        scanf("%s",i_name);
			printf("\n");

                      	fy=fopen("temporary.dat","w+");
                        rewind(fi);

                        while(fread(&v,sizeof(v),1,fi)==1){
                        	if(strcmp(v.name,i_name)!=0)
                                	fwrite(&v,sizeof(v),1,fy);
                              	else
					printf("The Record has been Deleted Successfully.\n");
                       	}
                        fclose(fi);
                        fclose(fy);
                        remove("inv.dat");
                    	rename("temporary.dat","inv.dat");
                                                                                		
			inv();
			break;
		case 6:	//Go to main menu
			menu();
			break;
	}
}
