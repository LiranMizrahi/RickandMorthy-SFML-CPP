//
// Created by Liran Mizrahi on 11/16/2020.
//
#pragma once
//this is const for read from file
const char COIN = '*';
const char ENEMY = '%';
const char HERO = '@';
const char LADDER = 'H';
const char ROPE = '-';
const char SPACE = ' ';
const char FLOOR = '#';
const char GIFT = '+';


const int	LEFT = 1;
const int	RIGHT = 2;
const int	UP = 3;
const int	DOWN = 4;


const int BOARDWIDTH = 1600;
const int BOARDHEIGHT = 899;
const int WIDTHSIZECALI = 25;
const int HEIGHTSIZECALI = 15;

//define all speeds of moving objects
const float FALLINGSPEED = 300.f;
const  float HEROSPEED = 350.f ;
const  float ENEMYSPEED = 300.f;
const int NUMBEROFLEVELS = 2;

//this consts is for the player select in the menu
const int HEROASJERRY = 1;
const int HEROASRICK = 2;

