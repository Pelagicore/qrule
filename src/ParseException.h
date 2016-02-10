#ifndef PARSEEXCEPTION_H
#define PARSEEXCEPTION_H

#include <QString>

class ParseException: public std::exception {
  public:
    ParseException(QString reason): reason(reason) {}
    virtual const char* what() const throw() {
      return "My exception happened";
    }
  private:
    QString reason;
};

#endif // PARSEEXCEPTION_H

