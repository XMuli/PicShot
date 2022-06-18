/*******************************************************************
 * Copyright (c) 2021-2022 偕臧  All rights reserved.
 *
 * Author: XMuli <xmulitech@gmail.com>
 * GitHub: https://github.com/XMuli
 * Blog:   https://xmuli.tech
 *
 * Date: 2022.06.18
 * Description: 工具栏框架类，负责绘画好
 ******************************************************************/
#include "frametoolbar.h"
#include "../xglobal.h"
#include "../widget/xhorizontalline.h"
#include "../widget/xverticalline.h"
#include "../screen/screenshot.h"
#include <QColor>
#include <QPainter>
#include <QBoxLayout>

FrameToolBar::FrameToolBar(Qt::Orientations orien, QWidget *parent)
    : QWidget(parent)
    , m_scal(1)
    , m_orien(orien)
    , m_layout(nullptr)
{
    setWindowFlags(Qt::FramelessWindowHint);      // 去掉标题栏
    setAttribute(Qt::WA_TranslucentBackground);   // 设置透明，自绘画为圆角矩形

    initUI();
}

FrameToolBar::~FrameToolBar()
{

}

void FrameToolBar::addWidget(QWidget *w)
{
    if (!w)
        m_layout->addWidget(new QPushButton("btn1"));

}

void FrameToolBar::addSpacer()
{
    if (m_orien == Qt::Horizontal)
        m_layout->addWidget(new XVerticalLine(ICON_WIDTH * m_scal, this));
    else
        m_layout->addWidget(new XHorizontalLine(ICON_WIDTH * m_scal, this));
}

void FrameToolBar::initUI()
{
    m_scal = ScreenShot::getScale();
    if (m_orien == Qt::Horizontal) {
        m_layout = new QHBoxLayout(this);
        resize(395 * m_scal, 40 * m_scal);
    } else {
        m_layout = new QVBoxLayout(this);
        resize(40 * m_scal, 395 * m_scal);
    }

    setLayout(m_layout);
    m_layout->setMargin(CW_MARGIN);
    m_layout->setSpacing(CW_ITEM_SPACE);

    // TEST BEGIN
    m_layout->addWidget(new QPushButton("btn1"));
    m_layout->addWidget(new QPushButton("btn2"));
    addSpacer();
    m_layout->addWidget(new QPushButton("btn3"));
    // TEST END
}

void FrameToolBar::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter pa(this);
    pa.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    pa.setPen(Qt::NoPen);
    QColor col("#131313");
    col.setAlphaF(0.6);
    pa.setBrush(col);
    pa.drawRoundedRect(contentsRect(), CW_RADIRS, CW_RADIRS);
}
