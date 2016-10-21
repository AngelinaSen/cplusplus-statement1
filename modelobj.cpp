#include "modelobj.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

int ModelingObject::canSense(ModelingObject* anotherObj)
{
	int sens2 = sens*sens;
	int x2 = (x - anotherObj->x)*(x - anotherObj->x);
	int y2 = (y - anotherObj->y)*(y - anotherObj->y);
	int z2 = (z - anotherObj->z)*(z - anotherObj->z);
	if ((x2 + y2 + z2) < sens2) {
		return 1;
		//return true;
	}
	else
		return 0;
	//return false; 
}

bool ModelingObject::isObjectInArea() 
{
	if ((x > 0) && (x < 1000000) && (y > 0) && (y < 1000000) && (z > 0) && (z < 1000000)) 
	{
		return true;
	}
	else
		return false;
}

void ModelingObject::changeDirectionTo(ModelingObject* anotherObj)
{
	int speedModule = vx*vx + vy*vy + vz*vz;
	int distModule = (x - anotherObj->x)*(x - anotherObj->x) + (y - anotherObj->y)*(y - anotherObj->y) + (z - anotherObj->z)*(z - anotherObj->z);
	double lambda = sqrt(speedModule / distModule);
	double tvx = (x - anotherObj->x)*lambda;
	double tvy = (y - anotherObj->y)*lambda;
	double tvz = (z - anotherObj->z)*lambda;
	vx = (int)trunc(tvx);
	vy = (int)trunc(tvy);
	vz = (int)trunc(tvz);
}

void ModelingObject::changeDirectionFrom(ModelingObject * anotherObj)
{
	changeDirectionTo(anotherObj);
	vx = -vx;
	vx = -vy;
	vz = -vz;
}

void ModelingObject::takeStep()
{
	x = x + vx;
	y = y + vy;
	x = z + vz;
}



std::vector<ModelingObject*> InOut::readTextFile() {
	std::ifstream fin(filename);
	int D, DS, S, SS, F, FS, H, HS, N;
	fin >> D >> DS >> S >> SS >> F >> FS >> H >> HS >> N;

	int x, y, z, vx, vy, vz;
	int count = D + S + F + H; //общее число животных во входном файле
	std::vector<ModelingObject*> ObjectVec;
	ObjectVec.reserve(count);
	
	for (int i = 0; i < D; i++) {
		fin >> x >> y >> z >> vx >> vy >> vz;
		ModelingObject* tmp = new Dragonfly(x, y, z, vx, vy, vz, DS);
		ObjectVec.emplace_back(tmp);

	}
	for (int i = 0; i < S; i++) {
		fin >> x >> y >> z >> vx >> vy >> vz;
		ModelingObject* tmp = new Stork(x, y, z, vx, vy, vz, SS);
		ObjectVec.emplace_back(tmp);

	}
	for (int i = 0; i < F; i++) {
		fin >> x >> y >> vx >> vy;
		ModelingObject* tmp = new Frog(x, y, vx, vy, FS);
		ObjectVec.emplace_back(tmp);

	}
	for (int i = 0; i < H; i++) {
		fin >> x >> y >> vx >> vy;
		ModelingObject* tmp = new Hedgehog(x, y, vx, vy, HS);
		ObjectVec.emplace_back(tmp);

	}
	return ObjectVec;
}

bool Stork::isDangerous(ModelingObject* anotherObj) {
	return false;
}

bool Dragonfly::isDangerous(ModelingObject* anotherObj) {
	if ((anotherObj->type == FROG) || (anotherObj->type == STORK)) {
		return true;
	}
	else {
		return false;
	}
}
bool Frog::isDangerous(ModelingObject* anotherObj) {
	if ((anotherObj->type == STORK) || (anotherObj->type == HEDGEHOG)) {
		return true;
	}
	else {
		return false;
	}
}
bool Hedgehog::isDangerous(ModelingObject* anotherObj) {
	return false;
}