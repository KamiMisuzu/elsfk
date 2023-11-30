#include "Blocks.h"

int** Blocks::getShape()
{
	return this->shape;
}

int* Blocks::getPosition()
{
	return this->position;
}

void Blocks::setPosition(int* pos)
{
	this->position = pos;
}

int Blocks::getWideshape()
{
	return this->wideshape;
}

int Blocks::getLongshape()
{
	return this->longshape;
}

void Blocks::setPositionstatus(bool value)
{
	this->Positionstatus = value;
}

bool Blocks::getPositionstatus()
{
	return this->Positionstatus;
}

void Blocks::setpositionMap()
{
	this->positionMap.clear();
	int wide = this->getWideshape();
	int longs =  this->getLongshape();
	int** shape = this->getShape();
	int x = this->getPosition()[0];
	int y = this->getPosition()[1];
	int kuan = 0;
	int dlongs = 0;

	int* cabe = new int[wide * longs];
	int js = 0;
	for (int i = 0; i < wide; i++)
	{
		for (int j = 0; j < longs; j++) {
			cabe[js] = x + i;
			js++;
			cabe[js] = y + j;
			js++;
		}
	}
	int j = 0;
	int j2 = 0;
	int qz = 0;
	for (int i = 0; i < (wide * longs)/2; i++)
	{
		for (int z = 0; z < 2; z++)
		{
			std::string tempstr = std::to_string(cabe[j++]) + "," + std::to_string(cabe[j++]);
			std::string tempstr2 = std::to_string(shape[i][z]);
			this->positionMap[tempstr] = tempstr2;
		}    //020212

	}

}

std::map<std::string, std::string> Blocks::getpositionMap()
{
	return this->positionMap;
}
