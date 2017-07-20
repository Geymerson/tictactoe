/**
  @author: Geymerson Ramos
  email: geymerson@ic.ufal.br
  last updated july, 2017

  This class implements tic-tac-toe using
  minimax algorithm and alpha-beta pruning
**/

#include "../header/board.h"

Board::Board(QObject *parent) : QObject(parent) {
    initBoard();
}

void Board::initBoard() {
    m_board = "         ";
    emit boardChanged();
}

bool Board::victoryCheck(const QByteArray& board, char a) const {
    if (rowCheck(board, a) == 3 || colCheck(board, a) == 3 ||
            diagCheck(board, a) == 3) {
        return true;
    }
    return false;
}

int Board::rowCheck(const QByteArray& board, char a) const {
    int score = 0;
    for (int row = 0; row < 3; ++row) {
        int rowScore = 0;
        for (int col = 0; col < 3; ++col) {
            if (board.at(row * 3 + col) == a) {
                rowScore++;
            }
        }
        score = (score < rowScore) ? rowScore : score;
    }
    return score;
}

int Board::colCheck(const QByteArray& board, char a) const {
    int score = 0;
    for (int col = 0; col < 3; ++col) {
        int colScore = 0;
        for (int row = 0; row < 3; ++row) {
            if (board.at(row * 3 + col) == a) {
                colScore++;
            }
        }
        score = (score < colScore) ? colScore : score;
    }
    return score;
}

int Board::diagCheck(const QByteArray& board, char a) const {
    int score = 0, diagScore = 0;
    for (int pos = 0; pos < 9; pos+=4) {
        if (board.at(pos) == a) {
            diagScore++;
        }
    }
    score = (score < diagScore) ? diagScore : score;
    diagScore = 0;
    for (int pos = 2; pos < 7; pos+=2) {
        if (board.at(pos) == a) {
            diagScore++;
        }
    }
    score = (score < diagScore) ? diagScore : score;
    return score;
}

void Board::printBoardState() const {
    for (int var = 0; var < 3; ++var) {
       qDebug() << m_board.at(var * 3) <<'|' <<  m_board.at(var*3 + 1)<< '|' << m_board.at(var*3 + 2);
       if(var != 2) qDebug() << "_________";
    }
}

void Board::printBoardState(const QByteArray &gameState) const {
    for (int var = 0; var < 3; ++var) {
       qDebug() << gameState.at(var * 3) << '|' << gameState.at(var*3 + 1) << '|' << gameState.at(var*3 + 2);
       if(var != 2) qDebug() << "_________";
    }
    qDebug() << '\n';
}

QList<QByteArray> Board::generateNextStates(const QByteArray &gameState, char a) {
    QList<QByteArray> gameStates;
    for (int var = 0; var < 9; ++var) {
        if (gameState.at(var) == ' ') {
            QByteArray newBoard = gameState;
            newBoard[var] = a;
            gameStates.append(newBoard);
        }
    }
    return gameStates;
}

bool Board::statesComparator(const QPair<QByteArray, int> &s1, const QPair<QByteArray, int> &s2) {
    return s1.second > s2.second;
}

int Board::minimax(const QByteArray &state, int depth, bool myTurn) {
    m_allPossibleStates.clear();
    qDebug().nospace() << "\nNext states: " << m_allPossibleStates.length() <<
                ", old prediction game states cleared.";

    qDebug().nospace() << "Generating next game states.";
    m_nextPossibleStates = generateNextStates(state, 'O');
    qDebug().nospace() << "There is " << m_nextPossibleStates.length() << " possible states.";

    qDebug().nospace() << "Minimax is processing the current game state.";
    int maxV = maxValue(state, depth, myTurn, INT_MIN, INT_MAX);
    qDebug().nospace() << "All possible results: " << m_allPossibleStates.length();
    qSort(m_allPossibleStates.begin(), m_allPossibleStates.end(), statesComparator);

    for (int i = 0; i < m_allPossibleStates.length(); ++i) {
        if(maxV == m_allPossibleStates.at(i).second &&
                m_nextPossibleStates.contains(m_allPossibleStates.at(i).first)) {
            m_board = m_allPossibleStates.at(i).first;
            break;
        }
    }
    return maxV;
}

