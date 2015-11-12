/**
 * @file rodsmetadataconditionwidget.h
 * @brief Definition of RodsMetadataConditionWidget class
 *
 * The RodsMetadataConditionWidget class extends the class RodsConditionWidget and
 * implements a widget for entering a metadata condition for a GenQuery.
 *
 * Copyright (C) 2014-2015 University of Jyväskylä. All rights reserved.
 * License: The BSD 3-Clause License, see LICENSE file for details.
 *
 * @author Ilari Korhonen
 */

#ifndef RODSMETADATACONDITIONWIDGET_H
#define RODSMETADATACONDITIONWIDGET_H

// C++ standard library headers
#include <string>
#include <map>

// Qt framework headers
#include <QWidget>
#include <QString>
#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>

// Kanki iRODS C++ class library headers
#include "rodsconnection.h"
#include "rodsobjentry.h"
#include "_rodsgenquery.h"

// application headers
#include "rodsconditionwidget.h"

class RodsMetadataConditionWidget : public RodsConditionWidget
{
    Q_OBJECT

public:

    //
    RodsMetadataConditionWidget(objType_t objType, const std::map<std::string, std::string> &attrs,
                                QWidget *parent = 0);

private:

    // widget layout
    QHBoxLayout *layout;

    // label widget
    QLabel *labelWidget;

    // metadata attribute select
    QComboBox *attrSel;

    // condition operator select
    QComboBox *condBox;

    // text field
    QLineEdit *valueField;
};

#endif // RODSMETADATACONDITIONWIDGET_H
