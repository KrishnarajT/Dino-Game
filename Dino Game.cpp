//#include"Header.h"
//
//sf::RectangleShape Player( sf::Vector2f( 150.0f, 150.0f ) );
//sf::RectangleShape Player_D( sf::Vector2f( 150.0f, 100.0f ) );
//sf::RectangleShape Ground( sf::Vector2f( 3840.0f, 80.0f ) );
//sf::RectangleShape Obstacle_1( sf::Vector2f( 130.0f, 150.0f ) );
//sf::RectangleShape Obstacle_12( sf::Vector2f( 130.0f, 150.0f ) );
//sf::RectangleShape Obstacle_13( sf::Vector2f( 130.0f, 150.0f ) );
//sf::RectangleShape Obstacle_14( sf::Vector2f( 130.0f, 150.0f ) );
//sf::RectangleShape Obstacle_2( sf::Vector2f( 130.0f, 200.0f ) );
//sf::RectangleShape Obstacle_22( sf::Vector2f( 130.0f, 200.0f ) );
//sf::RectangleShape Obstacle_23( sf::Vector2f( 130.0f, 200.0f ) );
//sf::RectangleShape Obstacle_24( sf::Vector2f( 130.0f, 200.0f ) );
//sf::RectangleShape Obstacle_3( sf::Vector2f( 400.0f, 80.0f ) );
//sf::RectangleShape Obstacle_32( sf::Vector2f( 400.0f, 80.0f ) );
//sf::RectangleShape Obstacle_33( sf::Vector2f( 400.0f, 80.0f ) );
//sf::RectangleShape Obstacle_34( sf::Vector2f( 400.0f, 80.0f ) );
//sf::View look( sf::FloatRect( 0, 0, 1920, 1080 ) );
//
//struct Player
//{
//	string Name;
//	int Score;
//}Player_Info_Obj, Cur_Player;
//int Obstacle_Distance = 1000;
//class Dino_Game {
//	public:
//	
//	sf::Texture Back_Tex, Back_Tex2, Ground_Tex, Obs_1_Tex, Obs_3_Tex, Obs_2_Tex, Dino_Tex, Dino_Tex2, Dino_Tex_D, Dino_Tex_D2;
//	sf::Sprite spr, spr2;
//	sf::Text Highscore_Txt, Score_Txt, Highscore_Val, Score_Val, Game_Name;
//	sf::Font Score_Font, Mario_Font;
//	sf::Clock Dino_Clock, Gravity_Clock, Score_Clock, Obs_Clock;
//	sf::Time D1, T1, T2;
//	bool started = 0, Ground_Col = 0, collision = 0;
//	string Player_Name;
//	int Score = 0, Highscore = 0, found = 0, Player_Pos = 0;
//	float x = 1.0f, Ob_1_x = 1000;
//	bool Check_Obs_in_View( int X_Cordinate )
//	{
//		bool present = 0;
//		int LXL, LXR;
//		X_Cordinate = abs( X_Cordinate );
//		LXL = look.getCenter().x - 960;
//		LXR = look.getCenter().x + 960;
//		if (X_Cordinate <= LXR && X_Cordinate >= LXL)
//		{
//			present = 1;
//		}
//		else present = 0;
//		return present;
//	}
//	void Highscore_Getter()
//	{
//		ifstream fin( "Highscore.txt" );
//		fin >> Highscore;
//		fin.close();
//	}
//	int Ramdomize_Obstacle_Placement()
//	{
//		srand( time( 0 ) );
//		int distance = rand() % 300 + 700;
//		cout << "Distance = " << distance;
//		cout << endl;
//		int Obs_No 
//= rand() % 3 + 1;
//		cout << "Obstacle = " << Obs_No;
//		cout << endl;
//		Obstacle_Distance += distance;
//		int boool;
//		cout << "Obstacle Dist = " << Obstacle_Distance << endl;
//		if (Obs_No == 1)
//		{
//			if (Obstacle_Distance < look.getCenter().x + 1920)
//			{
//				boool = Check_Obs_in_View( Obstacle_1.getOrigin().x );
//				if (boool == 0)
//				{
//					cout << "selected Obstacle was 11" << endl;
//					cout << "View Centre = ";
//					cout << look.getCenter().x << endl;
//					cout << "Origin Before" << Obstacle_1.getOrigin().x << endl;
//					Obstacle_1.setOrigin( -Obstacle_Distance, -780 );
//					cout << "Origin After" << Obstacle_1.getOrigin().x << endl;
//					return 1;
//				}
//				boool = Check_Obs_in_View( Obstacle_12.getOrigin().x );
//				if (boool == 0)
//				{
//					Obstacle_12.setOrigin( -Obstacle_Distance, -780 );
//					return 1;
//				}
//				boool = Check_Obs_in_View( Obstacle_13.getOrigin().x );
//				if (boool == 0)
//				{
//					Obstacle_13.setOrigin( -Obstacle_Distance, -780 );
//					return 1;
//				}
//				boool = Check_Obs_in_View( Obstacle_14.getOrigin().x );
//				if (boool == 0)
//				{
//					Obstacle_14.setOrigin( -Obstacle_Distance, -780 );
//					return 1;
//				}
//			}
//			else Obstacle_Distance -= distance;
//		}
//		else if (Obs_No == 2)
//		{
//			if (Obstacle_Distance < look.getCenter().x + 1920)
//			{
//				if (!Check_Obs_in_View( Obstacle_2.getOrigin().x ))
//				{
//					Obstacle_2.setOrigin( -Obstacle_Distance, -730 );
//					return 1;
//				}
//				else if (!Check_Obs_in_View( Obstacle_22.getOrigin().x ))
//				{
//					Obstacle_22.setOrigin( -Obstacle_Distance, -730 );
//					return 1;
//				}
//				else if (!Check_Obs_in_View( Obstacle_23.getOrigin().x ))
//				{
//					Obstacle_23.setOrigin( -Obstacle_Distance, -730 );
//					return 1;
//				}
//				else if (!Check_Obs_in_View( Obstacle_24.getOrigin().x ))
//				{
//					Obstacle_24.setOrigin( -Obstacle_Distance, -730 );
//					return 1;
//				}
//			}
//			else Obstacle_Distance -= distance;
//
//		}
//		else if (Obs_No == 3)
//		{
//			if (Obstacle_Distance < look.getCenter().x + 1920)
//			{
//				if (!Check_Obs_in_View( Obstacle_3.getOrigin().x ))
//				{
//					Obstacle_3.setOrigin( -Obstacle_Distance, -730 );
//					return 1;
//				}
//				else if (!Check_Obs_in_View( Obstacle_32.getOrigin().x ))
//				{
//					Obstacle_32.setOrigin( -Obstacle_Distance, -730 );
//					return 1;
//				}
//				else if (!Check_Obs_in_View( Obstacle_33.getOrigin().x ))
//				{
//					Obstacle_33.setOrigin( -Obstacle_Distance, -730 );
//					return 1;
//				}
//				else if (!Check_Obs_in_View( Obstacle_34.getOrigin().x ))
//				{
//					Obstacle_34.setOrigin( -Obstacle_Distance, -730 );
//					return 1;
//				}
//			}
//			else Obstacle_Distance -= distance;
//
//		}
//	}
//
//	void Set_Attributes()
//	{
//		Highscore_Txt.setFont( Score_Font );
//		Highscore_Txt.setCharacterSize( 40 );
//		Highscore_Txt.setString( "High " );
//		Highscore_Txt.setOrigin( -1300, -150 );
//		Highscore_Txt.setFillColor( sf::Color::Black );
//		Highscore_Txt.setStyle( sf::Text::Style::Regular );
//
//		Highscore_Val.setFont( Score_Font );
//		Highscore_Val.setCharacterSize( 40 );
//		Highscore_Val.setString( to_string( Highscore ) );
//		Highscore_Val.setOrigin( -1500, -150 );
//		Highscore_Val.setFillColor( sf::Color::Black );
//		Highscore_Val.setStyle( sf::Text::Style::Regular );
//
//		Score_Val.setFont( Score_Font );
//		Score_Val.setCharacterSize( 40 );
//		Score_Val.setString( to_string( Score ) );
//		Score_Val.setOrigin( -1800, -150 );
//		Score_Val.setFillColor( sf::Color::Black );
//		Score_Val.setStyle( sf::Text::Style::Regular );
//
//		Score_Txt.setFont( Score_Font );
//		Score_Txt.setCharacterSize( 40 );
//		Score_Txt.setString( "Score " );
//		Score_Txt.setOrigin( -1600, -150 );
//		Score_Txt.setFillColor( sf::Color::Black );
//		Score_Txt.setStyle( sf::Text::Style::Regular );
//
//		Game_Name.setFont( Mario_Font );
//		Game_Name.setCharacterSize( 100 );
//		Game_Name.setString( "SUPER T-REX BROS" );
//		Game_Name.setOrigin( -500, -20 );
//		Game_Name.setFillColor( sf::Color::Red );
//		Game_Name.setStyle( sf::Text::Style::Bold );
//
//		Mario_Font.loadFromFile( "Mario_Font.ttf" );
//		Score_Font.loadFromFile( "Score_Font.ttf" );
//		Back_Tex.loadFromFile( "Mario Background.png" );
//
//		Obs_1_Tex.loadFromFile( "O1.png" );
//		Obs_2_Tex.loadFromFile( "O2.png" );
//		Obs_3_Tex.loadFromFile( "O3.png" );
//		spr.setTexture( Back_Tex );
//		spr2.setTexture( Back_Tex );
//
//		Gravity_Clock.restart();
//		Score_Clock.restart();
//	}
//	//void Set_Attributes2(string str)
//	//{
//	//	Mario_Font.loadFromFile( "Mario_Font.ttf" );
//	//	Game_Name.setFont( Mario_Font );
//	//	Game_Name.setCharacterSize( 100 );
//	//	Game_Name.setString( str );
//	//	Game_Name.setOrigin( -500, -20 );
//	//	Game_Name.setFillColor( sf::Color::Blue );
//	//	Game_Name.setStyle( sf::Text::Style::Bold );
//	//
//	//}
//	int i = 0, Back_X = 1920;
//	int Background_X = 1920;
//	int b1x = 0, b2x = 0, View_X;
//	int j = 2;
//	int DinoX_1 = 0, DinoY_1 = 0, DinoX_2 = 0, DinoY_2 = 0, DinoX_3 = 0, DinoY_3 = 0;
//	int Dist_Dino_Obs_1 = 0;
//	float View_Speed = 1;
//	int Main()
//	{
//		Obstacle_1.setOrigin( 10000, 10000 );
//		Obstacle_12.setOrigin( 10000, 10000 );
//		Obstacle_13.setOrigin( 10000, 10000 );
//		Obstacle_14.setOrigin( 10000, 10000 );
//		Obstacle_2.setOrigin( 10000, 10000 );
//		Obstacle_22.setOrigin( 10000, 10000 );
//		Obstacle_23.setOrigin( 10000, 10000 );
//		Obstacle_24.setOrigin( 10000, 10000 );
//		Obstacle_3.setOrigin( 10000, 10000 );
//		Obstacle_32.setOrigin( 10000, 10000 );
//		Obstacle_33.setOrigin( 10000, 10000 );
//		Obstacle_34.setOrigin( 10000, 10000 );
//		Highscore_Getter();
//		sf::RenderWindow window( sf::VideoMode( 1920, 1080 ), "T - REX", sf::Style::Close | sf::Style::Resize );
//		sf::SoundBuffer Jump_Buffer, Hit_Buffer;
//		Jump_Buffer.loadFromFile("Jump.wav");
//		Hit_Buffer.loadFromFile("Dead.wav");
//		sf::Sound Jump_Sound, Hit_Sound;
//		Jump_Sound.setBuffer( Jump_Buffer );
//		Hit_Sound.setBuffer( Hit_Buffer );
//
//		sf::Music Back_Music;
//		Back_Music.openFromFile( "Background.ogg" );
//
//		Dino_Tex.loadFromFile( "Dino Hind.png" );
//		Dino_Tex2.loadFromFile( "Dino Fore.png" );
//		Dino_Tex_D.loadFromFile( "Dino D Hind.png" );
//		Dino_Tex_D2.loadFromFile( "Dino D Fore.png" );
//
//
//
//		Set_Attributes();
//		Player.setOrigin( -500.0f, -200.0f );
//		Player_D.setOrigin( -500.0f, -275.0f );
//		Ground.setTexture( &Ground_Tex );
//		Ground.setOrigin( 0, -900 );
//		Player.setTexture( &Dino_Tex );
//		Player_D.setTexture( &Dino_Tex_D );
//		Obstacle_1.setTexture( &Obs_1_Tex );
//		Obstacle_12.setTexture( &Obs_1_Tex );
//		Obstacle_13.setTexture( &Obs_1_Tex );
//		Obstacle_14.setTexture( &Obs_1_Tex );
//		Obstacle_2.setTexture( &Obs_2_Tex );
//		Obstacle_22.setTexture( &Obs_2_Tex );
//		Obstacle_23.setTexture( &Obs_2_Tex );
//		Obstacle_24.setTexture( &Obs_2_Tex );
//		Obstacle_3.setTexture( &Obs_3_Tex );
//		Obstacle_32.setTexture( &Obs_3_Tex );
//		Obstacle_33.setTexture( &Obs_3_Tex );
//		Obstacle_34.setTexture( &Obs_3_Tex );
//		bool space = 0;
//		int something = 1;
//		int Obs_Distance = 1000, Obs_No = 1;
//		//spr2.setOrigin( 3840, 0 );
//		Obs_Clock.restart();
//		Back_Music.play();
//		Back_Music.setLoop( true );
//		while (window.isOpen())
//		{
//
//			switch (Score)
//			{
//				case 20: View_Speed = 1.1f;
//					break;
//				case 30: View_Speed = 1.2f;
//					break;
//				case 50: View_Speed = 1.8f;
//					break;
//				case 70: View_Speed = 1.9f;
//					break;
//				case 100:View_Speed = 2.0f;
//					break;
//			}
//			if (sf::Keyboard::isKeyPressed( sf::Keyboard::Q ))
//			{
//				look.move( -10, 0 );
//			}
//			if (sf::Keyboard::isKeyPressed( sf::Keyboard::E ))
//			{
//				look.move( 10, 0 );
//			}
//
//
//			sf::Event evnt;
//			while (window.pollEvent( evnt ))
//			{
//				switch (evnt.type)
//				{
//					case sf::Event::Closed:
//						window.close();
//						break;
//				}
//			}
//			if (started == 1)
//			{
//				T1 = Obs_Clock.getElapsedTime();
//				if (T1.asSeconds() >= 1)
//				{
//					Ramdomize_Obstacle_Placement();
//					Obs_Clock.restart();
//				}
//				//change_Dino();
//				T2 = Score_Clock.getElapsedTime();
//				look.move( View_Speed, 0 );
//				//Obstacle_1.move( -1, 0 );
//				if (sf::Keyboard::isKeyPressed( sf::Keyboard::S ))
//				{
//					if (i <= 20)
//					{
//						Player_D.setTexture( &Dino_Tex_D );
//					}
//					else if (i > 20)
//					{
//						Player_D.setTexture( &Dino_Tex_D2 );
//					}
//					if (i > 41)
//					{
//						i = 0;
//					}
//				}
//				else
//				{
//					if (i <= 20)
//					{
//						Player.setTexture( &Dino_Tex );
//					}
//					else if (i > 20)
//					{
//						Player.setTexture( &Dino_Tex2 );
//					}
//					if (i > 41)
//					{
//						i = 0;
//					}
//				}
//				i++;
//
//
//				View_X = look.getCenter().x;
//				if (View_X == b1x + Back_X)
//				{
//					b2x += j * Back_X;
//					spr2.setOrigin( -b2x, 0 );
//				}
//				if (View_X == b2x + Back_X)
//				{
//					b1x = b2x + j * Back_X;
//					spr.setOrigin( -b1x, 0 );
//				}
//			}
//			if (collision != 1 && T2.asMilliseconds() >= 500)
//			{
//				Score++;
//				Score_Val.setString( to_string( Score ) );
//				Score_Clock.restart();
//			}
//			//Obstacle_1.setOrigin( -1920, -780 );
//			//Obstacle_2.setOrigin( -2920, -730 );
//			//Obstacle_3.setOrigin( -3920, -730 );
//
//			//T1 = Obs_Clock.getElapsedTime();
//			//if (T1.asMilliseconds() > 5000)
//			//{
//			//	Ob_1_x += 5000;
//			//	Obs_Clock.restart();
//			//}
//			if (sf::Keyboard::isKeyPressed( sf::Keyboard::A ))
//			{
//				Player.move( -1.0f, 0 );
//				Player_D.move( -1.0f, 0 );
//			}
//			else if (sf::Keyboard::isKeyPressed( sf::Keyboard::D ))
//			{
//				Player.move( 1.0f, 0 );
//				Player_D.move( 1.0f, 0 );
//			}
//			if (sf::Keyboard::isKeyPressed( sf::Keyboard::Space ) && space == 0)
//			{
//				Jump_Sound.play();
//				x = -5;
//				space = 1;
//			}
//			else if (sf::Keyboard::isKeyPressed( sf::Keyboard::W ) && space == 0)
//			{
//				Jump_Sound.play();
//				x = -5;
//				space = 1;
//			}
//			if (Ground_Col == 0 || space == 1)
//			{
//				Player.move( 0, x );
//				Player_D.move( 0, x );
//			}
//			x += 0.025;
//
//
//			if (Player.getPosition().y + 150 + 200 >= 920)
//			{
//				Ground_Col = 1;
//				space = 0;
//			}
//			else Ground_Col = 0;
//			if (Player_D.getPosition().y + 150 + 200 >= 920)
//			{
//				Ground_Col = 1;
//				space = 0;
//			}
//			else Ground_Col = 0;
//
//			if (sf::Keyboard::isKeyPressed( sf::Keyboard::Space ))
//			{
//				started = 1;
//			}
//			DinoY_1 = abs( Player.getOrigin().y ) + abs( Player.getPosition().y );
//			DinoX_1 = look.getCenter().x - (960 - 500) + Player.getPosition().x;
//
//			if (DinoX_1 + 150 >= abs( Obstacle_1.getOrigin().x ) && DinoX_1 <= abs( Obstacle_1.getOrigin().x ) + 130)
//			{
//				if (DinoY_1 + 150 > 780)
//				{
//					Back_Music.pause();
//					Hit_Sound.play();
//					break;
//				}
//			}
//			DinoY_2 = abs( Player.getOrigin().y ) + abs( Player.getPosition().y );
//			DinoX_2 = look.getCenter().x - (960 - 500) + Player.getPosition().x;
//			if (DinoX_2 + 150 >= abs( Obstacle_2.getOrigin().x ) && DinoX_2 <= abs( Obstacle_2.getOrigin().x ) + 130)
//			{
//				if (DinoY_2 + 150 > 730)
//				{
//					Back_Music.pause();
//					Hit_Sound.play();
//					break;
//				}
//			}
//			DinoY_3 = abs( Player.getOrigin().y ) + abs( Player.getPosition().y );
//			DinoX_3 = look.getCenter().x - (960 - 500) + Player.getPosition().x;
//			if (DinoX_3 + 150 >= abs( Obstacle_3.getOrigin().x ) && DinoX_3 <= abs( Obstacle_3.getOrigin().x ) + 400)
//			{
//				if (!sf::Keyboard::isKeyPressed( sf::Keyboard::S ) && DinoY_3 + 150 > 730)
//				{
//					Back_Music.pause();
//					Hit_Sound.play();
//					break;
//				}
//			}
//			window.clear( sf::Color::White );
//
//			//View View
//
//			window.setView( look );
//			window.draw( spr );
//			window.draw( spr2 );
//			window.draw( Obstacle_1 );
//			window.draw( Obstacle_12 );
//			window.draw( Obstacle_13 );
//			window.draw( Obstacle_14 );
//			window.draw( Obstacle_2 );
//			window.draw( Obstacle_22 );
//			window.draw( Obstacle_23 );
//			window.draw( Obstacle_24 );
//			window.draw( Obstacle_3 );
//			window.draw( Obstacle_32 );
//			window.draw( Obstacle_33 );
//			window.draw( Obstacle_34 );
//			//Default View
//
//			window.setView( window.getDefaultView() );
//
//
//			if (sf::Keyboard::isKeyPressed( sf::Keyboard::S ))
//			{
//				window.draw( Player_D );
//			}
//			else
//			{
//				window.draw( Player );
//			}
//			window.draw( Highscore_Txt );
//			window.draw( Highscore_Val );
//			window.draw( Score_Val );
//			window.draw( Score_Txt );
//			window.draw( Game_Name );
//			window.display();
//		}
//		Delay( 3000 );
//		window.close();
//		system( "cls" );
//		cout << "you lost ! thanks for playing. Please Try Again";
//
//		if (Score > Highscore)
//		{		ofstream fout( "Highscore.txt" );
//			fout << Score;	fout.close();
//		}	
//
//		_getch();
//		return 0;
//	}
//};
//int main()
//{
//	Dino_Game obj;
//	obj.Main();
//	return 0;
//}