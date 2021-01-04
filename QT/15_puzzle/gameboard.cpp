#include "gameboard.h"
#include <algorithm>
#include <random>

namespace  {
    bool isAdjacent(GameBoard::Position f, GameBoard::Position s);

}
//ОСТАНОВИЛСЯ

GameBoard::GameBoard(const size_t boardDimension, QObject *parent)
    : QAbstractListModel{parent},
      m_dimension {boardDimension},
      m_boardsize {m_dimension * m_dimension}
      //m_hiddenElementValue {m_boardsize}
{
    m_rawBoard.resize(m_boardsize);
    std::iota(m_rawBoard.begin(), m_rawBoard.end(), 1);
    shuffle();
}

bool GameBoard::move(int index)
{
    if(!isPositionValid(static_cast<size_t>(index))){
        return false;
    }

    size_t row;
    size_t column;

    std::tie(row,column) = getRowCol(index);



}

int GameBoard::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_rawBoard.size();

}

QVariant GameBoard::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() || role != Qt::DisplayRole){
        return {};
    }

    const int rowIndex {index.row()};

    if(!isPositionValid(rowIndex)){
        return {};
    }

    return QVariant::fromValue(m_rawBoard[rowIndex].value);
}

void GameBoard::shuffle()
{
    static auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937 genertor(seed);

    do{
        std::shuffle(m_rawBoard.begin(), m_rawBoard.end(), genertor);
    }while(!isBoardValid());
}

bool GameBoard::isPositionValid(const size_t position) const
{
    return position < m_boardsize;
}

bool GameBoard::isBoardValid() const
{
    int inv {0};
    for (size_t i {0}; i < m_boardsize; ++i){
        for (size_t j = 0; j < m_boardsize; ++j){
            if (m_rawBoard[j].value > m_rawBoard[i].value){
                ++inv;
            }
        }
    }

    const size_t start_point = 1;

    for (size_t i = 0; i < m_boardsize; ++i){
        if(m_rawBoard[i].value == m_boardsize)
            inv += start_point + i / m_dimension;
    }

    return (inv % 2) == 0;
}

GameBoard::Position GameBoard::getRowCol(size_t index) const
{
    size_t row = index / m_dimension;
    size_t column = index % m_dimension;

    return std::make_pair(row,column);
}

size_t GameBoard::boardsize() const
{
    return m_boardsize;
}

size_t GameBoard::dimension() const
{
    return m_dimension;
}
