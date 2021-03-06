#pragma once

#include <services/service.h>

class QTimer;

namespace services {

class ResultsExporterSettings : public ServiceSettings
{
	using Super = ServiceSettings;

	QF_VARIANTMAP_FIELD(QString, e, setE, xportDir)
	QF_VARIANTMAP_FIELD2(int, e, setE, xportIntervalSec, 0)
	QF_VARIANTMAP_FIELD(QString, w, setW, henFinishedRunCmd)

public:
	ResultsExporterSettings(const QVariantMap &o = QVariantMap()) : Super(o) {}
};

class ResultsExporter : public services::Service
{
	Q_OBJECT

	using Super = services::Service;
public:
	ResultsExporter(QObject *parent);

	//void run() override;
	//void stop() override;

	void loadSettings() override;
	ResultsExporterSettings settings() const {return ResultsExporterSettings(m_settings);}

	qf::qmlwidgets::framework::DialogWidget *createDetailWidget() override;

	static QString serviceName();

	//QString exportDir() const {return settings().exportDir();}
	//void setExportDir(const QString &s);

	//int exportIntervalSec() const {return settings().exportIntervalSec();}
	//void setExportIntervalSec(int sec);

	//QString whenFinishedRunCmd() const {return settings().whenFinishedRunCmd();}
	//void setWhenFinishedRunCmd(const QString &s);
private:
	void onExportTimerTimeOut();
private:
	QTimer *m_exportTimer = nullptr;
};

} // namespace services

