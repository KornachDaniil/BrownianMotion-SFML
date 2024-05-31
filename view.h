#pragma once
#include <SFML/Graphics.hpp>
int viewX, viewY;
sf::View view;

void get_player_coordinate_for_view(float x, float y) { //функция для считывания координат игрока
	viewX = int(x); viewY = int(y);//считываем коорд игрока и проверяем их, чтобы убрать края
	view.setCenter(viewX, viewY); //следим за игроком, передавая его координаты камере. +100 - сместили камеру по иксу вправо. эксперементируйте
}
int getviewx() { return(viewX); }
int getviewy() { return(viewY); }
