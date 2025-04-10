#ifndef ISTATUSABLE_H
#define	ISTATUSABLE_H
#include <QVariant>

template <typename T>
class IStatusable {
	public:
		virtual ~IStatusable() = default;
		virtual T getCurrentstate() const = 0;
		virtual bool isFinished() const = 0;
		virtual int getProgress() const = 0;
};

#endif // !ISTATUSABLE_H