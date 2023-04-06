﻿// SPDX-License-Identifier:
// SPDX-FileCopyrightText: 2021-2023 XMuli <xmulitech@gmail.com>
//
// Source: https://github.com/XMuli/Flipped

#ifndef DATAMAID_H
#define DATAMAID_H

#include <QObject>
#include <QSize>
#include <QIcon>
#include <QImage>
#include <QColor>
#include <QScreen>
#include <QString>
#include <QPixmap>
#include <QScreen>
#include <QVariant>
#include <QSettings>
#include <QDomElement>
#include <QGlobalStatic>
#include <QStandardPaths>
#include <QCoreApplication>
#include <QGuiApplication>

#define DATAMAID DataMaid::instance()

// perference UI config
const QString INIT_GENERAL("General");                   // 初始化 常规
const QString INIT_INTERFACE("Interface");               // 初始化 界面
const QString INIT_OUTPUT("Output");                     // 初始化 输出
const QString INIT_PIN("Pin");                           // 初始化 贴图
const QString INIT_HOTKEYS("Hotkeys");                   // 初始化 快捷键

// DataIni：通过 SETTINGINI 对 .ini 进行数据的读和写
// DataMaid：类似单例，所有的 .ini 的参数，全部存放于此；other ui class ⇌ [DataMaid 主 ⇌ DataIni] ⇌ .ini
// 
// DataIni 通过 QSetting 对 .ini 进行读写， 数据统一保存到 DataMaid::instance() 中，里面为时刻最新的
class DataIni : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString lanuage MEMBER m_lanuage NOTIFY sigLanuage)
    Q_PROPERTY(QString font MEMBER m_font NOTIFY sigFont)
    Q_PROPERTY(bool autoRun MEMBER m_autoRun NOTIFY sigAutoRun)
    Q_PROPERTY(bool asAdmin MEMBER m_asAdmin NOTIFY sigAsAdmin)
    Q_PROPERTY(QString logLevel MEMBER m_logLevel NOTIFY sigLogLevel)
    Q_PROPERTY(bool autoUpdate MEMBER m_autoUpdate NOTIFY sigAutoUpdate)

    Q_PROPERTY(QString borderStyle MEMBER m_borderStyle NOTIFY sigBorderStyle)
    Q_PROPERTY(QString borderColor MEMBER m_borderColor NOTIFY sigBorderColor)
    Q_PROPERTY(int borderWidth MEMBER m_borderWidth NOTIFY sigBorderWidth)
    Q_PROPERTY(QString crosshairColor MEMBER m_crosshairColor NOTIFY sigCrosshairColor)
    Q_PROPERTY(int crosshairWidth MEMBER m_crosshairWidth NOTIFY sigCrosshairWidth)
    Q_PROPERTY(bool smartWindow MEMBER m_smartWindow NOTIFY sigSmartWindow)
    Q_PROPERTY(bool crosshair MEMBER m_crosshair NOTIFY sigCrosshair)
    Q_PROPERTY(bool showCursor MEMBER m_showCursor NOTIFY sigShowCursor)
    Q_PROPERTY(bool autoCopy2Clipboard MEMBER m_autoCopy2Clipboard NOTIFY sigAutoCopy2Clipboard)

    Q_PROPERTY(int imageQuailty MEMBER m_imageQuailty NOTIFY sigImageQuailty)
    Q_PROPERTY(QString fileName MEMBER m_fileName NOTIFY sigFileName)
        
    Q_PROPERTY(QString configPath MEMBER m_configPath NOTIFY sigConfigPath)
    Q_PROPERTY(bool quickSave MEMBER m_quickSave NOTIFY sigQuickSave)
    Q_PROPERTY(bool autoSave MEMBER m_autoSave NOTIFY sigAutoSave)
    Q_PROPERTY(QString quickSavePath MEMBER m_quickSavePath NOTIFY sigQuickSavePath)
    Q_PROPERTY(QString autoSavePath MEMBER m_autoSavePath NOTIFY sigAutoSavePath)


    Q_PROPERTY(bool windowShadow MEMBER m_windowShadow NOTIFY sigWindowShadow)
    Q_PROPERTY(int opacity MEMBER m_opacity NOTIFY sigOpacity)
    Q_PROPERTY(int maxSize MEMBER m_maxSize NOTIFY sigMaxSize)

    Q_PROPERTY(QString scrnCapture MEMBER m_scrnCapture NOTIFY sigScrnCapture)
    Q_PROPERTY(QString delayCapture MEMBER m_delayCapture NOTIFY sigDelayCapture)
    Q_PROPERTY(QString fullScrnCapture MEMBER m_fullScrnCapture NOTIFY sigFullScrnCapture)

