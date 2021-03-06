#ifndef CHESSBOARD
#define CHESSBOARD

#include "piece.h"
#include <iostream>

/**
 * @brief Construct the chessboard, manage the movement chosen by the
 * user and manage the checkmate and the stalemate situation.
 *
 */
class Chessboard {

  private:
    // indicate the chessboard with the piece
    Piece *chess_tab[8][8];
    // indicate the x coordinates of white king
    int white_king_x;
    // indicate the y coordinates of white king
    int white_king_y;
    // indicate the x coordinates of black king
    int black_king_x;
    // indicate the y coordinates of black king
    int black_king_y;
    // indicate the number of stroke without a take in a row
    int stroke_without_take;
    // indicate at the end of the game all the pieces destroyed
    int destroyed_pieces[12];

  public:
    /**
     * @brief Construct a new Chessboard object
     */
    Chessboard();

    /**
     * @brief Destroy the Chessboard object
     */
    ~Chessboard();

    /**
     * @brief Print the chessboard
     */
    void print_board();

    /**
     * @brief Get the chess_tab object
     * @return the piece address
     */
    Piece *get_piece(int x, int y) const;

    /**
     * @brief Check if the piece put in argument is on the board
     * @param name
     * @return true
     * @return false
     */
    int is_contained(string name);

    /**
     * @brief Check if the three situation of non possibility of
     * checkmate is on the board. These situations are :
     * - a king against a king
     * - a king against a king and two knights
     * - a king against a king and a bishop or a knight
     * @return true
     * @return false
     */
    bool lack_of_piece_for_checkmate(void);

    /**
     * @brief Move the chess_tab object chosen by the user
     * @param init_x the x coordinate of the piece to move
     * @param init_y the y coordinate of the piece to move
     * @param dest_x the x coordinate of the destination
     * @param dest_y the y coordinate of the destination
     */
    void move(int init_x, int init_y, int dest_x, int dest_y);

    /**
     * @brief Increase by one each time a piece is detroyed the piece
     * in question
     * @param name
     */
    void set_destroyed_pieces(string name);

    /**
     * @brief Verify if the player (color) is in check situation
     * @param color
     * @return true
     * @return false
     */
    bool is_check(Color color);

    /**
     * @brief Verify if the player (color) is in checkmate
     * @param color
     * @return true
     * @return false
     */
    bool is_checkmate(Color color);

    /**
     * @brief Increase by one the number of stroke without a take
     * in a row
     */
    void set_counter();

    /**
     * @brief Verify if the player (color) is in stalemate
     * @param color
     * @return true
     * @return false
     */
    bool is_stalemate(Color color);

    /**
     * @brief Verify if the move chosen by the player (color) is
     * valid (the piece chosen is the player's piece, the
     * destination is empty or it is a take, if the move does not
     * put the player in check)
     * @param color
     * @param init_x
     * @param init_y
     * @param dest_x
     * @param dest_y
     * @return true
     * @return false
     */
    bool allowed_move(Color color, int init_x, int init_y, int dest_x,
                      int dest_y);

    /**
     * @brief Display the number of pieces destroyed at the end of the
     * game
     */
    void print_destroyed_pieces(void);
};

#endif