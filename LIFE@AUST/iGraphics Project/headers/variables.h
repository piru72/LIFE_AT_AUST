int play_button,control_button,story_button,about,exit_button;
int loadx;

int screen_play,screen_highscore,screen_control,screen_member,screen_story;

int screen_member_light,screen_control_light,screen_story_light ,screen_highscore_light,screen_play_light,joystick_light;

int screen_input_resume;

int screen_game_over;
int screen_name_not_found;
int screen_append_data ;

int screen_go_level_2,screen_level_2;
int screen_go_level_3,screen_level_3;

int screen_certificate;

int screen_level_1,screen_resume_game;

int f=0;

int menu_picture,high_score;

bool showMenu = false,showGameOver=false,loadMenu=true,monkey_gayeb=false;
bool showPlay=false,showAbout=false,showInst=false,showOption=false,showResult=false;

bool showExit=false,showStory=false,showNewGame=false,showResumeGame=false,show2ndMenu=false;

//! code of tara starts here

int rect_x1, rect_y1;
int rect_x, rect_y;
int rect_dx, rect_dy;


//! code of parvez starts here

int rect_y_2;
int rect_dy_2 =10;
int rect_y_3;
int rect_dy_3=13;


/**=======================================================================================================================
 *!                                                   Variable for text input
 *=======================================================================================================================**/

int screen_input;
char player_name[100];
int length;

int screen =1;
int mode;

/**================================================================================================
 *!                               This variables are related to book changes
 *================================================================================================**/

int obstacle_cse_1203,obstacle_cse_1205,obstacle_eee_1241,obstacle_me_1211,obstacle_math_1219;

int obstacle_cse_2103,obstacle_cse_2106,obstacle_eee_2141,obstacle_hum_2109,obstacle_math_2101;

int obstacle_cse_2207,obstacle_cse_2201,obstacle_cse_2213,obstacle_cse_2209,obstacle_math_2203;

int obstacle_cse1203_y =10, obstacle_cse1205_y =10 ,obstacle_eee_y =10 , obstacle_me_y =10 ,obstacle_math_y =10 ;
int obstacle_new  ;

int speed = 10;

int obstacle_book_flag;

int book_state = 1;

/**================================================================================================
 *!                                        For crush move
 *================================================================================================**/

int all_pic[50];
int pic,pic_1;
int flag_1=1;
int i;

/**================================================================================================
 *!                                        crush move
 *================================================================================================**/

int girl_x=0,girl_y=300,bag_y=girl_y;
int bag;
int girl[40];
char index=0;
int bc,life_bar=0;
int check=0;
int bag_x,character_y=140;
int crush_change_timer,bag_move_timer;


/**================================================================================================
 *!                                        Variables for showing the points
 *================================================================================================**/

int game_point = 0 ;
char game_point_char[10];

int total_game_point = 0 ;
char total_game_point_char[10];

char left_chances_char[10];

int frame_width = 1000, frame_height= 610 ;


/**================================================================================================
 *!                                        Variables for throwfunction
 *================================================================================================**/

int th=0;
int left_chances=10;
int target,object_throwable;
double theta=(th*3.1416)/180;
int return_time=0;
int timer_theta_change,timer_ball_move,timer_speedometer_change,timer_obstacle_change,timer_instruction_text_move;
double throw_object_X=142,throw_object_Y=158;
int sound = 0;
int line=100;
int velocity=15;
int k=2; //for velocity bar
double vx=velocity*cos(theta);
double vy=velocity*sin(theta);
int rotate_count=0;
int p=1,t=1;
int throw_brain;
double line_X=line*cos(theta),line_Y=line*sin(theta);

int resume_game_flag_throw = 1;

double g=9.8/100;

int screen_width = 1000;
int screen_height = 610;
int speedometer_X=25,speedometer_Y=100;
bool player=true,throw_ball=false,angle_set_throw=true;
int checkvalue=1;

/**======================
 *!    Moveable text 
 *========================**/

int instruction_move_flag =1,instruction_move_x = 1000 , instruction_move_dx = 5;


/**======================
 *!    Certificate text 
 *========================**/

int certificate_name_flag = 0;

int* high_score_2;



