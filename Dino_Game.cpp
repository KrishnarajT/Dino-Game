#include "Header.h"
//Declaring Structure for the player File
struct Player_Info {
	string Player_Name;
	int points = 1000;
}Player_Info_Obj, Cur_Player_Info_Obj;//2 objects, 1 for the current player and another for retrieving information from the text file.

//Declaring the shapes
sf::RectangleShape Apple_Shape( sf::Vector2f( 30.0f, 30.0f ) );
sf::RectangleShape Up_Border( sf::Vector2f( 1060.0f, 15.0f ) );
sf::RectangleShape Down_Border( sf::Vector2f( 1075.0f, 15.0f ) );
sf::RectangleShape Left_Border( sf::Vector2f( 15.0f, 720.0f ) );
sf::RectangleShape Right_Border( sf::Vector2f( 15.0f, 720.0f ) );
sf::RectangleShape Player( sf::Vector2f( 150.0f, 150.0f ) );
sf::RectangleShape Player_D( sf::Vector2f( 150.0f, 100.0f ) );
sf::RectangleShape Ground( sf::Vector2f( 3840.0f, 80.0f ) );
sf::RectangleShape Obstacle_1( sf::Vector2f( 130.0f, 150.0f ) );
sf::RectangleShape Obstacle_12( sf::Vector2f( 130.0f, 150.0f ) );
sf::RectangleShape Obstacle_13( sf::Vector2f( 130.0f, 150.0f ) );
sf::RectangleShape Obstacle_14( sf::Vector2f( 130.0f, 150.0f ) );
sf::RectangleShape Obstacle_2( sf::Vector2f( 130.0f, 200.0f ) );
sf::RectangleShape Obstacle_22( sf::Vector2f( 130.0f, 200.0f ) );
sf::RectangleShape Obstacle_23( sf::Vector2f( 130.0f, 200.0f ) );
sf::RectangleShape Obstacle_24( sf::Vector2f( 130.0f, 200.0f ) );
sf::RectangleShape Obstacle_3( sf::Vector2f( 400.0f, 80.0f ) );
sf::RectangleShape Obstacle_32( sf::Vector2f( 400.0f, 80.0f ) );
sf::RectangleShape Obstacle_33( sf::Vector2f( 400.0f, 80.0f ) );
sf::RectangleShape Obstacle_34( sf::Vector2f( 400.0f, 80.0f ) );
sf::View look( sf::FloatRect( 0, 0, 1920, 1080 ) );

//Declaring the Default theme in the game ( Non Purchased )
string topic = "People", theme = "People";
string color = "GREY";
//val is hte counter for the frames in the video displaying, life is the number of lives with the player.
int val = 0, life = 3;
string Answer;
//Declaring a general Parent class from which all the other classes can inherit basic variables.
class General
{
	public:
	sf::Sprite spr, spr2;
	sf::Text Highscore_Txt, Score_Txt, Highscore_Val, Score_Val, Game_Name;
	sf::Font Score_Font, Mario_Font;
	sf::Clock Dino_Clock, Gravity_Clock, Score_Clock, Obs_Clock;
	sf::Time D1, T1, T2;

	sf::Sprite Mini_Border;
	sf::Texture Background_Texture, Video_Texture, People_Texture, Border_Texture, Mini_Border_Texture;;
	sf::Sprite Back_Image, Video_Image, People_Image, Border, Soul_Stone_Video_Image, Loki_Video_Image;
	sf::Text  Score_Disp_Text, Answer_Text, Life_Text, Life_Text_Val, Play_Game, How_To, About, Records, Quit, Store, ch1, ch2, ch3, ch4, ch5, ch6, Back_To_Menu, Present_Word, Time_Passed, Time_Val, Enter_Player_Name, Player_Name, Underline, Dialog, Topic_Select_Text;
	sf::Font font, fonthead, fontheadgame;
	int Obstacle_Distance = 1000;

	//Funtion to delay some time
	void Delay( int millisecond )
	{
		bool a = 0;
		sf::Clock clock;
		while (a == 0)
		{
			sf::Time T1, T2;
			sf::Time delay = sf::milliseconds( millisecond );
			T1 = clock.getElapsedTime();
			if (T1.asMilliseconds() < delay.asMilliseconds())
			{
				a = 0;
			}
			else
			{
				a = 1;
			}
		}
	}
}General_Obj;

// Class inherited from the general class to draw teh dialog box on the screen for necessary events in the game specific to each scenario.
class Dialog_Box : public General {
	public:
	const char *ch1_c, *ch2_c;//char pointers to be converted from strings.
	string one, two, Score_Disp_Str, Answer_Str, Func;//Strings for the words to display in the dialog later to be converted into their correspondin char pointers.

	//Copy Constructor to assignt the values of one two and to know the scenario in which the dialog box is used.
	Dialog_Box( string a, string b, string Function_Of_Dialog_Box )
	{
		one = a;
		two = b;
		Func = Function_Of_Dialog_Box;
	}

	//Function to assign the basic attributes to the images in the dialog box.
	void SetAttributes()
	{
		Background_Texture.loadFromFile( "Resources/Backgrounds/greenback.jpg" );
		Border_Texture.loadFromFile( "Resources/Borders/Border5.png" );
		Back_Image.setTexture( Background_Texture );
		Border.setTexture( Border_Texture );
		fonthead.loadFromFile( "Resources/Fonts/DeliusUnicase.ttf" );
		font.loadFromFile( "Resources/Fonts/Merienda-Regular.ttf" );
		//font.loadFromFile("Resources/Fonts/amarurgt.ttf");
	}

	//Function to check which key is pressed so it can return a number accordingly in the respective scenario.
	//returns 0 if nothing is pressed and then after the loop it checks again.
	//only useful after a key is pressed and the function returns other than 0.
	int KeyPressChecker()
	{
		if (Func == "Game Over")
		{
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::R ))
			{
				return 1;
			}
			else if (sf::Keyboard::isKeyPressed( sf::Keyboard::B ))
			{
				return 2;
			}
			else return 0;
		}
		else return 3;
	}

	//Function to assign attributed to the text in the dialog box.
	void SetText()
	{
		int Font_Size = 100, FontHead_Size = 35;
		//asssign differet origins in deffernt scenarios due to different spaces occupied by longer sentences.
		ch1.setOrigin( -115, -150 );
		if (Func == "Game Over")
		{
			ch1.setOrigin( -115, -150 );
			ch2.setOrigin( -550, -350 );
			Score_Disp_Text.setOrigin( -560, -150 );
			Score_Disp_Str = to_string( Player_Info_Obj.points );
			Answer_Str = Answer;
			Answer_Text.setOrigin( -125, -250 );
		}

		//assigning the values of one to their character pointers.
		ch1_c = one.c_str();
		ch2_c = two.c_str();

		//attributes for indivudual text variables.
		ch1.setFont( fonthead );
		ch1.setString( ch1_c );
		ch1.setCharacterSize( FontHead_Size );
		ch1.setFillColor( sf::Color::Red );
		ch1.setStyle( sf::Text::Style::Bold );
		Score_Disp_Text.setFont( fonthead );
		Score_Disp_Text.setString( Score_Disp_Str );
		Score_Disp_Text.setCharacterSize( FontHead_Size );
		Score_Disp_Text.setFillColor( sf::Color::Blue );
		Score_Disp_Text.setStyle( sf::Text::Style::Bold );
		Answer_Text.setFont( fonthead );
		Answer_Text.setString( Answer_Str );
		Answer_Text.setCharacterSize( FontHead_Size );
		Answer_Text.setFillColor( sf::Color::Blue );
		Answer_Text.setStyle( sf::Text::Style::Bold );
		ch2.setFont( fonthead );
		ch2.setString( ch2_c );
		ch2.setCharacterSize( FontHead_Size );
		ch2.setFillColor( sf::Color::Black );
		ch2.setStyle( sf::Text::Style::Bold );
		ch3.setFont( fonthead );
		ch3.setString( "BACK TO MENU" );
		ch3.setCharacterSize( FontHead_Size );
		ch3.setFillColor( sf::Color::Black );
		ch3.setStyle( sf::Text::Style::Bold );
		ch3.setOrigin( -100, -350 );
	}
	int Main()
	{
		int Return_Val;//value of the key pressed.
		sf::RenderWindow window( sf::VideoMode( 800, 500 ), "Look at me !!!!", sf::Style::Resize );
		SetText();
		while (window.isOpen())
		{
			sf::Event evnt;
			while (window.pollEvent( evnt ))
			{
				switch (evnt.type)
				{
					case sf::Event::Closed:
						window.close();
						break;
				}
			}
			SetAttributes();
			Return_Val = KeyPressChecker();
			window.clear( sf::Color::White );//make the background white
			window.draw( Back_Image );
			window.draw( Border );
			window.draw( ch1 );
			window.draw( Score_Disp_Text );
			window.draw( Answer_Text );
			window.draw( ch2 );
			window.draw( ch3 );
			window.display();
			//we know that KeypressChecker() returns values from 0 to a positive number, if that number is 0, we just proceed to check again.
			if (Return_Val == 1 || Return_Val == 2)
				return Return_Val;
			else if (Return_Val == 3)
				return 3;//3 stands for incorrect value for the function of the Dialog Box
		}

	}
}
Play_Over_Disp( "YOUR TOTAL SCORE IS ", "REPEAT", "Game Over" );

