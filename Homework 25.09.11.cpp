#include <SFML/Graphics.hpp>;

using namespace sf;
using namespace std;

Color MAIN_COLOR(57, 62, 173, 0);
float speed = 0.1f;
int main()
{
	RenderWindow window(VideoMode({ 475,750 }), "SFML");

	Vertex figure[] =
	{
		{{0,0}, Color::Green, {0,0}},
		{{100,0}, Color::Green, {0,0}},
		{{50,0}, Color::Green, {0,0}},

		{{50,100}, Color::Blue, {0,0}},
		{{100,0}, Color::Blue, {0,0}},
		{{100,100}, Color::Blue, {0,0}}
	};
	bool toRight = rand() % 2;
	bool toDown = rand() % 2;
	CircleShape Circle(50);
	Circle.setPosition({ 0,0 });
	Circle.setFillColor(Color::Red);

	while (window.isOpen())
	{
		while (const optional event = window.pollEvent())
		{
			if (event->is<Event::Closed>())
				window.close();
		}

		float x = Circle.getPosition().x;
		float y = Circle.getPosition().y;
		float diameter = Circle.getRadius() * 2;

		window.clear(Color::White);
		//window.draw(figure, 6, PrimitiveType::Triangles);
		if (toRight)
			x += speed;
		else
			x -= speed;
		if (toDown)
			y += speed;
		else
			y -= speed;
		if (x + diameter >= window.getSize().x)
			toRight = false;
		if (x <= 0)
			toRight = true;
		if (y + diameter >= window.getSize().y)
			toDown = false;
		if (y <= 0)
			toDown = true;
		Circle.setPosition({ x,y });
		window.draw(Circle);
		window.display();
	}


	return 0;
}
