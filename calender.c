#include<stdio.h>

#include<conio.h>

#include <stdlib.h>

#include<string.h>                 

#include<ctype.h>                   

#include<dos.h>  


int flag=0;//this varabel just for the if statment in the char closeapplictaion() function to make a falst if the yousef PRESSED Y the flage varable will changes to 1 and the program will stoped//
int mainminu();//mainminue function
int choice=0;//this varabel just for the switch case//
int calenter();
int year;
int day=0;
int dayInMonth;
int weekDay=0;
int startingDay;
int month;
char anther;//this char just for the if statment to make option to go 
char addEvent();
char viewEvent();
char closeapplictaion();
char important[50];
char c;//this char just for openthe folder and make the while statment/
FILE *fptr;



int get_first_weekDay(int year)
{
    int day;
    day = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
    return day;
} 


int main () {
	
	mainminu();
	system("cls");
	
		switch(choice){
		
		case 1:
		
		calenter();
		
	 	break;
	 	
	    case 2:
	    
		addEvent();
	 
	    break;
	    
	    case 3:
	    
	    viewEvent();
	    
	    break;
	    
	    case 4:
	    
	    closeapplictaion();
	    
	    break;
	    
     
     	 default:
	 	{	
	 	    puts("\aWrong Entry!!Please re-entered correct option");
              
             	
				return 	mainminu();//i make the return value to mainminu() other way it will go inv loop//
				
               break;     

		         }//end default
	 
     
     
	       }//end switch
     
     
     	return 0;
     
	  





}



int mainminu(){
	    //color for the interface//
	system("color 3F");
		//inter face for the program//
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\tWELCOME\n\t\t\t\t\t\t\t\t\t\t\t\t\t  To \n\t\t\t\t\t\t\t\t\t\t\t      \xdb\xdb\xdb\xdb\xdb\xdb Calender Notes \xdb\xdb\xdb\xdb\xdb\xdb\n");
   	printf("\t\t\t\t\t\t\t\t\t\t\t\t<1> view calender\n\t\t\t\t\t\t\t\t\t\t\t\t<2> add event\n\t\t\t\t\t\t\t\t\t\t\t\t<3> View Event's list\n\t\t\t\t\t\t\t\t\t\t\t\t<4> close applictaion\n");
	printf("\n\n Please Enter your choice :\n");
	scanf(" %d",&choice);	
	return choice;
}


int calenter(){
	
	
	printf("\n\n Please Enter The Year :\n");
    
	scanf("%d",&year);
	
	//defined the months as a char//
	char *months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    
	//the number of days in the month
	int monthDays[]={31,28,31,30,31,30,31,31,30,31,30,31};
	
	//checking if the year IS LIPE OR NOT // 
    if((year%4==0&&year%100!=0)||year%400==0)
    {    
    	//here we will replace the second element of char which is "28" with "29"//
        monthDays[1]=29;
    }
    
	startingDay=get_first_weekDay(year);
   
   // creat a for loop to print all months//
    for(month=0;month<12;month++)
    {
    	//genrate the number of day with the char which is conected with the number of each month//
        dayInMonth=monthDays[month]+1;
        
        // print the char of months names//
		printf("\n\n------------------%s----------------",months[month]);
		
		//print the name of the days//
        printf("\n  Sun   Mon  Tue  Wed  Thurs Fri  Sat\n");
        
		//creat a space for the next first day in the month//
		for(weekDay=0;weekDay<startingDay;weekDay++)
        {
           printf("     ");
        }
        //a for loop for printing the number of days 
		for(day=1;day<dayInMonth;day++)
        {
            printf("%5d",day);
            
            //creat a new line for every shown week//
			if(++weekDay>6)
            {
                printf("\n");
                //to make it run for the loop to all months
				weekDay=0;
            }
            startingDay=weekDay;
        }
    }
    	printf("\n DO you want to See anther Year (Y/N) :\n");
	 	scanf(" %s",&anther);
	 	if(anther=='Y'||anther=='y'){//if statment to creat  i option for user to press Y(which mean add anther memebr) OR N (whitch mean back manminue)/
			system("cls");
	 		return calenter();
		 }//end of if statment
		 else{
		 	system("cls");
		 	return main();
		 }//end of else
    
}

char addEvent(){
	
		printf(" Enter the day  :\n");
	 	scanf(" %d",&day);
	 	printf(" Enter the month in numbers :\n");
	 	scanf(" %d",&month);
	 	printf(" Enter the year:\n");
	 	scanf(" %d",&year);
	 	printf(" Enter how important is the event (low,medium,extremly) : \n ");
        scanf(" %s",&important);
        
		/*if (important=='l'||important=='L'){
        textcolor(2);
        }
        else if (important=='m'||important=='M'){
				
       	textcolor(14);
        }
		*/	
        
				
        fptr = fopen("C:\\Users\\ENVY\\Documents\\program.txt","a");//i creat and open  here a folder txt to save the members information .(append "a").
        fprintf(fptr,"\t\t%d\t\t%d\t\t%d\t\t%s\n",day,month,year,important);//showe the information of the memebers/
   		fclose(fptr);//close the folder .
        
	 	printf(" DO you want to add anther Event (Y/N) :\n");//if statment to creat  i option for user to press Y(which mean add anther memebr) OR N (whitch mean back manminue)/
	 	scanf(" %s",&anther);
	 	if(anther=='Y'||anther=='y'){
	 		system("cls");
	 		return addEvent();
		 }//end of the if statment
		 else{
		 	system("cls");
		 	return main();
		 }//end of else
	 	
	 	 
	 	
	
}    //end  addEvent 


char viewEvent(){
		
		printf("\t\tDay\t\tMonth\t\tYear\t\timportant\n");
		
		fptr = fopen("C:\\Users\\ENVY\\Documents\\program.txt","r");//i used her this strution to read the file whitch i created to show the user the information that he sved // 
		
		   c = fgetc(fptr); 
    		while (c != EOF) 
    			{ 
        			printf ("%c", c); 
        			c = fgetc(fptr); 
    			}
   			fclose(fptr);

	 	printf(" DO you want to Add New Event ! (Y/N) :\n");
	 	scanf(" %s",&anther);//if statment to creat  i option for user to press Y(which mean viewEvents ) OR N (whitch mean back manminue)/
	 	if(anther=='Y'||anther=='y'){
	 		system("cls");
	 		return addEvent();
		 }//end of the if statment
		 else{
		 	system("cls");
		 	return main();
		 }//end else
	
	
	
	
	
}//end viewEvents

char closeapplictaion(){
	

		printf(" DO You Want To Close The Application !(Y/N) :\n");
	 	scanf(" %s",&anther);
	 	if(anther=='Y'||anther=='y'){// use the if statment to make the statment wrrong/
	 	flag=1;//by makeing the varible = to 1 //
		 }
		 else if(anther=='N'||anther=='n'){
		system("cls");
		 return main();
	}//end of if statment/
	 
return 0;
	 }//end of function close the program//




