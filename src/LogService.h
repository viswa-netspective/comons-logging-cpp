#ifndef __LOGSERVICE_H_
#define __LOGSERVICE_H_


/*Log4cpp Library*/
#include <log4cpp/Category.hh>
#include <log4cpp/PropertyConfigurator.hh>
#include <log4cpp/Configurator.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/SimpleLayout.hh>
#include <stdarg.h>
#include <iostream>
#define defaultconf "/etc/log4cpp.conf"
#define defaultcate "log.echo"
using namespace std;



class LogService
{

	private:
	log4cpp::Category *log_root; 
        log4cpp::Category *InfoLog; 

	public:
	LogService(string cate, string file);
	int info(const char *format, ...);
        int notify(const char *format, ...);
        int error(const char *format, ...);
        int warn(const char *format, ...);
        int data(const char *format, ...);

};


class LogServiceFactory
{
	private:
	static LogService *loggerPrivate;
	public:
	static LogService* Create(string category,string filename);
	static LogService* Create();
};

#endif
