
#include <SFML/Graphics.hpp>
#include <time.h>
#include "Menu.h"
#include <iostream>
using namespace sf;


using namespace sf;

struct point
{
    int x, y;
};

void StartGameFunction() {

    srand(time(0));
    RenderWindow window(VideoMode(400, 533), "The Moca Doodle Game!"); //ขนาดหน้าจอเกม
    window.setFramerateLimit(60);

    Texture t1, t2, t3, t4, t5, t6, main;
    t1.loadFromFile("images/background.png");
    t2.loadFromFile("images/platform.png");
    t3.loadFromFile("images/doodle.png");
    t4.loadFromFile("images/backgroundlose.png");

    t5.loadFromFile("images/background2.jpg");
    t6.loadFromFile("images/");

    Sprite sBackground(t1), sPlat(t2), sPers(t3), sBackgroundlose(t4), background2(t5), background3(t6);



    point plat[10];

    for (int i = 0; i < 10; i++)
    {
        plat[i].x = rand() % 400;
        plat[i].y = rand() % 533;
    }

    int x = 100, y = 100, h = 200;
    float dx = 0, dy = 0;
    int sum = 0;


    while (window.isOpen())
    {

        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
        }




        if (Keyboard::isKeyPressed(Keyboard::Right)) x += 3;
        if (Keyboard::isKeyPressed(Keyboard::Left)) x -= 3;
        // if (Keyboard::isKeyPressed(Keyboard::Space )) y -= 10;

        dy += 0.2;
        y += dy;
        if (y > 500)  dy = -10;



        if (y < h)
            for (int i = 0; i < 10; i++)
            {
                y = h;
                plat[i].y = plat[i].y - dy;
                if (plat[i].y > 533) { plat[i].y = 0; plat[i].x = rand() % 400; }
                sum = sum + 1;
            }

        for (int i = 0; i < 10; i++)
            if ((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 68)
                && (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0))  dy = -10;

        sPers.setPosition(x, y);



        window.draw(sBackground);
        window.draw(sPers);

        if (sum >= 10000) {
            window.draw(background2);
            window.draw(sPers);
        }


        for (int i = 0; i < 10; i++)
        {

            sPlat.setPosition(plat[i].x, plat[i].y);
            window.draw(sPlat);
        }



        if (y > 490) {
            dy = 0;
            window.clear();
            window.draw(sBackgroundlose);
        }

        window.display();
    }

}




int main()
{
    srand(time(0));
    RenderWindow window(VideoMode(400, 533), "The Moca Doodle Game!"); //ขนาดหน้าจอเกม
    window.setFramerateLimit(60);

    /////////////////////////Mainmenu/////////////////////////////////////////////////////////////////////////////////////////////////////////
    Menu menu(window.getSize().x, window.getSize().y);
    sf::Texture texture;
    if (!texture.loadFromFile("images/background.png")){

    }
    sf::Sprite background;
    background.setTexture(texture);

    window.setFramerateLimit(60);



    while (window.isOpen())
    {
        Event e;
        while (window.pollEvent(e))
        {
            switch (e.type)
            {
            case sf::Event::KeyReleased:
                switch (e.key.code)
                {
                case sf::Keyboard::Up:
                    menu.MoveUp();
                    break;

                case sf::Keyboard::Down:
                    menu.MoveDown();
                    break;

                case sf::Keyboard::Return:
                    switch (menu.GetPressItem())            // กด Enter เพื่อเลือกเมนู ตามเคสต่าง ๆ
                    {
                    case 1: // Start Game
                        StartGameFunction();
                        break;
                    case 2: // Exit Game
                        window.close();
                        break;
                    }


                    break;
                }
                break;

            case sf::Event::Closed:
                window.close();
                break;
            }
        }

        window.clear();
        window.draw(background);
        menu.draw(window);
        window.display();

    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   
    //load pararell
    
  

    return 0;
}
