// albert - a simple application launcher for linux
// Copyright (C) 2014-2015 Manuel Schneider
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once
#include <QObject>
#include <memory>
#include "core/extension.h"
#include "core/queryhandler.h"

namespace Debug {

class Private;

class Extension final :
        public Core::Extension,
        public Core::QueryHandler
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID ALBERT_EXTENSION_IID FILE "metadata.json")

public:

    Extension();
    ~Extension();

    QString name() const override { return "Debug"; }
    QWidget *widget(QWidget *parent = nullptr) override;
    QStringList triggers() const override;
    void handleQuery(Core::Query * query) const override;
    ExecutionType executionType() const override;

    int count() const;
    void setCount(const int &count);

    bool async() const;
    void setAsync(bool async);

    int delay() const;
    void setDelay(const int &delay);

    const QString& trigger() const;
    void setTrigger(const QString &trigger);

private:

    std::unique_ptr<Private> d;

};
}
