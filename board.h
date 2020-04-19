#ifndef BOARD_H
#define BOARD_H

#include <QDebug>
#include <QList>

#include "component.h"
#include "componentdata.h"
#include "boardarray.h"
#include "boardgroup.h"
#include "epmxrayinfo.h"
#include "footprints.h"
#include "pd.h"

class Board {
  public:
    Board() {
        qDebug() << "Board constructor";
    }

    void addEpmXrayInfo(const EpmXrayInfo& info);
    void addPdElem(Pd* elem);
    void addFootprintElem(Footprint * elem2);
    void addComponentData(ComponentData* cdata);

    void addBoardName(BoardArray* board_info);
    void addBoardGroup(BoardGroup* gr);
    void addBoardArray(BoardArray* ba);
    void print() const;

    //bool getDataForComponent(int index, int &number, QPointF &point, QSizeF &size);

    Component* createComponent(int index);

    Footprint* getFootprint(const QString& part);
    BoardArray* getBoardArray(int index) const;

    double boardWidth() const;
    double boardHeight() const;


private:
    EpmXrayInfo m_info;
    QList<BoardGroup*> m_boardGroupList;
    QList<BoardArray*> m_boardArrayList;

    QList<Pd*> m_pdList;
    QList<Footprint*> m_footprintsList;
    QList<BoardArray*> m_BoardInfoList;
    QList<ComponentData*> m_componentDataList;
};

#endif // BOARD_H

