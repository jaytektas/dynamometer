#include "mainwindow.h"
#include <QApplication>

#include "communications.h"
#include "connectiondialog.h"
#include "statuspacket.h"
#include "channellist.h"
#include "configuration.h"
#include "run.h"

#include <QMessageBox>

using namespace std;
using namespace Dynamometer;

namespace Dynamometer
{
DCommunications *Comms;
DStatusPacket *Status;
DChannelList *Channels;
DConfiguration *Configuration;
QMap<QDateTime, DRun *> Runs;
}

int main(int argc, char *argv[])
{
QApplication a(argc, argv);
QApplication::setOrganizationName("jaytek");
QApplication::setOrganizationDomain("org.jaytek");
QApplication::setApplicationName("dynamometer");

    Configuration = new DConfiguration();

    Comms = new DCommunications();
    Status = new DStatusPacket(Comms);
    Channels = new DChannelList();
    if (!Channels->load(Configuration->getChannelFilename()))
    {

    }

    QObject::connect(Comms, SIGNAL(connected(bool)), Status, SLOT(connected(bool)));
    // connect up the status to push it's packet over to the channels for processing
    QObject::connect(Status, SIGNAL(statusUpdate(QByteArray)), Channels, SLOT(statusUpdate(QByteArray)));

    MainWindow w;
    w.show();

    return a.exec();
}

