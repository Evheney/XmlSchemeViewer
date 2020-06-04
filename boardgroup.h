#ifndef BOARDGROUP_H
#define BOARDGROUP_H


class BoardGroup
{
public:
    //BoardGroup() = delete;
    BoardGroup(int grName, double grw, double grh, double grx, double gry);
    ~BoardGroup();

    int getGrName() const;

    double getGrw() const;

    double getGrh() const;

    double getGrx() const;

    double getGry() const;


private:

    int grName;
    double grw;
    double grh;
    double grx;
    double gry;
};

#endif // BOARDGROUP_H
