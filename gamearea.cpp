#include "gamearea.h"


GameArea::GameArea(QWidget *parent) : QWidget(parent) // llamar constructor clase base
{
    setBackgroundRole( QPalette::Base );
    setAutoFillBackground( true );
    fila_actual=columna_actual=0; // Para el recuadro azul que se mueve con el cursor
     for (int i=0; i<8 ; i++)
      for (int j=0; j<8 ; j++)
          this->TABLERO_INTERNO[i][j]=-1;

    imagen_tablero.load(":/images/tablero.png");


}

void GameArea::reset()
{
     for (int i=0; i<8 ; i++)
      for (int j=0; j<8 ; j++)
          this->TABLERO_INTERNO[i][j]=-1;

}
void GameArea::setValor(int fila, int col, int valor)
{
    // Se deberia validar fila y col pero asumamos que vienen bien
    this->TABLERO_INTERNO[fila][col]=valor;

}
 int GameArea::getValor(int fila, int col)
 {
     // Igual deberia validar fila y col
     return this->TABLERO_INTERNO[fila][col];

 }
void GameArea::focusOutEvent ( QFocusEvent * event )
{
  this->releaseKeyboard();
}
void GameArea::focusInEvent ( QFocusEvent * event )
{
  this->grabKeyboard();
}
void GameArea::enterEvent ( QEvent * event )
{
    this->setFocus();
}

QPixmap GameArea::retorna_imagen()
{
  return this->imagen_tablero;

}


void GameArea::paintEvent( QPaintEvent * event ){
    QPainter painter( this ); // Inicializar el Painter
    // Dibujar el tablero primero SIEMPRE

    painter.drawPixmap(0,0,this->retorna_imagen());
    QPen pen(Qt::blue, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen( pen);
    painter.setBrush(Qt::transparent); // Y la brocha transparente.
    painter.drawRect(columna_actual*59+15,fila_actual*59+15,59,59);
    // Redibujar el tablero
     for (int i=0; i<8 ; i++)
      for (int j=0; j<8 ; j++)
      {
          if(this->TABLERO_INTERNO[i][j]!=-1)
         {  // Pintar un circulo pequeño con un color de acuerdo al numero interno.
              painter.setPen(Qt::black);
              painter.setBrush(this->getColor(this->TABLERO_INTERNO[i][j]));
              painter.drawEllipse(j*59+25,i*59+25,30,30);


          }
      }


}
enum Qt::GlobalColor GameArea::getColor(int cual)
{
    switch(cual)
    {
        case 0 : return Qt::white;
        case 1 : return Qt::red;
        case 2 : return Qt::blue;
        case 3 : return Qt::yellow;
        case 4 : return Qt::green;
        case 5 : return Qt::gray;
        case 6 : return Qt::magenta;
        case 7 : return Qt::darkMagenta;
        default: return Qt::black;


    }

}
int GameArea::getCurrentfila()
{
    return fila_actual;
}
int GameArea::getCurrentcolumna()
{
    return columna_actual;
}

void GameArea::setCurrentCell(int fila, int col)
{
    if((fila>=0 && fila<=7)&&(col>=0 && col<=7))
    {
      fila_actual = fila;
      columna_actual = col;
    }

}
void GameArea::setConexion( ClientConnection *con)
{
    this->referenciaConexion = con;

}

