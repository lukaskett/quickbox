#pragma once

#include "../quickeventcoreglobal.h"

#include <qf/core/utils.h>

#include <QVariantMap>

class QSqlRecord;
class SIMessageCardReadOut;
class SIMessageTransmitPunch;

namespace quickevent {
namespace core {
namespace si {

class QUICKEVENTCORE_DECL_EXPORT ReadPunch : public QVariantMap
{
private:
	typedef QVariantMap Super;

	QF_VARIANTMAP_FIELD(int, c, setC, ode)
	QF_VARIANTMAP_FIELD(int, t, setT, ime)
	QF_VARIANTMAP_FIELD(int, m, setM, sec)
	QF_VARIANTMAP_FIELD(int, d, setD, ay)
	QF_VARIANTMAP_FIELD(int, w, setW, eek)
public:
	ReadPunch(const QVariantMap &data = QVariantMap()) : QVariantMap(data) {}
	ReadPunch(const QVariantList &var_list);

	QVariantList toVariantList() const;
	QString toJsonArrayString() const;
};

class QUICKEVENTCORE_DECL_EXPORT ReadCard : public QVariantMap
{
private:
	typedef QVariantMap Super;

	QF_VARIANTMAP_FIELD(int, r, setR, unId)
	QF_VARIANTMAP_FIELD(int, s, setS, tationCodeNumber)
	QF_VARIANTMAP_FIELD(int, c, setC, ardNumber)
	QF_VARIANTMAP_FIELD(int, c, setC, heckTime)
	QF_VARIANTMAP_FIELD(int, s, setS, tartTime)
	QF_VARIANTMAP_FIELD(int, f, setF, inishTime)
	QF_VARIANTMAP_FIELD(int, f, setF, inishTimeMs)
	QF_VARIANTMAP_FIELD(QVariantList, p, setP, unches)
	//QF_VARIANTMAP_FIELD(bool, is, set, CardLent)
public:
	ReadCard(const QVariantMap &data = QVariantMap()) : QVariantMap(data) {}
	ReadCard(const QSqlRecord &rec);
	ReadCard(const SIMessageCardReadOut &si_card);

	int punchCount() const;
	ReadPunch punchAt(int i) const;
	QList<ReadPunch> punchList() const;
	QString toString() const;
};

}}}

