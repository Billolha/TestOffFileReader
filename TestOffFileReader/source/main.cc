
/*! \file main.cc
 *
 * \author Paul BERNARD <paul.bernard@eisti.fr>
 *                                                   
 * \version 0.1
 *            Creation du fichier main.cc
 */

#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QWidget>
#include <QGradient>
#include <QPen>

#include "main.hh"


/*! 
 * \fn int main(int argc, char** argv) 
 * \author Paul BERNARD <paul.bernard@eisti.fr> 
 * \version 0.1 
 * 
 * \param argc : le nombre de parametres donnee en ligne de commande 
 * \param argv : la ligne de commande 
 * 
 * \return retourne 0 si tout ce passe bien 
 * 
 * \brief 
 */ 
int main(int argc, char** argv){
  
  //init des ressources
  Q_INIT_RESOURCE(basicdrawing);
 
  QApplication app(argc, argv);
  //Creation d'une fenetre
  Fenetre fenetre;
  
  //on affiche la fenetre
  fenetre.show();
  
  //fin de l'exec
  return app.exec();
  
}




