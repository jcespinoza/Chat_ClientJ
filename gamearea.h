#ifndef GAMEAREA_H
#define GAMEAREA_H


#include <QWidget>
#include <QPainter>
#include <QString>
#include <Qlist>
#include "clientconnection.h"


class GameArea : public QWidget
{
public:
     GameArea(QWidget *parent = 0); // Este es el constructor por default


     void setCurrentCell(int fila, int col);
     void setConexion(ClientConnection *con);
     void setValor(int fila, int col, int valor);
     int getValor(int fila, int col);
     int getCurrentfila();
     int getCurrentcolumna();
     void reset();

private:

    int fila_actual, columna_actual;
    int filaPieza, columnaPieza;
    ClientConnection *referenciaConexion;
    QPixmap imagen_tablero;
    int TABLERO_INTERNO[8][8];
    enum Qt::GlobalColor getColor(int cual);





protected:
    void paintEvent(QPaintEvent *event);
    void focusOutEvent ( QFocusEvent * event );
    void focusInEvent ( QFocusEvent * event );
    void enterEvent ( QEvent * event ) ;
    QPixmap retorna_imagen();
};

#endif // GAMEAREA_H
