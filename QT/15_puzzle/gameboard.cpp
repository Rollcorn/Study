#include "gameboard.h"
#include <algorithm>

GameBoard::GameBoard(const size_t boardDimension, QObject *parent)
    : QAbstractListModel{parent},
      m_dimension {boardDimension},
      m_boardsize {m_dimension * m_dimension}
{
    m_rawBoard.resize(m_boardsize);
    std::iota(m_rawBoard.begin(), m_rawBoard.end(), 1);
}
