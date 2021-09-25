int th=0;
int left_chances=9;
int image;
double theta=(th*3.1416)/180;


double throw_object_X=142,throw_object_Y=158;

int line=100;
int v=15;
int k=2; //for velocity bar
double vx=v*cos(theta);
double vy=v*sin(theta);

int p=1,t=1;
//int rotate_count =0;

double line_X=line*cos(theta),line_Y=line*sin(theta);

int timer_theta_change,timer_ball_move,timer_velocity_bar;


double g=24.8/100;//!why g is 24.8

int screen_width = 800;
int screen_height = 800;
int speedometer_X=25,speedometer_Y=100;
bool player=true,throw_ball=false,angle_set_throw=true;
void playGame();
void screen_level_1_throw()
{
	if(left_chances == 0 )
	{	
		iSetColor(0,0,0);
		iText(300,300,"Game Over");
		iPauseTimer(0);
	}
	iSetColor(255,255,255);
	iFilledRectangle(0,0,1198, 700);
	iSetColor(0,0,0);
	iLine(152,168,line_X+142,line_Y+158);
	
	playGame();
	iShowBMP(920,290,"target.bmp");

}
void thetaChange()
{
	int k=0;
			if(player)
	{

		if(angle_set_throw)
		{
			th=th+p;
			theta=(th*3.1416)/180; //radian to degree
			line_X=line*cos(theta);
			line_Y=line*sin(theta);
			
			if(th>=90)
			{
				p=-1;
			}
			if(th<=0)
			{
				k++;
				p=1;
			}
			//printf("th= %d\nk=%d\n",th,k);
		}
	}

}	
void ballMove()						//ball moving function
{

	if(throw_ball)
	{
		vx=v*cos(theta);
		vy=v*sin(theta);
		throw_object_X = 142 + (vx*t);							//position of ball
		throw_object_Y=158+(vy*t-(0.5*g*t*t));

		//printf("t = %d\n");
		t++;
		//printf("theta = %.2f\n",theta);
		//printf("v = %d\n",v);
		//printf("throw_object_X = %.2f\n canY=%.2f\n",throw_object_X,canY);
		
		if(throw_object_X+20>=1200 || throw_object_Y+10>=1400 || throw_object_Y+10<=40)                        ////boundary
		{
			throw_object_X=142;
			throw_object_Y=158;
			throw_ball=false;
			
			t=1;
			
			iResumeTimer(2);
			speedometer_X=25,speedometer_Y=100;								//green bar up and down
			player=true,angle_set_throw=true;
			th=0;
		}
		
		
		if(throw_object_X+20<=1030 && throw_object_X+20>=990 && throw_object_Y+10<= 170 && throw_object_Y+10>=50)  /// front
		{
			throw_object_X=142;
			throw_object_Y=158;
			throw_ball=false;
		
			t=1;th=0;
			
			iResumeTimer(2);
			speedometer_X=25,speedometer_Y=100;
			
			player=true,angle_set_throw=true;

		}
		
		
		
		
		if(throw_object_X + 20<=1000 && throw_object_X +20>=920 && throw_object_Y+10<=397 && throw_object_Y +10>=324)   ////our Head
		{
			printf("Yoo Worked out!!");
			throw_object_X=142;
			throw_object_Y=158;
			throw_ball=false;
			
			t=1;th=0;
		
		
			iResumeTimer(2);
			speedometer_X=25,speedometer_Y=100;
			
			player=true,angle_set_throw=true;

		}
		
		
		if(throw_object_X + 20>=568 &&throw_object_X + 20<=630 && throw_object_Y+10<=288)   ///wall
		{
			throw_object_X=142;
			throw_object_Y=158;
			throw_ball=false;
		
			t=1;th=0;
			
			iResumeTimer(2);
			speedometer_X=25,speedometer_Y=100;
			player=true,angle_set_throw=true;
		}
		
	}

}
void velocityControl()										//velocity bar with different colours for ball throughing
{
	
	iSetColor(253,210,191);
	iFilledRectangle(25,100,60,30);//20,15

	iSetColor(255,107,107);
	iFilledRectangle(25,115,60,25);//20,10

	iSetColor(253,210,191);
	iFilledRectangle(25,125,60,25);

	iSetColor(255,107,107);
	iFilledRectangle(25,135,60,25);

	iSetColor(253,210,191);
	iFilledRectangle(25,145,60,25);

	iSetColor(255,107,107);
	iFilledRectangle(25,155,60,25);

	iSetColor(253,210,191);
	iFilledRectangle(25,165,60,25);

	iSetColor(255,107,107);
	iFilledRectangle(25,175,60,25);

	iSetColor(253,210,191);
	iFilledRectangle(25,185,60,25);

	iSetColor(255,107,107);
	iFilledRectangle(25,195,60,25);

	iSetColor(253,210,191);
	iFilledRectangle(25,205,60,25);

	iSetColor(255,255,255);
	iFilledRectangle(speedometer_X,speedometer_Y,60,25);			//green line up down at velocity bar
}	
void VelocityBar()								///in this function green line goes up and down and after pressing space the final velocity is set for cat
{
	speedometer_Y=speedometer_Y+k;
	if(speedometer_Y>=212)
	{
		k=-2;
	}
	if(speedometer_Y<=100)
	{
		k=2;
	}
	if(throw_ball)
	{
		iPauseTimer(2);
		if(speedometer_Y>=100 && speedometer_Y<=115)
		{
			v=v-5;
		}if(speedometer_Y>=116 && speedometer_Y<=125)
		{
			v=v-4;
		}if(speedometer_Y>=126 && speedometer_Y<=135)
		{
			v=v-3;
		}if(speedometer_Y>=136 && speedometer_Y<=145)
		{
			v=v-2;
		}if(speedometer_Y>=146 && speedometer_Y<=155)
		{
			v=v-1;
		}if(speedometer_Y>=156 && speedometer_Y<=165)
		{
			v=v-0;
		}if(speedometer_Y>=166 && speedometer_Y<=175)
		{
			v=v+1;
		}if(speedometer_Y>=176 && speedometer_Y<=185)
		{
			v=v+2;
		}if(speedometer_Y>=186 && speedometer_Y<=195)
		{
			v=v+3;
		}if(speedometer_Y>=196 && speedometer_Y<=205)
		{
			v=v+4;
		}if(speedometer_Y>=206 && speedometer_Y<=215)
		{
			v=v+5;
		}
	}

}
void  ball_throw_command(unsigned char key)
{
	if(player==true)
	{
		if(!angle_set_throw)
		{
			if (key == ' ')
			{
				throw_ball=true;
				
				printf("%d\n",left_chances);
				left_chances--;
			}
		}
		else
		{
			if (key == ' ')
			angle_set_throw=false;
		}
	}

}
void playGame()
{
	
	if(player==true)
	{
									
		iLine(152,168,line_X+142,line_Y+158);
		

		iShowBMPAlternativeSkipWhite(throw_object_X,throw_object_Y,"kick_1.bmp");

		

		if(!angle_set_throw)
		{
			velocityControl();													///calling velocity control bar 
		}

	}
}
