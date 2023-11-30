#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <string>
class Blocks 
{
protected:
	int* position; //位置
	bool Positionstatus = 1; //位置状态 1代表在运动 0代表以停止
	int** shape; //存储方块形状的属性 二维数组
	int wideshape;
	int longshape;
	std::map<std::string, std::string> positionMap;
public:
	int** getShape();
	int* getPosition();
	void setPosition(int* pos);
	int getWideshape();
	int getLongshape();
	void setPositionstatus(bool value);
	bool getPositionstatus();
	void setpositionMap();
	std::map<std::string, std::string> getpositionMap();
};     