//class to do the files for the player and to accept the name of the player.
class Player : public General
{
	public:

	int sizeofobj = sizeof( Player_Info_Obj );
	string filename, Player_Name_Str = "";
	sf::Clock clock;
	sf::Time T1;

	//integers for each letter that the user can press.
	int a = 1, b = 1, c = 1, d = 1, e = 1, f = 1, g = 1, h = 1, i = 1, j = 1, k = 1, l = 1, n = 1, m = 1, o = 1, p = 1, q = 1, r = 1, s = 1, t = 1, u = 1, v = 1, w = 1, x = 1, y = 1, z = 1, space = 1;
	int I = 0, J = 0, Input_Done = 0, Text_Done = 0, ankey = 0, ramesh, found, checkres;
	char Player_Name_Char;
	string theme, Cur_Player_Name = "";
	const char *cstr1, *cstr2;

	//assign the attributes for each image in the player section.
	void SetAttributes()
	{
		Background_Texture.loadFromFile( "Resources/Backgrounds/background3.png" );
		Border_Texture.loadFromFile( "Resources/Borders/Border3.png" );
		Back_Image.setTexture( Background_Texture );
		Border.setTexture( Border_Texture );
		Mini_Border.setTexture( Mini_Border_Texture );
	}

	//set the attributes for each text in the player section.
	void SetText()
	{
		//if the input is done i.e the user has pressed enter for giving his name this var becomes 1 meaning the player is accepted.
		if (Input_Done == 1)
		{
			cstr1 = "PLAYER ACCEPTED";
		}
		else
		{
			cstr1 = ""; // do not display anythign on the screen.
		}
		fonthead.loadFromFile( "Resources/Fonts/DeliusUnicase.ttf" );
		font.loadFromFile( "Resources/Fonts/Merienda-Regular.ttf" );
		Game_Name.setFont( font );
		Game_Name.setString( "HANG MAN" );
		Game_Name.setCharacterSize( 100 );
		Game_Name.setFillColor( sf::Color::Blue );
		Game_Name.setStyle( sf::Text::Style::Bold );
		Game_Name.setStyle( sf::Text::Style::Underlined );
		Game_Name.setOrigin( -650, -20 );
		Enter_Player_Name.setFont( fonthead );
		Enter_Player_Name.setString( "ENTER PLAYER NAME" );
		Enter_Player_Name.setCharacterSize( 50 );
		Enter_Player_Name.setFillColor( sf::Color::Black );
		Enter_Player_Name.setOrigin( -650, -200 );
		Dialog.setFont( fonthead );
		Dialog.setString( cstr1 );
		Dialog.setCharacterSize( 50 );
		Dialog.setFillColor( sf::Color::Black );
		Dialog.setOrigin( -650, -500 );
		//Enter_Player_Name.setStyle(sf::Text::Style::);
		//Enter_Player_Name.setStyle(sf::Text::Style::Underlined);
		Player_Name.setFont( fonthead );
		Player_Name.setString( Player_Name_Str );
		Player_Name.setCharacterSize( 50 );
		Player_Name.setFillColor( sf::Color::Red );
		Player_Name.setStyle( sf::Text::Style::Italic );
		Player_Name.setOrigin( -700, -325 );
		Underline.setFont( fonthead );
		Underline.setString( "________________________________________________" );
		Underline.setCharacterSize( 40 );
		Underline.setFillColor( sf::Color::Blue );
		Underline.setStyle( sf::Text::Style::Bold );
		Underline.setOrigin( -300, -350 );
	}

	//Function to simulate the keyboard and get the name of the player.

	// we want to simulate how an actual keyboard works when we type as this is almost that.
	/*
	when we generally press a key on the keyboard, we keep our finger on that key of the keyboard for some 20 milliseconds.
	a
	this program takes less than 1 millisecond to run again and so it check whether you have entered something more than 500 times a second
	so if we keep the finger on the keyboard for 20 milliseconds, it will print a 20 times on the screen, which is a problem as we only want 1
	if we keep our finger on the keyboard (key pressed) , for about 1500 milliseconds, then the keyboard recognises that we want to repeat the
	letter many times( like how we do in backspace )
	so it waits for us to press the key for about 100 milliseconds.
	after 1500 ms it displays a lot of the letter
	eg aaaaaaaaaaaaaaaaaaaaaaaaa
	*more like*
	a (waits for 1500 ms) aaaaaaaaaaaaaaaaaaaa
	now in these 100 ms, we can press another character like b then it would have to wit for another 100 ms to show lots of bbbbb
	eg a (wait20 ms) b (wait 1500ms) bbbbbbbbbbbbbbbbb

	so we need to tell the computer to keep track of how many milliseconds has passed after we press the key a
	so after every 50 milliseconds, we increment an integer I whose value is initially equal to J
	so after I gets incremented 50 times, around 50 * 50 milliseconds have passed
	so we can release the buffer to print a many times.
	then we assign the value of I to J and then we can repeat the process again.
	a
	Now, when we press a key, and then we go to press another key, we press the other key without actually letting go of the previous key
	in other words, we press 2 keys at the same time which messes up the code logic as both go one after the other and at that time, we do not
	check any condition so both go on pressing for ever very fast, for avoiding this, we introduce 'ankey' variable.
	ankey starts working when we press 2 keys at the same time, it has a default value of 0 as in everything is fine no keys are pressed twice

	the last key pressed by the user is not A and it has been pressed before 50 ms of pressing the last key which lets assume is B
	provided that ankey is either 0 or 1 (because this may happen repeatedly); the value of ankey is set to the value of the alphabet pressed
	in numerical order.
	a=1
	b=2
	and so on.
	so in this case ankey is 1. so when b is pressed at the same time, b wont be assigned to the player name because of an && statement
	that requires ankey to be either 2 or 0.
	and one it has been 100 ms after pressing any key, ankey will set itself to 0 so other keys can be pressed.

	*/
	string Get_Player_Name()
	{
		//everytime this function starts, restart the clock
		T1 = clock.getElapsedTime();

		//ankey = whether the user has pressed another key
		//Player_Name_Char is the letter that hthe user presses.
		//T1 is the elapsed time.
		//I is always 0
		//J is the number of times 
		//boolean a = 1 means A is free to be used in the next iteration, 0 means a was already used b4
		//if the user has not pressed a before this and since he pressed the last letter, the elapsed time is less than 50 milliseconds,
		//and he has pressed A now wth less than 50 milliseconds from the last time he pressed something, then Ankey is 1.
		//assume that A and B are pressed together
		if (Player_Name_Char != 'A' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed( sf::Keyboard::A ) && ankey == 0)
		{
			ankey = 1;
		}

		//if the time passed since the last time the user pressed something is more than 100 milliseconds, ankey is 0, irrespective of the key pressed.
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}

