/*
 * Copyright (C) Pedram Pourang (aka Tsu Jan) 2014 <tsujan2000@gmail.com>
 *
 * FeatherPad is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * FeatherPad is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TABPAGE_H
#define TABPAGE_H

#include <QPointer>
#include "searchbar.h"
#include "textedit.h"

namespace FeatherPad {

class TabPage : public QWidget
{
    Q_OBJECT
public:
    explicit TabPage (QWidget *parent = 0, bool sysIcons = false);

    QPointer<TextEdit> textEdit() const {
        return textEdit_;
    }

    void setSearchBarVisible (bool visible);
    bool isSearchBarVisible() const;
    void focusSearchBar();

    QString searchEntry() const;
    void clearSearchEntry();

    bool matchCase() const;
    bool matchWhole() const;

    void disableShortcuts (bool disable);

signals:
    void find (bool forward);
    void searchFlagChanged();

private:
    QPointer<TextEdit> textEdit_;
    QPointer<SearchBar> searchBar_;
};

}

#endif // TABPAGE_H