int Board::maxValue(const QByteArray &state, int depth, bool myTurn, int alpha, int beta) {

    if(victoryCheck(state, 'X')) {
        m_allPossibleStates.append( qMakePair(state, depth - 10));
        return depth - 10;
    }
    if(victoryCheck(state, 'O')) {
        m_allPossibleStates.append( qMakePair(state, 10 - depth));
        return 10 - depth;
    }
    if(isFinalState(state)) {
        m_allPossibleStates.append( qMakePair(state, 0));
        return 0;
    }

    char c = myTurn ? 'O':'X';
    int maxVal = INT_MIN;
    QList<QByteArray> nextStates = generateNextStates(state, c);
    for (int i = 0; i < nextStates.length(); ++i) {
        maxVal = qMax(maxVal, minValue(nextStates.at(i), depth + 1, !myTurn, alpha, beta));
        if (maxVal >= beta) {
           return maxVal;
        }
        alpha = qMax(alpha, maxVal);
    }

    m_allPossibleStates.append( qMakePair(state, maxVal));
    return maxVal;
}

int Board::minValue(const QByteArray &state, int depth, bool myTurn, int alpha, int beta) {

    if(victoryCheck(state, 'X')) {
        m_allPossibleStates.append( qMakePair(state, depth - 10));
        return depth - 10;
    }
    if(victoryCheck(state, 'O')) {
        m_allPossibleStates.append( qMakePair(state, 10 - depth));
        return 10 - depth;
    }
    if(isFinalState(state)) {
        m_allPossibleStates.append( qMakePair(state, 0));
        return 0;
    }

    char c = myTurn ? 'O':'X';
    int minVal = INT_MAX;
    QList<QByteArray> nextStates = generateNextStates(state, c);
    for (int i = 0; i < nextStates.length(); ++i) {
        minVal = qMin(minVal, maxValue(nextStates.at(i), depth + 1, !myTurn, alpha, beta));
        if (minVal <= alpha) {
           return minVal;
        }
        beta = qMin(beta, minVal);
    }
    m_allPossibleStates.append( qMakePair(state, minVal));
    return minVal;
}

bool Board::isValidPosition(int pos) const {
    if(pos >=0 && pos < 9) {
        return true;
    }
    qDebug() << "This is an invalid position, choose another one.";
    return false;
}

bool Board::isFinalState(const QByteArray &state) const {
    //There still empty positions
    for (int var = 0; var < 9; ++var) {
        if (state.at(var) == ' ') {
            return false;
        }
    }
    //There is no empty positions, draw game
    return true;
}

//Check if this position is empty
bool Board::emptyPosition(int pos) const {
    if(m_board.at(pos) == ' ') {
        return true;
    }
    qDebug() << "This position is not empty, choose another one!";
    return false;
}

//Set char in the board position
void Board::setPosition(char c, int pos) {
    if (isValidPosition(pos) && emptyPosition(pos)) {
        if(c == 'X' || c == 'O' || c == ' ') {
            m_board[pos] = c;            
            emit boardChanged();
        } else {
            qDebug() << "invalid character: " << c;
        }
    }
}

void Board::setPosition(int c, int pos) {
    if (isValidPosition(pos) && emptyPosition(pos)) {
        if(c == 1) {
            m_board[pos] = ' ';
            emit boardChanged();
        }
        else if(c == 2) {
            m_board[pos] = 'X';
            if (victoryCheck(m_board, 'X')) { //Check if X won
                emit xWon();
//                return;
            }

            minimax(m_board, 0, true); //Computer turn

            if (victoryCheck(m_board, 'O')) { //Check if O won
                emit oWon();
//                return;
            }
            if (isFinalState(m_board)) { //Check for a draw game
                emit drawGame();
//                return;
            }
            emit boardChanged();
        }
        else if(c == 3) {
            m_board[pos] = 'O';
            emit boardChanged();
        }
        else {
            qDebug() << c <<" is an invalid character.";
        }
    }
}

//Get a char at position 'pos' in the board
char Board::getPosition(int pos) const {
    if (isValidPosition(pos)) {
        return m_board.at(pos);
    }
    return 'e';
}

int Board::position(int pos) const {
    if (isValidPosition(pos)) {
        if (m_board.at(pos) == ' ') { return 1; }
        if (m_board.at(pos) == 'X') { return 2; }
        if (m_board.at(pos) == 'O') { return 3; }
    }
    return -1;
}

QByteArray Board::board() const {
    return m_board;
}

QList< QPair<QByteArray,int> > Board::getNextStates() const {
    return m_allPossibleStates;
}
