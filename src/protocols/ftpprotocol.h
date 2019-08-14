#ifndef FTPPROTOCOL_H
#define FTPPROTOCOL_H

#include <QtCore>
#include "./base.h"

class FtpUploader : public Uploader
{
    const QUrl _ftpUrl;
    QString _outputUrl;
public:
    FtpUploader(const QVariantMap settings);
    void upload(QDataStream *stream, UploadJob &job) override;
};

class FtpProtocol : public Protocol
{
    QList<ProtocolSettingInfo> _settingInfos;
public:
    FtpProtocol();

    // Protocol interface
    const QString getName();
    const QString getTitle();
    const QList<ProtocolSettingInfo> &getSettingInfos();
    Uploader *createUploader(const QVariantMap &settings);
};

#endif // FTPPROTOCOL_H
