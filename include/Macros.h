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

const int WINDOWSIZEWIDTH = 1600;
const int WINDOWSIZEHEIGHT = 1080;
const int BOARDWIDTH = 1600;
const int BOARDHEIGHT = 899;
const int WIDTHSIZECALI = 25;
const int HEIGHTSIZECALI = 15;

//Define  the speeds for the moving objects
const float FALLINGSPEED = 250.f;
const  float HEROSPEED = 250.f ;
const  float ENEMYSPEED = 250.f;

const float RESTOREFLOORTIME = 5000;
const int GIFTSHOWTIME = 10000;

const int ADDTIMEGIFTTIME = 15;
const int HERODIGDELTATIME = 200;
const int NUMBEROFLEVELS = 4;
const int NUMBEROFLEVELBACKGROUD =4;

//This consts is for the player select in the menu
const int HEROASJERRY = 1;
const int HEROASRICK = 2;

const int COINVALUE = 50;

const int HEROSTARTLIFE = 3;
const int FACTORSCAL  = 25;
const int FRAMERATESPEED = 60;


