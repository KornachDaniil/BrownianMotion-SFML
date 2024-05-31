#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <Windows.h>
#include <time.h>
#include <string>
#include "view.h"
using namespace sf;
using namespace std;

class molsstuff 
{
public:
	float xs, ys, x, y, a;
};

void Set_xs_ys(molsstuff stuff[], float& speedmol, float& cs, float& sn)
{
	for (int i = 0; i < 1000; i++)
	{
		cs = cos(stuff[i].a * 0.0175);
		sn = sin(stuff[i].a * 0.0175);
		stuff[i].xs = speedmol * cs;
		stuff[i].ys = speedmol * sn;
	}
}

void Set_Texture_s_mol(Sprite s_mol[], Texture &mol_t)
{
	for (int i = 0; i < 9; i++) s_mol[i].setTexture(mol_t);
	// Установка размеров текстуры для кнопок
	s_mol[0].setTextureRect(IntRect(0, 0, 85, 85));
	s_mol[1].setTextureRect(IntRect(85, 0, 85, 85));
	s_mol[2].setTextureRect(IntRect(170, 0, 85, 85));
	s_mol[3].setTextureRect(IntRect(0, 85, 85, 85));
	s_mol[4].setTextureRect(IntRect(85, 85, 85, 85));
	s_mol[5].setTextureRect(IntRect(170, 85, 85, 85));
	s_mol[6].setTextureRect(IntRect(0, 170, 85, 85));
	s_mol[7].setTextureRect(IntRect(85, 170, 85, 85));
	s_mol[8].setTextureRect(IntRect(170, 170, 85, 85));
}

void Test(molsstuff stuff[], float& speedmol, float& cs, float& sn, int &i, int &u)
{
	cs = cos(stuff[i].a * 0.0175);
	sn = sin(stuff[i].a * 0.0175);
	stuff[i].xs = speedmol * cs;
	stuff[i].ys = speedmol * sn;
	cs = cos(stuff[u].a * 0.0175);
	sn = sin(stuff[u].a * 0.0175);
	stuff[u].xs = speedmol * cs;
	stuff[u].ys = speedmol * sn;
}

void Set_Position_s_mol(Sprite s_mol[], Sprite& s_exit, int &sw, int &sh)
{
	get_player_coordinate_for_view(int(sw / 2), int(sh / 2));
	if (true)
	{// Установка позиции кнопок веществ
		s_mol[0].setPosition(getviewx() - 85 - 43, getviewy() - 85 - 43);
		s_mol[1].setPosition(getviewx() - 43, getviewy() - 85 - 43);
		s_mol[2].setPosition(getviewx() + 43, getviewy() - 85 - 43);
		s_mol[3].setPosition(getviewx() - 85 - 43, getviewy() - 43);
		s_mol[4].setPosition(getviewx() - 43, getviewy() - 43);
		s_mol[5].setPosition(getviewx() + 43, getviewy() - 43);
		s_mol[6].setPosition(getviewx() - 85 - 43, getviewy() + 43);
		s_mol[7].setPosition(getviewx() - 43, getviewy() + 43);
		s_mol[8].setPosition(getviewx() + 43, getviewy() + 43);
		s_exit.setPosition(getviewx() + int(sw / 2) - 126, getviewy() - int(sh / 2)); // Установка позиции кнопки выхода
	}
}

void Set_Position_s_stuff(Sprite s_stuff[], int& sw, int& sh, float &stuffy)
{
	// Установка позции интерфейса изменения входных данных 
	s_stuff[0].setPosition(getviewx() - int(sw / 2) + int(sw / 455) + 87, getviewy() - int(sh / 2) + 56 + stuffy);
	s_stuff[1].setPosition(getviewx() - int(sw / 2) + int(sw / 455) + 87 + 58, getviewy() - int(sh / 2) + 56 + stuffy);
	s_stuff[2].setPosition(getviewx() - int(sw / 2) + int(sw / 455) + 87 + 87, getviewy() - int(sh / 2) + 56 + stuffy);
	s_stuff[3].setPosition(getviewx() - int(sw / 2) + int(sw / 455) + 87 + 116, getviewy() - int(sh / 2) + 56 + stuffy);
	s_stuff[4].setPosition(getviewx() - int(sw / 2) + int(sw / 455), getviewy() - int(sh / 2) + 85 + stuffy);
	s_stuff[5].setPosition(getviewx() - int(sw / 2) + int(sw / 455) + 58, getviewy() - int(sh / 2) + 85 + stuffy);
	s_stuff[6].setPosition(getviewx() - int(sw / 2) + int(sw / 455) + 87, getviewy() - int(sh / 2) + 85 + stuffy);
	s_stuff[7].setPosition(getviewx() - int(sw / 2) + int(sw / 455) + 116, getviewy() - int(sh / 2) + 85 + stuffy);
	s_stuff[8].setPosition(getviewx() - int(sw / 2) + int(sw / 455), getviewy() - int(sh / 2) + 56 + stuffy);
	s_stuff[9].setPosition(getviewx() - int(sw / 2) + int(sw / 455) + 87 + 116 + 58, getviewy() - int(sh / 2) + 56 + stuffy);
}

