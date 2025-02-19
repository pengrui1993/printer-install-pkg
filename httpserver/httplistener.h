/**
  @file
  @author Stefan Frings
*/

#ifndef HTTPLISTENER_H
#define HTTPLISTENER_H


#include<QtNetwork/QTcpServer>
#include <QSettings>
#include <QBasicTimer>
#include "httpglobal.h"
#include "httpconnectionhandler.h"
#include "httpconnectionhandlerpool.h"
#include "httprequesthandler.h"

namespace stefanfrings {

/**
  Listens for incoming TCP connections and and passes all incoming HTTP requests to your implementation of HttpRequestHandler,
  which processes the request and generates the response (usually a HTML document).
  <p>
  Example for the required settings in the config file:
  <code><pre>
  ;host=192.168.0.100
  port=8080
  minThreads=1
  maxThreads=10
  cleanupInterval=1000
  readTimeout=60000
  ;sslKeyFile=ssl/my.key
  ;sslCertFile=ssl/my.cert
  maxRequestSize=16000
  maxMultiPartSize=1000000
  </pre></code>
  The optional host parameter binds the listener to one network interface.
  The listener handles all network interfaces if no host is configured.
  The port number specifies the incoming TCP port that this listener listens to.
  @see HttpConnectionHandlerPool for description of config settings minThreads, maxThreads, cleanupInterval and ssl settings
  @see HttpConnectionHandler for description of the readTimeout
  @see HttpRequest for description of config settings maxRequestSize and maxMultiPartSize
*/

class DECLSPEC HttpListener : public QTcpServer {
    Q_OBJECT
    Q_DISABLE_COPY(HttpListener)
public:

    /**
      Constructor.
      Creates a connection pool and starts listening on the configured host and port.
      @param settings Configuration settings, usually stored in an INI file. Must not be 0.
      Settings are read from the current group, so the caller must have called settings->beginGroup().
      Because the group must not change during runtime, it is recommended to provide a
      separate QSettings instance that is not used by other parts of the program.
      The HttpListener does not take over ownership of the QSettings instance, so the
      caller should destroy it during shutdown.
      @param requestHandler Processes each received HTTP request, usually by dispatching to controller classes.
      @param parent Parent object.
      @warning Ensure to close or delete the listener before deleting the request handler.
    */
    HttpListener(const QSettings* settings, HttpRequestHandler* requestHandler, QObject* parent=nullptr);

    /** Destructor */
    virtual ~HttpListener();

    /**
      Restart listeing after close().
    */
    void listen();

    /**
     Closes the listener, waits until all pending requests are processed,
     then closes the connection pool.
    */
    void close();

protected:

    /** Serves new incoming connection requests */
    void incomingConnection(tSocketDescriptor socketDescriptor);

private:

    /** Configuration settings for the HTTP server */
    const QSettings* settings;

    /** Point to the reuqest handler which processes all HTTP requests */
    HttpRequestHandler* requestHandler;

    /** Pool of connection handlers */
    HttpConnectionHandlerPool* pool;

signals:

    /**
      Sent to the connection handler to process a new incoming connection.
      @param socketDescriptor references the accepted connection.
    */

    void handleConnection(tSocketDescriptor socketDescriptor);

};

} // end of namespace

#endif // HTTPLISTENER_H
