#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->Conexion = new ClientConnection();


    connect(Conexion, SIGNAL(newMessage(ClientConnection*,QString,QString)),
            this, SLOT(procesarMensaje(ClientConnection*,QString,QString)));

    connect(Conexion, SIGNAL(connected(ClientConnection*, QString)),
            this, SLOT(seConecto(ClientConnection*, QString)));

    connect(Conexion, SIGNAL(disconnected(ClientConnection*, QString)),
            this , SLOT(seDesconecto(ClientConnection*, QString)));

    connect(Conexion, SIGNAL(ConnectionError(ClientConnection*, QString,QString)),
            this , SLOT(errorConexion(ClientConnection*, QString,QString)));

    this->Tablero = new GameArea();
    this->Tablero->setConexion(this->Conexion);

    this->Tablero->setFocusPolicy(Qt::TabFocus);
    this->ui->gridLayout->addWidget(this->Tablero,0,0,1,1);
    setNotPlayable();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->Conexion;
    delete this->Tablero;
}

void MainWindow::on_btnSalir_clicked()
{
    this->close();
}

void MainWindow::on_btnConnect_clicked()
{
    //READ:Validar que no deje en blanco, Nick, host, y puerto
    if(   this->ui->lineEdit_Nick->text().trimmed()==""
       || this->ui->lineEdit_Server->text().trimmed()==""
       || this->ui->lineEdit_Port->text().trimmed()==""
       )
    {
         QMessageBox::information(this,"Datos Vacios","Nick, Server o puerto vacios");
    }
    else
    {
        this->Conexion->conectarse(this->ui->lineEdit_Server->text(),
                                   this->ui->lineEdit_Port->text().toInt(),
                                   this->ui->lineEdit_Nick->text()
                                   );

    }
}

//----------------PUBLIC SLOTS ----------------------------
void MainWindow::procesarMensaje(ClientConnection *con, QString comando, QString mensaje)
{


    //Dependiendo del comando hacer ciertas cosas, por ejemplo
//    this->ui->textEdit->append("Comando recibido:" + comando + ">>" + mensaje);
    if(comando=="NICKLIST")
    {
       // this->ui->textEdit->append("Recibi la lista de Nicks.");
        //Viene la lista de nicks, sin el mio, este viene en otro mensaje.
        // Estos vienen separados por comas
        QStringList listtemp = mensaje.split(",");
        QString temporal = listtemp.at(0);
        if(temporal=="X") return; //La lista esta vacia.
        int i=0;
        while(i<listtemp.count())
        {
            // Agregarla al listwidget
            this->ui->listWidget->addItem(listtemp.at(i));

            i++;
        }
    }
    if(comando=="PLAY"){
        setPlayable();
        qDebug() << "it was this";
    }
    if(comando=="NEWNICK")
    {
          //Hay un nuevo nick
          //Agregarlo a la lista, al final
          this->ui->listWidget->addItem(mensaje);
         // this->ui->textEdit->append("Nuevo nick ha llegado :" + mensaje);


    }
    if(comando=="OLDNICK")
    {
        //Revisar otros casos y validaciones
        int i=0;
        while(i<this->ui->listWidget->count())
        {
            if(mensaje==this->ui->listWidget->item(i)->text())
                break;

            i++;
        }
       delete this->ui->listWidget->takeItem(i);

    }
    if(comando=="MSGFROM")
    {
        //Obtener el nick
        QString elNick;
        int end = mensaje.indexOf(":");
        elNick=mensaje.mid(0,end);
        mensaje = mensaje.mid(end+1);
        this->ui->textEdit->append(elNick+">>"+mensaje);

    }
    if(comando=="SERVERSTOP")
    {
        this->ui->textEdit->append("El server se detuvo");

    }
     if(comando=="RESETGAME")
    {
        this->ui->textEdit->append("Reset el Game");
        this->Tablero->reset();
        this->Tablero->update();

    }
    if(comando=="INFO")
    {
        this->ui->textEdit->append(mensaje);

    }
    if(comando=="MOVEOK")
    {
        int numjugador, fila,col;
        bool band;
        numjugador = mensaje.mid(0,1).toInt(&band,10);
        fila = mensaje.mid(2,1).toInt(&band,10);
        col = mensaje.mid(4,1).toInt(&band,10);
        // Ya se el jugador, la fila y columna, ahora setearlo
        // en el GameArea o sea el tablero
        this->Tablero->setValor(fila,col,numjugador);
        // redibuje el Tablero
        this->Tablero->update();
    }


}
void MainWindow::seConecto(ClientConnection *con, QString nick)
{
    this->ui->textEdit->append("Confirmando conexion .....");
    this->ui->btnConnect->setEnabled(false);
    this->ui->btnDisconnect->setEnabled(true);
    con->estaConectado = true;


}
void MainWindow::seDesconecto(ClientConnection *con, QString nick)
{
    this->ui->btnConnect->setEnabled(true);
    this->ui->btnDisconnect->setEnabled(false);
    this->ui->textEdit->append("Conexion cerrada ..." + nick);
    con->nick="";
    this->ui->listWidget->clear();

}
void MainWindow::errorConexion(ClientConnection*, QString titulo,QString mensaje)
{
    this->ui->textEdit->append("ERROR:"+titulo + ">>"+ mensaje);

}