void Set_the_Texture_Size_s_stuff(float cds[], Sprite s_stuff[])
{
	// Установка размерности текстуры у интерфеса изменения входных данных
	if (cds[0] < 100) s_stuff[0].setTextureRect(IntRect(0, 29, 57, 28)); else s_stuff[0].setTextureRect(IntRect(0, 0, 57, 28));
	if (cds[1] < 100) s_stuff[1].setTextureRect(IntRect(57, 29, 28, 28)); else s_stuff[1].setTextureRect(IntRect(57, 0, 28, 28));
	if (cds[2] < 100) s_stuff[2].setTextureRect(IntRect(85, 29, 28, 28)); else s_stuff[2].setTextureRect(IntRect(85, 0, 28, 28));
	if (cds[3] < 100) s_stuff[3].setTextureRect(IntRect(113, 29, 57, 28)); else s_stuff[3].setTextureRect(IntRect(113, 0, 57, 28));
	if (cds[4] < 100) s_stuff[4].setTextureRect(IntRect(0, 29, 57, 28)); else s_stuff[4].setTextureRect(IntRect(0, 0, 57, 28));
	if (cds[5] < 100) s_stuff[5].setTextureRect(IntRect(57, 29, 28, 28)); else s_stuff[5].setTextureRect(IntRect(57, 0, 28, 28));
	if (cds[6] < 100) s_stuff[6].setTextureRect(IntRect(85, 29, 28, 28)); else s_stuff[6].setTextureRect(IntRect(85, 0, 28, 28));
	if (cds[7] < 100) s_stuff[7].setTextureRect(IntRect(113, 29, 57, 28)); else s_stuff[7].setTextureRect(IntRect(113, 0, 57, 28));
	if (cds[8] < 100) s_stuff[8].setTextureRect(IntRect(256, 29, 86, 28)); else s_stuff[8].setTextureRect(IntRect(256, 0, 86, 28));
	if (cds[9] < 100) s_stuff[9].setTextureRect(IntRect(170, 29, 86, 28)); else s_stuff[9].setTextureRect(IntRect(170, 0, 86, 28));
}

