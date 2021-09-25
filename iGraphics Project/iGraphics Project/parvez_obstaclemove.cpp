/*Created by 
Parvez Ahammed - 200104129 
Tabassum Tara lamia - 200104128
Chandrima sarker shipra 200104131 */

/**================================================================================================
 *!                                       Must needed header files
 *================================================================================================**/
# include "iGraphics.h"
#include "bitmap_loader.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/**================================================================================================
 *!                                 Header files created by the developers
 *================================================================================================**/
#include "variables.h"
#include "screen_change.h"
#include "menu.h"
#include "file_handler.h"
#include "obstacle_move.h"

/**================================================================================================
 *!                                        Function created by the developers
 *================================================================================================**/
// void collisionCheck();
void screen_change(int,int);
void screen_show(int);
void menu();
void goToMenuOptions();
void image_load();
void menu_hover(int ,int);
void show_obstacle_image();
void changable_text();
void high_score_shower();
void file_handler();
void newGame();
void changable_text();
void show_obstacle_image();


void newGame()										///new game starting ! reseting all the values
{
	showMenu=false,loadMenu=true;
	showPlay=false,showAbout=false,showInst=false,showOption=false,showResult=false,showGameOver=false,show2ndMenu=false;
	showNewGame=false,showResumeGame=false;

	length = 0;
	mode = 0;
	player_name[0]= 0;
}
void iDraw()
{

	iClear();

    if (screen == 1)
    {
        if(showMenu == false && loadMenu==true)				//loading screen
	    {

	        iShowImage(0,0,1000,610,screen);
	        iSetColor(67,77,111);
	        iRectangle(350,150,280,30);
	        iFilledRectangle(350,150,loadx,30);
	        iText(450,120,"Loading . . .");
	        }
	        if(showMenu == true && loadMenu==false && monkey_gayeb==true)			///checking if game load is finished
	        {
		        menu();
	        }
	    goToMenuOptions();	   //calling goToMenuOptions
    }
    if (screen == 2)
	{
		 	iShowImage(0,0,1000,610,screen_highscore);
		 	high_score_shower();
	}    
    if (screen == 3)    iShowImage(0,0,1000,610,screen_play);
    if (screen == 4)    iShowImage(0,0,1000,610,screen_member);
    if (screen == 5)    iShowImage(0,0,1000,610,screen_story);
    if (screen == 6)    iShowImage(0,0,1000,610,screen_control);
    if (screen == 7)  
    {
                iShowImage(0,0,1000,610,screen_level_1);
				show_obstacle_image();	
   				changable_text();


    }  
    if (screen == 8)     iShowImage(0,0,1000,610,screen_resume_game);
	if (screen == 9)     iShowImage(0,0,1000,610,screen_member_light);
	if (screen == 10)    iShowImage(0,0,1000,610,screen_control_light);
	if (screen == 11)    iShowImage(0,0,1000,610,screen_story_light);
	if (screen == 12)    iShowImage(0,0,1000,610,screen_highscore_light);
	if (screen == 13)    iShowImage(0,0,1000,610,screen_play_light);
	if (screen == 14)    iShowImage(0,0,1000,610,joystick_light);

	if (screen == 15) 
	{
		iShowImage(0,0,1000,610,screen_input);

		if(mode == 1) {
		iSetColor(255, 255, 255);
		iText(300, 300, player_name,GLUT_BITMAP_TIMES_ROMAN_24);
		}

	} 

}

void  show_obstacle_image()
{
	iShowImage(560,obstacle_me_y,50,50,obstacle_me_1211);
    iShowImage(620,obstacle_cse1203_y,50,50,obstacle_cse_1203);
	iShowImage(680,obstacle_cse1205_y,50,50,obstacle_cse_1205);
    iShowImage(740,obstacle_eee_y,50,50,obstacle_eee_1241);
	iShowImage(800,obstacle_math_y,50,50,obstacle_math_1219);

}

void changable_text(){

	std::sprintf(game_point_char, "%d", game_point);
    iText(106, 495, game_point_char,GLUT_BITMAP_TIMES_ROMAN_24);

	std::sprintf(left_chances_char, "%d", left_chances);
    iText(270, 495, left_chances_char,GLUT_BITMAP_TIMES_ROMAN_24);

}

