#ifndef CONFIGVALUE_H
#define CONFIGVALUE_H

#include <QSettings>
#include <QVariant>
#include <QString>
#include <QFileInfo>

/********对SEMS配置文件的操作********/
namespace ConfigValue {
    //根据索引获取配置文件的值
    QVariant getConfigValueWithKey(const QString &filePath,const QString &key);

    //根据索引修改配置文件的值
    bool setConfigValueWithKey(const QString &filePath,const QString &key,const QString &value);

} // namespace ConfigValue
#endif // CONFIGVALUE_H
