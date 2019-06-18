#ifndef APPLICATION_H
#define APPLICATION_H

#include "components/errormessage.h"
#include "upgradedialog.h"
#include "aboutdialog.h"
#include "configdialog.h"
#include "historywindow.h"
#include "uploaddialog.h"
#include "store/sqlstore.h"
#include "core/error.h"
#include "core/tagservice.h"
#include "core/serverservice.h"
#include "core/settingservice.h"
#include "core/outputformatservice.h"
#include "core/clipservice.h"

#include <QtGlobal>
#include <QApplication>
#include <QIcon>
#include <QSystemTrayIcon>

class Application : public QApplication
{
    Q_OBJECT

public:
    Application(int &argc, char **argv);
    ~Application() override;

    int showUpgradeWindow();
    void createTrayIcon();
    void showAboutDialog();
    void showConfigDialog();
    void showHistoryWindow();
    void showUploadDialog();
    bool prepare(const QString& dbPath);

    const QString &getDbPath();

    TagService *tagService();
    ServerService *serverService();
    SettingService *settingService();
    OutputFormatService *outputFormatService();
    ClipService *clipService();

private:
    template <typename T>
    void showWindowOrDialog(T **widget);
    QIcon _windowIcon;
    QString _dbPath;
    SqlStore *_store = nullptr;
    TagService *_tagService = nullptr;
    ServerService *_serverService = nullptr;
    SettingService *_settingService = nullptr;
    OutputFormatService *_outputFormatService = nullptr;
    ClipService *_clipService = nullptr;

    UpgradeDialog *upgradeDialog = nullptr;
    AboutDialog *aboutDialog = nullptr;
    ConfigDialog *configDialog = nullptr;
    HistoryWindow *historyWindow = nullptr;
    UploadDialog *uploadDialog = nullptr;

public slots:
    void trayIconActivated(QSystemTrayIcon::ActivationReason);
};

#define APP (qobject_cast<Application*>qApp)
#define THUMB_WIDTH 160
#define THUMB_HEIGHT 160


#endif // APPLICATION_H