void iMouseMove(int mx, int my)
{
	//place your codes here
	//printf("(x,y):%d,%d \n",mx, my); -- this is for debugging the code
}

void iPassiveMouse(int mx, int my)
{
	

	if(monkey_gayeb==true)
	{
		menu_hover(mx,my);
	}
}

void iMouse(int button, int state, int mx, int my)
{

		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
		    printf("x= %d\ty= %d\t screen = %d\n", mx,my,screen);
            screen_change(mx,my);       
        }

		if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		{
		//place your codes here
        //user_data_appender(game_point);
		iPauseTimer(0);
		}
		
}

void iKeyboard(unsigned char key)
{

	if(mode == 1)
	{
        if(key == '\r')
		{
			mode = 3;
			screen = 7;

			strcpy(details[total_user+1].name, player_name);
			printf("%s\n", details[total_user+1].name);
			user_name_appender();

			for(int i = 0; i < length; i++)
				player_name[i] = 0;
			length = 0;
		}
		else
		{
			player_name[length] = key;
			length++;
		}
	}

	if (key == 'p' && screen == 7 ) 
	{
			book_state =0;
	}
	if (key == 'r' && screen == 7 && book_state == 0) book_state = 1;

	if ( key == 's' && screen == 7 && book_state == 1 ) user_point_appender(game_point);
	

	
	if(key == 'x')
	{
		//do something with 'x'
		user_point_appender(game_point);
		exit(0);
	}

}

void iSpecialKeyboard(unsigned char key)  //special key that will end the game 
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}

}

void file_handler()
{
	file_line_counter();
	printf("File line %d\nTotal User %d\n",total_lines,total_user);
	file_scanner();

	point_array_modified = sort_decreasing_order( delete_duplicate_element(point_array) );

	highest_score_printer();


}


void image_load()
{
    screen= iLoadImage("images//screen_load.png");
	play_button      = iLoadImage("images//btn_play.png");  //loading the images
	menu_picture     = iLoadImage("images//joystick.png"); 
	high_score       = iLoadImage("images//btn_high_score.png"); 
	control_button   = iLoadImage("images//btn_control.png");
	story_button     = iLoadImage("images//btn_story.png");
	about            = iLoadImage("images//btn_about.png");
	exit_button      = iLoadImage("images//btn_exit.png");

    screen_play      = iLoadImage("images//screen_play.png");
    screen_highscore = iLoadImage("images//screen_highscore.png");
    screen_control   = iLoadImage("images//screen_control.png");
    screen_member    = iLoadImage("images//screen_member.png");
    screen_story     = iLoadImage("images//screen_story.png");
    screen_level_1   = iLoadImage("images//screen_level_1.png");
    screen_resume_game   = iLoadImage("images//screen_resume.png");
	screen_input       = iLoadImage("images//screen_input.png");

    obstacle_bamboo = iLoadImage("images//bamboo.png");

	screen_member_light    = iLoadImage("images//screen_member_light.png");
	screen_control_light   = iLoadImage("images//screen_control_light.png");
	screen_story_light     = iLoadImage("images//screen_story_light.png");
	screen_highscore_light = iLoadImage("images//screen_highscore_light.png");
	screen_play_light      = iLoadImage("images//screen_play_light.png");
	joystick_light         = iLoadImage("images//joystick_light.png");

	obstacle_cse_1203  = iLoadImage("images//cse_1203.png");
	obstacle_cse_1205  = iLoadImage("images//cse_1205.png");
	obstacle_eee_1241  = iLoadImage("images//eee_1241.png");
	obstacle_me_1211   = iLoadImage("images//me_1211.png");
	obstacle_math_1219 = iLoadImage("images//math_1219.png");

}

int main()
{
	newGame();
	file_handler();

	iInitialize(frame_width, frame_height, "Life @ AUST");  //initializing the game frame
	image_load();
    iSetTimer(200,menuLoad);
	iSetTimer(20, rectangle_change_1);
	
	
	iStart(); // it will start drawing

	return 0;
}
