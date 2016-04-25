// Copyright (C) 2016 Pelagicore
//
// You may use this file under the terms of the GPLv3 license.
// See the file LICENSE from this package for details.
//
// SPDX-License-Identifier: GPL-3.0

#ifndef PARSEEXCEPTION_H
#define PARSEEXCEPTION_H

#include <QString>

class ParseException: public std::exception {
  public:
    ParseException(QString reason): reason(reason) { wh=reason.toStdString().c_str(); }
    virtual const char* what() const throw() {
      return this->wh;
    }
    QString reason;
    const char* wh;
  private:
};

#endif // PARSEEXCEPTION_H

