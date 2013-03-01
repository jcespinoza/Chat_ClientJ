#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <Qlist>
#include <QKeyEvent>
//READ: Incluir la client connection
#include "clientconnection.h"
#include "gamearea.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    //READ: Declarar un apuntador a una conexion
    ClientConnection *Conexion;
    GameArea *Tablero;
    bool canPlayUI;

public slots:
     void procesarMensaje(ClientConnection *con, QString comando, QString mensaje);
     void seConecto(ClientConnection *con, QString nick);
     void seDesconecto(ClientConnection *con, QString nick);
     void errorConexion(ClientConnection*, QString titulo,QString mensaje);

private slots:
     void setPlayable(){canPlayUI = true;}
     void setNotPlayable(){canPlayUI = true;}
    void on_lineEdit_editingFinished();
    void on_btnDisconnect_clicked();
    void on_lineEdit_Mensaje_returnPressed();
    void on_btnConnect_clicked();
    void on_btnSalir_clicked();

protected:
     virtual void keyPressEvent( QKeyEvent *event );
};

#endif // MAINWINDOW_H
