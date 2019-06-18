#ifndef UPLOADDIALOG_H
#define UPLOADDIALOG_H

#include "models/clip.h"

#include <QDialog>
#include <QKeyEvent>

/*
#include <QResizeEvent>
#include <QtDebug>
*/

namespace Ui {
class UploadDialog;
}

class UploadDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UploadDialog(QWidget *parent = nullptr);
    ~UploadDialog();

private:
    Ui::UploadDialog *ui;
    QList<Clip> _clips;
    QLayout *_previewLayout;

protected:
    void accept() override;

public slots:
    void reload();
    void refresh();
};

#endif // UPLOADDIALOG_H
