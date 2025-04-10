#ifndef IPROCESSABLE_H
#define IPROCESSABLE_H
#include <QVariant>
#include <QObject>


class IProcessable {

	public:	
		virtual ~IProcessable() = default;
		Q_INVOKABLE virtual void start() = 0;
		Q_INVOKABLE virtual void processInput(const QVariant) = 0;
		Q_INVOKABLE virtual void nextStep() = 0;
		Q_INVOKABLE virtual int currentStep() = 0;
};
#endif