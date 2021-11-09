#include "game1.h"
#include "datahandler.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define MAX_NUMBER_OF_SHIPS 7
#define MAX_NUMBER_OF_ENEMY_SHIPS 7

game1::game1(QWidget *parent) : QWidget(parent)
{
//    view = new QGraphicsView();
//    scene = new QGraphicsScene();

//    goodC = new QLabel("Good Coding Practices");
//    badC = new QLabel("Bad Coding Practices");

//    QGraphicsProxyWidget* pw = scene->addWidget(goodC);
//    QGraphicsProxyWidget* pw2 = scene->addWidget(badC);
//    pw->setPos(50,100);
//    pw2->setPos(300,100);

//    grid1 = new QGraphicsGridLayout();
//    grid2 = new QGraphicsGridLayout();

//    QGraphicsProxyWidget* pw3 = scene->add(grid1);
//    QGraphicsProxyWidget* pw4 = scene->addWidget(grid2);

//    scene->setSceneRect(0,0,500,500);
//    view->setFixedSize(600,600);
//    view->setScene(scene);

//    view->show();



    if(playing){
        widget = new QWidget();
        box = new QHBoxLayout();
        grid1 = new QGridLayout();
        grid2 = new QGridLayout();

        grid2->setSpacing(0);

        grid2->setContentsMargins(50,50,50,50);
        grid1->setContentsMargins(50,50,50,50);

        box->addLayout(grid1);
        box->addLayout(grid2);
       // box->setSpacing(5);
       // box->SetNoConstraint(5);
        //box->setContentsMargins(50,50,50,50);
        QVBoxLayout* vbl = new QVBoxLayout();
        QHBoxLayout* box2 = new QHBoxLayout();

        QLabel* label1 = new QLabel("                   Good Coding Practices");
        label1->setFont(QFont("Arial", 15, QFont::Bold));
        label1->setContentsMargins(50,0,50,0);
        QLabel* label2 = new QLabel("                   Bad Coding Practices");
        label2->setContentsMargins(50,0,50,0);
        label2->setFont(QFont("Arial", 15, QFont::Bold));
        box2->addWidget(label1);
        box2->addWidget(label2);
        box2->setSpacing(50);
        vbl->addLayout(box2);
        vbl->addLayout(box);
    //  grid1->addWidget(new QLabel("Good Coding Practices"),0,0);
    //  grid2->addWidget(new QLabel("Bad Coding Practices"),0,0);

    //  QSignalMapper mapper(this);



        for(int i = 0; i<16; i++){
            button* b = new button(i, false);
            QAction* action = new QAction();

            b->toolButton->setDefaultAction(action);
            connect(action, &QAction::triggered, [this,b]()
            {
                place(b);
            });

            b->toolButton->setIcon(QIcon(":/Battleship_images/square"));
            arr1.push_back(b);
        }

        ships_initialized = true;

        int k = 0;
        for(int i = 1; i<5; i++){
            for(int j = 0; j<4; j++){
                grid1->addWidget(arr1[k]->toolButton,i,j);
                k++;
            }
        }

        for(int i = 0; i<16; i++){
            button* b = new button(i, false);

            b->toolButton->setIcon(QIcon(":/Battleship_images/square"));
            arr2.push_back(b);

            QAction* action = new QAction();
            b->toolButton->setDefaultAction(action);
            connect(action, &QAction::triggered, [this,b,i]()
            {
                attempt(i, arr2);
            });
        }

        place_enemy(arr2);  //----------------------------------------------------------------------------

        int k2 = 0;
        for(int i = 1; i<5; i++){
            for(int j = 0; j<4; j++){
                grid2->addWidget(arr2[k2]->toolButton,i,j);
                k2++;
            }
        }



        widget->setLayout(vbl);
        widget->show();
     }  //if playing
//end game
//    while (ships_initialized == false); //wait for the ships to be initialized
//    while(number_of_ships != MAX_NUMBER_OF_SHIPS - 1);
//    ships_initialized = true;
//    while (number_of_attempts_left > 0 && number_of_ships != 0 && number_of_enemy_ships != 0); //wait for the game to end.

  // widget

//    QWidget* widget2 = new QWidget();
//    QGridLayout* gl = new QGridLayout();
//    QLabel* q = new QLabel("Game Over!");
//    q->setFont(QFont("Arial", 30, QFont::Bold));
//    gl->addWidget(q);
//    widget2->setLayout(gl);
//    widget2->show();
}

