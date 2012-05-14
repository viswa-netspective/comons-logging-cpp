#include<LogService.h>

using namespace std;

LogService* LogServiceFactory::loggerPrivate=NULL;

LogService* LogServiceFactory::Create(string cate,string file)
{
	if(cate.empty())
        {
                cate=defaultcate;
        }
        if(file.empty())
        {
                file=defaultconf;
        } 
	if(!loggerPrivate) {
                loggerPrivate = new LogService(cate,file);
        }
        return loggerPrivate;
}

LogService* LogServiceFactory::Create()
{
	if(!loggerPrivate) {
		loggerPrivate = new LogService(defaultcate,defaultconf);
	} 
        return loggerPrivate;

}


LogService::LogService(string cate,string file)
{

	log_root = &log4cpp::Category::getRoot();
        InfoLog = &log4cpp::Category::getInstance(std::string(cate));
        log4cpp::PropertyConfigurator::configure(file);


}


int LogService::info(const char *format, ...)
{
	char msg[1000];
	va_list argptr;
    	va_start(argptr, format);
    	vsprintf(msg, format, argptr);
    	va_end(argptr);
        InfoLog->info(string(msg));
	return 0;
}
int LogService::notify(const char *format, ...)
{
	char msg[1000];
    	va_list argptr;
    	va_start(argptr, format);
    	vsprintf(msg, format, argptr);
    	va_end(argptr);
        InfoLog->notice(string(msg));
        return 0;
}

int LogService::error(const char *format, ...)
{
	char msg[1000];
    	va_list argptr;
	va_start(argptr, format);
    	vsprintf(msg, format, argptr);
	va_end(argptr);
        InfoLog->error(string(msg));
        return 0;
}
int LogService::warn(const char *format, ...)
{
	char msg[1000];
    	va_list argptr;
    	va_start(argptr, format);
    	vsprintf(msg, format, argptr);
    	va_end(argptr);
        InfoLog->warn(string(msg));
        return 0;
}

int LogService::data(const char *format, ...)
{
	char msg[1000];
    	va_list argptr;
    	va_start(argptr, format);
    	vsprintf(msg, format, argptr);
    	va_end(argptr);
        InfoLog->info(string(msg));
        return 0;
}
