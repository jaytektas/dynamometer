#ifndef DASHWIDGET_H
#define DASHWIDGET_H

#include <QWidget>

using namespace std;

namespace Ui {
class DDashWidget;
}

namespace Dynamometer
{
class DDashWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DDashWidget(QWidget *parent = nullptr);
    ~DDashWidget();

    int getIndex() const { return d_index; }
    void setIndex(int index) { d_index = index; }

    QString getName() const { return d_name; }
    void setName(QString name) { d_name = name; }

    bool getDocked() const { return d_docked; }
    void setDocked(bool docked) { d_docked = docked; }

private slots:
    void showContextMenu(const QPoint & point);
    void contextMenuChannelSelected(QAction *action);
    void changeBackground();
    void undockFromTab();
    void dockToTab();
    void addDialGauge();
    void addLinearGauge();
    void addLCDNumber();
    void addLabel();
    void addHistogram();

signals:
    void undock();
    void dock();

protected:

    Ui::DDashWidget *ui;
    QString d_name;
    int d_index;
    bool d_docked = true;
    QPoint d_context;
    QWidget *d_dockParent = nullptr;
};
}

#endif // DASHWIDGET_H
