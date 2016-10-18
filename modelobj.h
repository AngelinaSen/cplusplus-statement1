
#ifndef _MODELOBJ_H
#define _MODELOBJ_H

#include <vector>
#include <fstream>
#include <iostream>

enum ObjectType {
	STORK,
	DRAGONFLY,
	FROG,
	HEDGEHOG
};

class ModelingObject {
public:
	ObjectType type;
	ModelingObject() {};
	ModelingObject(int a, int b, int c, int va, int vb, int vc, int s) {
		x = a;
		y = b;
		z = c;
		vx = va;
		vy = vb;
		vz = vc;
		sens = s;
		eatDistance = 1;
	}


	
	int canSense(ModelingObject* anotherObj);
	bool isObjectInArea();
	void changeDirection(ModelingObject* anotherObj);
	void takeStep();


	virtual bool isDangerous(ModelingObject* anotherObj) = 0;

	int getX() { return x; }
	int getY() { return y; }
	int getZ() { return z; }
	int getVX() { return vx; }
	int getVY() { return vy; }
	int getVZ() { return vz; }

protected:
	int x, y, z;
	int vx, vy, vz, sens;

	int eatDistance;
};

class Stork :public ModelingObject {
public:
	Stork(int a, int b, int c, int va, int vb, int vc, int s):ModelingObject(a, b, c, va, vb, vc, s){
		type = STORK;

	}

	//is another object dangerous for the current object 
	bool isDangerous(ModelingObject* anotherObj);


};

class Dragonfly :public ModelingObject {
public:
	Dragonfly(int a, int b, int c, int va, int vb, int vc, int s): ModelingObject(a, b, c, va, vb, vc, s){
		type = DRAGONFLY;
	}
	bool isDangerous(ModelingObject* anotherObj);

};

class Frog : public ModelingObject {
public:
	Frog(int a, int b, int va, int vb, int s): ModelingObject(a, b, 0, va, vb, 0, s){
		type = FROG;
		eatDistance = 3;
	}
	bool isDangerous(ModelingObject* anotherObj);
};

class Hedgehog : public ModelingObject {
public:
	Hedgehog(int a, int b, int va, int vb, int s):ModelingObject(a, b, 0, va, vb, 0, s){
		type = HEDGEHOG;
	}

	bool isDangerous(ModelingObject* anotherObj);
};

class InOut {
	char*  filename;
public:
	InOut(char* name) {
		filename = name;
	}
	std::vector<ModelingObject*> readTextFile();

};
#endif