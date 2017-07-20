#ifndef BOARD_H
#define BOARD_H

/**
    @author: Geymerson Ramos
    email: geymerson@ic.ufal.br
    last updated july, 2017

    TIC-TAC-TOE header class
**/

#include <QObject>
#include <QDebug>

class Board : public QObject {
    Q_OBJECT
    Q_PROPERTY(QByteArray board READ board NOTIFY boardChanged)

private:
    QByteArray m_board;
    QList<QByteArray> m_nextPossibleStates;
    QList< QPair<QByteArray, int> > m_allPossibleStates;

signals:
    void boardChanged();
    void xWon();
    void oWon();
    void drawGame();

public:
    explicit Board(QObject *parent = nullptr);

    //Check for a game winner, this method checks for a
    //row, column or diagonal win
    Q_INVOKABLE bool victoryCheck(const QByteArray& board, char a) const;

    //A row win check
    int rowCheck(const QByteArray& board, char a) const;

    //A column win check
    int colCheck(const QByteArray& board, char a) const;

    //A diagonal win check
    int diagCheck(const QByteArray& board, char a) const;

    //Verify if the game state is final: there's no more positions left
    Q_INVOKABLE bool isFinalState(const QByteArray& state) const;

    //Set char 'a' at board position 'pos'
    //a must be X or O, pos must be a number between 0 and 8 inclusive.
    void setPosition(char a, int pos);
    Q_INVOKABLE void setPosition(int c, int pos);

    //Get the char at position 'pos'
    char getPosition(int pos) const;
    Q_INVOKABLE int position(int pos) const;

    //Set the current board value to 'board'
    //    void setBoard(const QByteArray& board);

    //Return the current board state
    QByteArray board() const;

    //Return generated states
    QList< QPair<QByteArray,int> > getNextStates() const;

    //Check if the position 'pos' is valid
    bool isValidPosition(int pos) const;

    //Check if the position 'pos' is empty
    Q_INVOKABLE bool emptyPosition(int pos) const;

    //Initiate board
    Q_INVOKABLE void initBoard();

    //Print the current board state
    void printBoardState() const;
    void printBoardState(const QByteArray &gameState) const;

    //Get all possible game states for char a
    QList<QByteArray> generateNextStates(const QByteArray &gameStat, char a);

    //These 3 methods implements the game intelligence
    int minimax(const QByteArray &state, int depth, bool myTurn);
    int maxValue(const QByteArray &state, int depth, bool myTurn, int alpha, int beta);
    int minValue(const QByteArray &state, int depth, bool myTurn, int alpha, int beta);

    //This method is used by the qSort function
    //Use '>' for descending order and '<' for ascending.
    static bool statesComparator(const QPair<QByteArray, int> &s1, const QPair<QByteArray, int> &s2);
};

#endif // BOARD_H
