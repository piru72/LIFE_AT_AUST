bool pause_button_flag = false;
void screen_change(int mx,int my)
{   
    int mouse_distance_from_center ; // as we are considering circle finding out the distance of mouse cursor from each circle center

		/**=======================================================================================================================
		 *!                      This six condition below is for going to different options from main menu
		 *=======================================================================================================================**/

            if(mx>=560 && mx<=609 && my>= 347 && my<=380 && (screen == 1 ||screen==14))	
			{
				mouse_distance_from_center =sqrt (   pow((float)585- mx ,2)  +  pow((float)363- my ,2)   );
				if( mouse_distance_from_center < 26) screen = 2;
			}
            
            else if(mx>=377 && mx<=469 && my>= 257 && my<=333 && (screen == 1 ||screen==14))
			{
				mouse_distance_from_center =sqrt (   pow((float)422- mx ,2)  +  pow((float)293- my ,2)   );
				if( mouse_distance_from_center < 46)  screen = 3;	
			}
			
		    else if(mx>=646 && mx<=686&& my>= 342 && my<=391 && (screen == 1 ||screen==14))
			{
				mouse_distance_from_center =sqrt (   pow((float)671- mx ,2)  +  pow((float)364- my ,2)   );
				if( mouse_distance_from_center < 26)  screen = 6 ;
			}

		    else if(mx>=609 && mx<=643 && my>= 395 && my<=427 && (screen == 1 ||screen==14))
			{
				mouse_distance_from_center =sqrt (   pow((float)626- mx ,2)  +  pow((float)411- my ,2)   );
				if( mouse_distance_from_center < 21) screen = 5;	
			}

		    else if(mx >=530 && mx <= 591 && my >= 270 && my <= 328 && (screen == 1 ||screen==14))  
		    {
			    mouse_distance_from_center = sqrt (   pow((float)563- mx ,2)  +  pow((float)292- my ,2)   );
			    if( mouse_distance_from_center < 35) screen = 4;	    
		    }

            else if(mx >=320 && mx <= 387 && my >= 354 && my <= 413 && (screen == 1 ||screen==14))
		    {	
			    mouse_distance_from_center =sqrt (   pow((float)356- mx ,2)  +  pow((float)378- my ,2)   );
			    if( mouse_distance_from_center < 35) exit(0);    
		    }




			/**================================================================================================
			 *!     This is the functionality of back button going back directly to the joystick screen
			 *================================================================================================**/
			else if(  mx >= 21 && mx <= 172 && my >= 553 && my <= 586  && (screen ==7 || screen == 18 || screen == 19) )
			{
				 screen = 3 ;
				 user_point_appender(total_game_point);

			}   
			else if(  mx >= 21 && mx <= 172 && my >= 553 && my <= 586  && screen ==8)    screen = 3 ;

            else if( screen >= 2 &&  screen <= 23  && mx >= 21 && mx <= 172 && my >= 553 && my <= 586  )  screen = 1 ;

			else if( mx >= 21 && mx <= 172 && my >= 553 && my <= 586 && screen == 22 )  screen = 3 ;

			else if( mx >= 21 && mx <= 172 && my >= 553 && my <= 586 && screen == 23 )  screen = 3 ;

			else if( mx >= 21 && mx <= 172 && my >= 553 && my <= 586 && screen == 21 )  screen = 20 ;
			
			else if( mx >= 21 && mx <= 172 && my >= 553 && my <= 586  && screen ==3 ) 
			{
			iResumeTimer(0);
			screen = 7 ;
			} 


			


			/**=======================================================================================================================
			 *!                                                   Play button and resume button
			 *=======================================================================================================================**/
            else if ( mx >= 379 && mx <= 623 && my >= 343 && my <= 396  && (screen == 3 || screen == 13) && resume_game_flag_throw == 1)
			{
				screen = 15;
				certificate_name_flag  = 1;

			} 
            else if ( mx >= 379 && mx <= 623 && my >= 216 && my <= 270  && (screen == 3 || screen == 13))
			
			{
				mode=1;
				screen = 22;
				certificate_name_flag  = 2;

			} 


			/**=======================================================================================================================
			 *!                                                  Resume button of game screen
			 *=======================================================================================================================**/
            else if(  mx >= 870 && mx <= 986 && my >= 567 && my <= 593  && ( screen ==7 || screen == 18 || screen ==19)  ) 
			{
				if (pause_button_flag == false)
				{
						iPauseTimer(timer_instruction_text_move);
				iPauseTimer(timer_theta_change);
				iPauseTimer(timer_ball_move);
				iPauseTimer(timer_speedometer_change);
				iPauseTimer(timer_obstacle_change);
				pause_button_flag= true;

				}	
				else if (pause_button_flag)
				{
					iResumeTimer(timer_instruction_text_move);
				iResumeTimer(timer_theta_change);
				iResumeTimer(timer_ball_move);
				iResumeTimer(timer_speedometer_change);
				iResumeTimer(timer_obstacle_change);
				pause_button_flag= false;

				}
				
			}    
			else if(  mx >= 870 && mx <= 986 && my >= 524 && my <= 548  && (screen ==7 || screen == 18 || screen == 19) )    screen = 24 ;


			/**=======================================================================================================================
			 *!                                     This are for interchanging the light and dark mode
			 *=======================================================================================================================**/

			else if ( mx >= 797 && mx <= 891 && my >= 542 && my <= 586  && screen == 4) screen =9;
			else if ( mx >= 797 && mx <= 891 && my >= 542 && my <= 586  && screen == 9) screen =4;

			else if ( mx >= 797 && mx <= 891 && my >= 542 && my <= 586  && screen == 6) screen =10;
			else if ( mx >= 797 && mx <= 891 && my >= 542 && my <= 586  && screen == 10) screen =6;

			else if ( mx >= 797 && mx <= 891 && my >= 542 && my <= 586  && screen == 5) screen =11;
			else if ( mx >= 797 && mx <= 891 && my >= 542 && my <= 586  && screen == 11) screen =5;

			else if ( mx >= 797 && mx <= 891 && my >= 542 && my <= 586  && screen == 2) screen =12;
			else if ( mx >= 797 && mx <= 891 && my >= 542 && my <= 586  && screen == 12) screen =2;

			else if ( mx >= 797 && mx <= 891 && my >= 542 && my <= 586  && screen == 3) screen =13;
			else if ( mx >= 797 && mx <= 891 && my >= 542 && my <= 586  && screen == 13) screen =3;

			else if ( mx >= 797 && mx <= 891 && my >= 542 && my <= 586  && screen == 1) screen  =14;
			else if ( mx >= 797 && mx <= 891 && my >= 542 && my <= 586  && screen == 14) screen =1;


			/**================================================================================================
			 *!                      Codes below are different each time so are unique
			 *================================================================================================**/

			else if(mx >= 207 && mx <= 737 && my >= 272 && my <= 338 && mode == 0 && screen == 15 || mode==3 ) mode = 1;

			else if( mx >= 829 && mx <= 923 && my >= 34 && my <= 67 && screen == 16 )  screen = 15 ; //retry option

			else if( mx >= 353 && mx <= 597 && my >= 343 && my <= 398 && screen == 17 && level == 2 )  screen = 18 ;

			else if( mx >= 353 && mx <= 597 && my >= 343 && my <= 398 && screen == 17 && level == 3 )  screen = 19 ;

			else if( mx >= 830 && mx <= 982 && my >= 32 && my <= 67 && screen == 20  )  screen = 21 ;


			// no button from the save data screen
			else if(  screen == 24  && mx >= 535 && mx <= 761 && my >= 157 && my <= 307 && level == 1 )  screen = 7 ;
			else if(  screen == 24  && mx >= 535 && mx <= 761 && my >= 157 && my <= 307 && level == 2 )  screen = 18 ;
			else if(  screen == 24  && mx >= 535 && mx <= 761 && my >= 157 && my <= 307 && level == 3 )  screen = 19 ;

			else if(  screen == 24  && mx >= 213 && mx <= 438 && my >= 157 && my <= 307 && (level == 3 || level == 2 || level ==1) )  
			{
				resume_data_appender();
				screen = 3;

			}


			//else if( mx >= 353 && mx <= 597 && my >= 343 && my <= 398 && screen == 19 )  screen = 20 ;



}

