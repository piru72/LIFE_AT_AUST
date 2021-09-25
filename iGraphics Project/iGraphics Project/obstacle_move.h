/**================================================================================================
 *!                               This variables are related to book changes
 *================================================================================================**/

int obstacle_cse_1203,obstacle_cse_1205,obstacle_eee_1241,obstacle_me_1211,obstacle_math_1219;
int obstacle_cse1203_y =10, obstacle_cse1205_y =10 ,obstacle_eee_y =10 , obstacle_me_y =10 ,obstacle_math_y =10 ;
int obstacle_new  ;

int speed = 10;

int obstacle_book_flag;

int book_state = 1;


/**================================================================================================
 *!                                        Variables for showing the points
 *================================================================================================**/

int game_point = 0 ;
char game_point_char[10];

//int left_chances = 0 ;
char left_chances_char[10];


int frame_width = 1000, frame_height= 610 ;



void rectangle_change_1(){

	srand(time(0));

	obstacle_book_flag = (rand()%5 +1) ;


	switch (obstacle_book_flag * book_state )
	{
		
	case 1 :	obstacle_math_y += speed ;
				if (obstacle_math_y +60 > frame_height || obstacle_math_y -10 < 0 ) 
				{
					speed = -speed;
		
					
				} 
				break;

	case 2 :	obstacle_eee_y += speed;
				if (obstacle_eee_y +60 > frame_height || obstacle_eee_y -10  < 0 ) 
				{
					speed = -speed;
					
				} 
				break;
	
	case 3 :	obstacle_cse1205_y += speed;
				if (obstacle_cse1205_y +60 > frame_height || obstacle_cse1205_y -10  < 0 ) 
				{
					speed = -speed;
				} 
				break;
	
	case 4: 	obstacle_cse1203_y += speed;
				if (obstacle_cse1203_y +60 > frame_height || obstacle_cse1203_y -10 < 0 ) 
				{
					speed = -speed;
					
				} 
				break;

	case 5:   	obstacle_me_y += speed;
				if (obstacle_me_y +60 > frame_height || obstacle_me_y -10 < 0 ) 
				{
					speed = -speed;
					
				} 
				break;

	default:
		break;
	}


}