private:
    inline bool setQStrProperty(const QString& proper, const QVariant& val);

public:
    explicit DataIni(QObject* parent = nullptr);
    void readFromAllIni();
    void writeToAllIni(const bool bReset = false);

    void resetAllData();
    void resetGeneral();
    void resetInterface();
    void resetOutput();
    void resetPin();
    void resetHotkeys();

public:
    void writeToGeneralIni(const bool bReset);
    void writeToInterfaceIni(const bool bReset);
    void writeToOutputIni(const bool bReset);
    void writeToPinIni(const bool bReset);
    void writeToHotkeysIni(const bool bReset);

private:
    QString resetLanuage() { m_lanuage = "en_US"; return m_lanuage; }
    QString resetFont() { m_font = "SimSun,9"; return m_font; }
    bool resetAutoRun() { m_autoRun = true; return m_autoRun; }
    bool resetAsAdmin() { m_asAdmin = false; return m_asAdmin; }
    QString resetLogLevel() { m_logLevel = "debug"; return m_logLevel; }
    bool resetAutoUpdate() { m_autoUpdate = false; return m_autoUpdate; }

    QString resetBorderStyle() { m_borderStyle = "flipped"; return m_borderStyle; }
    QString resetBorderColor() { m_borderColor = "#0e70ff"; return m_borderColor; }
    int resetBorderWidth() { m_borderWidth = 2; return m_borderWidth; }
    QString resetCrosshairColor() { m_crosshairColor = "#db000f"; return m_crosshairColor; }
    int resetCrosshairWidth() { m_crosshairWidth = 1; return m_crosshairWidth; }
    bool resetSmartWindow() { m_smartWindow = true; return m_smartWindow; }
    bool resetCrosshair() { m_crosshair = false; return m_crosshair; }
    bool resetShowCursor() { m_showCursor = false; return m_showCursor; }
    bool resetAutoCopy2Clipboard() { m_autoCopy2Clipboard = true; return m_autoCopy2Clipboard; }

    int resetImageQuailty() { m_imageQuailty = -1; return m_imageQuailty; }
    QString resetFileName() { m_fileName = "Flipped_$yyyyMMdd_hhmmss$.png"; return m_fileName; }
    QString resetConfigPath() { m_configPath = qApp->applicationDirPath() + "/config"; return m_configPath; }
    bool resetQuickSave() { m_quickSave = true; return m_quickSave; }
    bool resetAutoSave() { m_autoSave = false; return m_autoSave; }

    QString resetQuickSavePath() { m_quickSavePath = QStandardPaths::standardLocations(QStandardPaths::DesktopLocation).first(); return m_quickSavePath; }
    QString resetAutoSavePath() { m_autoSavePath = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation).first(); return m_autoSavePath; }


    bool resetWindowShadow() { m_windowShadow = false; return m_windowShadow; }
    int resetOpacity() { m_opacity = 100; return m_opacity; }
    int resetMaxSize() { m_maxSize = 100000; return m_maxSize; }

    QString resetScrnCapture() { m_scrnCapture = "Ctrl+Shift+L"; return m_scrnCapture; }       // TODO 2023.04.02: 对应的 Mac 上面需要修改
    QString resetDelayCapture() { m_delayCapture = "Ctrl+Shift+S"; return m_delayCapture; }
    QString resetFullScrnCapture() { m_fullScrnCapture = "Ctrl+Shift+F"; return m_fullScrnCapture; }

