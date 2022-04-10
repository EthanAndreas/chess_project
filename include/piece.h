#ifndef PIECE
#define PIECE

#include <iostream>
#include <string>

#include "enum.h"
using namespace std;

class Piece {

  private:
    Color color;
    string name;

  public:
    Piece(Color col, string str);

    ~Piece();

    void print();

    Color get_color() const;
    string get_name() const;

    bool get_castling() const;
    void set_castling();

    Movement is_valid_move(int init_x, int init_y, int dest_x,
                           int dest_y, Piece *chess_tab[8][8]) const;
};

class Bishop : public Piece {

  public:
    Bishop(Color col, string str);

    Movement is_valid_move(int init_x, int init_y, int dest_x,
                           int dest_y, Piece *chess_tab[8][8]) const;
};

class Knight : public Piece {

  public:
    Knight(Color col, string str);

    Movement is_valid_move(int init_x, int init_y, int dest_x,
                           int dest_y, Piece *chess_tab[8][8]) const;
};

class Queen : public Piece {

  public:
    Queen(Color col, string str);

    Movement is_valid_move(int init_x, int init_y, int dest_x,
                           int dest_y, Piece *chess_tab[8][8]) const;
};

class Rook : public Piece {

  private:
    // indicate if the rook has been castled
    bool castling;

  public:
    Rook(Color col, string str);

    bool get_castling() const;
    void set_castling();

    Movement is_valid_move(int init_x, int init_y, int dest_x,
                           int dest_y, Piece *chess_tab[8][8]) const;
};

class King : public Piece {

  private:
    // indicate if the king has been castled
    bool castling;

  public:
    King(Color col, string str);

    bool get_castling() const;
    void set_castling();

    Movement is_valid_move(int init_x, int init_y, int dest_x,
                           int dest_y, Piece *chess_tab[8][8]) const;
};

class Pawn : public Piece {

  public:
    Pawn(Color col, string str);

    Movement is_valid_move(int init_x, int init_y, int dest_x,
                           int dest_y, Piece *chess_tab[8][8]) const;
};

#endif