		//if the last key pressed by the user was A
		if (Player_Name_Char == 'A')
		{
			//if the player has pressed the last key A and he has also pressed A now, and ankey is either 1 or 0
			//This section is to check whether or not to show repeated A because it is possible to reach here only if you have pressed a before
			//checks if A is pressed now and if it is not pressed with some other letter ( ankey is 1 or 0 ).
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::A ) && (ankey == 1 || ankey == 0))
			{
				clock.restart();//restart the clock because the user pressed a key for sure, only then this if loop is iterated

				//if the time passed after the user pressed A is Greater than 50 milliseconds, or if I-J is 50 or if boolean A is 0,
				if (T1.asMilliseconds() > 50 || I - J == 50 || a == 0)
				{
					Player_Name_Char = 'A';//set the character pressed to A
					Player_Name_Str += Player_Name_Char;//add the player character to the name of the player

					//the I-J is in the || condition so we have to check it again
					if (I - J == 50)
					{
						//a is generally not 0 but if it is 0 that means the user has pressed a for more then 2500 (50*50) milliseconds
						//so we will assign a to 0 so that in the if loop above, a is checked to be 0 and it will keep displaying 1 but
						//it wont show that until i increments 50 times so that the difference bw i and j is 50.
						a = 0;
					}

					//if this if loop runs then the user has pressed A before this and now also, so the vallues of I and J must be same
					//for the next checking
					//its kept after the if condition above or else that condition wont ever run.
					J = I;
					//The J = I condition is vital here, 
					//when this loop runs, it will display a on the screen and then the I-j=50 part becomes useless and the t1>50 ms becomes imp
					//as if it takes more than 50 ms, then you have obviously lifted your finger so you are nor trying to do a lot of aaaa
					//so at that point this loop runs because of the if loop on top and then i=j. also the if loop on the bottom ensures that if you have 
					//started pressing a lot of aaaa then obviously boolean a will be 0 coz of the if loop above and if you wait for mre than 50 ms, u dont want 
					// to press a lot of aaaa so the if condition down will ensure that the boolean a is set back to 1
				}
				if (T1.asMilliseconds() > 50)
				{
					a = 1;
				}
				//if the time passed after the use pressed a the last time is less than 50 ms increment I
				else
				{
					I++;
				}
			}

		}

		//If the last  key pressed by the user was not A, and the user presses A
		//ankey is either 1 or 0 so no 2 letters are pressed together
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::A ) && (ankey == 1 || ankey == 0))
		{
			I = J = 0;//the value of I and J is same is 0.
			Player_Name_Char = 'A';//the player presses a assign the playernamechar to A
			Player_Name_Str += Player_Name_Char;//add this character that the user just pressed to the name of the player
			a = 1;//boolean A = 1 that means
			clock.restart();
		}







		if (Player_Name_Char != 'B' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed( sf::Keyboard::B ) && ankey == 0)
		{
			ankey = 2;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'B')
		{
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::B ) && (ankey == 2 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || b == 0)
				{
					Player_Name_Char = 'B';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						b = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					b = 1;
				}
				else
				{
					I++;
				}
			}

		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::B ) && (ankey == 2 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'B';
			Player_Name_Str += Player_Name_Char;
			b = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'C' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed( sf::Keyboard::C ) && ankey == 0)
		{
			ankey = 3;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'C')
		{
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::C ) && (ankey == 3 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || c == 0)
				{
					Player_Name_Char = 'C';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						c = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					c = 1;
				}
				else
				{
					I++;
				}
			}

		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::C ) && (ankey == 3 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'C';
			Player_Name_Str += Player_Name_Char;
			c = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'D' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed( sf::Keyboard::D ) && ankey == 0)
		{
			ankey = 4;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'D')
		{
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::D ) && (ankey == 4 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || d == 0)
				{
					Player_Name_Char = 'D';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						d = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					d = 1;
				}
				else
				{
					I++;
				}
			}

		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::D ) && (ankey == 4 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'D';
			Player_Name_Str += Player_Name_Char;
			d = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'E' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed( sf::Keyboard::E ) && ankey == 0)
		{
			ankey = 5;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'E')
		{
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::E ) && (ankey == 5 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || e == 0)
				{
					Player_Name_Char = 'E';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						e = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					e = 1;
				}
				else
				{
					I++;
				}
			}

		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::E ) && (ankey == 5 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'E';
			Player_Name_Str += Player_Name_Char;
			e = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'F' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed( sf::Keyboard::F ) && ankey == 0)
		{
			ankey = 6;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'F')
		{
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::F ) && (ankey == 6 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || f == 0)
				{
					Player_Name_Char = 'F';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						f = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					f = 1;
				}
				else
				{
					I++;
				}
			}

		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::F ) && (ankey == 6 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'F';
			Player_Name_Str += Player_Name_Char;
			f = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'G' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed( sf::Keyboard::G ) && ankey == 0)
		{
			ankey = 7;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'G')
		{
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::G ) && (ankey == 7 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || g == 0)
				{
					Player_Name_Char = 'G';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						g = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					g = 1;
				}
				else
				{
					I++;
				}
			}

		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::G ) && (ankey == 7 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'G';
			Player_Name_Str += Player_Name_Char;
			g = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'H' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed( sf::Keyboard::H ) && ankey == 0)
		{
			ankey = 8;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'H')
		{
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::H ) && (ankey == 8 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || h == 0)
				{
					Player_Name_Char = 'H';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						h = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					h = 1;
				}
				else
				{
					I++;
				}
			}

		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::H ) && (ankey == 8 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'H';
			Player_Name_Str += Player_Name_Char;
			h = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'I' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed( sf::Keyboard::I ) && ankey == 0)
		{
			ankey = 9;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'I')
		{
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::I ) && (ankey == 9 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || i == 0)
				{
					Player_Name_Char = 'I';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						i = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					i = 1;
				}
				else
				{
					I++;
				}
			}

		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::I ) && (ankey == 9 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'I';
			Player_Name_Str += Player_Name_Char;
			i = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'J' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed( sf::Keyboard::J ) && ankey == 0)
		{
			ankey = 10;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'J')
		{
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::J ) && (ankey == 10 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || j == 0)
				{
					Player_Name_Char = 'J';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						j = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					j = 1;
				}
				else
				{
					I++;
				}
			}

		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::J ) && (ankey == 10 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'J';
			Player_Name_Str += Player_Name_Char;
			j = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'K' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed( sf::Keyboard::K ) && ankey == 0)
		{
			ankey = 11;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'K')
		{
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::K ) && (ankey == 11 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || k == 0)
				{
					Player_Name_Char = 'K';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						k = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					k = 1;
				}
				else
				{
					I++;
				}
			}

		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::K ) && (ankey == 11 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'K';
			Player_Name_Str += Player_Name_Char;
			k = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'L' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed( sf::Keyboard::L ) && ankey == 0)
		{
			ankey = 12;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'L')
		{
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::L ) && (ankey == 12 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || l == 0)
				{
					Player_Name_Char = 'L';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						l = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					l = 1;
				}
				else
				{
					I++;
				}
			}

		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::L ) && (ankey == 12 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'L';
			Player_Name_Str += Player_Name_Char;
			l = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'M' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed( sf::Keyboard::M ) && ankey == 0)
		{
			ankey = 13;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'M')
		{
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::M ) && (ankey == 13 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || m == 0)
				{
					Player_Name_Char = 'M';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						m = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					m = 1;
				}
				else
				{
					I++;
				}
			}

		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::M ) && (ankey == 13 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'M';
			Player_Name_Str += Player_Name_Char;
			m = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'N' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed( sf::Keyboard::N ) && ankey == 0)
		{
			ankey = 14;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'N')
		{
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::N ) && (ankey == 14 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || n == 0)
				{
					Player_Name_Char = 'N';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						n = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					n = 1;
				}
				else
				{
					I++;
				}
			}

		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::N ) && (ankey == 14 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'N';
			Player_Name_Str += Player_Name_Char;
			n = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'O' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed( sf::Keyboard::O ) && ankey == 0)
		{
			ankey = 15;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'O')
		{
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::O ) && (ankey == 15 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || o == 0)
				{
					Player_Name_Char = 'O';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						o = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					o = 1;
				}
				else
				{
					I++;
				}
			}

		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::O ) && (ankey == 15 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'O';
			Player_Name_Str += Player_Name_Char;
			o = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'P' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed( sf::Keyboard::P ) && ankey == 0)
		{
			ankey = 16;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'P')
		{
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::P ) && (ankey == 16 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || p == 0)
				{
					Player_Name_Char = 'P';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						p = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					p = 1;
				}
				else
				{
					I++;
				}
			}

		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::P ) && (ankey == 16 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'P';
			Player_Name_Str += Player_Name_Char;
			p = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'Q' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed( sf::Keyboard::Q ) && ankey == 0)
		{
			ankey = 17;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'Q')
		{
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::Q ) && (ankey == 17 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || q == 0)
				{
					Player_Name_Char = 'Q';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						q = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					q = 1;
				}
				else
				{
					I++;
				}
			}

		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::Q ) && (ankey == 17 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'Q';
			Player_Name_Str += Player_Name_Char;
			q = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'R' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed( sf::Keyboard::R ) && ankey == 0)
		{
			ankey = 18;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'R')
		{
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::R ) && (ankey == 18 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || r == 0)
				{
					Player_Name_Char = 'R';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						r = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					r = 1;
				}
				else
				{
					I++;
				}
			}

		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::R ) && (ankey == 18 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'R';
			Player_Name_Str += Player_Name_Char;
			r = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'S' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed( sf::Keyboard::S ) && ankey == 0)
		{
			ankey = 19;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'S')
		{
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::S ) && (ankey == 19 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || s == 0)
				{
					Player_Name_Char = 'S';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						s = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					s = 1;
				}
				else
				{
					I++;
				}
			}

		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::S ) && (ankey == 19 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'S';
			Player_Name_Str += Player_Name_Char;
			s = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'T' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed( sf::Keyboard::T ) && ankey == 0)
		{
			ankey = 20;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'T')
		{
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::T ) && (ankey == 20 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || t == 0)
				{
					Player_Name_Char = 'T';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						t = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					t = 1;
				}
				else
				{
					I++;
				}
			}

		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::T ) && (ankey == 20 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'T';
			Player_Name_Str += Player_Name_Char;
			t = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'U' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed( sf::Keyboard::U ) && ankey == 0)
		{
			ankey = 21;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'U')
		{
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::U ) && (ankey == 21 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || u == 0)
				{
					Player_Name_Char = 'U';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						u = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					u = 1;
				}
				else
				{
					I++;
				}
			}

		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::U ) && (ankey == 21 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'U';
			Player_Name_Str += Player_Name_Char;
			u = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'V' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed( sf::Keyboard::V ) && ankey == 0)
		{
			ankey = 22;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'V')
		{
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::V ) && (ankey == 22 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || v == 0)
				{
					Player_Name_Char = 'V';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						v = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					v = 1;
				}
				else
				{
					I++;
				}
			}

		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::V ) && (ankey == 22 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'V';
			Player_Name_Str += Player_Name_Char;
			v = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'W' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed( sf::Keyboard::W ) && ankey == 0)
		{
			ankey = 23;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'W')
		{
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::W ) && (ankey == 23 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || w == 0)
				{
					Player_Name_Char = 'W';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						w = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					w = 1;
				}
				else
				{
					I++;
				}
			}

		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::W ) && (ankey == 23 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'W';
			Player_Name_Str += Player_Name_Char;
			w = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'X' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed( sf::Keyboard::X ) && ankey == 0)
		{
			ankey = 24;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'X')
		{
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::X ) && (ankey == 24 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || x == 0)
				{
					Player_Name_Char = 'X';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						x = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					x = 1;
				}
				else
				{
					I++;
				}
			}

		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::X ) && (ankey == 24 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'X';
			Player_Name_Str += Player_Name_Char;
			x = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'Y' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed( sf::Keyboard::Y ) && ankey == 0)
		{
			ankey = 25;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'Y')
		{
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::Y ) && (ankey == 25 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || y == 0)
				{
					Player_Name_Char = 'Y';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						y = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					y = 1;
				}
				else
				{
					I++;
				}
			}

		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::Y ) && (ankey == 25 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'Y';
			Player_Name_Str += Player_Name_Char;
			y = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'Z' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed( sf::Keyboard::Z ) && ankey == 0)
		{
			ankey = 26;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'Z')
		{
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::Z ) && (ankey == 26 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || z == 0)
				{
					Player_Name_Char = 'Z';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						z = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					z = 1;
				}
				else
				{
					I++;
				}
			}

		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::Z ) && (ankey == 26 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'Z';
			Player_Name_Str += Player_Name_Char;
			z = 1;
			clock.restart();
		}

		if (Player_Name_Char != ' ' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed( sf::Keyboard::Space ) && ankey == 0)
		{
			ankey = 27;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == ' ')
		{
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::Space ) && (ankey == 27 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || space == 0)
				{
					Player_Name_Char = ' ';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						space = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					space = 1;
				}
				else
				{
					I++;
				}
			}

		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::Space ) && (ankey == 27 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = ' ';
			Player_Name_Str += Player_Name_Char;
			space = 1;
			clock.restart();
		}
		if (sf::Keyboard::isKeyPressed( sf::Keyboard::Return ))
		{
			cout << "return pressed";
			Input_Done = 1;
			return Player_Name_Str;
		}
		else return "NOT ENTERED YET";
	}

	int Cur_Player_Loc = -1;//location of the player in the file

	//Update a player record in the file.
	void update()
	{
		fstream fcom;
		fcom.open( "Player_Info.dat", ios::binary | ios::app );
		fcom.seekp( (Cur_Player_Loc * sizeofobj), ios::beg );//change the position of the put pointer to 1 minus the current position.
		fcom.write( ( char* ) &Player_Info_Obj, sizeofobj );//write to that position
		fcom.close();
	}

	//Fumction to check whether the player's name is already in the file.
	int check()
	{
		ifstream fin;
		fin.open( "Player_info.dat", ios::binary );

		while (!fin.eof())
		{
			fin.read( ( char* ) &Cur_Player_Info_Obj, sizeofobj );//write hte player name to Cur_Player_Info_Obj
			if (Cur_Player_Info_Obj.Player_Name == Cur_Player_Name)//If that name is the name that the player entered, found is 1 and function stops.
			{
				found = 1;
				break;
			}
			else
			{
				found = 0;
				Cur_Player_Loc++;
			}
		}
		fin.close();
		if (found == 1)
		{
			return 1;
		}
		else return 0;
	}//if found is 1 then we update else it's a new player and so we write a new record.

	int Main()
	{
		found = 0;
		SetAttributes();
		sf::RenderWindow window( sf::VideoMode( 1920, 1080 ), "										INPUT PLAYER NAME", sf::Style::Resize | sf::Style::Close );
		while (window.isOpen())
		{
			sf::Event evnt;
			while (window.pollEvent( evnt ))
			{
				switch (evnt.type)
				{
					case sf::Event::Closed:
						window.close();
						break;
				}
			}
			if (Input_Done == 0)
			{
				Cur_Player_Name = Get_Player_Name();
			}
			SetText();
			window.clear( sf::Color::White );
			window.draw( Back_Image );
			window.draw( Border );
			window.draw( Game_Name );
			window.draw( Enter_Player_Name );
			window.draw( Dialog );
			window.draw( Player_Name );
			window.draw( Underline );
			window.display();
			if (Input_Done == 1)//if the input is done then check the name after delaying for 2 seconds
			{
				Delay( 1200 );
				//check returns 1 if the name was found else 0.
				return check();
			}
		}
	}
}Player_Obj;