void MainWindow::on_lineEdit_Mensaje_returnPressed()
{
    if(this->Conexion->estaConectado)
    {
       if(this->ui->lineEdit_Mensaje->text().trimmed()!="")
          this->Conexion->sendMessage("MSG:" +
                                      this->ui->lineEdit_Mensaje->text().trimmed() +
                                      "\n\r");
       this->ui->lineEdit_Mensaje->clear();


    }
    if(this->ui->lineEdit_Mensaje->text().trimmed()!="")
        ;
      //this->ui->webView->setUrl("http://www.google.com/search?q=" + this->ui->lineEdit_Mensaje->text().trimmed());

}

void MainWindow::on_btnDisconnect_clicked()
{
    this->Conexion->disconnect();

}
void MainWindow::keyPressEvent( QKeyEvent *event )
{
   // Revisar cual tecla se presiono ?
    // Aqui se agrega la condicion de canPlay()
    if (this->Conexion->estaConectado && canPlayUI)
    {
       switch(event->key())
       {

          case Qt::Key_Left :

           this->Tablero->setCurrentCell
                   (this->Tablero->getCurrentfila(),
                    this->Tablero->getCurrentcolumna()-1);

           break;

          case Qt::Key_Right :

           this->Tablero->setCurrentCell
                   (this->Tablero->getCurrentfila(),
                    this->Tablero->getCurrentcolumna()+1);

             break;
          case Qt::Key_Up :

             this->Tablero->setCurrentCell
                   (this->Tablero->getCurrentfila()-1,
                    this->Tablero->getCurrentcolumna());

             break;
           case Qt::Key_Down :

            this->Tablero->setCurrentCell
                   (this->Tablero->getCurrentfila()+1,
                    this->Tablero->getCurrentcolumna());

          break;
          // Cuando de enter hay que mandar el mensaje del movimiento
          case Qt::Key_Return :
                 int f = this->Tablero->getCurrentfila();
                 int c = this->Tablero->getCurrentcolumna();
                 QString tempf,tempc;
                 tempf.setNum(f,10);
                 tempc.setNum(c,10);

                 this->Conexion->sendMessage("MOVE:"+tempf+":"+tempc + "\n\r");
               //  this->ui->textEdit->append("MOVE:"+tempf+":"+tempc + "\n\r");
                 // Importante notar que aun asi, NO se cambia nada de tablero
                 // mientras no recibamos el Ok del server (MOVEOK)
              break;
      }
   }
   this->Tablero->update();


}







void MainWindow::on_lineEdit_editingFinished()
{
  //this->ui->webView->setUrl("http://www.google.com/search?q=" + this->ui->lineEdit->text());
}


