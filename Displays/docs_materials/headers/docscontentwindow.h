#ifndef DOCSCONTENTWINDOW_H
#define DOCSCONTENTWINDOW_H

#include <QWidget>

namespace Ui {
class DocsContentWindow;
}

class DocsContentWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DocsContentWindow(QWidget *parent = 0);
    ~DocsContentWindow();

private:
    Ui::DocsContentWindow *ui;
};

#endif // DOCSCONTENTWINDOW_H