//Main Game Class
class Play_Game :public General
{
	public:
	sf::Texture Back_Tex, Back_Tex2, Ground_Tex, Obs_1_Tex, Obs_3_Tex, Obs_2_Tex, Dino_Tex, Dino_Tex2, Dino_Tex_D, Dino_Tex_D2;

	bool started = 0, Ground_Col = 0, collision = 0;
	int Score = 0, Highscore = 0, found = 0, Player_Pos = 0;
	float x = 1.0f, Ob_1_x = 1000;
	bool Check_Obs_in_View( int X_Cordinate )
	{
		bool present = 0;
		int LXL, LXR;
		X_Cordinate = abs( X_Cordinate );
		LXL = look.getCenter().x - 960;
		LXR = look.getCenter().x + 960;
		if (X_Cordinate <= LXR && X_Cordinate >= LXL)
		{
			present = 1;
		}
		else present = 0;
		return present;
	}
	void Highscore_Getter()
	{
		ifstream fin( "Highscore.txt" );
		fin >> Highscore;
		fin.close();
	}
	int Ramdomize_Obstacle_Placement()
	{
		srand( time( 0 ) );
		int distance = rand() % 300 + 700;
		cout << "Distance = " << distance;
		cout << endl;
		int Obs_No
			= rand() % 3 + 1;
		cout << "Obstacle = " << Obs_No;
		cout << endl;
		Obstacle_Distance += distance;
		int boool;
		cout << "Obstacle Dist = " << Obstacle_Distance << endl;
		if (Obs_No == 1)
		{
			if (Obstacle_Distance < look.getCenter().x + 1920)
			{
				boool = Check_Obs_in_View( Obstacle_1.getOrigin().x );
				if (boool == 0)
				{
					cout << "selected Obstacle was 11" << endl;
					cout << "View Centre = ";
					cout << look.getCenter().x << endl;
					cout << "Origin Before" << Obstacle_1.getOrigin().x << endl;
					Obstacle_1.setOrigin( -Obstacle_Distance, -780 );
					cout << "Origin After" << Obstacle_1.getOrigin().x << endl;
					return 1;
				}
				boool = Check_Obs_in_View( Obstacle_12.getOrigin().x );
				if (boool == 0)
				{
					Obstacle_12.setOrigin( -Obstacle_Distance, -780 );
					return 1;
				}
				boool = Check_Obs_in_View( Obstacle_13.getOrigin().x );
				if (boool == 0)
				{
					Obstacle_13.setOrigin( -Obstacle_Distance, -780 );
					return 1;
				}
				boool = Check_Obs_in_View( Obstacle_14.getOrigin().x );
				if (boool == 0)
				{
					Obstacle_14.setOrigin( -Obstacle_Distance, -780 );
					return 1;
				}
			}
			else Obstacle_Distance -= distance;
		}
		else if (Obs_No == 2)
		{
			if (Obstacle_Distance < look.getCenter().x + 1920)
			{
				if (!Check_Obs_in_View( Obstacle_2.getOrigin().x ))
				{
					Obstacle_2.setOrigin( -Obstacle_Distance, -730 );
					return 1;
				}
				else if (!Check_Obs_in_View( Obstacle_22.getOrigin().x ))
				{
					Obstacle_22.setOrigin( -Obstacle_Distance, -730 );
					return 1;
				}
				else if (!Check_Obs_in_View( Obstacle_23.getOrigin().x ))
				{
					Obstacle_23.setOrigin( -Obstacle_Distance, -730 );
					return 1;
				}
				else if (!Check_Obs_in_View( Obstacle_24.getOrigin().x ))
				{
					Obstacle_24.setOrigin( -Obstacle_Distance, -730 );
					return 1;
				}
			}
			else Obstacle_Distance -= distance;

		}
		else if (Obs_No == 3)
		{
			if (Obstacle_Distance < look.getCenter().x + 1920)
			{
				if (!Check_Obs_in_View( Obstacle_3.getOrigin().x ))
				{
					Obstacle_3.setOrigin( -Obstacle_Distance, -730 );
					return 1;
				}
				else if (!Check_Obs_in_View( Obstacle_32.getOrigin().x ))
				{
					Obstacle_32.setOrigin( -Obstacle_Distance, -730 );
					return 1;
				}
				else if (!Check_Obs_in_View( Obstacle_33.getOrigin().x ))
				{
					Obstacle_33.setOrigin( -Obstacle_Distance, -730 );
					return 1;
				}
				else if (!Check_Obs_in_View( Obstacle_34.getOrigin().x ))
				{
					Obstacle_34.setOrigin( -Obstacle_Distance, -730 );
					return 1;
				}
			}
			else Obstacle_Distance -= distance;

		}
	}

