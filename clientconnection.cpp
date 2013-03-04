#include "clientconnection.h"

ClientConnection::ClientConnection()
{
    //READ: Instanciar Socket y conectar las señales, la
    socket = new QTcpSocket(this);
    canPlay = false;
    connect(socket, SIGNAL(connected()), this, SLOT(conectado()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(recv()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnect()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));

    this->nick="";
    this->estaConectado =false;
}
void ClientConnection::recv() {
        message.append(socket->readAll());

        int pos;
        while((pos = message.indexOf("\n\r")) > -1) {
                parseMessage(QString(message.left(pos+2)));
                message = message.mid(pos+2);
        }
}
void ClientConnection::conectarse(QString host, int port,QString nick)
{
  this->socket->abort();
  this->nick = nick;
  this->socket->connectToHost(host, port);
}

void ClientConnection::conectado()
{

    this->sendMessage("CON:" + this->nick + "\n\r");
   //Avisar a la pantalla principal que logre conectarme pero no confirmado el nick
    this->estaConectado=false; // Se confirma hasta que recibimos nuestro nick otra vez


}

void ClientConnection::parseMessage(QString msg) {

    //READ: Emitir los comandos con sus respectivos mensajes
       if(msg.startsWith("NICKLIST:"))
       {
           msg = msg.mid(9);
           msg = msg.mid(0,msg.length()-2);
           emit newMessage(this,"NICKLIST",msg);
       }
       if(msg.startsWith("PLAY")){
           emit startGame();
           emit newMessage(this, "PLAY", "You can now play");
       }
       if(msg.startsWith("NEWNICK:"))
       {
           msg = msg.mid(8);
           msg = msg.mid(0,msg.length()-2);
           emit newMessage(this,"NEWNICK",msg);
           if (this->nick==msg) // Es mi mismo nick, entonces confirmar
                emit connected(this, nick);
       }
       if(msg.startsWith("OLDNICK:"))
       {
           msg = msg.mid(8);
           msg = msg.mid(0,msg.length()-2);
           emit newMessage(this,"OLDNICK",msg);
       }
        if(msg.startsWith("MSGFROM:"))
       {
           msg = msg.mid(8);
           msg = msg.mid(0,msg.length()-2);
           emit newMessage(this,"MSGFROM",msg);
       }
       if(msg.startsWith("SERVERSTOP:"))
       {
           emit newMessage(this,"SERVERSTOP","");
       }
       if(msg.startsWith("RESETGAME:"))
       {
           emit newMessage(this,"RESETGAME","");
       }
       if(msg.startsWith("MOVEOK:"))
       {
           msg = msg.mid(7);
           msg = msg.mid(0,msg.length()-2);
           emit newMessage(this,"MOVEOK",msg);
       }
       if(msg.startsWith("INFO:"))
       {
           msg = msg.mid(5);
           msg = msg.mid(0,msg.length()-2);
           emit newMessage(this,"INFO",msg);
       }



      /*          int start = msg.indexOf("Nick: ");
                int end = msg.indexOf("\n", start);
                QString newNick = msg.mid(start + 6, end - start - 6);
*/

}
void ClientConnection::sendMessage(QString msg) {
    //READ: Si el socket de la conexion es valido entonces enviar el mensaje
    // Pero convertirlo en ASCII
    if (socket->isValid())
        socket->write(msg.toLatin1());

}
void ClientConnection::disconnect() {
       //READ: Emitir una señal al server para desconectarse
     this->estaConectado =false;
     this->socket->close();
     emit disconnected(this, nick);

}
void ClientConnection::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
          emit ConnectionError(this, tr("Chat Client"),
                                 tr("The host was not found. Please check the "
                                    "host name and port settings."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        emit ConnectionError(this, tr("Chat Client"),
                                 tr("The connection was refused by the peer. "
                                    "Make sure the Chat server is running, "
                                    "and check that the host name and port "
                                    "settings are correct."));
        break;
    default:
        emit ConnectionError(this, tr("Chat Client"),
                                 tr("The following error occurred: %1.")
                                 .arg(socket->errorString()));
    }


}