/**================================================================================================
 *!                                        Meaning of values of screen variable
 *================================================================================================**/

// screen = 1  means --------- the main menu or the joystick image will be shown
// screen = 2  means --------- the highscore screen will be shown
// screen = 3  means --------- the screen play will be shown which includes play and resume button
// screen = 4  means --------- the list of the devs that created this game
// screen = 5  means --------- the story of the game will be shown
// screen = 6  means --------- the control of the game will be shown
// screen = 7  means --------- this is the interface of the 1 level
// screen = 8  means --------- this is the resume game screen
// screen = 9  means --------- this is the //!light version of member screen
// screen = 10 means --------- this is the //!light version of control screen
// screen = 11 means --------- this is the //!light version of story screen
// screen = 12 means --------- this is the //!light version of highscore screen
// screen = 13 means --------- this is the //!light version of play screen
// screen = 14 means --------- this is the //!light version of main menu screen
// screen = 15 means --------- this is the input screen where user will input his name
// screen = 16 means --------- this means that the game is over 
// screen = 17 means --------- this means the interval before going to next level game
// screen = 18 means --------- this is the interface of the 2 level
// screen = 19 means --------- this is the interface of the 3 level
// screen = 20 means --------- this is the interval period before going to level 4
// screen = 21 means --------- this is for attaching the certificates
// screen = 22 means --------- this is page for taking name input from resume option
// screen = 23 means --------- this is the name not found screen
// screen = 24 means --------- this is the page for user data appender