	void Set_Attributes()
	{
		Highscore_Txt.setFont( Score_Font );
		Highscore_Txt.setCharacterSize( 40 );
		Highscore_Txt.setString( "High " );
		Highscore_Txt.setOrigin( -1300, -150 );
		Highscore_Txt.setFillColor( sf::Color::Black );
		Highscore_Txt.setStyle( sf::Text::Style::Regular );

		Highscore_Val.setFont( Score_Font );
		Highscore_Val.setCharacterSize( 40 );
		Highscore_Val.setString( to_string( Highscore ) );
		Highscore_Val.setOrigin( -1500, -150 );
		Highscore_Val.setFillColor( sf::Color::Black );
		Highscore_Val.setStyle( sf::Text::Style::Regular );

		Score_Val.setFont( Score_Font );
		Score_Val.setCharacterSize( 40 );
		Score_Val.setString( to_string( Score ) );
		Score_Val.setOrigin( -1800, -150 );
		Score_Val.setFillColor( sf::Color::Black );
		Score_Val.setStyle( sf::Text::Style::Regular );

		Score_Txt.setFont( Score_Font );
		Score_Txt.setCharacterSize( 40 );
		Score_Txt.setString( "Score " );
		Score_Txt.setOrigin( -1600, -150 );
		Score_Txt.setFillColor( sf::Color::Black );
		Score_Txt.setStyle( sf::Text::Style::Regular );

		Game_Name.setFont( Mario_Font );
		Game_Name.setCharacterSize( 100 );
		Game_Name.setString( "SUPER T-REX BROS" );
		Game_Name.setOrigin( -500, -20 );
		Game_Name.setFillColor( sf::Color::Red );
		Game_Name.setStyle( sf::Text::Style::Bold );

		Mario_Font.loadFromFile( "Mario_Font.ttf" );
		Score_Font.loadFromFile( "Score_Font.ttf" );
		Back_Tex.loadFromFile( "Mario Background.png" );

		Obs_1_Tex.loadFromFile( "O1.png" );
		Obs_2_Tex.loadFromFile( "O2.png" );
		Obs_3_Tex.loadFromFile( "O3.png" );
		spr.setTexture( Back_Tex );
		spr2.setTexture( Back_Tex );

		Gravity_Clock.restart();
		Score_Clock.restart();
	}
	//void Set_Attributes2(string str)
	//{
	//	Mario_Font.loadFromFile( "Mario_Font.ttf" );
	//	Game_Name.setFont( Mario_Font );
	//	Game_Name.setCharacterSize( 100 );
	//	Game_Name.setString( str );
	//	Game_Name.setOrigin( -500, -20 );
	//	Game_Name.setFillColor( sf::Color::Blue );
	//	Game_Name.setStyle( sf::Text::Style::Bold );
	//
	//}

