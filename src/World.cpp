#include "../headers/World.hpp"

void World::setNeighborghood(int i, int j, int x, Cell *tn[8]){
    if(i<=0 || i>=COLS) tn[x]=nullptr;
    else if(j<= 0 || j >= ROWS) tn[x]=nullptr;
    else tn[x] = this->Cells[i][j];
};

void World::initCells(){
    for (int i = 0; i < COLS; i++)
    for (int j = 0; j < ROWS; j++){
        this->Cells[i][j] = new Cell(CELL_SIZE, i+x, j+y, this);
    }

    Cells[5][5]->setParticle(new Sand());
    Cells[5][6]->setParticle(new Sand());
    Cells[5][15]->setParticle(new Water());
    Cells[3][2]->setParticle(new Sand());


    Cell *tn[8];
    //Set neighborhood
    for (int i = 0; i < COLS; i++)
    for (int j = 0; j < ROWS; j++){
        setNeighborghood(i-1, j-1, 0, tn);
        setNeighborghood(i  , j-1, 1, tn);
        setNeighborghood(i+1, j-1, 2, tn);
        setNeighborghood(i+1, j  , 3, tn);
        setNeighborghood(i+1, j+1, 4, tn);
        setNeighborghood(i  , j+1, 5, tn);
        setNeighborghood(i-1, j+1, 6, tn);
        setNeighborghood(i-1, j  , 7, tn);
                                                                
        this->Cells[i][j]->setNeighborhood(tn);
    }

};

World::World(int x, int y){
    this->x = x;
    this->y = y;
    initCells();
};

World::World(){
    initCells();
};

void World::draw(sf::RenderTarget* w){
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++){
            Cells[i][j]->draw(w);
        };
};

void World::update(){
    for (int i = 0; i < COLS; i++)
        for (int j = 0; j < ROWS; j++){
            Cells[i][j]->update();
        };
    
    c cc;
    Particle *p;
    while(changes.size() > 0){
        p=changes.back().a->getParticle();
        changes.back().a->setParticle(changes.back().b->getParticle());
        changes.back().b->setParticle(p);
        changes.pop_back();
        p=nullptr;
    };
};

void World::setX(int x){ this->x = x; };
void World::setY(int y){ this->y = y; };

int World::getX(){ return this->x; };
int World::getY(){ return this->y; };

void World::stackChanges(Cell *a, Cell *b){
    c cc;
    cc.a = a;
    cc.b = b;
    this->changes.push_back(cc);
};

void World::newParticle(int i, int j){
    if(i < COLS && j < ROWS)
        if(Cells[i][j]->getParticle()==nullptr)
            if(floor(rand()%5)==1)
                Cells[i][j]->setParticle(new Sand());
            else
                Cells[i][j]->setParticle(new Water());


};
