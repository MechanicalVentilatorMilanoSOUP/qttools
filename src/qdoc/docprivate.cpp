/****************************************************************************
**
** Copyright (C) 2020 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the tools applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL-EXCEPT$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/
#include "docprivate.h"

#include "atom.h"
#include "openedlist.h"
#include "text.h"

#include <QtCore/qhash.h>
#include <QtCore/qregexp.h>

QT_BEGIN_NAMESPACE

/*!
  If the doc is a ditamap, the destructor deletes each element
  in the ditamap structure. These were allocated as needed.
 */
DocPrivate::~DocPrivate()
{
    delete extra;
    qDeleteAll(ditamap_);
}

void DocPrivate::addAlso(const Text &also)
{
    alsoList.append(also);
}

void DocPrivate::constructExtra()
{
    if (extra == nullptr)
        extra = new DocPrivateExtra;
}

QT_END_NAMESPACE
