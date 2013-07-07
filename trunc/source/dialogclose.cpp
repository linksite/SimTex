/***************************************************************************
 *   copyright       : (C) 2013 by Quentin BRAMAS                          *
 *   http://www.simtex.fr                                                  *
 *                                                                         *
 *   This file is part of SimTex.                                          *
 *                                                                         *
 *   SimTex is free software: you can redistribute it and/or modify        *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation, either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   SimTex is distributed in the hope that it will be useful,             *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with SimTex.  If not, see <http://www.gnu.org/licenses/>.       *                         *
 *                                                                         *
 ***************************************************************************/

#include "dialogclose.h"
#include "ui_dialogclose.h"
#include <QDebug>

DialogClose::DialogClose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogClose),
    _confirmed(false)
{
    ui->setupUi(this);

    connect(this->ui->confirmAndClose, SIGNAL(clicked()), this, SLOT(confirmAndClose()));
    connect(this->ui->cancel, SIGNAL(clicked()), this, SLOT(close()));
}

DialogClose::~DialogClose()
{
    delete ui;
}


void DialogClose::confirmAndClose()
{
    _confirmed = true;
    this->close();
}
void DialogClose::setMessage(QString message)
{
    this->ui->label->setText(message);
}
