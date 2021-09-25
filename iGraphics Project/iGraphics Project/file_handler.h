#include<iostream>
using namespace std;

#include <string.h>

#define FILENAME "player_data.txt"
#define FILENAME2 "high_score.txt"

int *delete_duplicate_element(int*);
int *sort_decreasing_order(int*);

int appender_flag = 1;

int point_array[20];
int *point_array_modified;

int file_line_counter(){  // counts the line of a file and at the end returns the total lines
FILE *fp;
   char ch;
   int linesCount=0;
   //open file in read more
   fp=fopen(FILENAME,"r");
   if(fp==NULL) {
      printf("File \"%s\" does not exist!!!\n",FILENAME);
      return -1;
   }
   //read character by character and check for new line
   while((ch=fgetc(fp))!=EOF) {
      if(ch=='\n')
         linesCount++;
   }
   //close the file
   fclose(fp);
   //print number of lines
   return linesCount;

}


int total_attributes =2;  //here this is the number of attributes like id and name here
int total_lines =file_line_counter() + 1;  //for here adding 1 to get the perfect amount of line else it skips one line
int total_user = total_lines /total_attributes ;  // we can get user number by this formula

struct user_details{   //declaring the structures for storing the details
   char name[10];
   int point;
} details[20];

struct user_string{ //declaring the structures for storing the attribute name
   char name[10];
   char point[10];
} string_details[20];

struct high_scorer{
   char name[10];
   int point;
} high_scorer[7];

void file_scanner(){     //this function will scan all the lines from the file 
   FILE *fp = fopen (FILENAME,"r");

   if(fp==NULL)  printf("File \"%s\" does not exist!!!\n",FILENAME);

   else{
      for (int i =0 ; i <total_user;i ++)
      {
         fscanf(fp, "%s %s",&string_details[i].name,&details[i].name);
         fscanf(fp, "%s %d",&string_details[i].point,&details[i].point);
         point_array[i]= details[i].point;
      }
   }

}

int *sort_decreasing_order(int *array){    //will sort the incoming array in descending order anr return it

   int swap;
   int range = total_user;
   for (int i= 0 ; i< range - 1 ; i++)
            {
                for (int j = 0 ; j < range - i- 1; j++)
                    {
                    if (array[j] < array[j+1]) 
                        {
                            swap       = array[j];
                            array[j]   = array[j+1];      // using bubble sort to sort the array 
                            array[j+1] = swap;
                         }
                    }
            }
        return array; 
}
 
int *delete_duplicate_element(int *array){  //will delete the duplicate element of an array 
   int range = total_user;

   for(int i=0; i<range; i++)
    {
        for(int j=i+1; j<range; j++)
        {   
            if(array[i] == array[j])
            {
               
                for(int k=j; k < range - 1; k++)
                {
                    array[k] = array[k + 1];
                }
                range--;  
                j--;
            }
        }
    }
    
    return array ;

}

void highest_score_printer(){ //this function will print the highest score in a file 

   FILE *fp = fopen (FILENAME2,"w");

   if(fp==NULL)  printf("File \"%s\" does not exist!!!\n",FILENAME2);

   else
   {
         fprintf(fp,"Highest Scores \n");

         for (int i =0 ; i <total_user ;i ++) {

                     for	(int j = 0 ; j <total_user;j++)
                    {
                         if (point_array_modified[i] == details[j].point)
                            {
                              // printf("%s %s\n",string_details[j].name,details[j].name);
         			            // printf("%s %d\n",string_details[j].point,details[j].point);

                              fprintf(fp,"%s %s\n",string_details[j].name,details[j].name);
         			            fprintf(fp,"%s %d\n",string_details[j].point,details[j].point);

                              strcpy (high_scorer[i].name , details[j].name);
                              high_scorer[i].point = details[j].point;  
                            }
                    }
				}

   }
}
// whenever called this function will append the point
void user_point_appender(int point)
{

   FILE *fp = fopen (FILENAME,"a");

   if(fp==NULL)  printf("File \"%s\" does not exist!!!\n",FILENAME2);

   else
   {
     fprintf(fp,"\nPoint %d",point);
   }
}

//whenever called this function will append the name passed 
void user_name_appender()
{

   FILE *fp = fopen (FILENAME,"a");

   if(fp==NULL)  printf("File \"%s\" does not exist!!!\n",FILENAME2);

   else
   {
       fprintf(fp,"\nName %s",details[total_user+1].name);
   }
}

//this will print the highscores int the game window 
void high_score_shower(){

	//std::sprintf(game_point_char, "%d", game_point);

	int high_score_dy = 50;
	int high_score_y = 390;
	char serial_char[10];
	char high_score_char[10];
	//highest_score_printer();
	for (int i = 0 ; i < 7 ; i++)
	{

      iSetColor(255,255,255);
		std::sprintf(serial_char, "%d", i+1);
		iText(230, high_score_y, serial_char,GLUT_BITMAP_TIMES_ROMAN_24); // for the serial of the high scorer

		std::sprintf(high_score_char, "%d", high_scorer[i].point);

		iText(745, high_score_y, high_score_char,GLUT_BITMAP_TIMES_ROMAN_24);// for the points

		iText(363, high_score_y , high_scorer[i].name,GLUT_BITMAP_TIMES_ROMAN_24); // for showing the names
		high_score_y-=high_score_dy ;	
		
	}
}

