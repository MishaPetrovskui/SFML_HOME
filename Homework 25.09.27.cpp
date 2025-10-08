#include <SFML/Graphics.hpp>;
#include <iostream>;
#include <Math.h>;

using namespace sf;
using namespace std;

int randint(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}

const Font font("Inkfree.ttf");

char Knopka[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
	srand(time(0));
	RenderWindow window(VideoMode({ 1000,700 }), "SFML");

	int activeButton = 0;
	Text answers[4]
	{
		Text(font, "A", 50),
		Text(font, "B", 50),
		Text(font, "C", 50),
		Text(font, "D", 50)
	};
	int activequestion = 0;
	int correctAnswers[5] = { 2, 1, 3, 0, 2 };
	Text test[5]
	{
		Text(font, "Question 1: How many legs does a cat have?", 50),
		Text(font, "Question 2: What is the capital of England?", 50),
		Text(font, "Question 3 What is the capital of Australia?:", 50),
		Text(font, "Question 4: Choose the correct form of the verb: \"She ___ to the store yesterday.\"", 50),
		Text(font, "Question 5: Which word is a synonym of \"happy\"?", 50)
	};

	for (int i = 0; i < 4; i++)
	{
		if (i == activeButton)
			answers[i].setFillColor(Color::Red);
		answers[i].setPosition({ 50.f, 400.f + (float)(answers[i].getCharacterSize() * i) });
	}

	for (int i = 0; i < 5; i++)
		test[i].setFillColor(Color::Black);
	int correct = 0;
	bool finished = false;

	Clock clock;
	Text fpsText(font, " ", 20);
	fpsText.setFillColor(Color::Black);
	fpsText.setPosition({ 10.f, 10.f });

	/*int index = randint(0, 26);
	int clickCount = 0;
	Text text1(font, "Click for " + Knopka[index], 50);
	text1.setString("Clicked: " + to_string(clickCount++) + "times" + "Button: " + Knopka[index]);
	text1.setFillColor(Color::Black);*/

	while (window.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();
		float fps = (deltaTime > 0) ? 1.f / deltaTime : 0.f;
		fpsText.setString("FPS: " + to_string((int)fps));
		while (const optional event = window.pollEvent())
		{
			if (event->is<Event::Closed>())
				window.close();
			if (event->is<Event::KeyPressed>())
				if (event->getIf<Event::KeyPressed>()->code == Keyboard::Key::Escape)
					window.close();
			/*if (event->is<Event::KeyPressed>())
			{
				auto keyEvent = event->getIf<Event::KeyPressed>()->code;
				if (keyEvent == Keyboard::Key::Up)
					text1.setCharacterSize(text1.getCharacterSize()+1);
				if (keyEvent == Keyboard::Key::Down)
					text1.setCharacterSize(text1.getCharacterSize() - 1);
				if (text1.getCharacterSize() < 1)
					text1.setCharacterSize(1);
				if (text1.getCharacterSize() > 300)
					text1.setCharacterSize(300);
			}
			if (event->is<Event::KeyPressed>())
				if (event->getIf<Event::KeyPressed>()->code == (Keyboard::Key)index)
				{
					index = randint(0, 26);
					text1.setString("Clicked: " + to_string(clickCount++) + "times" + "Button: " + Knopka[index]);
				}*/
			if (!finished)
			{
				if (event->is<Event::KeyPressed>())
				{
					auto keyEvent = event->getIf<Event::KeyPressed>()->code;
					if (keyEvent == Keyboard::Key::Up)
						activeButton = max(0, activeButton - 1);
					if (keyEvent == Keyboard::Key::Down)
						activeButton = min(3, activeButton + 1);
					if (keyEvent == Keyboard::Key::Enter)
					{
						if (activeButton == correctAnswers[activequestion])
						{
							correct++;
							cout << "Correct!" << endl;
						}
						else
							cout << "Wrong!" << endl;

						activequestion++;
						activeButton = 0;
						if (activequestion >= 5)
							finished = true;
						sf::sleep(sf::milliseconds(200));
					}
				}
			}
		}
		/*cout << Knopka[index] << endl;
		cout << index << endl;
		if (clickCount < 10)
			text1.setFillColor(Color::Green);
		else if (clickCount >= 11 && clickCount < 30)
			text1.setFillColor(Color::Yellow);
		else if (clickCount > 30)
			text1.setFillColor(Color::Red);

		text1.setOrigin({ text1.getLocalBounds().size.x / 2.f, text1.getLocalBounds().size.y / 2.f });
		text1.setPosition({(window.getSize().x / 2.f), (window.getSize().y / 2.f) });*/
		window.clear(Color::White);
		window.draw(fpsText);
		if (!finished)
		{
			window.draw(test[activequestion]);

			if (activequestion == 0)
			{
				answers[0].setString("A. 2");
				answers[1].setString("B. 3");
				answers[2].setString("C. 4");
				answers[3].setString("D. 5");
			}
			else if (activequestion == 1)
			{
				answers[0].setString("A. Paris");
				answers[1].setString("B. London");
				answers[2].setString("C. Berlin");
				answers[3].setString("D. Madrid");
			}
			else if (activequestion == 2)
			{
				answers[0].setString("A. Sydney");
				answers[1].setString("B. Melbourne");
				answers[2].setString("C. Canberra");
				answers[3].setString("D. Brisbane");
			}
			else if (activequestion == 3)
			{
				answers[0].setString("A. went");
				answers[1].setString("B. go");
				answers[2].setString("C. goes");
				answers[3].setString("D. going");
			}
			else if (activequestion == 4)
			{
				answers[0].setString("A. sad");
				answers[1].setString("B. angry");
				answers[2].setString("C. joyful");
				answers[3].setString("D. tired");
			}

			for (int i = 0; i < 4; i++)
			{
				if (i == activeButton)
					answers[i].setFillColor(Color::Red);
				else
					answers[i].setFillColor(Color::Black);
				window.draw(answers[i]);
			}
		}
		else
		{
			Text result(font, "Your score: " + to_string(correct) + " / 5", 50);
			result.setFillColor(Color::Black);
			result.setPosition({ 200.f, 300.f });
			window.draw(result);
		}

		window.display();

	}


	return 0;
}
