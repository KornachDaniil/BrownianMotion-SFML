#pragma once
#include <SFML/Graphics.hpp>
int viewX, viewY;
sf::View view;

void get_player_coordinate_for_view(float x, float y) { //������� ��� ���������� ��������� ������
	viewX = int(x); viewY = int(y);//��������� ����� ������ � ��������� ��, ����� ������ ����
	view.setCenter(viewX, viewY); //������ �� �������, ��������� ��� ���������� ������. +100 - �������� ������ �� ���� ������. �����������������
}
int getviewx() { return(viewX); }
int getviewy() { return(viewY); }
