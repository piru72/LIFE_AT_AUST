void menuLoad()				///menu loading function!
{
	if(loadx<280)
	loadx+=20;
	if(loadx==280)
	{
		showMenu = true;
		loadMenu =false;
		monkey_gayeb=true;
		iPauseTimer(0);
	}
}

void rectangle_change(){
	
	rect_y1 += rect_dy;
	 if(rect_y1  > 175 || rect_y1 < 0)rect_dy = -rect_dy;
}

/**================================================================================================
 *!                                     This functions are related to the hovering function of the menu 
 *================================================================================================**/
void menu_hover(int mx,int my)
{
    int mouse_distance_from_center;
    if(mx>=560 && mx<=609 && my>= 347 && my<=380)									///for RESULT
			{
				mouse_distance_from_center =sqrt (   pow((float)585- mx ,2)  +  pow((float)363- my ,2)   );

				if( mouse_distance_from_center < 26)
				{
					showResult=true;
				    showInst=false,showPlay = false,showAbout=false,showMenu=false,showOption=false;
				    f=1;
				//PlaySound(" mouse_hover.wav ", NULL, SND_ASYNC);

				}
				
			}

		else if(mx>=377 && mx<=469 && my>= 257 && my<=333)
			{
				mouse_distance_from_center =sqrt (   pow((float)422- mx ,2)  +  pow((float)293- my ,2)   );
				
				if( mouse_distance_from_center < 46)
				
				{
					showPlay =true;
				    showInst=false,showResult= false,showAbout=false,showMenu=false,showOption=false;
				showNewGame=true;show2ndMenu=false;
				f=1;
				//PlaySound("mouse_hover.wav", NULL, SND_ASYNC);

				}
				
			}
			
		else if(mx>=646 && mx<=686&& my>= 342 && my<=391)
			{
				mouse_distance_from_center =sqrt (   pow((float)671- mx ,2)  +  pow((float)364- my ,2)   );

				if( mouse_distance_from_center < 26)
				{
						showPlay =true;
						showInst =true;
						showPlay=false,showResult= false,showAbout=false,showMenu=false,showOption=false;
				f=1;
				//PlaySound("mouse_hover.wav", NULL, SND_ASYNC);

				}
				
			}
		else if(mx>=609 && mx<=643 && my>= 395 && my<=427)
			{
				mouse_distance_from_center =sqrt (   pow((float)626- mx ,2)  +  pow((float)411- my ,2)   );

				if( mouse_distance_from_center < 21)
				
				{
					showPlay =true;
					showStory=true;
					showInst=false,showPlay=false,showResult= false,showAbout=false,showMenu=false,showOption=false;
					f=1;
					///PlaySound("mouse_hover.wav", NULL, SND_ASYNC);

				}
				
			}
		else if(mx >=530 && mx <= 591 && my >= 270 && my <= 328)  // For teh game creator pop up
		{

			mouse_distance_from_center = sqrt (   pow((float)563- mx ,2)  +  pow((float)292- my ,2)   );

			if( mouse_distance_from_center < 35)
			{
				showPlay=true;
			    showAbout =true;
				showPlay=false,showInst=false,showResult= false,showMenu=false,showOption=false;
				showNewGame=true;show2ndMenu=false;
				f=1;
				//PlaySound("mouse_hover.wav", NULL, SND_ASYNC);

			}
			    
		}
		else if(mx >=320 && mx <= 387 && my >= 354 && my <= 413)
		{	
			mouse_distance_from_center =sqrt (   pow((float)356- mx ,2)  +  pow((float)378- my ,2)   );

			if( mouse_distance_from_center < 35){
				showPlay=true;
			    showExit =true;
				showPlay=false,showInst=false,showResult= false,showAbout=false,showMenu=false,showOption=false;
				showNewGame=true;show2ndMenu=false;
				f=1;
				//PlaySound("mouse_hover.wav ", NULL, SND_ASYNC);

			}

		}
		else
			{
				showPlay =false;
				showNewGame=false;
				showResult=false;
				showPlay = true;
				monkey_gayeb=true;
				showInst =false;
				showStory=false;
				showAbout=false;
				showExit=false;
				f=1;
			}
}

void menu()																///menu background and buttons
{
	
	iShowImage(0,0,1000,610,menu_picture);
	
}

/**================================================================================================
 *!                                    on hover different text msg will appear
 *================================================================================================**/
void goToMenuOptions()													//going to any selected option
{
	if(showPlay==true)
	{

		if(f==1)
		{
			menu();
		}
		if(showNewGame && !show2ndMenu)
		{
			iShowImage(0,0,1000,610,menu_picture);
			iShowImage(246,300,175,45,play_button);
			//game starting function calling
		}
		if(showResumeGame && !show2ndMenu)
		{
			menu();
		}
	}

	if(showInst==true)
	{
		iShowImage(0,0,1000,610,menu_picture);
		iShowImage(678,373,175,45,control_button);
		
	}
	if(showStory==true)
	{
		iShowImage(0,0,1000,610,menu_picture);
		iShowImage(635,415,175,45,story_button);
	}
	if(showExit==true)
	{
		iShowImage(0,0,1000,610,menu_picture);
		iShowImage(170,395,175,45,exit_button);
	}
	if(showAbout==true)
	{
		iShowImage(0,0,1000,610,menu_picture);
		iShowImage(580,285,175,45,about);
	}
	if(showResult==true)
	{
		iShowImage(0,0,1000,610,menu_picture);
		iShowImage(416,368,175,45,high_score);
	
	}
}
