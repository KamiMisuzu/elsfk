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
	int* position; //λ��
	bool Positionstatus = 1; //λ��״̬ 1�������˶� 0������ֹͣ
	int** shape; //�洢������״������ ��ά����
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

