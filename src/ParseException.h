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

