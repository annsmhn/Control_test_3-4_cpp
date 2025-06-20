#include "framework.h"
#include "Main.h"
#include <iostream>

using namespace std;

class Figure
{
protected:
public:
	virtual void Draw(HDC hdc, int x0, int y0, int r) = 0;
	virtual void Set_Colour(unsigned char r, unsigned char g, unsigned char b) = 0;
	virtual ~Figure() {};
};

class ElipseWithRadius : public Figure
{
private:
	int x0, y0, r;
	HPEN pen;

public:
	ElipseWithRadius(): x0(10), y0(10), r(5), pen(CreatePen(PS_SOLID, 0, RGB(255,255,255))){}
	void Draw(HDC hdc, int x0, int y0, int r) override
	{
		SelectObject(hdc,pen);
		Ellipse(hdc, x0, y0, x0+r, y0 + r);

		//выведена эмпирическим путем
		Rectangle(hdc, x0, y0+(r/2), x0 + (r / 2), y0 + (r / 2) + 2);
	}

	void Set_Colour(unsigned char r, unsigned char g, unsigned char b) override
	{
		pen = CreatePen(PS_SOLID, 0, RGB(r, g, b));
	}
	~ElipseWithRadius() 
	{

	};
};