/**================================================================================================
 *!                                        Variable for resume user 
 *================================================================================================**/

char resume_player_name[100];

int resume_user_number;
int resume_total_user;

struct resume_details {
    char resume_name [10];
    int  resume_left_chances;
    int  resume_game_level;
    int  resume_game_point;
} resume_details [20]; 

struct resume_string_details{
    char  resume_name [10];
    char  resume_left_chances[10];
    char  resume_game_level[10];
    char  resume_game_point[10];
} resume_string_details [20];


int level =1;

void newGame()										///new game starting ! reseting all the values
{
	showMenu=false,loadMenu=true;
	showPlay=false,showAbout=false,showInst=false,showOption=false,showResult=false,showGameOver=false,show2ndMenu=false;
	showNewGame=false,showResumeGame=false;

	length = 0;
	mode = 0;
	player_name[0]= 0;


   
}

void image_load()
{
    screen           = iLoadImage("images//screen_load.png");
	play_button      = iLoadImage("images//btn_play.png");  //loading the images
	menu_picture     = iLoadImage("images//joystick.png");
	high_score       = iLoadImage("images//btn_high_score.png");
	control_button   = iLoadImage("images//btn_control.png");
	story_button     = iLoadImage("images//btn_story.png");
	about            = iLoadImage("images//btn_about.png");
	exit_button      = iLoadImage("images//btn_exit.png");

    screen_play         = iLoadImage("images//screen_play.png");
    screen_highscore    = iLoadImage("images//screen_highscore.png");
    screen_control      = iLoadImage("images//screen_control.png");
    screen_member       = iLoadImage("images//screen_member.png");
    screen_story        = iLoadImage("images//screen_story.png");
    screen_level_1      = iLoadImage("images//screen_level_1.png");
    screen_resume_game  = iLoadImage("images//screen_resume.png");
	screen_input        = iLoadImage("images//screen_input.png");

	screen_input_resume       = iLoadImage("images//screen_input_resume.png");
	screen_name_not_found      = iLoadImage("images//screen_name_not_found.png");
	screen_append_data = iLoadImage("images//screen_append_data.png");


	screen_member_light    = iLoadImage("images//screen_member_light.png");
	screen_control_light   = iLoadImage("images//screen_control_light.png");
	screen_story_light     = iLoadImage("images//screen_story_light.png");
	screen_highscore_light = iLoadImage("images//screen_highscore_light.png");
	screen_play_light      = iLoadImage("images//screen_play_light.png");
	joystick_light         = iLoadImage("images//joystick_light.png");

	obstacle_cse_1203  = iLoadImage("images//cse_1203.png");
	obstacle_cse_1205  = iLoadImage("images//cse_1205.png");
	obstacle_eee_1241  = iLoadImage("images//eee_1241.png");
	obstacle_me_1211   = iLoadImage("images//me_1211.png");
	obstacle_math_1219 = iLoadImage("images//math_1219.png");

	

	obstacle_cse_2103  = iLoadImage("images//cse_2103.png");
	obstacle_cse_2106  = iLoadImage("images//cse_2106.png");
	obstacle_eee_2141  = iLoadImage("images//eee_2141.png");
	obstacle_hum_2109  = iLoadImage("images//hum_2109.png");
	obstacle_math_2101 = iLoadImage("images//math_2101.png");

    obstacle_cse_2207  = iLoadImage("images//cse_2207.png"); 
    obstacle_cse_2201  = iLoadImage("images//cse_2201.png");
    obstacle_cse_2213  = iLoadImage("images//cse_2213.png");
    obstacle_cse_2209  = iLoadImage("images//cse_2209.png");
    obstacle_math_2203 = iLoadImage("images//math_2203.png");

	screen_game_over  = iLoadImage("images//screen_game_over.png");
	
	screen_go_level_2 = iLoadImage("images//screen_go_level_2.png");
	screen_go_level_3 = iLoadImage("images//screen_go_level_3.png");


	screen_level_2 = iLoadImage("images//screen_level_2.png");
	screen_level_3 = iLoadImage("images//screen_level_3.png");
    throw_brain    = iLoadImage("images//object_throw.png");

    screen_certificate = iLoadImage("images//screen_certificate.png");

}


