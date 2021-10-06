void keyboard_control(unsigned char key)

{
    
	if(mode == 1 && screen == 15) // this is for the play button and new users
	{
        if(key == '\r') // taking enter key as the input
		{
			mode = 3;
			screen = 7; // going to 1st level of screen
			
			total_game_point =0; // initializing the points and games from start
			game_point =0;

			

			strcpy(details[total_user+1].name, player_name); // copying the string into a new structure
			printf("%s\n", details[total_user+1].name);
			user_name_appender(); // appending the name in a file upon clicking enter

			for(int i = 0; i < length; i++)// for taking new name 
				player_name[i] = 0;
			length = 0;


		}
		else
		{
			player_name[length] = key;// taking the key into string
			length++;
		}
	}

	if(mode == 1 && screen == 22) // this is the screen for resume button
	{
        if(key == '\r')
		{
			mode = 3; // exiting from the mode

			if(user_authenticator () == true) 
			
			{
				if (resume_details[resume_user_number].resume_game_level == 1)
				{
						 screen = 7;
						 level = resume_details[resume_user_number].resume_game_level;
						 left_chances = resume_details[resume_user_number].resume_left_chances;
						 game_point   = resume_details[resume_user_number].resume_game_point;
				} 
				else if (resume_details[resume_user_number].resume_game_level == 2)
				{
						 screen = 18;
						 level = resume_details[resume_user_number].resume_game_level;
						 left_chances = resume_details[resume_user_number].resume_left_chances;
						 game_point   = resume_details[resume_user_number].resume_game_point;

				} 
				else if (resume_details[resume_user_number].resume_game_level == 3) 
				{
						 screen = 19;
						 level = resume_details[resume_user_number].resume_game_level;
						 left_chances = resume_details[resume_user_number].resume_left_chances;
						 game_point   = resume_details[resume_user_number].resume_game_point;
					
				}


			} 
			else if(user_authenticator () == false) screen = 23;
			
			
			
			// total_game_point =0;
			// game_point =0;
			// strcpy(details[total_user+1].name, player_name);
			printf("%s\n", resume_player_name);
			// user_name_appender();

			for(int i = 0; i < length; i++)
				resume_player_name[i] = 0;

			length = 0;


		}
		else
		{
			resume_player_name[length] = key;
			length++;
		}
	}

	if (key == 'p' && (screen == 7 || screen == 19 ))
	{
			book_state =0;
	}

	if ( key == 's' && screen == 7 && book_state == 1 ) user_point_appender(game_point);

	if(screen == 7 ||screen == 18 || screen == 19)
	{
		ball_throw_command(key);
	}



	if(key == 'x')
	{
		//do something with 'x'
		user_point_appender(game_point);
		exit(0);
	}
}