// template.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;
using namespace System;

ref class HouseTemplate abstract {
private:
	//default implementation
	void buildWindows() {
		Console::WriteLine("Building Glass Windows");
	}
	void buildFoundation() {
		Console::WriteLine("Building foundation with cement,iron rods and sand");
	}
public:
	void buildHouse(){
		buildFoundation();
		buildPillars();
		buildWalls();
		buildWindows();
		Console::WriteLine("House is built.");
	}

	//methods to be implemented by subclasses
	virtual void buildWalls()   = 0;
	virtual void buildPillars() = 0;
};

ref class WoodenHouse : HouseTemplate {
public:
	virtual void buildWalls() override  {
		Console::WriteLine("Building Wooden Walls");
	}

	virtual  void buildPillars() override {
		Console::WriteLine("Building Pillars with Wood coating");
	}
};

ref class GlassHouse : HouseTemplate {
public:
	virtual void buildWalls() override {
		Console::WriteLine("Building Glass Walls");
	}

	virtual void buildPillars() override {
		Console::WriteLine("Building Pillars with glass coating");
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	HouseTemplate^ houseType = gcnew WoodenHouse();
	//using template method
	houseType->buildHouse();
	Console::WriteLine("************");

	houseType = gcnew GlassHouse();

	houseType->buildHouse();
	Console::ReadLine();
	return 0;
}

