
int screen =1;
int mode;

void screen_change(int mx,int my)
{   
    int mouse_distance_from_center ;

            if(mx>=560 && mx<=609 && my>= 347 && my<=380 && (screen == 1 ||screen==14))									// for RESULT
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

            else if( screen >= 2 &&  screen <= 15  && mx >= 21 && mx <= 172 && my >= 553 && my <= 586  )  screen = 1 ;

            //else if ( mx >= 379 && mx <= 623 && my >= 343 && my <= 396  && (screen == 3 || screen == 13)) screen = 7;

            else if ( mx >= 379 && mx <= 623 && my >= 216 && my <= 270  && (screen == 3 || screen == 13)) screen = 8;

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


			else if ( mx >= 379 && mx <= 623 && my >= 343 && my <= 396  && (screen == 3 || screen == 13)) screen = 15;

			else if ( mx >= 797 && mx <= 891 && my >= 542 && my <= 586  && screen == 15) screen  =7;

			if(mx >= 207 && mx <= 737 && my >= 272 && my <= 338 && mode == 0 && screen == 15 || mode==3 ) mode = 1;

			if(  mx >= 21 && mx <= 172 && my >= 553 && my <= 586  && screen ==7 ) 
			{
				//iPauseTimer(0);
				 screen = 3 ;
			}
			else if( mx >= 21 && mx <= 172 && my >= 553 && my <= 586  && screen ==3 ) 
			{
			iResumeTimer(0);
			screen = 7 ;
			} 


}