	int Main()
	{
		bool started = 0, Ground_Col = 0, collision = 0;
		int Score = 0, Highscore = 0, found = 0, Player_Pos = 0;
		float x = 1.0f, Ob_1_x = 1000;
		int i = 0, Back_X = 1920;
		int Background_X = 1920;
		int b1x = 0, b2x = 0, View_X;
		int j = 2;
		int DinoX_1 = 0, DinoY_1 = 0, DinoX_2 = 0, DinoY_2 = 0, DinoX_3 = 0, DinoY_3 = 0;
		int Dist_Dino_Obs_1 = 0;
		float View_Speed = 1;
		look.setCenter( 960, 540 );
		Obstacle_1.setOrigin( 10000, 10000 );
		Obstacle_12.setOrigin( 10000, 10000 );
		Obstacle_13.setOrigin( 10000, 10000 );
		Obstacle_14.setOrigin( 10000, 10000 );
		Obstacle_2.setOrigin( 10000, 10000 );
		Obstacle_22.setOrigin( 10000, 10000 );
		Obstacle_23.setOrigin( 10000, 10000 );
		Obstacle_24.setOrigin( 10000, 10000 );
		Obstacle_3.setOrigin( 10000, 10000 );
		Obstacle_32.setOrigin( 10000, 10000 );
		Obstacle_33.setOrigin( 10000, 10000 );
		Obstacle_34.setOrigin( 10000, 10000 );

		Highscore_Getter();
		sf::RenderWindow window( sf::VideoMode( 1920, 1080 ), "T - REX", sf::Style::Close | sf::Style::Resize );
		sf::SoundBuffer Jump_Buffer, Hit_Buffer;
		Jump_Buffer.loadFromFile( "Jump.wav" );
		Hit_Buffer.loadFromFile( "Dead.wav" );
		sf::Sound Jump_Sound, Hit_Sound;
		Jump_Sound.setBuffer( Jump_Buffer );
		Hit_Sound.setBuffer( Hit_Buffer );

		sf::Music Back_Music;
		Back_Music.openFromFile( "Background.ogg" );

		if (color == "GREY")
		{
			Dino_Tex.loadFromFile( "Dino Hind.png" );
			Dino_Tex2.loadFromFile( "Dino Fore.png" );
			Dino_Tex_D.loadFromFile( "Dino D Hind.png" );
			Dino_Tex_D2.loadFromFile( "Dino D Fore.png" );
		}
		else if (color == "RED")
		{
			Dino_Tex.loadFromFile( "Dino HindR.png" );
			Dino_Tex2.loadFromFile( "Dino ForeR.png" );
			Dino_Tex_D.loadFromFile( "Dino D HindR.png" );
			Dino_Tex_D2.loadFromFile( "Dino D ForeR.png" );
		}
		else if (color == "GREEN")
		{
			Dino_Tex.loadFromFile( "Dino HindG.png" );
			Dino_Tex2.loadFromFile( "Dino ForeG.png" );
			Dino_Tex_D.loadFromFile( "Dino D HindG.png" );
			Dino_Tex_D2.loadFromFile( "Dino D ForeG.png" );
		}
		else if (color == "BLUE")
		{
			Dino_Tex.loadFromFile( "Dino HindL.png" );
			Dino_Tex2.loadFromFile( "Dino ForeL.png" );
			Dino_Tex_D.loadFromFile( "Dino D HindL.png" );
			Dino_Tex_D2.loadFromFile( "Dino D ForeL.png" );
		}
		else if (color == "BLACK")
		{
			Dino_Tex.loadFromFile( "Dino HindY.png" );
			Dino_Tex2.loadFromFile( "Dino ForeY.png" );
			Dino_Tex_D.loadFromFile( "Dino D HindY.png" );
			Dino_Tex_D2.loadFromFile( "Dino D ForeY.png" );
		}




		Set_Attributes();
		Player.setOrigin( -500.0f, -200.0f );
		Player_D.setOrigin( -500.0f, -275.0f );
		Ground.setTexture( &Ground_Tex );
		Ground.setOrigin( 0, -900 );
		Player.setTexture( &Dino_Tex );
		Player_D.setTexture( &Dino_Tex_D );
		Obstacle_1.setTexture( &Obs_1_Tex );
		Obstacle_12.setTexture( &Obs_1_Tex );
		Obstacle_13.setTexture( &Obs_1_Tex );
		Obstacle_14.setTexture( &Obs_1_Tex );
		Obstacle_2.setTexture( &Obs_2_Tex );
		Obstacle_22.setTexture( &Obs_2_Tex );
		Obstacle_23.setTexture( &Obs_2_Tex );
		Obstacle_24.setTexture( &Obs_2_Tex );
		Obstacle_3.setTexture( &Obs_3_Tex );
		Obstacle_32.setTexture( &Obs_3_Tex );
		Obstacle_33.setTexture( &Obs_3_Tex );
		Obstacle_34.setTexture( &Obs_3_Tex );
		bool space = 0;
		int something = 1;
		int Obs_Distance = 1000, Obs_No = 1;
		//spr2.setOrigin( 3840, 0 );
		Obs_Clock.restart();
		Back_Music.play();
		Back_Music.setLoop( true );
		while (window.isOpen())
		{

			switch (Score)
			{
				case 20: View_Speed = 1.1f;
					break;
				case 30: View_Speed = 1.2f;
					break;
				case 50: View_Speed = 1.8f;
					break;
				case 70: View_Speed = 1.9f;
					break;
				case 100:View_Speed = 2.0f;
					break;
			}
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::Q ))
			{
				look.move( -10, 0 );
			}
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::E ))
			{
				look.move( 10, 0 );
			}


			sf::Event evnt;
			while (window.pollEvent( evnt ))
			{
				switch (evnt.type)
				{
					case sf::Event::Closed:
						window.close();
						break;
				}
			}
			if (started == 1)
			{
				T1 = Obs_Clock.getElapsedTime();
				if (T1.asSeconds() >= 1)
				{
					Ramdomize_Obstacle_Placement();
					Obs_Clock.restart();
				}
				//change_Dino();
				T2 = Score_Clock.getElapsedTime();
				look.move( View_Speed, 0 );
				//Obstacle_1.move( -1, 0 );
				if (sf::Keyboard::isKeyPressed( sf::Keyboard::S ))
				{
					if (i <= 20)
					{
						Player_D.setTexture( &Dino_Tex_D );
					}
					else if (i > 20)
					{
						Player_D.setTexture( &Dino_Tex_D2 );
					}
					if (i > 41)
					{
						i = 0;
					}
				}
				else
				{
					if (i <= 20)
					{
						Player.setTexture( &Dino_Tex );
					}
					else if (i > 20)
					{
						Player.setTexture( &Dino_Tex2 );
					}
					if (i > 41)
					{
						i = 0;
					}
				}
				i++;


				View_X = look.getCenter().x;
				if (View_X == b1x + Back_X)
				{
					b2x += j * Back_X;
					spr2.setOrigin( -b2x, 0 );
				}
				if (View_X == b2x + Back_X)
				{
					b1x = b2x + j * Back_X;
					spr.setOrigin( -b1x, 0 );
				}
			}
			if (collision != 1 && T2.asMilliseconds() >= 500)
			{
				Score++;
				Score_Val.setString( to_string( Score ) );
				Score_Clock.restart();
			}
			//Obstacle_1.setOrigin( -1920, -780 );
			//Obstacle_2.setOrigin( -2920, -730 );
			//Obstacle_3.setOrigin( -3920, -730 );

			//T1 = Obs_Clock.getElapsedTime();
			//if (T1.asMilliseconds() > 5000)
			//{
			//	Ob_1_x += 5000;
			//	Obs_Clock.restart();
			//}
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::A ))
			{
				Player.move( -1.0f, 0 );
				Player_D.move( -1.0f, 0 );
			}
			else if (sf::Keyboard::isKeyPressed( sf::Keyboard::D ))
			{
				Player.move( 1.0f, 0 );
				Player_D.move( 1.0f, 0 );
			}
			if (sf::Keyboard::isKeyPressed( sf::Keyboard::Space ) && space == 0)
			{
				Jump_Sound.play();
				x = -5;
				space = 1;
			}
			else if (sf::Keyboard::isKeyPressed( sf::Keyboard::W ) && space == 0)
			{
				Jump_Sound.play();
				x = -5;
				space = 1;
			}
			if (Ground_Col == 0 || space == 1)
			{
				Player.move( 0, x );
				Player_D.move( 0, x );
			}
			x += 0.025;


			if (Player.getPosition().y + 150 + 200 >= 920)
			{
				Ground_Col = 1;
				space = 0;
			}
			else Ground_Col = 0;
			if (Player_D.getPosition().y + 150 + 200 >= 920)
			{
				Ground_Col = 1;
				space = 0;
			}
			else Ground_Col = 0;

			if (sf::Keyboard::isKeyPressed( sf::Keyboard::Space ))
			{
				started = 1;
			}
			DinoY_1 = abs( Player.getOrigin().y ) + abs( Player.getPosition().y );
			DinoX_1 = look.getCenter().x - (960 - 500) + Player.getPosition().x;

			if (DinoX_1 + 150 >= abs( Obstacle_1.getOrigin().x ) && DinoX_1 <= abs( Obstacle_1.getOrigin().x ) + 130)
			{
				if (DinoY_1 + 150 > 780)
				{
					Back_Music.pause();
					Hit_Sound.play();
					break;
				}
			}
			DinoY_2 = abs( Player.getOrigin().y ) + abs( Player.getPosition().y );
			DinoX_2 = look.getCenter().x - (960 - 500) + Player.getPosition().x;
			if (DinoX_2 + 150 >= abs( Obstacle_2.getOrigin().x ) && DinoX_2 <= abs( Obstacle_2.getOrigin().x ) + 130)
			{
				if (DinoY_2 + 150 > 730)
				{
					Back_Music.pause();
					Hit_Sound.play();
					break;
				}
			}
			DinoY_3 = abs( Player.getOrigin().y ) + abs( Player.getPosition().y );
			DinoX_3 = look.getCenter().x - (960 - 500) + Player.getPosition().x;
			if (DinoX_3 + 150 >= abs( Obstacle_3.getOrigin().x ) && DinoX_3 <= abs( Obstacle_3.getOrigin().x ) + 400)
			{
				if (!sf::Keyboard::isKeyPressed( sf::Keyboard::S ) && DinoY_3 + 150 > 730)
				{
					Back_Music.pause();
					Hit_Sound.play();
					break;
				}
			}
			window.clear( sf::Color::White );

			//View View

			window.setView( look );
			window.draw( spr );
			window.draw( spr2 );
			window.draw( Obstacle_1 );
			window.draw( Obstacle_12 );
			window.draw( Obstacle_13 );
			window.draw( Obstacle_14 );
			window.draw( Obstacle_2 );
			window.draw( Obstacle_22 );
			window.draw( Obstacle_23 );
			window.draw( Obstacle_24 );
			window.draw( Obstacle_3 );
			window.draw( Obstacle_32 );
			window.draw( Obstacle_33 );
			window.draw( Obstacle_34 );
			//Default View

			window.setView( window.getDefaultView() );


			if (sf::Keyboard::isKeyPressed( sf::Keyboard::S ))
			{
				window.draw( Player_D );
			}
			else
			{
				window.draw( Player );
			}
			window.draw( Highscore_Txt );
			window.draw( Highscore_Val );
			window.draw( Score_Val );
			window.draw( Score_Txt );
			window.draw( Game_Name );
			window.display();
		}
		Delay( 3000 );
		window.close();
		system( "cls" );

		if (Score > Highscore)
		{
			ofstream fout( "Highscore.txt" );
			fout << Score;	fout.close();
		}

		_getch();
		return 0;
	}
}Play_Obj;

