#ifndef BOARD_H
#define BOARD_H

#include <QDebug>
#include <QList>

#include "board_info.h"
#include "epmxrayinfo.h"
#include "pd.h"
#include "footprints.h"
#include "component.h"
#include "componentdata.h"

class Board {
  public:
    Board() {
        qDebug() << "Board constructor";
    }

    void addEpmXrayInfo(const EpmXrayInfo& info);
    void addPdElem(Pd* elem);
    void addFootprintElem(Footprint * elem2);
    void addComponentData(ComponentData* cdata);

    void addBoardName(Board_info* board_info);
    void print() const;

    //bool getDataForComponent(int index, int &number, QPointF &point, QSizeF &size);

    Component* createComponent(int index);
private:
    EpmXrayInfo m_info;
    QList<Pd*> m_pdList;
    QList<Footprint*> m_footprintsList;
    QList<Board_info*> m_BoardInfoList;
    QList<ComponentData*> m_componentDataList;
};

#endif // BOARD_H

