#ifndef FIELDMANAGER_H
#define FIELDMANAGER_H

#include <QObject>

class FieldManager : public QObject
{
	Q_OBJECT
public:
	explicit FieldManager(QObject *parent = nullptr);

signals:

public slots:
};

#endif // FIELDMANAGER_H