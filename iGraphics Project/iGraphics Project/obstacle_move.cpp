
#include <stdio.h>
#include <stdlib.h>
# include "iGraphics.h"
#include <iostream>

#include "file_handler.h"

#include "variables.h"

#include "screen_change.h"
#include "obstacle_move.h"


void show_obstacle_image();
void load_image();
void changable_text();
void high_score_shower();
void file_handler();

void iDraw()
{
	//place your drawing codes here	

	iClear();

	if (screen == 7)
	{
		iShowImage(0,0,frame_width,frame_height,screen_level_1);
   		show_obstacle_image();	
   		changable_text();
	}
	if (screen == 2)   
	{

		 iShowImage(0,0,1000,610,screen_highscore);
		 high_score_shower();

	}	
}



void changable_text(){

	std::sprintf(game_point_char, "%d", game_point);
    iText(106, 495, game_point_char,GLUT_BITMAP_TIMES_ROMAN_24);

	std::sprintf(left_chances_char, "%d", left_chances);
    iText(270, 495, left_chances_char,GLUT_BITMAP_TIMES_ROMAN_24);

}

void  show_obstacle_image()
{
	iShowImage(560,obstacle_me_y,50,50,obstacle_me_1211);
    iShowImage(620,obstacle_cse1203_y,50,50,obstacle_cse_1203);
	iShowImage(680,obstacle_cse1205_y,50,50,obstacle_cse_1205);
    iShowImage(740,obstacle_eee_y,50,50,obstacle_eee_1241);
	iShowImage(800,obstacle_math_y,50,50,obstacle_math_1219);

}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}


/*
	function iPassiveMouse() is called when the user moves the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iPassiveMouse(int mx, int my)
{
	//place your codes here
	
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here

		printf("mx = %d\tmy=%d \n",mx,my);
		screen_change(mx,my);
		
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		user_data_appender(game_point);
		iPauseTimer(0);
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		//do something with 'p'
		iPauseTimer(0);
	}
	if(key == 'r')
	{
		iResumeTimer(0);
	}
	if(key == ' ')
	{
		iResumeTimer(0);
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	
}



void rectangle_change_1(){

			if(obstacle_book_flag % 5 == 1 )
			{
				obstacle_math_y += obstacle_math_dy;
				if (obstacle_math_y +60 > frame_height || obstacle_math_y < 0 ) 
				{
					obstacle_math_dy = -obstacle_math_dy;
					obstacle_book_flag+=1;

					game_point+=1;
				} 
			}

			if (obstacle_book_flag % 5 == 2)
			{
				obstacle_eee_y += obstacle_eee_dy;
				if (obstacle_eee_y +60 > frame_height || obstacle_eee_y   < 0 ) 
				{
					obstacle_eee_dy = -obstacle_eee_dy;
					obstacle_book_flag+=1;
					game_point+=1;
				} 
			}

			if (obstacle_book_flag % 5== 3)
			{
				 obstacle_cse1205_y += obstacle_cse1205_dy;
				if (obstacle_cse1205_y +60 > frame_height || obstacle_cse1205_y   < 0 ) 
				{
					obstacle_cse1205_dy = -obstacle_cse1205_dy;
					obstacle_book_flag+=1;
					game_point+=1;
				} 
			}

			if (obstacle_book_flag  % 5 == 4)
			{
				 obstacle_cse1203_y += obstacle_cse1203_dy;
				if (obstacle_cse1203_y +60 > frame_height || obstacle_cse1203_y  < 0 ) 
				{
					obstacle_cse1203_dy = -obstacle_cse1203_dy;
					obstacle_book_flag+=1;
					game_point+=1;
				} 
			}
			if (obstacle_book_flag % 5 == 0 )
			{
				 obstacle_me_y += obstacle_me_dy;
				if (obstacle_me_y +60 > frame_height || obstacle_me_y  < 0 ) 
				{
					obstacle_me_dy = -obstacle_me_dy;
					obstacle_book_flag+=1;
					game_point+=1;
				} 
			}


}

void load_image()
{
	screen_level_1     = iLoadImage("images//screen_level_1.png");
	screen_highscore   = iLoadImage("images//screen_highscore.png");

	obstacle_cse_1203  = iLoadImage("images//cse_1203.png");
	obstacle_cse_1205  = iLoadImage("images//cse_1205.png");
	obstacle_eee_1241  = iLoadImage("images//eee_1241.png");
	obstacle_me_1211   = iLoadImage("images//me_1211.png");
	obstacle_math_1219 = iLoadImage("images//math_1219.png");

}

void file_handler()
{
	file_line_counter();
	printf("File line %d\nTotal User %d\n",total_lines,total_user);
	file_scanner();

	point_array_modified = sort_decreasing_order(delete_duplicate_element(point_array));

	// for (int i =0 ; i < 7 ;i ++)
	// {
	// 	printf("Point is %d\n",point_array[i]);
	// }
	highest_score_printer();


}




int main()
{
	iSetTimer(20, rectangle_change_1);


	iInitialize(frame_width , frame_height, " Greed island");

	load_image();

	file_handler();

	
	iStart();


	return 0;
}

