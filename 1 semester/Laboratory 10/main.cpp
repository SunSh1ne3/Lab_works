/*Вариант 6.
Создайте N(0 < N < 100) квадратов.Перемещайте их из исходного положения влево до конца экрана с 
разной скоростью.При достижении конца экрана остановите фигуры*/


#include <SFML/Graphics.hpp>
#include<thread>
#include<chrono>
#include <vector>
#include <iostream>
#include <Rectangle.hpp>

using namespace std::chrono_literals;
using namespace mt;

int main()
{
    srand(time(0));
     int N = 7;
    int a = 40;
    bool T = true;
    bool F = false;
    sf::Texture texture;
    if (!texture.loadFromFile("space.jpg"))
    {
        std::cout << "File space.jpg not found!" << std::endl;
        return -1;
    }
    sf::Sprite background(texture);

    float x0 = 800, y0 = 800;
    sf::RenderWindow window(sf::VideoMode(x0, y0), L"Лаба №10 работает.");

    //создаем массив для фигур
    std::vector<mt::Rectangle*> Rectangles;
    for (int i = 0; i < y0; i += y0 / N)
    {
        Rectangles.push_back(new Rectangle(x0 - a / 2, i + a, a, rand() % 15+10, T));
    }

    //окошко
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //отскок
        for (const auto& Rectangle : Rectangles)
        {
            if (Rectangle->Get_L())
            {
                Rectangle->Move();
                if (Rectangle->Get_x() <= 0+a/1.5)
                {
                    Rectangle->Set_L(F);
                    Rectangle->Skorost(rand() % 10 + 1);
                    Rectangle->Move();

                }
            }

            else if (!Rectangle->Get_L())
            {
                Rectangle->Move1();

                if (Rectangle->Get_x() >= x0 - a/1.5 )
                {
                    Rectangle->Set_L(T);
                    Rectangle->Skorost(rand() % 10 + 1);
                    Rectangle->Move1();
                }
            }

        }




        window.clear();

        window.draw(background);
        //перемещение в буфер
        for (const auto& Rectangle : Rectangles)
        {
            window.draw(*Rectangle->Get());
        }

        window.display();

        std::this_thread::sleep_for(40ms);
    }

    for (const auto& Rectangle : Rectangles)
    {
        delete Rectangle;
    }
    Rectangles.clear();

    return 0;
}