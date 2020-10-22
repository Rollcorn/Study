#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <QAbstractListModel>
#include <vector>

class GameBoard : public QAbstractListModel
{
    Q_OBJECT
public:
    static constexpr size_t defaultPuzzleDimension {4};
    GameBoard(const size_t boardDimension = defaultPuzzleDimension, QObject* parent = nullptr);

    struct Tile{
        size_t value{};
        Tile& operator=(const size_t newValue){
            value = newValue;
            return  *this;
        }
        bool operator==(const size_t other){
            return other == value;
        }
    };

private:
    std::vector<Tile> m_rawBoard;
    const size_t m_dimension;
    const size_t m_boardsize;

};



#endif // GAMEBOARD_H
