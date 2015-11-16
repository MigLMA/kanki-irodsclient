/**
 * @file rodsconditionwidget.h
 * @brief Definition of RodsConditionWidget class
 *
 * The RodsConditionWidget class extends the Qt widget class QWidget and
 * implements an abstract widget for entering an iRODS GenQuery condition.
 *
 * Copyright (C) 2014-2015 University of Jyväskylä. All rights reserved.
 * License: The BSD 3-Clause License, see LICENSE file for details.
 *
 * @author Ilari Korhonen
 */

#ifndef RODSCONDITIONWIDGET_H
#define RODSCONDITIONWIDGET_H

// C++ standard library headers
#include <string>

// Qt framework headers
#include <QWidget>
#include <QFrame>
#include <QHBoxLayout>

// Kanki iRODS C++ class library headers
#include <rodsconnection.h>
#include <_rodsgenquery.h>


class RodsConditionWidget : public QFrame
{
    Q_OBJECT

public:

    //
    explicit RodsConditionWidget(QWidget *parent = 0);

    //
    ~RodsConditionWidget();

    // pure virtual function to define interface to the evaluation
    // of the genquery conditions generated by the widget
    virtual void evaluateConds(Kanki::RodsGenQuery *query) = 0;

protected:

    // widget layout
    QHBoxLayout *layout;
};

#endif // RODSCONDITIONWIDGET_H
