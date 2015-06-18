#ifndef DOCSDISPLAY_H
#define DOCSDISPLAY_H

#include <QWidget>

namespace Ui {
class docsdisplay;
}

class docsdisplay : public QWidget
{
    Q_OBJECT

public:
    explicit docsdisplay(QWidget *parent = 0);
    ~docsdisplay();

private:
    Ui::docsdisplay *ui;
};

#endif // DOCSDISPLAY_H
