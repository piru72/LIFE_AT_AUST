
#include <stdio.h>
#include <stdlib.h>
# include "iGraphics.h"



int rect_x1, rect_y1;
int rect_x, rect_y;
int rect_dx, rect_dy;

int frame_width = 1000 ;
int frame_height = 610;

int r=253,g=210,b=191;
int r1=255, g1=107, b1=107;
int r2=69,  g2=82,  b2=108;
int r3=255, g3=107, b3=107;
int r4=69,  g4=82,  b4=108;
int r5=255, g5=107, b5=107;



void collisionCheck();
/* 
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here	

	iClear();

    

	iSetColor(r,g,b);
	iFilledRectangle(0,0,800,800);

	iSetColor(r1,g1,b1);
	iFilledRectangle(rect_x + 15,rect_y + 45,60,30);

	iSetColor(r2,g2,b2);
	iFilledRectangle(rect_x + 15,rect_y + 90,60,30);

	iSetColor(r3,g3,b3);
	iFilledRectangle(rect_x + 15,rect_y + 135,60,30);

	iSetColor(r4,g4,b4);
	iFilledRectangle(rect_x + 15,rect_y + 180,60,30);

	iSetColor(r5,g5,b5);
	iFilledRectangle(rect_x + 15,rect_y + 225,60,30);
	

	iSetColor(255,255,255);
    iFilledRectangle(rect_x1 +15 ,rect_y1+47 ,60,30);

	

	
	

	
	iSetColor(39, 39, 39);
	iText(10, 10, "Press p for pause, r for resume, END for exit.");

	

	// iSetColor(233, 244, 200);
	// iText(30, 30, "Hello bro you did good");
}

void speedometer(){

	

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
		//do something with 'q'
		iPauseTimer(0);
		collisionCheck();
		
		
	}
	if(key == 'r')
	{
		iResumeTimer(0);

	}

	if(key == 'l')
	{
		//ball_x -=20;
		collisionCheck();
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
	//place your codes for other keys here
}

void collisionCheck()
{
	rect_y1 +=rect_dy;

	if(rect_y1 > 0 &&  rect_y1 < 45) //0,40
	{
		r1 = 182;
		g1 = 25;
		b1 = 25;
		
	}
   
	if(rect_y1 > 41 && rect_y1 < 82 )//41,82
	{
		r2 = 182;
		g2 = 25;
		b2 = 25;

	}
	if(rect_y1 > 84 && rect_y1 <130)//84,130
	{
		r3 = 182;
		g3 = 25;
		b3 = 25;

	}
	if(rect_y1 > 132 && rect_y1 < 160) //132,160
	{
		r4 = 182;
		g4 = 25;
		b4 = 25;
	}
	if( rect_y1 > 165 && rect_y1 < 178)//165,178
	{
		r5 = 182;
		g5 = 25;
		b5 = 25;
	}

	//printf("collision y=%d\n",rect_y1);
//The blocks turned red when the white block touched their coordinates and the white block is working from bottom to topp 

}




void rectangle_change(){
	
	rect_y1 += rect_dy;
	 if(rect_y1  > 175 || rect_y1 < 0)rect_dy = -rect_dy;
	 

}

int main()
{
	//place your own initialization codes here. 
	//iSetTimer(35, ballChange);
	iSetTimer(35, rectangle_change);
	
	
	

	rect_dy = 7;
	iInitialize(frame_width , frame_height, " Greed island");
	iStart();


	return 0;
}
