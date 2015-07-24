#ifndef DOCSDISPLAY_H
#define DOCSDISPLAY_H

#include "../docs_materials/headers/docscontentwindow.h"
#include "../docs_materials/headers/docsnavmenu.h"
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
    DocsNavMenu *nav;
    DocsContentWindow *content;
    Ui::docsdisplay *ui;
};

#endif // DOCSDISPLAY_H
