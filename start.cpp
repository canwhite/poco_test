#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Util/ServerApplication.h"
#include <string>
using namespace Poco::Net;
using namespace Poco::Util;
using namespace std;


//request和response
class HelloWorldRequestHandler: public HTTPRequestHandler
{
    virtual void handleRequest(HTTPServerRequest &req, HTTPServerResponse &resp)
    {
        resp.setStatus(HTTPResponse::HTTP_OK);
        resp.setContentType("text/html");
        ostream& out = resp.send();
        out << "Hello, World!";
        out.flush();
    }
};


//工厂方法，上边的包装
class HelloWorldRequestHandlerFactory: public HTTPRequestHandlerFactory
{
public:
    virtual HTTPRequestHandler* createRequestHandler(const HTTPServerRequest &)
    {
        return new HelloWorldRequestHandler;
    }
};



class MyApp: public ServerApplication
{
protected:
    //虚函数main，这个在ServerApplication内部被调用
    int main(const vector<string> &)
    {
        HTTPServer srv(new HelloWorldRequestHandlerFactory, 8089);
        srv.start();
        cout << endl << "Server started" << endl;
        waitForTerminationRequest(); 
        cout << endl << "Shutting down..." << endl;
        srv.stop();
        return Application::EXIT_OK;
    }
};


int main(int argc, char** argv)
{
    MyApp app;
    return app.run(argc, argv);
}