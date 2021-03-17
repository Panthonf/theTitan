
#include <SFML/Graphics.hpp>
#include <time.h>
#include "Menu.h"
#include <iostream>
#include <sstream>
#include "menulose.h"
using namespace sf;


using namespace sf;

struct point
{
    int x, y;
};



void StartGameFunction() {

    //-------------------------------------------PararelBackground-------------------------------------------------------
    srand(time(0));
    RenderWindow window(VideoMode(400, 533), "The Moca Doodle Game!"); //ขนาดหน้าจอเกม
    window.setFramerateLimit(60);

    int x = 100, y = 100, h = 200;
    float dx = 0, dy = 0;
    int sum = 0;
    int score = 0;


    Texture t2, t3, t4, t5, t6, main;

    t2.loadFromFile("images/platform.png");
    t3.loadFromFile("images/doodle.png");
    t4.loadFromFile("images/backgroundlose.png");


    Sprite  sPlat(t2), sPers(t3), sBackgroundlose(t4);


    ///////////////////////////////////////////////////////

    sf::Texture texture; //สร้าง texture
    texture.loadFromFile("images/background1.png"); //เก็บค่าไฟล์ภาพไว้ใน texture

    
    //ตั้ง background เป็น texture เดียวกัน
    Sprite background1, background2;
    background1.setTexture(texture);
    background2.setTexture(texture);

    //กำหนดขนาดให้เท่าจอภาพ

    background1.setScale((float)window.getSize().x / texture.getSize().x, (float)window.getSize().y / texture.getSize().y);
    background2.setScale((float)window.getSize().x / texture.getSize().x, (float)window.getSize().y / texture.getSize().y);

    //ภาพ2ต่อท้ายภาพ1

    background2.setPosition(0, background1.getPosition().y - 533);

    float speed = 100.0f;  // ความเร็วของการเลื่อน 100
    float deltaTime = 0.0f;
    Clock clock;  //ใช้ Clock นับเวลาที่เปลี่ยนไป deltaTime

    point plat[10];

    for (int i = 0; i < 10; i++)
    {
        plat[i].x = rand() % 400;
        plat[i].y = rand() % 533;
    }

   
    while (window.isOpen())
    {  
        //Score Objects
        if (sum > 1) {
            score++;
        }
        Font arial;
        arial.loadFromFile("font/f1.ttf");

        std::ostringstream ssScore;
        ssScore << "SCORE: " << score;

        Text lblScore;
        lblScore.setCharacterSize(30);
        lblScore.setPosition({ 10,10 });
        lblScore.setFont(arial);
        lblScore.setString(ssScore.str());

        //---------------------------------------------------เปลี่ยน Background 2-------------------------------------------------------------//

        if (sum > 1000) { //เเวลาในการเปลี่ยนฉาก ตาม place//
            sum = 0;
            texture.loadFromFile("images/background2.png"); //เก็บค่าไฟล์ภาพไว้ใน texture
            ////////////////////////////////////////////////////////////////////////
            Sprite background1, background2;
            background1.setTexture(texture);
            background2.setTexture(texture);

            //กำหนดขนาดให้เท่าจอภาพ

            background1.setScale((float)window.getSize().x / texture.getSize().x, (float)window.getSize().y / texture.getSize().y);
            background2.setScale((float)window.getSize().x / texture.getSize().x, (float)window.getSize().y / texture.getSize().y);

            //ภาพ2ต่อท้ายภาพ1

            background2.setPosition(0, background1.getPosition().y - 533);

            float speed = 100.0f;  // ความเร็วของการเลื่อน 100
            float deltaTime = 0.0f;
            Clock clock;  //ใช้ Clock นับเวลาที่เปลี่ยนไป deltaTime

            point plat[10];

            for (int i = 0; i < 10; i++)
            {
                plat[i].x = rand() % 400;
                plat[i].y = rand() % 533;
            }


            while (window.isOpen())

            {
                if (sum > 1) {
                    score++;
                }
                Font arial;
                arial.loadFromFile("font/f1.ttf");

                std::ostringstream ssScore;
                ssScore << "SCORE: " << score;

                Text lblScore;
                lblScore.setCharacterSize(30);
                lblScore.setPosition({ 10,10 });
                lblScore.setFont(arial);
                lblScore.setString(ssScore.str());

                //--------------------------------------------------------เปลี่ยน Background 3---------------------------------------------------//
                if (sum > 10000) {
                    sum = 0;
                    texture.loadFromFile("images/background3.jpg"); //เก็บค่าไฟล์ภาพไว้ใน texture
                    ////////////////////////////////////////////////////////////////////////
                    Sprite background1, background2;
                    background1.setTexture(texture);
                    background2.setTexture(texture);

                    //กำหนดขนาดให้เท่าจอภาพ

                    background1.setScale((float)window.getSize().x / texture.getSize().x, (float)window.getSize().y / texture.getSize().y);
                    background2.setScale((float)window.getSize().x / texture.getSize().x, (float)window.getSize().y / texture.getSize().y);

                    //ภาพ2ต่อท้ายภาพ1

                    background2.setPosition(0, background1.getPosition().y - 533);

                    float speed = 100.0f;  // ความเร็วของการเลื่อน 100
                    float deltaTime = 0.0f;
                    Clock clock;  //ใช้ Clock นับเวลาที่เปลี่ยนไป deltaTime

                    point plat[10];

                    for (int i = 0; i < 10; i++)
                    {
                        plat[i].x = rand() % 400;
                        plat[i].y = rand() % 533;
                    }


                    while (window.isOpen())
                    {

                        //เมื่อเปิด window จับเวลาที่เปลี่ยนไป

                        deltaTime = clock.restart().asSeconds();

                        Event event;
                        while (window.pollEvent(event))
                        {
                            switch (event.type)
                            {
                            case Event::Closed:
                                window.close();
                                break;
                            }
                        }

                        if (background1.getPosition().y > 533)
                            background1.setPosition(0, background2.getPosition().y - 533);
                        if (background2.getPosition().y > 533)
                            background2.setPosition(0, background1.getPosition().y - 533);

                        //ขยับไปโดย ระยะทาง = ความเร็ว * เวลาที่เปลี่ยนไป

                        background1.move(0, speed * deltaTime);
                        background2.move(0, speed * deltaTime);

                        window.clear();
                        window.draw(background1);
                        window.draw(background2);


                        Event e;
                        while (window.pollEvent(e))
                        {
                            if (e.type == Event::Closed)
                                window.close();
                        }

                        if (Keyboard::isKeyPressed(Keyboard::Right)) x += 3;
                        if (Keyboard::isKeyPressed(Keyboard::Left)) x -= 3;
                        if (Keyboard::isKeyPressed(Keyboard::Space)) y -= 10;

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

                        window.draw(sPers);

                        for (int i = 0; i < 10; i++)
                        {

                            sPlat.setPosition(plat[i].x, plat[i].y);
                            window.draw(sPlat);
                        }



                        if (y > 490) {
                            dy = 0;
                            srand(time(0));
                            RenderWindow window(VideoMode(400, 533), "The Moca Doodle Game!"); //ขนาดหน้าจอเกม
                            window.setFramerateLimit(60);


                            menulose menu(window.getSize().x, window.getSize().y);
                            sf::Texture texture;
                            if (!texture.loadFromFile("images/background.png")) {

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

                                            
                                                switch (menu.GetPressItem())            //-------- กด Enter เพื่อเลือกเมนู ตามเคสต่าง ๆ ----------------------------
                                                {
                                                case 1: // ----------------------------------------Start Game-----------------------------------------------
                                                    window.clear();
                                                    window.close();
                                                    StartGameFunction();
                                                    break;

                                                case 2: // ----------------------------------------Exit Game-----------------------------------------------
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


                        }


                        window.display();

                    }
                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                }
                //เมื่อเปิด window จับเวลาที่เปลี่ยนไป

                deltaTime = clock.restart().asSeconds();

                Event event;
                while (window.pollEvent(event))
                {
                    switch (event.type)
                    {
                    case Event::Closed:
                        window.close();
                        break;
                    }
                }

                if (background1.getPosition().y > 533)
                    background1.setPosition(0, background2.getPosition().y - 533);
                if (background2.getPosition().y > 533)
                    background2.setPosition(0, background1.getPosition().y - 533);

                //ขยับไปโดย ระยะทาง = ความเร็ว * เวลาที่เปลี่ยนไป

                background1.move(0, speed * deltaTime);
                background2.move(0, speed * deltaTime);

                window.clear();
                window.draw(background1);
                window.draw(background2);


                Event e;
                while (window.pollEvent(e))
                {
                    if (e.type == Event::Closed)
                        window.close();
                }

                if (Keyboard::isKeyPressed(Keyboard::Right)) x += 3;
                if (Keyboard::isKeyPressed(Keyboard::Left)) x -= 3;
                if (Keyboard::isKeyPressed(Keyboard::Space)) y -= 10;

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

                //--------------------------------------เปลี่ยน background โดยใช้ค่า y-----------------------------------------------



                for (int i = 0; i < 10; i++)
                    if ((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 68)
                        && (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0))  dy = -10;

                sPers.setPosition(x, y);

                window.draw(sPers);

                for (int i = 0; i < 10; i++)
                {

                    sPlat.setPosition(plat[i].x, plat[i].y);
                    window.draw(sPlat);
                }



                if (y > 490) {
                    dy = 0;
                    srand(time(0));
                    RenderWindow window(VideoMode(400, 533), "The Moca Doodle Game!"); //ขนาดหน้าจอเกม
                    window.setFramerateLimit(60);


                    menulose menu(window.getSize().x, window.getSize().y);
                    sf::Texture texture;
                    if (!texture.loadFromFile("images/background.png")) {

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

                                   
                                        switch (menu.GetPressItem())            //-------- กด Enter เพื่อเลือกเมนู ตามเคสต่าง ๆ ----------------------------
                                        {
                                        case 1: // ----------------------------------------Start Game-----------------------------------------------
                                            window.clear();
                                            window.close();
                                            StartGameFunction();
                                            window.close();
                                            break;

                                        case 2: // ----------------------------------------Exit Game-----------------------------------------------
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


                }
                window.draw(lblScore);
                window.display();

            }
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        }
        //เมื่อเปิด window จับเวลาที่เปลี่ยนไป

        deltaTime = clock.restart().asSeconds();

        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                window.close();
                break;
            }
        }

        if (background1.getPosition().y > 533)
            background1.setPosition(0, background2.getPosition().y - 533);
        if (background2.getPosition().y > 533)
            background2.setPosition(0, background1.getPosition().y - 533);

        //ขยับไปโดย ระยะทาง = ความเร็ว * เวลาที่เปลี่ยนไป

        background1.move(0, speed * deltaTime);
        background2.move(0, speed * deltaTime);

        window.clear();
        window.draw(background1);
        window.draw(background2);


        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Right)) x += 3;
        if (Keyboard::isKeyPressed(Keyboard::Left)) x -= 3;
        if (Keyboard::isKeyPressed(Keyboard::Space)) y -= 10;


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

        //--------------------------------------เปลี่ยน background โดยใช้ค่า y-----------------------------------------------

        for (int i = 0; i < 10; i++)
            if ((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 68)
                && (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0))  dy = -10;

        sPers.setPosition(x, y);

        window.draw(sPers);

        for (int i = 0; i < 10; i++)
        {

            sPlat.setPosition(plat[i].x, plat[i].y);
            window.draw(sPlat);
        }

       

        if (y > 490) {
            dy = 0;
            srand(time(0));
            RenderWindow window(VideoMode(400, 533), "The Moca Doodle Game!"); //ขนาดหน้าจอเกม
            window.setFramerateLimit(60);


            menulose menu(window.getSize().x, window.getSize().y);
            sf::Texture texture;
            if (!texture.loadFromFile("images/background.png")) {

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

                                        switch (menu.GetPressItem())            //-------- กด Enter เพื่อเลือกเมนู ตามเคสต่าง ๆ ----------------------------
                                        {
                                        case 1: // ----------------------------------------Start Game-----------------------------------------------
                                           
                                            window.close();
                                            StartGameFunction();
                                            window.close();
                                            break;
                                            
                                        case 2: // ----------------------------------------Exit Game-----------------------------------------------
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
            
          
        }
        window.draw(lblScore);
        window.display();
       
    }

}

     //------------------------------------------Click-----------------------------------------------------------

void Click_() {
    //--------------------------------------ขนาดหน้าจอ window-------------------------------------------------
    srand(time(0));
    RenderWindow window(VideoMode(400, 533), "The Moca Doodle Game!"); //Title "The Moca Doodle Game!"
    window.setFramerateLimit(60);


    Menu menu(window.getSize().x, window.getSize().y);
    sf::Texture texture;
    if (!texture.loadFromFile("images/mainmenu.png")) {

    }
    sf::Sprite background;
    background.setTexture(texture);

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
                    int G = 10;

                    switch (menu.GetPressItem())            //-------- กด Enter เพื่อเลือกเมนู ตามเคสต่าง ๆ ----------------------------
                    {
                    case 1: // ----------------------------------------Start Game-----------------------------------------------
                        window.close();
                        StartGameFunction();
                        window.close();
                        break;
                    case 2: // ----------------------------------------Exit Game-----------------------------------------------
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


}

//-----------------------------------------------------------------Main-----------------------------------------------------------------------------------

int main()
{
    RenderWindow window(VideoMode(400, 533), "The Moca Doodle Game!"); //Title "The Moca Doodle Game!"
    window.setFramerateLimit(60);
    Click_();
    return 0;
}
