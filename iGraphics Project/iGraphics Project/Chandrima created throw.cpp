/*
	author: Tabassum Tara Lamia
			Chandrima Sarker 

*/
#include <stdio.h>
#include <stdlib.h>
# include "iGraphics.h"
#include "bitmap_loader.h"
#include "chandrima created throwfunction.h"

#include<iostream>


int screen_input,screen_game_over;

/* 
	function iDraw() is called again and again by the system.
*/

void iDraw()
{
	//place your drawing codes here	

	iClear();
	if ( screen == 15)
	{
		iShowImage(0,0,screen_width,screen_height,screen_input);
	}
	
	else if (screen == 16){
		screen_level_1_throw();
	}
	else if (left_chances == 0)
	{

		iShowImage(0,0,screen_width,screen_height,screen_game_over);
	}

	
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
	//if(player==true)		

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		printf("mx = %d\ my =%d\n",mx,my);

		if( screen == 15  && mx >= 21 && mx <= 172 && my >= 553 && my <= 586  )  screen = 16 ;
		
	}

	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
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
	ball_throw_command(key);
     
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
	//place your codes for other keys here
}



int main()
{
	//place your own initialization codes here. 
	
	 timer_theta_change=iSetTimer       (10,thetaChange);	
     timer_ball_move=iSetTimer          (25,ballMove);	
	 timer_speedometer_change=iSetTimer (10,VelocityBar);
	 
	iInitialize(screen_width, screen_height, "Velocity Bar");

	target = iLoadImage("images\\bird.png");
	screen_input = iLoadImage("images\\screen_input.png");
	screen_game_over = iLoadImage("images\\screen_game_over.png");

	object_throwable=iLoadImage("images\\object_throwable.png");

	iStart();


	return 0;
}


