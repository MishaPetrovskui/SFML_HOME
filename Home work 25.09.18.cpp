#include <SFML/Graphics.hpp>;
#include <iostream>;
#include <Math.h>;

using namespace sf;
using namespace std;

Color MAIN_COLOR(57, 62, 173, 0);
int main()
{
	RenderWindow window(VideoMode({ 700,700 }), "SFML");

	CircleShape shape(50.f);
	shape.setFillColor(Color::Green);
	shape.setOrigin({ shape.getRadius(), shape.getRadius() });
	shape.setPosition({ 60, 60 });
	float shape_speed = 0.5f;
	Vector2f pos_of_mouse;
	Vector2f pos_of_mouse1;
	Vector2f direction(1, 0);
	while (window.isOpen())
	{
		while (const optional event = window.pollEvent())
		{
			if (event->is<Event::Closed>())
				window.close();
			if (event->is<Event::KeyPressed>() && event->getIf<Event::KeyPressed>()->code == Keyboard::Key::Escape)
				window.close();
			if (event->is<Event::KeyPressed>() && event->getIf<Event::KeyPressed>()->code == Keyboard::Key::Numpad1)
				MAIN_COLOR = Color::Blue;
			if (event->is<Event::KeyPressed>() && event->getIf<Event::KeyPressed>()->code == Keyboard::Key::Numpad2)
				MAIN_COLOR = Color::Red;
			if (event->is<Event::KeyPressed>() && event->getIf<Event::KeyPressed>()->code == Keyboard::Key::Numpad3)
				MAIN_COLOR = Color::Black;

			/*if (event->is<Event::KeyPressed>() && event->getIf<Event::KeyPressed>()->code == Keyboard::Key::D)
				shape.setPosition(shape.getPosition() + Vector2f(10, 0));
			if (event->is<Event::KeyPressed>() && event->getIf<Event::KeyPressed>()->code == Keyboard::Key::A)
				shape.setPosition(shape.getPosition() + Vector2f(-10, 0));
			if (event->is<Event::KeyPressed>() && event->getIf<Event::KeyPressed>()->code == Keyboard::Key::W)
				shape.setPosition(shape.getPosition() + Vector2f(0, -10));
			if (event->is<Event::KeyPressed>() && event->getIf<Event::KeyPressed>()->code == Keyboard::Key::S)
				shape.setPosition(shape.getPosition() + Vector2f(0, 10));*/

			if (event->is<Event::MouseButtonPressed>() && event->getIf<Event::MouseButtonPressed>()->button == Mouse::Button::Left)
			{
				//shape.setPosition((Vector2f)Mouse::getPosition(window));
				pos_of_mouse = (Vector2f)Mouse::getPosition(window);
			}
			if (event->is<Event::MouseButtonPressed>() && event->getIf<Event::MouseButtonPressed>()->button == Mouse::Button::Right)
			{
				//shape.setPosition((Vector2f)Mouse::getPosition(window));
				pos_of_mouse1 = (Vector2f)Mouse::getPosition(window);
				direction = { (pos_of_mouse1.x - shape.getPosition().x) / 150, (pos_of_mouse1.y - shape.getPosition().y) / 150 };
			}
			if (event->is<Event::MouseButtonPressed>() && event->getIf<Event::MouseButtonPressed>()->button == Mouse::Button::Middle)
			{
				shape.setRadius(shape.getRadius() + 1.f);
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Key::W) && shape.getPosition().y - shape.getRadius() > 0)
			shape.move({ 0, -0.5 });
		if (Keyboard::isKeyPressed(Keyboard::Key::S) && shape.getPosition().y + shape.getRadius() < window.getSize().y)
			shape.move({ 0, 0.5 });
		if (Keyboard::isKeyPressed(Keyboard::Key::A) && shape.getPosition().x - shape.getRadius() > 0)
			shape.move({ -0.5, 0 });
		if (Keyboard::isKeyPressed(Keyboard::Key::D) && shape.getPosition().x + shape.getRadius() < window.getSize().x)
			shape.move({ 0.5, 0 });

		/*if (shape.getPosition().x < pos_of_mouse.x)
			shape.move({ shape_speed, 0 });
		if (shape.getPosition().x > pos_of_mouse.x)
			shape.move({ -shape_speed, 0 });
		if (shape.getPosition().y < pos_of_mouse.y)
			shape.move({ 0, shape_speed });
		if (shape.getPosition().y > pos_of_mouse.y)
			shape.move({ 0, -shape_speed });*/

		/*if (abs(pos_of_mouse1.x - shape.getPosition().x) > 1 && abs(pos_of_mouse1.y - shape.getPosition().y) > 1)
		{
			shape.setPosition(shape.getPosition() + direction * shape_speed);
		}*/

		window.clear(MAIN_COLOR);
		window.draw(shape);
		window.display();
	}


	return 0;
}
