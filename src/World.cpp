#include "../headers/World.hpp"

World::World(){
    for (int i = 0; i < COLS; i++)
        for (int j = 0; j < ROWS; j++){
            this->Cells[i*COLS+j] = new Cell(CELL_SIZE, i, j);
        }

    Cells[18]->setParticle(new Particle(Types::SAND));
    Cells[25]->setParticle(new Particle(Types::SAND));
    Cells[32]->setParticle(new Particle(Types::SAND));


    Cell *tn[8];
    //Set neighborhood
    for (int i = 0; i < COLS; i++)
    for (int j = 0; j < ROWS; j++){
        tn[0] = this->Cells[(i)*COLS+(j+1)];
        tn[2] = this->Cells[(i)*COLS+(j-1)];
        tn[3] = this->Cells[(i+1)*COLS+(j-1)];
        tn[4] = this->Cells[(i+1)*COLS+(j)];
        tn[5] = this->Cells[(i+1)*COLS+(j+1)];
        tn[6] = this->Cells[(i-1)*COLS+(j-1)];
        tn[1] = this->Cells[(i-1)*COLS+(j)];
        tn[7] = this->Cells[(i-1)*COLS+(j+1)];

        this->Cells[i*COLS+j]->setNeighborhood(tn);
    }
};

void World::draw(sf::RenderTarget* w){
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++){
            Cells[i*COLS+j]->draw(w);
        };
};

void World::update(){
    for (int i = 0; i < COLS; i++)
        for (int j = 0; j < ROWS; j++){
            Cells[i*COLS+j]->update();
        };
};