/*******************************************************************************
 * retroshare-gui/src/util/ClickableLabel.cpp                                  *
 *                                                                             *
 * Copyright (C) 2020 by RetroShare Team       <retroshare.project@gmail.com>  *
 *                                                                             *
 * This program is free software: you can redistribute it and/or modify        *
 * it under the terms of the GNU Affero General Public License as              *
 * published by the Free Software Foundation, either version 3 of the          *
 * License, or (at your option) any later version.                             *
 *                                                                             *
 * This program is distributed in the hope that it will be useful,             *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                *
 * GNU Affero General Public License for more details.                         *
 *                                                                             *
 * You should have received a copy of the GNU Affero General Public License    *
 * along with this program. If not, see <https://www.gnu.org/licenses/>.       *
 *                                                                             *
 *******************************************************************************/
 
#include "ClickableLabel.h"

/** Constructor */
ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent, f) {

}

ClickableLabel::~ClickableLabel() {

}

void ClickableLabel::mousePressEvent(QMouseEvent* /*event*/) {
    emit clicked();
}

#if QT_VERSION >= QT_VERSION_CHECK (6, 0, 0)
void ClickableLabel::enterEvent(QEnterEvent* /*event*/)
#else
void ClickableLabel::enterEvent(QEvent* /*event*/)
#endif
{
    if (mUseStyleSheet) {
        setStyleSheet("QLabel { border: 2px solid #039bd5; }");
    }
}

void ClickableLabel::leaveEvent(QEvent* /*event*/)
{
    if (mUseStyleSheet) {
        setStyleSheet("");
    }
}
