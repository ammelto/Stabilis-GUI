#ifndef INPUTFIELD_H
#define INPUTFIELD_H

#include <QWidget>

namespace Ui {
class inputField;
}

class inputField : public QWidget
{
    Q_OBJECT

public:
    //PARENT, GEOMETRY, TEXT HINT, LOADED VALUE
    explicit inputField(QWidget *parent = 0, QRect r = QRect(0,0,0,0), QString s = "", QString d = "");
    void setValue(QString s);
    QString getValue();
    void setLocation(QRect r);
    ~inputField();

private:
    QColor secondary;
    QRect location;
    QString hint;

    bool eventFilter(QObject *obj, QEvent *event);
    Ui::inputField *ui;
};

#endif // INPUTFIELD_H