signals:
    void sigLanuage(QString language);
    void sigFont(QString font);
    void sigAutoRun(bool enable);
    void sigAsAdmin(bool enable);
    void sigLogLevel(QString level);
    void sigAutoUpdate(bool enable);

    void sigBorderStyle(QString style);
    void sigBorderColor(QString color);
    void sigBorderWidth(int width);
    void sigCrosshairColor(QString color);
    void sigCrosshairWidth(int width);
    void sigSmartWindow(bool enable);
    void sigCrosshair(bool enable);
    void sigShowCursor(bool enable);
    void sigAutoCopy2Clipboard(bool enable);

    void sigImageQuailty(int val);
    void sigFileName(QString str);
    void sigConfigPath(QString str);
    void sigQuickSave(int sta);
    void sigAutoSave(int sta);
    void sigQuickSavePath(QString str);
    void sigAutoSavePath(QString str);

    void sigWindowShadow(bool shadow);
    void sigOpacity(int val);
    void sigMaxSize(int val);

    void sigScrnCapture(QString hotkey);
    void sigDelayCapture(QString hotkey);
    void sigFullScrnCapture(QString hotkey);

private:
    QString m_lanuage;             // General
    QString m_font;
    bool    m_autoRun;
    bool    m_asAdmin;
    QString m_logLevel;
    bool    m_autoUpdate;

    QString m_borderStyle;         // Interface
    QString m_borderColor;
    int     m_borderWidth;
    QString m_crosshairColor;
    int     m_crosshairWidth;
    bool    m_smartWindow;
    bool    m_crosshair;
    bool    m_showCursor;
    bool    m_autoCopy2Clipboard;

    int     m_imageQuailty;        // Output
    QString m_fileName;
    QString m_configPath;
    bool    m_quickSave;
    bool    m_autoSave;
    QString m_quickSavePath;
    QString m_autoSavePath;

    bool    m_windowShadow;        // Pin
    int     m_opacity;
    int     m_maxSize;

    QString m_scrnCapture;         // Hotkeys
    QString m_delayCapture;
    QString m_fullScrnCapture;

    QSettings m_settings;
};

class DataMaid : public QObject
{
    Q_OBJECT
public:
    DataMaid(QObject* parent = nullptr);
    void init();
    QVariant paraValue(const char* key);
    QVariant paraValue(const QString key);
    void setParaValue(const char* key, const QVariant& val);
    void setParaValue(const QString key, const QVariant& val);

    void readFromAllIni();
    void writeToAllIni(const bool bReset = false);

public:
    static DataMaid* instance();

public:
    void writeToGeneralIni(const bool bReset);
    void writeToInterfaceIni(const bool bReset);
    void writeToOutputIni(const bool bReset);
    void writeToPinIni(const bool bReset);
    void writeToHotkeysIni(const bool bReset);

public:
    double scale(QScreen* screen = qGuiApp->primaryScreen());
    QIcon ChangeSVGColor(QString path, QString shape, QColor color, QSize size);
    void SetAttrRecur(QDomElement& elem, QString strtagname, QString strattr, QString strattrval);

    // Mosaics draw
    const QPixmap* smoothMosaic(QPixmap* pixmap, int radius = 10);
    const QImage pixlelatedMosaic(QPixmap* pixmap, int px = 20);

    // tabGeneral
    void setAutoRun();

    const QString formatToFileName(const QString name = "Flipped_$yyyyMMdd_hhmmss$.png");

signals:
    void sigWindowShadow(bool shadow);
    void sigOpacity(int val);
    void sigMaxSize(int val);

private:
    DataIni m_dataIni;
};

#endif // DATAMAID_H

