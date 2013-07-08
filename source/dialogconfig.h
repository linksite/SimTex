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

#ifndef DIALOGCONFIG_H
#define DIALOGCONFIG_H

#include <QDialog>
#include <QSettings>

namespace Ui {
class DialogConfig;
}

class DialogConfig : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogConfig(QWidget *parent = 0);
    ~DialogConfig();
public slots:
    void save(void);
    void saveAndClose(void);
    void show();
    
private:
    Ui::DialogConfig *ui;
    QSettings settings;
};

#endif // DIALOGCONFIG_H