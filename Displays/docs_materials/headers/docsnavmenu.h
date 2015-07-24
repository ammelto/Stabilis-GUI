#ifndef DOCSNAVMENU_H
#define DOCSNAVMENU_H

#include <QWidget>

namespace Ui {
class DocsNavMenu;
}

class DocsNavMenu : public QWidget
{
    Q_OBJECT

public:
    explicit DocsNavMenu(QWidget *parent = 0);
    ~DocsNavMenu();

private:
    Ui::DocsNavMenu *ui;
};

#endif // DOCSNAVMENU_H
