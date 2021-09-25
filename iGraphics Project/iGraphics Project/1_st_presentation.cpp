//Created by Parvez Ahammed ID - 200104129 ,Tara 200104129,Chandrima 200104131

# include "iGraphics.h"
#include "screen_change.h"
//#include "image_load.h"
#include "variables.h"
#include "speedometer.h"
#include "menu.h"


#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "bitmap_loader.h"

void collisionCheck();
void screen_change(int,int);
void screen_show(int);
void menu();
void goToMenuOptions();
void image_load();
void menu_hover(int ,int);

void newGame()														///new game starting ! reseting all the values
{
	showMenu=true,loadMenu=false;
	showPlay=false,showAbout=false,showInst=false,showOption=false,showResult=false,showGameOver=false,show2ndMenu=false;
	showNewGame=false,showResumeGame=false;
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
    if (screen == 2)    iShowImage(0,0,1000,610,screen_highscore);
    if (screen == 3)    iShowImage(0,0,1000,610,screen_play);
    if (screen == 4)    iShowImage(0,0,1000,610,screen_member);
    if (screen == 5)    iShowImage(0,0,1000,610,screen_story);
    if (screen == 6)    iShowImage(0,0,1000,610,screen_control);
    if (screen == 7)  
    {
                iShowImage(0,0,1000,610,screen_level_1);

                //! code of tara start here
                iSetColor(r1,g1,b1);
	            iFilledRectangle(   15,rect_y + 45,60,30);

	            iSetColor(r2,g2,b2);
	            iFilledRectangle(   15,rect_y + 90,60,30);

	            iSetColor(r3,g3,b3);
	            iFilledRectangle(   15,rect_y + 135,60,30);

	            iSetColor(r4,g4,b4);
	            iFilledRectangle(   15,rect_y + 180,60,30);

	            iSetColor(r5,g5,b5);
	            iFilledRectangle(   15,rect_y + 225,60,30);
	
	            iSetColor(255,255,255);
                iFilledRectangle(rect_x1 +15 ,rect_y1+47 ,60,30);

                //! code of parvez

                iShowImage(620,rect_y_2,100,100,obstacle_bamboo);
                iShowImage(680,rect_y_3,100,100,obstacle_bamboo);
                iShowImage(740,rect_y_2,100,100,obstacle_bamboo);
                iShowImage(800,rect_y_3,100,100,obstacle_bamboo);
    }  
    if (screen == 8)     iShowImage(0,0,1000,610,screen_resume_game);
	if (screen == 9)     iShowImage(0,0,1000,610,screen_member_light);
	if (screen == 10)    iShowImage(0,0,1000,610,screen_control_light);
	if (screen == 11)    iShowImage(0,0,1000,610,screen_story_light);
	if (screen == 12)    iShowImage(0,0,1000,610,screen_highscore_light);
	if (screen == 13)    iShowImage(0,0,1000,610,screen_play_light);
	if (screen == 14)    iShowImage(0,0,1000,610,joystick_light);

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
		    printf("x= %d\ny= %d\n", mx,my);
            screen_change(mx,my);       
        }
		
}



void iKeyboard(unsigned char key)
{
	if (key == 'p')   //p will pause the game
	{
		collisionCheck();
		iPauseTimer(0);
        
	}
	if (key == 'r')  //r will resume the game
	{
		iResumeTimer(0);
	}
    //! code of tara
    if(key == 'l')
	{
		//ball_x -=20;
		collisionCheck();
	}

}

void iSpecialKeyboard(unsigned char key)  //special key that will end the game 
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}

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

    obstacle_bamboo = iLoadImage("images//bamboo.png");

	screen_member_light = iLoadImage("images//screen_member_light.png");
	screen_control_light = iLoadImage("images//screen_control_light.png");
	screen_story_light = iLoadImage("images//screen_story_light.png");
	screen_highscore_light = iLoadImage("images//screen_highscore_light.png");
	screen_play_light = iLoadImage("images//screen_play_light.png");
	joystick_light = iLoadImage("images//joystick_light.png");

}

void rectangle_change_timer()
{

	iSetTimer(5, rectangle_change);
    iSetTimer(20, rectangle_change_1);

}

int main()
{

	iInitialize(frame_width, frame_height, "Life @ AUST");  //initializing the game frame

    iSetTimer(200,menuLoad);
    
    image_load();
    rect_dy = 7;

	rectangle_change_timer();

    

	iStart(); // it will start drawing

	return 0;
}
