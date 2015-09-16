/**
 * @file rodstransferwindow.h
 * @brief Definition of class RodsTransferWindow
 *
 * The RodsTransferWindow class extends the Qt widget base class QWidget
 * and implements a transfer progress display window
 *
 * Copyright (C) 2014-2015 University of Jyväskylä. All rights reserved.
 * License: The BSD 3-Clause License, see LICENSE file for details.
 *
 * @author Ilari Korhonen
 */

// application class RodsTransferWindow header
#include "rodstransferwindow.h"

RodsTransferWindow::RodsTransferWindow(QString title) :
    QWidget(NULL)
{
    this->setWindowTitle(title);

    this->layout = new QVBoxLayout(this);

    this->mainProgressMsg = new QLabel(this);
    this->layout->addWidget(this->mainProgressMsg);

    this->mainProgressBar = new QProgressBar(this);
    this->mainProgressBar->setMaximum(0);
    this->layout->addWidget(this->mainProgressBar);

    this->subProgressMsg = new QLabel(this);
    this->layout->addWidget(this->subProgressMsg);
    this->subProgressBar = new QProgressBar(this);
    this->subProgressBar->setMaximum(0);
    this->layout->addWidget(this->subProgressBar);

    this->cancelButton = new QPushButton("Cancel", this);
    this->layout->addWidget(this->cancelButton);

    connect(this->cancelButton, &QPushButton::pressed, this, &RodsTransferWindow::invokeCancel);
}

void RodsTransferWindow::setupMainProgressBar(QString initialMsg, int value, int maxValue)
{
    this->progressMax = maxValue;

    this->mainProgressBar->setMaximum(maxValue);
    this->updateMainProgress(initialMsg, value);
}

void RodsTransferWindow::updateMainProgress(QString currentMsg, int value)
{
    QString progMsg = "Processing item " + QVariant(value).toString();
    progMsg += " of " + QVariant(this->progressMax).toString();

    this->mainProgressMsg->setText(progMsg);
    this->subProgressMsg->setText(currentMsg);
    this->mainProgressBar->setValue(value);
}

void RodsTransferWindow::progressMarquee(QString currentMsg)
{
    this->mainProgressBar->setMaximum(0);
    this->subProgressBar->setMaximum(0);

    this->mainProgressMsg->setText("Initializing...");
    this->subProgressMsg->setText(currentMsg);
}

void RodsTransferWindow::invokeCancel()
{
    this->cancelRequested();
}
