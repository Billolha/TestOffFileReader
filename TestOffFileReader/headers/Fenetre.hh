#ifndef FENETRE_H
#define FENETRE_H

#include <QWidget>
#include "include.hh"
#include <QtGui>
#include <QPushButton>
#include <QApplication>
#include "ZoneAffichage.hh"
//classe zone d'affichage

class ZoneAffichage;
class Objet2d;
class Polygonne;


/*! 
 * \fn Polyedre chargeficoff(const char* nomfic) 
 * \author  Paul BERNARD <paul.bernard@eisti.fr> 
 * \version 0.1 
 *          Création de la fonction
 * 
 * \param nomfic : nom du fichier
 * 
 * \return un polyedre
 * 
 * \brief permet de creer un polyedre a partir du fichier chargé
 * 
*/ 
Polyedre chargeficoff (const char * nomfic);


/*! \class Fenetre
 * \author Paul BERNARD
 * \version 0.1
 * \brief classe fenetre
 *
 */
class Fenetre: public QWidget
{
  Q_OBJECT;
  
 private:
  ZoneAffichage * zoneAffichage;/*!< la zone ou on affiche l'objet*/  
  QGridLayout* mainLayout;/*!< le layuot de la fenetre */
  QString dossier;/*!< QString chemin du dossier ouvert */
  QString fichier;/*!< QString nom du fichier choisie */
  QComboBox* mybox;/*!< la liste deroulante de fichier */
  

 public:
  /*! \fn  Fenetre(void) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \brief permet d'init une fenetre par defaut
   * 
   */ 
  Fenetre();
  /*! \fn  ~Fenetre(void) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \brief destructeur de fenetre
   * 
   */ 
  ~Fenetre();
  /*! \fn  void keyPressEvent(QKeyEvent* event) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   *
   * \param event : un event clavier
   * 
   * \brief permet de gerer les events clavier
   * 
   */ 
  void keyPressEvent(QKeyEvent * event);


public slots :
  
  /*! \fn  void ouvrirDialogue() 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   *
   * 
   * \brief permet d'ouvrir la boite de dialogue (ouvrir dossier)
   * 
   */ 
  void ouvrirDialogue();
  /*! \fn  void ouvrirDialogue2(int id) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * \param id : numero du fichier dans la liste deroulante
   * 
   * \brief permet de creer et afficher la figure un fois le fichier 
   *        selectionne dans la liste deroulante
   * 
   */ 
  void ouvrirDialogue2(int id);
  /*! \fn  void zoomplus() 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   *
   * 
   * \brief permet de zoomer
   * 
   */ 
  void zoomplus();
  /*! \fn  void zoommoins() 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   *
   * 
   * \brief permet de dezoomer
   * 
   */ 
  void zoommoins();
  /*! \fn  void haut() 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   *
   * 
   * \brief permet de faire une rotation vers le haut
   * 
   */ 
  void haut();
  /*! \fn  void bas() 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   *
   * 
   * \brief permet de faire une rotation vers le bas
   * 
   */ 
  void bas();
  /*! \fn  void gauche() 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   *
   * 
   * \brief permet de faire une rotation vers la gauche
   * 
   */ 
  void gauche();
  /*! \fn  void droit() 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   *
   * 
   * \brief permet de faire une rotation vers la droite
   * 
   */ 
  void droit();
  
  
  /*! \fn  void mhaut() 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   *
   * 
   * \brief permet de faire un mouvement vers le haut
   * 
   */ 
  void mhaut();
  /*! \fn  void mbas() 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   *
   * 
   * \brief permet de faire un mouvement vers le bas
   * 
   */ 
  void mbas();
  /*! \fn  void mgauche() 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   *
   * 
   * \brief permet de faire un mouvement vers la gauche
   * 
   */ 
  void mgauche();
  /*! \fn  void mdroit() 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   *
   * 
   * \brief permet de faire un mouvement vers la droite
   * 
   */ 
  void mdroit();
  
  
  /*! \fn  void ouvrirDialogueaide() 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   *
   * 
   * \brief permet d'ouvrir l'aide
   * 
   */ 
  void ouvrirDialogueaide();
  
};

#endif
