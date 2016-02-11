#ifndef PARSEEXCEPTION_H
#define PARSEEXCEPTION_H

#include <QString>

class ParseException: public std::exception {
  public:
    ParseException(QString reason): reason(reason) {}
    virtual const char* what() const throw() {
      return "A KRule does not hold";
    }
    QString reason;
  private:
};

#endif // PARSEEXCEPTION_H

