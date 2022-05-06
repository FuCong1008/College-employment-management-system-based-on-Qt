#include "configvalue.h"

#include <QDebug>
#define cout qDebug()<<"["<<__FILE__<<"]["<<__LINE__<<"]"

QVariant ConfigValue::getConfigValueWithKey(const QString &filePath, const QString &key)
{
    QSettings fromSettings(filePath,QSettings::IniFormat);
    return fromSettings.value(key);
}

bool ConfigValue::setConfigValueWithKey(const QString &filePath, const QString &key, const QString &value)
{
    QFileInfo fileInfo(filePath);
    if(true == fileInfo.isFile())
    {
        QSettings fromSettings(filePath,QSettings::IniFormat);
        fromSettings.setValue(key,value);
        //cout << QStringLiteral("修改配置文件成功");
        return true;
    }
    else
    {
        cout << "fileInfo.isFile() error:" << filePath;
        return false;
    }
}