//Class for the Min Menu and Selecting all the other screen and sections.
class Menu : public General {
	public:
	void SetAttributes()
	{
		Background_Texture.loadFromFile( "Resources/Backgrounds/Dino_Background.png" );
		Back_Image.setTexture( Background_Texture );
		fonthead.loadFromFile( "Resources/Fonts/CloisterBlack.ttf" );
		font.loadFromFile( "Resources/Fonts/Roboto-thin.ttf" );
	}
	int KeyPressChecker()
	{
		if (sf::Keyboard::isKeyPressed( sf::Keyboard::P ))
		{
			return 1;
		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::C ))
		{
			return 2;
		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::H ))
		{
			return 3;
		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::Q ))
		{
			return 4;
		}
		else return 0;
	}
	int Main()
	{
		int Return_Val;
		sf::RenderWindow window( sf::VideoMode( 1920, 1080 ), "Dino Game", sf::Style::Close | sf::Style::Resize );
		while (window.isOpen())
		{
			sf::Event evnt;
			while (window.pollEvent( evnt ))
			{
				switch (evnt.type)
				{
					case sf::Event::Closed:
						window.close();
						break;
				}
			}
			SetAttributes();
			Return_Val = KeyPressChecker();
			if (Return_Val != 0)
			{
				return Return_Val;
			}
			window.clear( sf::Color::White );
			window.draw( Back_Image );
			window.display();
		}
	}
}Menu_Obj;

//Class for displaying the Help and Credits Page.
class Help_and_About : public General
{
	public:
	sf::Text Back_To_Menu;
	void SetAttributes()
	{
		Background_Texture.loadFromFile( "Resources/Backgrounds/Help_and_About.png" );
		Back_Image.setTexture( Background_Texture );
		fonthead.loadFromFile( "Resources/Fonts/DeliusUnicase.ttf" );
		font.loadFromFile( "Resources/Fonts/Merienda-Regular.ttf" );
	}
	int Key_Press_Ckecker()
	{
		if (sf::Keyboard::isKeyPressed( sf::Keyboard::B ))
		{
			return 2;
		}
		else return 0;
	}
	void Set_Text()
	{
		Back_To_Menu.setFont( fonthead );
		Back_To_Menu.setString( "BACK TO MENU (B)" );
		Back_To_Menu.setCharacterSize( 30 );
		Back_To_Menu.setFillColor( sf::Color::Black );
		Back_To_Menu.setStyle( sf::Text::Style::Bold );
		Back_To_Menu.setOrigin( -1400, -950 );
	}
	//text for help and about;
	/*
	how to play HangMan // heading
	HnagMan is a classic game that we have been playing since centuries. it is a word Guessing Game that requires the basic knowledge of
	words of the specified genre. This version of the game consists of several subtopics like movies, celebreties, colors, countries etc
	Play Classic
	upon selecting play classic, you will be presented with a hang mam and the alphabets just above the word that you are required to guess
	to guess a letter, press that letter on the keyboard and it will turn red signifying that it has been used up and all the occurances of
	the letter will be displayed on the screen filling up the word in the right places allowing you to press another letter in order to
	complete the word.
	you will be given a time limit and how fast you guess the word will determine your points.
	you will have 1 hints that you can use to help you guess the word which will reduce you points
	you have a limited amount of lives(5).every time you misguess a letter, a body part of the hangman appears on the screes
	and hence you goal is to correctly guess the word before the body of the hangman appears on the screen.

	Play Theme
	Upon selecting your theme in the store, the option of that skin will be available in the settings.
	the ruled of this mode of the game will be alike the classin mode, with the only exception that upon every misguess of a letter,
	you will be shown a scene of the genre( or movie or theme or villain ) that you have purchased from the store.
	you objective is therefore to prevent a negative ending to the theme( depending on the respective ciscumstances ).


	About
	Programmed by : Krishnaraj PT
	Class 12 A

	As a part of the CBSE Project to be submitted to Mini Mam.
	Programming language : C++

	Sincere thanks to :
	Parents and Teachers,
	Master Joshua Nishant, For helping with the creative aspects of the Game
	Stack OverFlow.com
	Google
	LearnC++.com
	Notepad++
	Paint.net Picsart

	*/
	int Main()
	{
		int Return_Val;
		sf::RenderWindow window( sf::VideoMode( 1920, 1080 ), "HANG MAN", sf::Style::Close | sf::Style::Resize );
		while (window.isOpen())
		{
			sf::Event evnt;
			while (window.pollEvent( evnt ))
			{
				switch (evnt.type)
				{
					case sf::Event::Closed:
						window.close();
						break;
				}
			}
			Return_Val = Key_Press_Ckecker();
			if (Return_Val != 0)
				return Return_Val;
			Set_Text();
			SetAttributes();
			window.clear( sf::Color::White );
			window.draw( Back_Image );
			window.draw( Back_To_Menu );
			window.draw( Quit );
			window.display();
		}
	}

}Help_About_Obj;