void game1::place(button* b){   //int index){
    if (choseShips) return;
    if(number_of_ships == 0 && (b->index == 0 || b->index==4 || b->index == 8 || b->index == 12 || b->index == 1 || b->index == 5 || b->index == 9 || b->index == 13)){
        arr1[b->index]->toolButton->setIcon(QIcon(":/Battleship_images/first"));
        arr1[b->index+1]->toolButton->setIcon(QIcon(":/Battleship_images/second"));
        arr1[b->index+2]->toolButton->setIcon(QIcon(":/Battleship_images/third"));
        b->ship=true;
        arr1[b->index+1]->ship=true;
        arr1[b->index+2]->ship=true;
        number_of_ships+=3;
    }
    if (!number_of_ships) return;
    else{

        if(number_of_ships < MAX_NUMBER_OF_SHIPS && b->ship == false){
            b->toolButton->setIcon(QIcon(":/Battleship_images/boat_small"));
            b->toolButton->setIconSize(QSize(100,100));
            b->ship = true;
            number_of_ships++;
           // std::cout << b->index << std::endl;
        }
        if (number_of_ships==MAX_NUMBER_OF_SHIPS)
        {
            choseShips=true;
        }

    //    if(number_of_ships == MAX_NUMBER_OF_SHIPS - 1){
    //        ships_initialized = true;
    //    }
        //arr1.takeAt(index)->toolButton->setIcon(QIcon(":/Battleship_images/boat_small"));
    }
}

void game1::place_enemy(QVector<button*> &vec){

    for (int i = 0; i<vec.size();i++){
        std::cout<<vec[i]->index<<std::endl;
    }

    srand(time(0));
    QVector<int> x;
    while( number_of_enemy_ships < MAX_NUMBER_OF_ENEMY_SHIPS){

        int y = rand() % 16;

        while(x.contains(y)){
           y = rand()  % 16;
        }

        std::cout << " THIS IS Y : " << y << std::endl;
        x.append(y);
        number_of_enemy_ships++;
        vec[y]->ship = true;
        //vec[y]->toolButton->setIcon(QIcon(":/Battleship_images/boat_small"));
        //vec.takeAt(x)->ship = true;
    }
}

void game1::attempt(int i, QVector<button*> &vec){
    if (!choseShips) return;
    if (number_of_attempts_left > 0 && number_of_ships != 0 && number_of_enemy_ships != 0 && ships_initialized){
        bool ans = false;
        if (vec[i]->ship) ans=question();
        if (ans){  //hit
                correct++;
                number_of_enemy_ships--;
                vec[i]->toolButton->setIcon(QIcon(":/Battleship_images/hit"));
                number_of_attempts_left--;

        }
        else{   //miss
            vec[i]->toolButton->setIcon(QIcon(":/Battleship_images/miss"));
            wrong++;
            for(int i = 0; i < arr1.size(); i++){
                if(arr1[i]->ship){
                    arr1[i]->ship = false;
                    arr1[i]->toolButton->setIcon(QIcon(":/Battleship_images/hit"));
                    number_of_ships--;
                    break;
                }
            }

            number_of_attempts_left--;


        }
    }
    if (correct==7)
    {
        widget->hide();
        QWidget* widget2 = new QWidget();
        QGridLayout* gl = new QGridLayout();
        QLabel* q = new QLabel("Congratulations! You are a coding expert!");
        q->setFont(QFont("Arial", 30, QFont::Bold));
        gl->addWidget(q);
        widget2->setLayout(gl);
        widget2->show();
    }
    if(number_of_attempts_left == 0 || number_of_ships == 0 || number_of_enemy_ships == 0|| wrong==4){

        widget->hide();
        QWidget* widget2 = new QWidget();
        QGridLayout* gl = new QGridLayout();
        QLabel* q = new QLabel("Game Over!");
        q->setFont(QFont("Arial", 30, QFont::Bold));
        gl->addWidget(q);
        widget2->setLayout(gl);
        widget2->show();
    }
}

bool game1::question(){
//        rand_nums.append(0);
//        srand(time(0));

//        while (rand_nums.contains(i))
//        {
//            i = rand()%16 + 1;
//        }

//        rand_nums.append(i);
        DataHandler h;
        srand(time(0));
        QVector<int> x;
        int size=h.arraySize();
        int y = rand() % size;

        while(x.contains(y)){
            y = rand()  % size;
        }

        x.append(y);


        QString quest = h.returnQues(y);
        QString ans1 = h.returnOption(y,1);
        QString ans2 = h.returnOption(y,2);
        QString ans3 = h.returnOption(y,3);

        QInputDialog* dl = new QInputDialog();
        dl->resize(500,500);
        QStringList items;
        bool ok = false;
        items << ans1 << ans2 << ans3;
        QString ans = dl->getItem(this, "Answer the following question", quest, items, 0, false, &ok);

        if (!ok) return false;
        QString correct = h.returnAns(y);
        qWarning() << ans << endl;

        if (ans == correct){
            return true;
        }

        return false;
}
