/*
	author: Tabassum Tara Lamia
			Parvez Ahammed
			Chandrima Sarker Shipra

*/
#include <stdio.h>
#include <stdlib.h>
# include "iGraphics.h"

int ball_x, ball_y;
int dx =5 , dy =100;

int rect_x, rect_y ;
int rect_dx, rect_dy =7;

int rect_y_2;
int rect_dy_2 =10;

int rect_y_3;
int rect_dy_3=13;


int screen_width = 800;
int screen_height = 800;
bool musicOn = true;

/* 
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here	

	iClear();
   
	iSetColor(250, 225, 0);
	iFilledRectangle(0,0,800,800);

	iSetColor(144, 13, 255);
	iFilledRectangle(720,400,80,80);

	iFilledRectangle(20,700,80,40);
	
	iSetColor(250, 225, 0);
	iText(740, 440, "Target");
	iText(30, 710, "Points");



	
	
 	iSetColor(144, 13, 255);


	iFilledRectangle(80,80,80,80);

	iFilledRectangle(80 + 30 ,80+80,20,40);

	iFilledRectangle(80+ 10  ,80 + 80 +40 ,60,60);

	iFilledRectangle(80 - 40  ,80 -20 + 80 ,40,20);

	iFilledRectangle(80  +80  ,80 -20 + 80 ,40,20);

	iFilledCircle(200,200,20);

	iFilledRectangle(80  ,80 - 40 ,20,40);

	iFilledRectangle(80 +80 -20 ,80 - 40 ,20,40);



	iFilledRectangle (40,340,50,200);

	iSetColor(250, 225, 0);
	iText(45, 360, "Meter");
	iText(45, 380, "Speed");

	iText(85, 85, "Character");
	


	
	iSetColor(144, 13, 255);
	iFilledRectangle(270,rect_y,30,80);
    iFilledRectangle(335,rect_y_2,30,80);
	iFilledRectangle(395,rect_y_3,30,80);
	
	iFilledRectangle(455,rect_y,30,80);
    iFilledRectangle(575,rect_y_2,30,80);
	iFilledRectangle(675,rect_y_3,30,80);

	
    iSetColor(250, 225, 255);
    


	iSetColor(39, 39, 39);
	iText(10, 10, "Press p for pause, r for resume, END for exit.");

	iText(10, 790, "Hello bro you did good");

	// iSetColor(233, 244, 200);
	// iText(30, 30, "Hello bro you did good");
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
		//do something with 'p'
		iPauseTimer(0);
	}
	if(key == 'r')
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
	//place your codes for other keys here
}



// void ballChange(){
// 	ball_x += dx;
// 	ball_y += dy;

// 	if(ball_x > screen_width || ball_x < 0)dx = -dx;
// 	if(ball_y > screen_height || ball_y < 0)dy = -dy;
// }

void ballChange(){
	ball_y += dy;

	//if(ball_x +40  > screen_width || ball_x+40  < 0)dx = -dx;
	if(ball_y +400 > screen_height || ball_y+400  < 0)dy = -dy;
}


void rectangle_change_1(){
	
	
			 if(rect_y == 0){
			 PlaySound("music\\dis.wav",NULL,SND_ASYNC);}
			 if(rect_y==700){
				 PlaySound("music\\dis.wav",NULL,SND_ASYNC);}
			 rect_y += rect_dy;
			 
	 if(rect_y+80 > 800 || rect_y < 0)
	 {
		 
		 rect_dy = -rect_dy;
     }

}


void rectangle_change_2(){
	 if(rect_y_2 == 0){
			 PlaySound("music\\dis.wav",NULL,SND_ASYNC);}
			 if(rect_y_2==730){
				 PlaySound("music\\dis.wav",NULL,SND_ASYNC);}
			 
			 
	rect_y_2 += rect_dy_2;
	
	if (rect_y_2 +80 > 800 || rect_y_2 < 0 )
	{
		rect_dy_2 = -rect_dy_2;
	}
}

void rectangle_change_3(){
	 if(rect_y_3 == 0){
			 PlaySound("music\\dis.wav",NULL,SND_ASYNC);}
			 if(rect_y_3==728){
				 PlaySound("music\\dis.wav",NULL,SND_ASYNC);}
			 
			
	
	rect_y_3 += rect_dy_3;
	
	if (rect_y_3 +80 > 800 || rect_y_3 < 0 )
	{
		rect_dy_3 = -rect_dy_3;
	}
}

int main()
{
	//place your own initialization codes here. 
	//iSetTimer(5, ballChange);
	iSetTimer(20, rectangle_change_1);
	iSetTimer(20, rectangle_change_2);
	iSetTimer(20, rectangle_change_3);


	iInitialize(screen_width , screen_height, " Greed island");
	iStart();


	return 0;
}

//this is the code i wrote for the vediot you can run it on your end to see everythin
//ok i am running it now then

//before commiting any changes try to pull it first then you wont face the problem I hope got it ?

//yes

// ok now then lets have a look at the surviving aust game 

//is the music on ?yes

//okay then lets find out where the sound is coming form

//open the project folder of surviving aus

