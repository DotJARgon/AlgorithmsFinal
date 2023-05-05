/*
* Author: Team Team (Tristan Brown, Marcelo Carpenter, Thomas Cho,
*          Joshua Linnett, Aaron Mendoza, Harrison Williams)
* Assignment Title: Jigsaw Puzzle Group Project
* Assignment Description: This is board class implementation file
* Due Date: 5/4/2023
* Date Created: 4/27/2023
* Date Last Modified: 5/4/2023
 */


#include "Board.h"
#include "TextureLoader.h"
#include <random>

/*
     * description: updates the edges with deterministic random aspects
     *              (inlets, outlets, shapes, rotation, etc.)
     * return: void
     * precondition: input edges are not null
     * postcondition: input edges are randomly updated with puzzle aspects
     */
void randomEdge(Edge& e1, Edge& e2) {
    int r = rand()%5;
    if(r == 0) {
        e1 = CIRCLE_OUTLET;
        e2 = CIRCLE_INLET;
    }
    else if(r == 1) {
        e1 = CIRCLE_INLET;
        e2 = CIRCLE_OUTLET;
    }
    else if(r == 2) {
        e1 = SQUARE_INLET;
        e2 = SQUARE_OUTLET;
    }
    else if(r == 3) {
        e1 = SQUARE_OUTLET;
        e2 = SQUARE_INLET;
    }
    else {
        e1 = e2 = FLAT;
    }
}
/*
     * description: This is Board constructor; This will generate fundamental layer of
     *              puzzle game in provided dimensions, plotter, texture, and sounds
     * return: void
     * precondition: dimension values are positive, plotter and texture and soundHandler pointers
     *               are valid
     * postcondition: Board layer is generated
     */
Board::Board(int num_rows, int num_cols, PlotterTexture* plotter, PieceTexture* texture, SoundHandler* soundHandler) {
    this->num_rows = num_rows;
    this->num_cols = num_cols;
    this->plotter = plotter;
    this->texture = texture;
    this->soundHandler = soundHandler;
    this->mousex = 0;
    this->mousey = 0;
    this->clicked = false;
    this->winState = false;

    this->selected = nullptr;

    vector<vector<Piece*>> tempGrid;

    for(int i = 0; i < num_cols; i++) {
        vector<Piece*> row;
        for(int j = 0; j < num_rows; j++) {
            Piece* piece = new Piece(FLAT, CIRCLE_OUTLET, FLAT, CIRCLE_INLET);
            piece->absx = j;
            piece->absy = i;
            piece->gridx = (rand()%num_rows) + num_rows;
            piece->gridy = (rand()%num_cols);

            piece->x = 0.5*double(piece->gridx) / num_rows + 0.25 / num_rows;
            piece->y = double(piece->gridy) / num_cols + 0.5 / num_cols;

            piece->ux = double(j) / num_rows;
            piece->uy = double(i) / num_cols;
            piece->width = 1.0 / num_rows;
            piece->height = 1.0 / num_cols;
            piece->rotation = 0;
            piece->rows = num_rows;
            piece->cols = num_cols;
            //piece->isSelected = true;
            this->board.push_back(piece);
            row.push_back(piece);
        }

        tempGrid.push_back(row);
    }

    for(int i = 0; i < num_cols; i++) {
        for(int j = 0; j < num_rows; j++) {
            Piece* p = tempGrid.at(i).at(j);

            Edge e1, e2;
            randomEdge(e1, e2);

            p->right = e1;
            tempGrid.at(i).at((j + 1)%num_rows)->left = e2;

            randomEdge(e1, e2);

            p->bottom = e1;
            tempGrid.at((i + 1)%num_cols).at(j)->top = e2;
        }
    }

    for(int i = 0; i < num_cols; i++) {
        for(int j = 0; j < num_rows; j++) {
            Piece* p = tempGrid.at(i).at(j);

            if(j == 0) p->left = FLAT;
            else if(j == num_rows-1) p->right = FLAT;
            if(i == 0) p->top = FLAT;
            else if(i == num_cols-1) p->bottom = FLAT;
        }
    }

    for(Piece* p : this->board) {
        int rand = std::rand()%4;
        for(int i = 0; i < rand; i++) {
            p->rotate(RIGHT_ROT);
        }
    }

}

