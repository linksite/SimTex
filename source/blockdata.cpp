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

#include "blockdata.h"
#include <QDebug>

QVector<ParenthesisInfo *> BlockData::parentheses() {
    return _parentheses;
}
QVector<LatexBlockInfo *> BlockData::latexblocks() {
    return _latexblocks;
}

void BlockData::insertPar( ParenthesisInfo *info ) {
    int i = 0;
    while (
        i < _parentheses.size() &&
        info->position > _parentheses.at(i)->position )
        ++i;
    _parentheses.insert( i, info );
}

void BlockData::insertLat( LatexBlockInfo *info ) {
    int i = 0;
    while (
        i < _latexblocks.size() &&
        info->position > _latexblocks.at(i)->position )
        ++i;
    _latexblocks.insert( i, info );
}

bool BlockData::isAClosingDollar(int position)
{
    bool even = false;
    foreach(int dollar, this->_dollars)
    {
        if(dollar > position)
        {
            return even;
        }
        even = !even;
    }
    return even;
}
