#ifndef ILOADABLE_H
#define ILOADABLE_H
#include <QString>
#include <QVariant>

class ILoadable {
	//virutal constructor
	Q_INVOKABLE virtual bool loadData(const QString& source) = 0;
	Q_INVOKABLE virtual bool loadMetaData(const QString& source) = 0;
};

#endif // ILOADABLE_H 