/***********************************************************************************************************************
**
** Copyright (C) 2022 Saratov Free Software Center. <optics@sarfsc.ru>
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation; either version 2
** of the License, or (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
**
***********************************************************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "statusbarwidget.h"

#include "graphmodel.h"

const int STRETCH_WIDGET = 1;

namespace gui
{
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow())
    , model(std::make_unique<GraphModel>())
{
    ui->setupUi(this);

    ui->statusbar->addPermanentWidget(new StatusBarWidget(), STRETCH_WIDGET);

    ui->graphWidget->setModel(model.get());
}

MainWindow::~MainWindow()
{
    delete ui;
}

} // namespace gui
