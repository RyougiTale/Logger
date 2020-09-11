#include <fstream>
#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
using std::ofstream;

class Logger
{
private:
    ofstream log_file;
    Logger()
    {
        log_file.open("temp.log");
        if (!log_file.is_open())
        {
            cerr << "err with open file" << endl;
        }
    }
    ~Logger()
    {
        log_file.close();
    }
    Logger(Logger const &) = delete;
    Logger &operator=(Logger const &) = delete;

public:
    static Logger &getInstace()
    {
        static Logger instance;
        return instance;
    }

    void log()
    {
        log_file << "hello world" << endl;
    }
};