//Class for the different changing the themes of the game.
class Settings : public General {
	public:
	sf::Text ch1, ch2, ch3, ch4, ch5, ch6, Back_To_Menu, Total_Coins;
	void SetAttributes()
	{
		Background_Texture.loadFromFile( "Resources/Backgrounds/background3.png" );
		Border_Texture.loadFromFile( "Resources/Borders/Border3.png" );
		Back_Image.setTexture( Background_Texture );
		Border.setTexture( Border_Texture );
		fonthead.loadFromFile( "Resources/Fonts/DeliusUnicase.ttf" );
		font.loadFromFile( "Resources/Fonts/Merienda-Regular.ttf" );
	}
	int KeyPressChecker()
	{
		if (sf::Keyboard::isKeyPressed( sf::Keyboard::R ))
		{
			return 1;
		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::L ))
		{
			return 2;
		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::G ))
		{
			return 3;
		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::C))
		{
			return 4;
		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::Y ))
		{
			return 5;
		}
		else if (sf::Keyboard::isKeyPressed( sf::Keyboard::B ))
		{
			return 6;
		}
		else return -1;
	}
	void SetText()
	{
		int Font_Size = 100, FontHead_Size = 80;
		Game_Name.setFont( font );
		Game_Name.setString( "SUPER TREX BROS" );
		Game_Name.setCharacterSize( Font_Size );
		Game_Name.setFillColor( sf::Color::Blue );
		Game_Name.setStyle( sf::Text::Style::Bold );
		Game_Name.setStyle( sf::Text::Style::Underlined );
		Game_Name.setOrigin( -650, -20 );
		Back_To_Menu.setFont( fonthead );
		Back_To_Menu.setString( "BACK TO MENU (B)" );
		Back_To_Menu.setCharacterSize( 30 );
		Back_To_Menu.setFillColor( sf::Color::Black );
		Back_To_Menu.setStyle( sf::Text::Style::Bold );
		Back_To_Menu.setOrigin( -1400, -950 );
		ch1.setFont( fonthead );
		ch1.setString( "SETTINGS" );
		ch1.setCharacterSize( FontHead_Size );
		ch1.setFillColor( sf::Color::Red );
		ch1.setStyle( sf::Text::Style::Bold );
		ch1.setStyle( sf::Text::Style::Underlined );
		ch1.setOrigin( -500, -150 );
		ch2.setFont( fonthead );
		ch2.setString( "RED (R)" );
		ch2.setCharacterSize( FontHead_Size );
		ch2.setFillColor( sf::Color::Black );
		ch2.setStyle( sf::Text::Style::Bold );
		ch2.setOrigin( -250, -300 );
		ch3.setFont( fonthead );
		ch3.setString( "BLUE (L)" );
		ch3.setCharacterSize( FontHead_Size );
		ch3.setFillColor( sf::Color::Black );
		ch3.setStyle( sf::Text::Style::Bold );
		ch3.setOrigin( -250, -400 );
		ch4.setFont( fonthead );
		ch4.setString( "GREEN (G)" );
		ch4.setCharacterSize( FontHead_Size );
		ch4.setFillColor( sf::Color::Black );
		ch4.setStyle( sf::Text::Style::Bold );
		ch4.setOrigin( -250, -500 );
		ch5.setFont( fonthead );
		ch5.setString( "GREY (C)" );
		ch5.setCharacterSize( FontHead_Size );
		ch5.setFillColor( sf::Color::Black );
		ch5.setStyle( sf::Text::Style::Bold );
		ch5.setOrigin( -250, -600 );
		ch6.setFont( fonthead );
		ch6.setString( "BLACK (Y)" );
		ch6.setCharacterSize( FontHead_Size );
		ch6.setFillColor( sf::Color::Black );
		ch6.setStyle( sf::Text::Style::Bold );
		ch6.setOrigin( -250, -700 );
	}
	int Main()
	{
		int Return_Val, Dialog_Res, Return_Val_Frm_Func = 0;
		sf::RenderWindow window( sf::VideoMode( 1920, 1080 ), "HANG MAN", sf::Style::Close | sf::Style::Resize );
		while (window.isOpen())
		{
			sf::Event evnt;
			while (window.pollEvent( evnt ))
			{
				switch (evnt.type)
				{
					case sf::Event::Closed:
						window.close();
						break;
				}
			}
			SetAttributes();
			SetText();
			Return_Val = KeyPressChecker();
			switch (Return_Val)
			{
				case 1: color = "RED";
					return 0;
					break;
				case 2: color = "BLUE";
					return 0;
					break;
				case 3: color = "GREEN";
					return 0;
					break;
				case 4: color = "GREY";
					return 0;
					break;
				case 5: color = "BLACK";
					return 0;
					break;
				case 6:window.close();
					break;
			}
			window.clear( sf::Color::White );
			window.draw( Back_Image );
			window.draw( Border );
			window.draw( Game_Name );
			window.draw( ch1 );
			window.draw( ch2 );
			window.draw( ch3 );
			window.draw( ch4 );
			window.draw( ch5 );
			window.draw( ch6 );
			window.draw( Back_To_Menu );
			window.display();
		}

	}
}Settings_Obj;

int main()
{
	int Quit = 0;
	int a, b, c, d, e, f, g, h, Skip_Menu = 0;

	//Run the main function for getting the name of the player
	//a is th evalue of the check function and whether hte function reuturned true or false determines whether to write or to update.
	//a = Player_Obj.Main();
	////if a is 0 then the player is new and we need to write the record of the player in the file.
	//if (a == 0)
	//{
	//	Player_Info_Obj.Player_Name = Player_Obj.Cur_Player_Name;//Updtate function works by using the Playe_Info_Obj
	//	Player_Obj.update();
	//}
	//else
	//{
	//	Player_Info_Obj = Cur_Player_Info_Obj;
	//}
	while (Quit == 0)
	{
		if (Skip_Menu == 0)
		{
			b = Menu_Obj.Main();
		}
		// b is the section of the menu that the player wants to go to.
		switch (b)
		{
			case 1://PLAY GAME
				c = Play_Obj.Main();//returns 1 for back to menu else returns 0.
				if (c == 1)
					Skip_Menu = 1;
				else
					Skip_Menu = 0;
				continue;//we do not use break because break goes to the next statement after the while loop but we want o rerun the while loop.
			case 3:
				Help_About_Obj.Main();
				continue;
			case 2:
				Settings_Obj.Main();
				continue;
			case 4:
				Player_Info_Obj.Player_Name = Player_Obj.Cur_Player_Name;
				Player_Obj.update();//update whatever we did to the object and then quit is 1 to end the loop.
				Quit = 1;
				continue;
		}
	}
	system( "cls" );
	cout << "Thanks for Playing SUPER TREX BROS";
	General_Obj.Delay( 100000000 );
	return 0;
}
