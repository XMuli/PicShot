﻿/*******************************************************************
 * Copyright (c) 2021-2022 偕臧  All rights reserved.
 *
 * Author: XMuli <xmulitech@gmail.com>
 * GitHub: https://github.com/XMuli
 * Blog:   https://xmuli.tech
 *
 * Date: 2021.11.06
 * Description: 圆角矩形窗口
 ******************************************************************/#include "xroundwidget.h"
#include "../xglobal.h"
#include <QColor>
#include <QHBoxLayout>
#include <QPainter>

XRoundWidget::XRoundWidget(QWidget *parent)
    : QWidget(parent)
{
    initUI();
}

XRoundWidget::~XRoundWidget()
{
}

void XRoundWidget::initUI()
{
    setWindowFlags(Qt::FramelessWindowHint);      // 去掉标题栏
    setAttribute(Qt::WA_TranslucentBackground);   // 设置透明，自绘画为圆角矩形
}

void XRoundWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter pa(this);
    pa.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    pa.setPen(Qt::NoPen);
    pa.setBrush(QColor(255, 255, 255, 0.8 * 255));
    pa.drawRoundedRect(contentsRect(), CW_RADIRS, CW_RADIRS);
}