/*
     * description: Board Destructor
     * return: void
     * precondition: this board object has been properly initialized
     * postcondition: it has cleaned up the memory it has created
     */
Board::~Board() {
    //delete all pieces, only thing unique to this object
    for(Piece* piece : this->board) {
        delete piece;
    }
}

bool Board::getWinState() {
    return this->winState;
}


/*
     * description: validates winning scenario.
     * return: bool
     * precondition: program is running && no edges are held
     * postcondition: ends the gaming process and display/play winning effects
     */
bool Board::checkWin() {
    return this->winState;
}

/*
     * description: ActionHandler for mouse inputs
     * return: void
     * precondition: mouse is clicked
     * postcondition: corresponding action is performed
     */
void Board::step() {
    this->plotter->getPlotter()->getMouseLocation(mousex, mousey);
    clicked = this->plotter->getPlotter()->mouseClick();
    if(clicked) this->plotter->getPlotter()->getMouseClick();
    double screenx = double(mousex) / plotter->WIDTH;
    double screeny = double(mousey) / plotter->HEIGHT;
    //as long as it is not null
    if(this->selected != nullptr) {
        this->selected->x = screenx;
        this->selected->y = screeny;

        char key = this->plotter->getPlotter()->getKey();
        if(key == RIGHT_ARROW) {
            this->selected->rotate(RIGHT_ROT);
        }
        else if(key == LEFT_ARROW) {
            this->selected->rotate(LEFT_ROT);
        }
    }

    if(clicked && this->selected == nullptr) {
        grab(mousex, mousey);
        this->soundHandler->playGrab();
    }
    else if(clicked) {
        this->selected->setGrid();
        bool collision = false;
        bool allNeighbors = true;
        int neighborCount = 0;
        for(Piece* p : this->board) {
            //does not check right side of board
            if(p->gridx < this->num_rows) {
                if(p != this->selected) {
                    if(p->gridx == this->selected->gridx && p->gridy == this->selected->gridy) {
                        collision = true;
                        break;
                    }
                    if(p->isAdjacent(this->selected)) {
                        neighborCount++;
                        if(!p->canInterlock(this->selected)) {
                            collision = true;
                            break;
                        }
                        if(!this->selected->areNeighbors(p)) {
                            allNeighbors = false;
                        }
                    }
                }
            }
        }
        if(!collision) {
            this->selected->isSelected = false;
            this->selected = nullptr;

            this->winState = checkWin();

            this->soundHandler->playDrop();

            if(allNeighbors && neighborCount > 0) {
                this->soundHandler->playRight();
            }

            //we have won! play victory!
            if(this->winState) {
                this->soundHandler->playVictory();
            }
        }
        else {
            this->soundHandler->playFail();
        }
    }

    if(this->selected) {
        this->selected->setGrid();
    }
    clicked = false;
}

/*
     * description: Populates board layer with plots and texture
     * return: void
     * precondition: board is valid
     * postcondition: board is populated with texture and plotter
     */
void Board::draw() {
    //this->background->plot(plotter, 0, 0, 0.5, 1.0);
    for(int i = 0; i < plotter->HEIGHT; i++) {
        for(int j = -1; j < 2; j++) {
            this->plotter->writePixel(plotter->WIDTH / 2 + j, i, 0);
        }

    }
    for(Piece* p : this->board) {
        if(p != this->selected) p->drawSelf(texture, plotter);
    }
    if(this->selected != nullptr) this->selected->drawSelf(texture, plotter);
}
/*
     * description: ActionHandler for mouse input that handles picking up piece
     * return: void
     * precondition: mouse input is valid
     * postcondition: corresponding action is performed
     */
void Board::grab(int mousex, int mousey) {
    double screenx = double(mousex) / plotter->WIDTH;
    double screeny = double(mousey) / plotter->HEIGHT;

    double dist = INFINITY;

    this->selected = nullptr;

    for(Piece* p : this->board) {
        p->isSelected = false;
        double dx = p->x - screenx;
        double dy = p->y - screeny;
        double d = abs(dx) + abs(dy);
        if(d < dist) {
            dist = d;
            this->selected = p;
        }
    }

    this->selected->isSelected = true;
}