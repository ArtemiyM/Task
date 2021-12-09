#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class geometryObj {
public:
	CircleShape octa;

	geometryObj() {
		octa.setPosition(250, 200);
		octa.setRadius(30.f);
		octa.setPointCount(8);
	}

	void draw(RenderWindow* window) {
		window->draw(octa);
	}

};

int main()
{
	srand(400);
	bool ismove = false;
	Color Cap;
	ContextSettings settings;
	settings.antialiasingLevel = 8;

	RenderWindow window(VideoMode(500, 300), "Task", Style::Default, settings);
		
	CircleShape circle(50.f);
	circle.setFillColor(Color(230, 0, 230)); 
	circle.setOutlineThickness(5.f); 
	circle.setOutlineColor(Color(80, 220, 50)); 
	circle.move(15, 15); 

	geometryObj circle1;
	circle1.octa.setFillColor(Color::Magenta);
	

	// Создаем треугольник
	CircleShape triangle(65.f, 3);
	triangle.setPosition(125, 15); 
	triangle.setFillColor(Color::Blue); 


	// Создаем квадрат
	CircleShape square(60.f, 4);
	square.setPosition(250, 15);
	square.setFillColor(Color::Red); 
	

	RectangleShape rectangle(Vector2f(70.f, 100.f));
	rectangle.move(165, 150);
	rectangle.setFillColor(Color(175, 180, 240));
	

	while (window.isOpen())
	{
		Vector2i mousePos = Mouse::getPosition(window);
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::C)
				{
					int r = rand() % 255, g = rand() % 255, b = rand() % 255;
					std::cout << "the c key was pressed" << std::endl;
					Cap = Color(r, g, b, 255);
					window.clear(Cap);

				}
			}
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.key.code == Mouse::Left)
				{
					if (circle.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						ismove = true;
					}
					std::cout << "mouse left key was pressed" << std::endl;
				}
			}
			if (event.type == Event::MouseButtonReleased) {
				if (event.key.code == Mouse::Left) {
					ismove = false;
				}
			}
			if (ismove == true) {
				circle.setPosition(mousePos.x, mousePos.y);
			}
			// Отрисовка окна
			window.clear(Cap);
			circle1.draw(&window);
			window.draw(circle);
			window.draw(triangle);
			window.draw(square);
			window.draw(rectangle);
			window.display();
		}
	}

	return 0;
}
