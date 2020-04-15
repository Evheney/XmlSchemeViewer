#ifndef BOARD_INFO_H
#define BOARD_INFO_H

#include <QString>
#include <QStringList>

class Board_info
{
public:
    QString board_name() const {return m_board_name;}
    QStringList board_arrays() const {return m_board_arrays;}
    QString board_pin_name() const {return m_board_pin_name;}

    void setBoard_name(const QString& board_name) {this->m_board_name = board_name;}
    void setboard_arrays(const QStringList& board_arrays){
        this->m_board_arrays = board_arrays;
    }
    void setBoard_pin_name(const QString& pin_name){
        this->m_board_pin_name = pin_name;
    }
    void print() const;
private:
    QString m_board_name;
    QStringList m_board_arrays;
    QString m_board_pin_name;

};

#endif // BOARD_INFO_H