int main()
{
	srand(time(NULL));
	int sw = 1280 /*GetSystemMetrics(SM_CXSCREEN)*/; // Разрешение 
	int sh = 720 /*GetSystemMetrics(SM_CYSCREEN)*/; // экрана
	int qofmols;
	bool start_simulation = false;
	bool interaction_mode = false;
	bool collision_mode = true;
	bool following_mode = false;
	float speedmol;
	float temp = 0;
	float gasmass = 1;
	float gasmolmass;
	float molgasmolmass;
	float cs; // cos
	float sn; // sin
	float r; // Радиус частицы
	float stuffy = -5;
	float cd = 0;
	float cds[10];
	Uint8 color_button_is_false = 205U; //Цвет интерфейса Выкл 
	Uint8 color_button_is_true = 255U; // Цвет интерфейса ВКЛ
	int color[3];
	color[0] = 0;
	color[1] = 0;
	color[2] = 0;
	for (int i = 0; i < 10; i++) // Инициализация
		cds[i] = 0;

	Font font;
	font.loadFromFile("font.ttf");
	Text text("", font, 24);
	text.setFillColor(Color(170, 170, 170));
	text.setStyle(sf::Text::Bold);

	Image exit_image;
	exit_image.loadFromFile("images/exitimage.png");
	exit_image.createMaskFromColor(Color(color_button_is_true, color_button_is_true, color_button_is_true));
	Texture exit_t;
	exit_t.loadFromImage(exit_image);
	Sprite s_exit;
	s_exit.setTexture(exit_t);
	s_exit.setPosition(0, 0);

	Image interaction_mode_image;
	interaction_mode_image.loadFromFile("images/interaction_mode_image.png");
	interaction_mode_image.createMaskFromColor(Color(color_button_is_true, color_button_is_true, color_button_is_true));
	Texture interaction_mode_t;
	interaction_mode_t.loadFromImage(interaction_mode_image);
	Sprite s_interaction_mode;
	s_interaction_mode.setTexture(interaction_mode_t);
	s_interaction_mode.setPosition(0, 0);

	Image collision_mode_image;
	collision_mode_image.loadFromFile("images/collision_mode_image.png");
	collision_mode_image.createMaskFromColor(Color(color_button_is_true, color_button_is_true, color_button_is_true));
	Texture collision_mode_t;
	collision_mode_t.loadFromImage(collision_mode_image);
	Sprite s_collision_mode;
	s_collision_mode.setTexture(collision_mode_t);
	s_collision_mode.setPosition(0, 0);

	Image following_mode_image;
	following_mode_image.loadFromFile("images/following_mode_image.png");
	following_mode_image.createMaskFromColor(Color(color_button_is_true, color_button_is_true, color_button_is_true));
	Texture following_mode_t;
	following_mode_t.loadFromImage(following_mode_image);
	Sprite s_following_mode;
	s_following_mode.setTexture(following_mode_t);
	s_following_mode.setPosition(0, 0);

	Image reset_image;
	reset_image.loadFromFile("images/resetimage.png");
	reset_image.createMaskFromColor(Color(color_button_is_true, color_button_is_true, color_button_is_true));
	Texture reset_t;
	reset_t.loadFromImage(reset_image);
	Sprite s_reset;
	s_reset.setTexture(reset_t);
	s_reset.setPosition(0, 0);

	Image stuff_image;
	stuff_image.loadFromFile("images/stuff.png");
	stuff_image.createMaskFromColor(Color(color_button_is_true, color_button_is_true, color_button_is_true));
	Texture stuff_t;
	stuff_t.loadFromImage(stuff_image);
	Sprite s_stuff[10];
	for (int i = 0; i < 10; i++) s_stuff[i].setTexture(stuff_t);

	Image mol_image;
	mol_image.loadFromFile("images/molecules.png");
	mol_image.createMaskFromColor(Color(color_button_is_true, color_button_is_true, color_button_is_true));
	Texture mol_t;
	mol_t.loadFromImage(mol_image);

	// Создание кнопок выбора необходимого вещества
	Sprite s_mol[9];
	Set_Texture_s_mol(s_mol, mol_t);

	CircleShape shapeshow[1000];
	molsstuff stuff[1000];

	RenderWindow window(sf::VideoMode(sw, sh), "Simulation", Style::Default);
	window.setVerticalSyncEnabled(true);
	view.reset(sf::FloatRect(0, 0, sw, sh));
	window.setPosition(Vector2i(0, 0));
	Clock clock;

	Set_Position_s_mol(s_mol, s_exit, sw, sh); // Установка позиции кнопок веществ

	// Установка базового цвета кнопок интерфейса
	if (!interaction_mode)
		s_interaction_mode.setColor(Color(color_button_is_false, color_button_is_false, color_button_is_false));
	else
		s_interaction_mode.setColor(Color(color_button_is_true, color_button_is_true, color_button_is_true));
	if (!collision_mode)
		s_collision_mode.setColor(Color(color_button_is_false, color_button_is_false, color_button_is_false));
	else
		s_collision_mode.setColor(Color(color_button_is_true, color_button_is_true, color_button_is_true));
	if (!following_mode)
		s_following_mode.setColor(Color(color_button_is_false, color_button_is_false, color_button_is_false));
	else
		s_following_mode.setColor(Color(color_button_is_true, color_button_is_true, color_button_is_true));

	while (window.isOpen())
	{
		if (start_simulation)
		{ // start_simulation == true
			float time = clock.getElapsedTime().asMilliseconds();
			clock.restart();
			if (cd < 41) 
				cd += time;
			for (int i = 0; i < 10; i++) if (cds[i] < 101) cds[i] += time;
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				s_exit.setColor(Color::Green);
				window.draw(s_exit);
				window.display();
				Sleep(300);
				window.close();
			}
			//Данные положения курсора
			Vector2i pixelPos = Mouse::getPosition(window);
			Vector2f pos = window.mapPixelToCoords(pixelPos);
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				if (event.type == Event::MouseButtonPressed)
				{//если нажата клавиша мыши
					if (event.key.code == Mouse::Left)
					{//а именно левая

						float _speedmol = (sqrt(3 * (temp + 273)) * 0.4175 * 1.17) / sqrt(molgasmolmass); // Расчитываем скорость малекул
						int _gofmols = int((gasmass / gasmolmass) * 1000);

						if (s_exit.getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт s_exit
						{
							s_exit.setColor(Color::Green);
							window.draw(s_exit);
							window.display();
							Sleep(300);
							window.close();
						}
						if (s_interaction_mode.getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт s_interaction_mode
						{
							interaction_mode = !interaction_mode;
							if (!interaction_mode) // Выкл
								s_interaction_mode.setColor(Color(color_button_is_false, color_button_is_false, color_button_is_false));
							else // Вкл
								s_interaction_mode.setColor(Color(color_button_is_true, color_button_is_true, color_button_is_true));
							window.draw(s_interaction_mode);
							window.display();
							Sleep(700);
							for (int i = 0; i < 1000; i++) shapeshow[i].setFillColor(Color(color[0], color[1], color[2]));
						}
						if (s_collision_mode.getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт s_collision_mode
						{
							collision_mode = !collision_mode;
							if (!collision_mode) // Выкл
								s_collision_mode.setColor(Color(color_button_is_false, color_button_is_false, color_button_is_false));
							else // Вкл
								s_collision_mode.setColor(Color(color_button_is_true, color_button_is_true, color_button_is_true));
							window.draw(s_collision_mode);
							window.display();
							Sleep(700);
						}
						if (s_following_mode.getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт s_following_mode
						{
							following_mode = !following_mode;
							if (!following_mode) // Выкл
								s_following_mode.setColor(Color(color_button_is_false, color_button_is_false, color_button_is_false));
							else // Вкл
								s_following_mode.setColor(Color(color_button_is_true, color_button_is_true, color_button_is_true));
							window.draw(s_following_mode);
							window.display();
							Sleep(700);
						}
						if (s_reset.getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт s_reset
						{
							s_reset.setColor(Color::Green);
							window.draw(s_reset);
							window.display();
							Sleep(300);
							start_simulation = false;
							for (int i = 0; i < 9; i++) 
								s_mol[i].setColor(Color(color_button_is_true, color_button_is_true, color_button_is_true));
							s_reset.setColor(Color(color_button_is_true, color_button_is_true, color_button_is_true));
						}
						if (cds[0] > 100 && s_stuff[0].getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт s_stuff[0] // Temp --
						{
							if (cd > 40)
							{
								if (temp > -223) 
									temp -= 1500; 
								else 
									temp = -273;
								cd = 0;
								cds[0] = 0;
								speedmol = _speedmol;
								Set_xs_ys(stuff, speedmol, cs, sn);
							}
						}
						if (cds[1] > 100 && s_stuff[1].getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт s_stuff[1] // Temp -
						{
							if (temp > -273 && cd > 40)
							{
								temp -= 500;
								cd = 0;
								cds[1] = 0;
								speedmol = _speedmol;
								Set_xs_ys(stuff, speedmol, cs, sn);
							}
						}
						if (cds[2] > 100 && s_stuff[2].getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт s_stuff[2] // Temp +
						{
							if (cd > 40)
							{
								temp += 500;
								cd = 0;
								cds[2] = 0;
								speedmol = _speedmol;
								Set_xs_ys(stuff, speedmol, cs, sn);
							}
						}
						if (cds[3] > 100 && s_stuff[3].getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт s_stuff[3] // Temp ++
						{
							if (cd > 40)
							{
								temp += 1500;
								cd = 0;
								cds[3] = 0;
								speedmol = _speedmol;
								Set_xs_ys(stuff, speedmol, cs, sn);
							}
						}
						if (cds[4] > 100 && s_stuff[4].getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт s_stuff[4] // Mass --
						{
							if (cd > 40 && gasmass > 1)
							{
								gasmass -= 1;
								cd = 0;
								cds[4] = 0;
								qofmols = _gofmols;
							}
						}
						if (cds[5] > 100 && s_stuff[5].getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт s_stuff[5] // Mass -
						{
							if (cd > 40 && gasmass > 0.11)
							{
								gasmass -= 0.1;
								cd = 0;
								cds[5] = 0;
								qofmols = _gofmols;
							}
						}
						if (cds[6] > 100 && s_stuff[6].getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт s_stuff[6] // Mass +
						{
							if (cd > 40 && qofmols < 990)
							{
								gasmass += 0.1;
								cd = 0;
								cds[6] = 0;
								qofmols = _gofmols;
							}
						}
						if (cds[7] > 100 && s_stuff[7].getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт s_stuff[7] // Mass ++
						{
							if (cd > 40 && qofmols < 890)
							{
								gasmass += 1;
								cd = 0;
								cds[7] = 0;
								qofmols = _gofmols;
							}
						}
						if (cds[8] > 100 && s_stuff[8].getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт s_stuff[8] // Temp ---
						{
							if (cd > 40)
							{
								if (temp > 217) 
									temp -= 3000; 
								else 
									temp = -273;
								cd = 0;
								cds[8] = 0;
								speedmol = _speedmol;
								Set_xs_ys(stuff, speedmol, cs, sn);
							}
						}
						if (cds[9] > 100 && s_stuff[9].getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт s_stuff[9] // Temp +++
						{
							if (cd > 40)
							{
								temp += 3000;
								cd = 0;
								cds[9] = 0;
								speedmol = _speedmol;
								Set_xs_ys(stuff, speedmol, cs, sn);
							}
						}
					}
				}
			}
			//`````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

			if (gasmass < 0.1) 
				gasmass = 0.1;



			// Передвижение частиц
			for (int i = 0; i < qofmols; i++)
			{
				stuff[i].x += stuff[i].xs * time / 1000;
				stuff[i].y += stuff[i].ys * time / 1000;
				if (stuff[i].x > sw + r) stuff[i].x = 0 - r + 1;
				if (stuff[i].y > sh + r) stuff[i].y = 0 - r + 1;
				if (stuff[i].x < 0 - r) stuff[i].x = sw + r - 1;
				if (stuff[i].y < 0 - r) stuff[i].y = sh + r - 1;
				shapeshow[i].setPosition(stuff[i].x, stuff[i].y);
			}


			if (interaction_mode == true || collision_mode == true)
			{ ///////////////
				for (int i = 0; i < qofmols; i++)
				{
					float min = 255;
					for (int u = 0; u < qofmols; u++)
					{
						if (i != u)
						{
							// Часто вычисляемые значения:
							// 1.
							float _stuff_x = stuff[i].x - stuff[u].x;
							float _stuff_y = stuff[i].y - stuff[u].y;

							float da = sqrt(_stuff_x * _stuff_x + _stuff_y * _stuff_y); // Смотреть "Часто вычисляемые значения" пункт 1
							if (da < min)
								min = da;
							if (min > 255)
								min = 255;
							if (da < r * 2 && collision_mode == true)
							{
								float _time = time / 1000;
								/*float _stuff_i_x_xs = stuff[i].x + stuff[i].xs * _time;
								float _stuff_u_x_xs = stuff[u].x + stuff[u].xs * _time;
								float _stuff_i_y_ys = stuff[i].y + stuff[i].ys * _time;
								float _stuff_u_y_ys = stuff[u].y + stuff[u].ys * _time;*/
								float a1, a2;
								a1 = (stuff[i].a + stuff[u].a) / 2;
								a2 = a1 + 180;
								if (a1 > 360)
									a1 = a1 - 360;
								if (a2 > 360)
									a2 = a2 - 360;
								stuff[i].a = a1;
								stuff[u].a = a2;
								Test(stuff, speedmol, cs, sn, i, u);
								float da1 = sqrt(((stuff[i].x + stuff[i].xs * _time) - (stuff[u].x + stuff[u].xs * _time)) * ((stuff[i].x + stuff[i].xs * _time) - (stuff[u].x + stuff[u].xs * _time)) + ((stuff[i].y + stuff[i].ys * _time) - (stuff[u].y + stuff[u].ys * _time)) * ((stuff[i].y + stuff[i].ys * _time) - (stuff[u].y + stuff[u].ys * _time)));

								if (da1 < da)
								{
									stuff[i].a = a2;
									stuff[u].a = a1;
									Test(stuff, speedmol, cs, sn, i, u);
								}
							}
						}
					}
					if (interaction_mode == true)
					{
						int newcolor[3];
						newcolor[0] = min;
						newcolor[1] = min;
						newcolor[2] = min;
						if (color[0] - 1 < newcolor[0]) newcolor[0] = int(color[0]) - 1;
						if (color[1] - 1 < newcolor[1]) newcolor[1] = int(color[1]) - 1;
						if (color[2] - 1 < newcolor[2]) newcolor[2] = int(color[2]) - 1;
						shapeshow[i].setFillColor(Color(color[0] - (newcolor[0]), color[1] - (newcolor[1]), color[2] - (newcolor[2])));
					}
				}
			} ///////////////
			if (following_mode == true)
			{
				stuff[0].x = pos.x;
				stuff[0].y = pos.y;
			}

			window.setView(view);
			window.clear(Color(30, 30, 30, 0));
			window.getSystemHandle();

			if (pos.y > 126)
			{
				if (stuffy > -127)
					stuffy -= 0.3 * time;
			}
			else if (stuffy < -2)
				stuffy += 0.6 * time;

			Set_Position_s_stuff(s_stuff, sw, sh, stuffy); // Установка позции интерфейса изменения входных данных 
			Set_the_Texture_Size_s_stuff(cds, s_stuff); // Установка размерности текстуры у интерфеса изменения входных данных

			// Одинаковый результат для вычисления отрисовки интерфейса
			int csh = int(sh / 2);
			int csw = int(sw / 2);
			float x = getviewx() + csw;
			float y = getviewy() - csh;

			for (int i = 0; i < qofmols; i++) window.draw(shapeshow[i]); // Отрисовка частиц 
			// Отрисовка кнопок модов и ресет с выходом
			s_exit.setPosition(x - 126, y + stuffy);
			window.draw(s_exit);
			s_reset.setPosition(x - 252, y + stuffy);
			window.draw(s_reset);
			s_interaction_mode.setPosition(x - 378, y + stuffy);
			window.draw(s_interaction_mode);
			s_collision_mode.setPosition(x - 504, y + stuffy);
			window.draw(s_collision_mode);
			s_following_mode.setPosition(x - 630, y + stuffy);
			window.draw(s_following_mode);

			// Вывод температуры 
			std::ostringstream thing_temp;
			thing_temp << "Temp ";
			thing_temp << int(temp);
			thing_temp << " C";
			text.setString(thing_temp.str());//задаем строку тексту и вызываем сформированную выше строку методом .str() 
			text.setPosition(getviewx() - int(sw / 2) + int(sw / 455), getviewy() - int(sh / 2) + stuffy);//задаем позицию текста, отступая от центра камеры
			window.draw(text);

			// Вывод массы
			std::ostringstream thing_mass;
			thing_mass << "Mass ";
			thing_mass << gasmass;
			thing_mass << " kg";
			text.setString(thing_mass.str());//задаем строку тексту и вызываем сформированную выше строку методом .str() 
			text.setPosition(getviewx() - int(sw / 2) + int(sw / 455), getviewy() - int(sh / 2) + 28 + stuffy);//задаем позицию текста, отступая от центра камеры
			window.draw(text);

			for (int i = 0; i < 10; i++)
				window.draw(s_stuff[i]); // Отрисовка кнопок для увеличения Temp и Mass
			window.display();
		} 

		else
		{ // start_simulation == false
			float time = clock.getElapsedTime().asMilliseconds();
			clock.restart();
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				s_exit.setColor(Color::Green);
				window.draw(s_exit);
				window.display();
				Sleep(300);
				window.close();
			}
			//Данные положения курсора//
			Vector2i pixelPos = Mouse::getPosition(window);
			Vector2f pos = window.mapPixelToCoords(pixelPos);
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				if (event.type == Event::MouseButtonPressed)
				{//если нажата клавиша мыши
					if (event.key.code == Mouse::Left)
					{//а именно левая
						if (s_exit.getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт s_exit
						{// Кнопка выхода из игры
							s_exit.setColor(Color::Green);
							window.draw(s_exit);
							window.display();
							Sleep(300);
							window.close();
						}
						for (int i = 0; i < 9; i++)
						{
							if (s_mol[i].getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт s_mol[i]
							{// Интерфейс для выбора вещества для симуляции
								s_mol[i].setColor(Color::Red);
								window.draw(s_mol[i]);
								window.display();
								Sleep(500);
								gasmass = 1;
								temp = 0;
								int mol;
								mol = i + 1;
								switch (mol)
								{// Преднастройка радиуса частиц(r) и массы в зависимости от выбранного типа вещества
								case 1:
									gasmolmass = 6.6;
									molgasmolmass = 4;
									r = 4;
									break;
								case 2:
									gasmolmass = 3.3;
									molgasmolmass = 2;
									r = 5;
									break;
								case 3:
									gasmolmass = 26.7;
									molgasmolmass = 32;
									r = 6;
									break;
								case 4:
									gasmolmass = 46, 5;
									molgasmolmass = 28;
									r = 6.5;
									break;
								case 5:
									gasmolmass = 73;
									molgasmolmass = 44;
									r = 7;
									break;
								case 6:
									gasmolmass = 100;
									molgasmolmass = 64;
									r = 7;
									break;
								case 7:
									gasmolmass = 58;
									molgasmolmass = 71;
									r = 7.5;
									break;
								case 8:
									gasmolmass = 28.3;
									molgasmolmass = 17;
									r = 10;
									break;
								case 9:
									gasmolmass = 26.6;
									molgasmolmass = 16;
									r = 5;
									break;
								}
								qofmols = int((gasmass / gasmolmass) * 1000);
								speedmol = (sqrt(3 * (temp + 273)) * 0.4175 * 1.17) / sqrt(molgasmolmass);
								for (int i = 0; i < 1000; i++)
								{
									shapeshow[i].setRadius(r); // Установка радиуса для частиц
									switch (mol)
									{// Пред установка цвета частиц в зависимости от выбранного типа вещества
									case 1:
										color[0] = 60;
										color[1] = 197;
										color[2] = 255;
										shapeshow[i].setFillColor(Color(60, 197, 255));
										break;
									case 2:
										color[0] = 255;
										color[1] = 159;
										color[2] = 190;
										shapeshow[i].setFillColor(Color(255, 159, 190));
										break;
									case 3:
										color[0] = 153;
										color[1] = 217;
										color[2] = 234;
										shapeshow[i].setFillColor(Color(153, 217, 234));
										break;
									case 4:
										color[0] = 193;
										color[1] = 193;
										color[2] = 193;
										shapeshow[i].setFillColor(Color(193, 193, 193));
										break;
									case 5:
										color[0] = 138;
										color[1] = 130;
										color[2] = 142;
										shapeshow[i].setFillColor(Color(138, 130, 142));
										break;
									case 6:
										color[0] = 255;
										color[1] = 249;
										color[2] = 128;
										shapeshow[i].setFillColor(Color(255, 249, 128));
										break;
									case 7:
										color[0] = 47;
										color[1] = 215;
										color[2] = 97;
										shapeshow[i].setFillColor(Color(47, 215, 97));
										break;
									case 8:
										color[0] = 191;
										color[1] = 129;
										color[2] = 254;
										shapeshow[i].setFillColor(Color(191, 129, 254));
										break;
									case 9:
										color[0] = 295;
										color[1] = 155;
										color[2] = 89;
										shapeshow[i].setFillColor(Color(255, 155, 89));
										break;
									}
									shapeshow[i].setOrigin(r, r);
									stuff[i].x = rand() % 1336; // Рандомная позиция по X
									stuff[i].y = rand() % 768; // Рандомная позиция по Y
									shapeshow[i].setPosition(stuff[i].x, stuff[i].y); // Спавн частицы
									if (true)
									{
										stuff[i].a = rand() % 360;
										cs = cos(stuff[i].a * 0.0175);
										sn = sin(stuff[i].a * 0.0175);
										stuff[i].xs = speedmol * cs;
										stuff[i].ys = speedmol * sn;
									}
								}
								start_simulation = true;
								stuffy = -2;
							}
						}
					}
				}
			}

			window.setView(view);
			window.clear(Color(30, 30, 30, 0));
			window.getSystemHandle();

			window.draw(s_exit);
			for (int i = 0; i < 9; i++)
				window.draw(s_mol[i]);

			window.display();
		}
	}

	return 0;
}