void instruction_move()
{
	iSetColor(255, 255, 255);
	if (instruction_move_flag ==1)  iText(instruction_move_x , 10, "Press p to stop the books",GLUT_BITMAP_TIMES_ROMAN_24);
	else if (instruction_move_flag ==2) iText(instruction_move_x , 10, "Press space to use your brain  just throw it!",GLUT_BITMAP_TIMES_ROMAN_24);
}
void instruction_move_2()
{
	iSetColor(255, 255, 255);
	if (instruction_move_flag ==1)  iText(instruction_move_x , 10, "No stopping the books now",GLUT_BITMAP_TIMES_ROMAN_24);
	else if (instruction_move_flag ==2) iText(instruction_move_x , 10, "Press space to use your brain  just throw it!",GLUT_BITMAP_TIMES_ROMAN_24);
}

void instruction_move_3()
{
	iSetColor(255, 255, 255);
	if (instruction_move_flag ==1)  iText(instruction_move_x , 10, "Avoid the crush and shine in life",GLUT_BITMAP_TIMES_ROMAN_24);
	else if (instruction_move_flag ==2) iText(instruction_move_x , 10, "Press space to use your brain  just throw it!",GLUT_BITMAP_TIMES_ROMAN_24);
}

void instructions_text_move()

{
	instruction_move_x -= instruction_move_dx;
	if( instruction_move_x < 0 && instruction_move_flag == 1 )
	{
		instruction_move_x = 1000;
		instruction_move_flag = 2;

	}
	else if( instruction_move_x < 0 && instruction_move_flag == 2 )
	{
		instruction_move_x = 1000;
		instruction_move_flag = 1;
	}
		
}

void changable_text(){

	std::sprintf(game_point_char, "%d", game_point);
    iText(106, 510, game_point_char,GLUT_BITMAP_TIMES_ROMAN_24);

	std::sprintf(left_chances_char, "%d", left_chances);
    iText(270, 510, left_chances_char,GLUT_BITMAP_TIMES_ROMAN_24);
}

void certificate_text()
{	
	iSetColor(86,116,127);
	if (certificate_name_flag == 1)
	{
		iText(469, 309, details[total_user+1].name ,GLUT_BITMAP_TIMES_ROMAN_24);

	}
    else if (certificate_name_flag == 2)
	{
		iText(469, 309, resume_details[resume_user_number].resume_name ,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	

	
    iText(391, 220, "Three",GLUT_BITMAP_HELVETICA_18);

	std::sprintf(total_game_point_char, "%d", total_game_point);
	iText(391, 190, total_game_point_char,GLUT_BITMAP_HELVETICA_18);

	float perfection;
	char perfection_char[10];
	perfection = ((total_game_point * 100) / 270);
	std::sprintf(perfection_char, "%.2f", perfection);
	iText(391, 160, perfection_char,GLUT_BITMAP_HELVETICA_18);

}
